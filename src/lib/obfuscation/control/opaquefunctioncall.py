import abc
import pycparser
import copy

from src.lib.crypto.rng import prng

import networkx as nx
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.chandling.variableclassifier as variableclassifier
import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.pycparserfinder as pycparserfinder
import src.lib.chandling.pycparsertypes as pycparsertypes
import src.lib.obfuscation.utils.namegenerator as namegenerator

class OpaqueFunctionCall(abc.ABC):

    def __init__(
        self, 
        cbuilder: cbuilder.CBuilder, 
        frequent_builder: cbuilder.FrequentCodeCBuilder,
        name_generation: namegenerator.NameGenerator,
        integer_definitions: ctypes.CTypeTable,
        function_finder: pycparserfinder.ItemFinder,
        variable_classifier: variableclassifier.StandardVariableClassifier,
        function_list: list[str],
        declarations_ast: pycparser.c_ast,
        dependecy_graph: nx.DiGraph
        ) -> None:
        self._cbuilder = cbuilder
        self._frequent_cbuiler = frequent_builder
        self._name_generation = name_generation
        self._integer_definitions = integer_definitions
        self._function_finder = function_finder
        self._variable_classifier = variable_classifier
        self._functions_list = function_list
        self._declarations_ast = declarations_ast
        self._dependency_graph = dependecy_graph

    @abc.abstractmethod
    def _create_function(self, function_name: str, declarations_ast: pycparser.c_ast, dependency_graph: nx.DiGraph) -> list[pycparser.c_ast.Node]:
        pass
    
    @abc.abstractmethod
    def use_opaque_call(self, used_predicate: pycparser.c_ast.Node, current_block: pycparser.c_ast.Compound) -> None:
        pass

class NoCallOpaqueFunctionCall(OpaqueFunctionCall):

    def _treat_simple(self, used_type: ctypes.CTypeInfo) -> pycparser.c_ast.Node:
        byte_string = prng.get_n_bytes(used_type.size)
        ctype_instance = used_type.enum_instance
        name = self._name_generation.generate_name()
        generated_variable = self._frequent_cbuiler.define_initialized_variable_bytes(byte_string, name, ctype_instance)
        return generated_variable

    def _treat_variable(self, declarations_ast: pycparser.c_ast, argument_type: pycparser.c_ast.Node, dependency_graph: nx.DiGraph) -> pycparser.c_ast.Node | None:
        primitive = pycparsertypes.corresponding_primitive(argument_type, self._integer_definitions)
        if not primitive is None:
            if primitive.enum_instance == ctypes.CTypes.VOID:
                return None
            return self._treat_simple(primitive)
        
        is_typedef = pycparsertypes.is_type_identifier(argument_type.type)
        if is_typedef:
            typedef_name = argument_type.type.names[0]
            typedef_identifier = dependencyresolver.identifier_of_name(typedef_name, dependency_graph)
            original_name, node_type = self._variable_classifier.classify_variable(typedef_identifier, dependency_graph)
            if ctypes.is_primitive(node_type):
                if node_type == ctypes.CTypes.VOID:
                    return None
                return self._treat_simple(self._integer_definitions[node_type])

        raise Exception("Object not made to handle complex types (enums, structs, union)")
    
    def _create_function(self, function_name: str, declarations_ast: pycparser.c_ast, dependency_graph: nx.DiGraph) -> list[pycparser.c_ast.Node]:
        function_node = self._function_finder.find(declarations_ast, function_name)
        function_identifier = dependencyresolver.identifier_of_name(function_name, dependency_graph)

        arguments = function_node.type.args.params
        variables = []
        for argument in arguments:
            argument_type = argument.type
            created_variable = self._treat_variable(declarations_ast, argument_type, dependency_graph)
            if not created_variable is None:
                variables.append(created_variable)

        function_call = self._cbuilder.function_call(function_name, [self._cbuilder.variable(var.name) for var in variables])

        return_type = function_node.type.type
        type_identifier = ctypes.corresponding_ctype(self._integer_definitions, return_type.type.names)

        if type_identifier != ctypes.CTypes.VOID:
            return_variable = self._treat_variable(declarations_ast, return_type, dependency_graph)
            final_statement = self._cbuilder.assignment(coperators.AssignmentCOperator.ASSIGNMENT, self._cbuilder.variable(return_variable.name), function_call)
            return variables + [return_variable] + [final_statement]
        else:
            return variables + [function_call]

    def use_opaque_call(self, used_predicate: pycparser.c_ast.Node, current_block: pycparser.c_ast.Compound) -> None:
        '''Place an opaque if with a call to the function'''
        block_range = len(current_block.block_items)
        chosen_index = prng.get_range_unsigned_integer(block_range + 1)

        chosen_function = prng.random_choice(self._functions_list)
        new_nodes_list = self._create_function(chosen_function, self._declarations_ast, self._dependency_graph)

        negated_predicate = self._cbuilder.unary_operation(coperators.UnaryCOperator.NOT, used_predicate) 
        new_block = self._cbuilder.block(new_nodes_list)
        new_if = self._cbuilder.if_block(negated_predicate, new_block)

        current_block.block_items.insert(chosen_index, new_if)
