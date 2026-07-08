import abc
import pycparser
import copy

from src.lib.crypto.rng import prng

import networkx as nx
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.coperators as coperators
import src.lib.chandling.variableclassifier as variableclassifier
import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.pycparserfinder as pycparserfinder
import src.lib.chandling.pycparsertypes as pycparsertypes
import src.lib.obfuscation.utils.namegenerator as namegenerator

class CBuilder(abc.ABC):

    def __init__(self, integer_definitions: ctypes.CTypeTable) -> None:
        self._integer_definitions = integer_definitions
    
    @abc.abstractmethod
    def variable(self, variable_name: str) -> pycparser.c_ast.ID:
        pass
    
    @abc.abstractmethod
    def constant(self, constant_type: ctypes.CTypes, value: int) -> pycparser.c_ast.Constant:
        pass
    
    @abc.abstractmethod
    def unary_operation(self, operator: coperators.UnaryCOperator, operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        pass
    
    @abc.abstractmethod
    def binary_operation(self, operator: coperators.BinaryCOperator, left_operand: pycparser.c_ast.Node, right_operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        pass

    @abc.abstractmethod
    def block(self, items_list: list[pycparser.c_ast.Node]) -> pycparser.c_ast.Compound:
        pass

    @abc.abstractmethod
    def assignment(self, operator: coperators.AssignmentCOperator, left_value: pycparser.c_ast.Node, right_value: pycparser.c_ast.Node) -> pycparser.c_ast.Assignment:
        pass
    
    @abc.abstractmethod
    def if_block(self, condition: pycparser.c_ast.Node, true_block: pycparser.c_ast.Compound, false_block: pycparser.c_ast.Compound | None = None) -> pycparser.c_ast.If:
        pass
    
    @abc.abstractmethod
    def while_block(self, condition: pycparser.c_ast.Node, statement_block: pycparser.c_ast.Compound) -> pycparser.c_ast.While:
        pass
    
    @abc.abstractmethod
    def function_call(self, name: str, arguments: list[pycparser.c_ast.Node]) -> pycparser.c_ast.Node:
        pass

    @abc.abstractmethod
    def cast(self, target_type: ctypes.CTypes, expression: pycparser.c_ast.Node) -> pycparser.c_ast.Cast:
        pass

    @abc.abstractmethod
    def declaration(self, variable_name: str, integer_type: ctypes.CTypes, initializer: pycparser.c_ast.Node | None = None) -> pycparser.c_ast.Decl:
        pass

class StandardCBuilder(CBuilder):

    def variable(self, variable_name: str) -> pycparser.c_ast.ID:
        return pycparser.c_ast.ID(
            name = variable_name
        )
    
    def constant(self, constant_type: ctypes.CTypes, value: int | str) -> pycparser.c_ast.Constant:
        const = pycparser.c_ast.Constant(
            type = self._integer_definitions[constant_type].cname_list,
            value = str(value)
        )

        return self.cast(
            constant_type,
            const
        )
    
    def unary_operation(self, operator: coperators.UnaryCOperator, operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        return pycparser.c_ast.UnaryOp(
            op = operator.value.pycparser_string,
            expr = copy.deepcopy(operand)
        )
    
    def binary_operation(self, operator: coperators.BinaryCOperator, left_operand: pycparser.c_ast.Node, right_operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        return pycparser.c_ast.BinaryOp(
            op = operator.value.pycparser_string,
            left = copy.deepcopy(left_operand),
            right = copy.deepcopy(right_operand)
        )

    def block(self, items_list: list[pycparser.c_ast.Node]) -> pycparser.c_ast.Compound:
        return pycparser.c_ast.Compound(
            block_items = copy.deepcopy(items_list)
        )
    
    def assignment(self, operator: coperators.AssignmentCOperator, left_value: pycparser.c_ast.Node, right_value: pycparser.c_ast.Node) -> pycparser.c_ast.Assignment:
        return pycparser.c_ast.Assignment(
            op = operator.value.pycparser_string,
            lvalue = copy.deepcopy(left_value),
            rvalue = copy.deepcopy(right_value)
        )
    
    def if_block(self, condition: pycparser.c_ast.Node, true_block: pycparser.c_ast.Compound, false_block: pycparser.c_ast.Compound | None = None) -> pycparser.c_ast.If:
        return pycparser.c_ast.If(
            cond = copy.deepcopy(condition),
            iftrue = copy.deepcopy(true_block),
            iffalse = copy.deepcopy(false_block)
        )
    
    def while_block(self, condition: pycparser.c_ast.Node, statement_block: pycparser.c_ast.Compound) -> pycparser.c_ast.While:
        return pycparser.c_ast.While(
            cond = copy.deepcopy(condition),
            stmt = copy.deepcopy(statement_block)
        )

    def function_call(self, name: str, arguments: list[pycparser.c_ast.Node]) -> pycparser.c_ast.Node:
        return pycparser.c_ast.FuncCall(
            pycparser.c_ast.ID(name),
            pycparser.c_ast.ExprList(copy.deepcopy(arguments))
        )
    
    def cast(self, target_type: ctypes.CTypes, expression: pycparser.c_ast.Node) -> pycparser.c_ast.Cast:
        return pycparser.c_ast.Cast(
            to_type = pycparser.c_ast.Typename(
                name=None, 
                quals=[], 
                align=None,
                type=pycparser.c_ast.TypeDecl(
                    declname=None, 
                    quals=[], 
                    align=None,
                    type=pycparser.c_ast.IdentifierType(names=self._integer_definitions[target_type].cname_list)
                )
            ),
            expr = copy.deepcopy(expression)
        )

    def declaration(self, variable_name: str, integer_type: ctypes.CTypes, initializer: pycparser.c_ast.Node | None = None) -> pycparser.c_ast.Decl:
        return pycparser.c_ast.Decl(
            name = variable_name,
            quals = [],
            align = [],
            storage = [],
            funcspec = [],
            type = pycparser.c_ast.TypeDecl(
                declname = variable_name,
                quals = [],
                align = None,
                type = pycparser.c_ast.IdentifierType(
                    names = self._integer_definitions[integer_type].cname_list
                )
            ),
            init = copy.deepcopy(initializer),
            bitsize = None
        )

class FrequentCodeCBuilder(abc.ABC):

    def __init__(self, cbuilder: CBuilder, integer_definitions: ctypes.CTypeTable) -> None:
        self._cbuilder = cbuilder
        self._integer_definitions = integer_definitions

    @abc.abstractmethod
    def define_initialized_variable(self, value: int, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        pass

    @abc.abstractmethod
    def define_initialized_variable_bytes(self, bytes_string: bytes, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        pass
    
    @abc.abstractmethod
    def define_variable_address(self, operand_name: str, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        pass

    @abc.abstractmethod
    def assign_constant(self, variable_name: str, number: int, target_type: ctypes.CTypes) -> pycparser.c_ast.Assignment:
        pass
    
    @abc.abstractmethod
    def add_constant(self, variable_name: str, number: int, target_type: ctypes.CTypes) -> pycparser.c_ast.Assignment:
        pass

class StandardFrequentCodeCBuilder(FrequentCodeCBuilder):

    def define_initialized_variable(self, value: int, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        constant = self._cbuilder.constant(
            target_type,
            value
        )

        return self._cbuilder.declaration(
            variable_name,
            target_type,
            constant
        )
    
    def define_initialized_variable_bytes(self, bytes_string: bytes, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        constant = self._cbuilder.constant(
            target_type,
            '0x' + bytes_string.hex()
        )

        return self._cbuilder.declaration(
            variable_name,
            target_type,
            constant
        )
    
    def define_variable_address(self, operand_name: str, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        operand_variable = self._cbuilder.variable(
            operand_name
        )
        
        address_of_operand = self._cbuilder.unary_operation(
            coperators.UnaryCOperator.ADDRESS,
            operand_variable
        )

        built_cast = self._cbuilder.cast(
            target_type,
            address_of_operand
        )

        return self._cbuilder.declaration(
            variable_name,
            target_type,
            built_cast
        )

    def assign_constant(self, variable_name: str, number: int, target_type: ctypes.CTypes) -> pycparser.c_ast.Assignment:
        constant = self._cbuilder.constant(target_type, number)
        variable = self._cbuilder.variable(variable_name)
        return self._cbuilder.assignment(
            coperators.AssignmentCOperator.ASSIGNMENT,
            variable,
            constant
        )

    def add_constant(self, variable_name: str, number: int, target_type: ctypes.CTypes) -> pycparser.c_ast.Assignment:
        constant = self._cbuilder.constant(target_type, number)
        variable = self._cbuilder.variable(variable_name)
        return self._cbuilder.assignment(
            coperators.AssignmentCOperator.ADDITIVEASSIGNMENT,
            variable,
            constant
        )

class RandomFunctionCallBuilder(abc.ABC):

    def __init__(
        self, 
        cbuilder: CBuilder, 
        frequent_builder: FrequentCodeCBuilder,
        name_generation: namegenerator.NameGenerator,
        integer_definitions: ctypes.CTypeTable,
        function_finder: pycparserfinder.ItemFinder,
        struct_finder: pycparserfinder.ItemFinder,
        enum_finder: pycparserfinder.ItemFinder,
        variable_classifier: variableclassifier.StandardVariableClassifier
        ) -> None:
        self._cbuilder = cbuilder
        self._frequent_cbuiler = frequent_builder
        self._name_generation = name_generation
        self._integer_definitions = integer_definitions
        self._function_finder = function_finder
        self._struct_finder = struct_finder
        self._enum_finder = enum_finder
        self._variable_classifier = variable_classifier

    @abc.abstractmethod
    def create_function(self, function_name: str, declarations_ast: pycparser.c_ast, dependency_graph: nx.DiGraph) -> list[pycparser.c_ast.Node]:
        pass
    
class StandardRandomFunctionCallBuilder(RandomFunctionCallBuilder):

    def _treat_simple(self, used_type: ctypes.CTypeInfo) -> pycparser.c_ast.Node:
        byte_string = prng.get_n_bytes(used_type.size)
        ctype_instance = used_type.enum_instance
        name = self._name_generation.generate_name()
        generated_variable = self._frequent_cbuiler.define_initialized_variable_bytes(byte_string, name, ctype_instance)
        return generated_variable

    def _treat_constant(self, used_type: ctypes.CTypeInfo) -> pycparser.c_ast.Node:
        byte_string = '0x' + prng.get_n_bytes(used_type.size).hex()
        ctype_instance = used_type.enum_instance
        return self._cbuilder.constant(ctype_instance, byte_string)

    def _treat_primitive(self, primitive: ctypes.CTypeInfo, within_user_type: bool) -> pycparser.c_ast.Node:
        if within_user_type:
            return self._treat_constant(primitive)
        else:
            return self._treat_simple(primitive)

    # def _handle_complex(self, declarations_ast: pycparser.c_ast, name: str, complex_c_type: ctypes.CTypes) -> pycparser.c_ast.Node:
    #     if complex_c_type == ctypes.UserDefinedTypes.STRUCT:
    #         original_struct = self._struct_finder.find(declarations_ast, name)
    #     return None

    def _treat_variable(self, declarations_ast: pycparser.c_ast, argument_type: pycparser.c_ast.Node, dependency_graph: nx.DiGraph, within_user_type: bool = False) -> pycparser.c_ast.Node:
        primitive = pycparsertypes.corresponding_primitive(argument_type, self._integer_definitions)
        if not primitive is None:
            return self._treat_primitive(primitive, within_user_type)
        
        is_typedef = pycparsertypes.is_type_identifier(argument_type.type)
        if is_typedef:
            typedef_name = argument_type.type.names[0]
            typedef_identifier = dependencyresolver.identifier_of_name(typedef_name, dependency_graph)
            original_name, node_type = self._variable_classifier.classify_variable(typedef_identifier, dependency_graph)
            if ctypes.is_primitive(node_type):
                return self._treat_primitive(self._integer_definitions[node_type], within_user_type)
            # return self._handle_complex(declarations_ast, original_name, node_type)

        # if pycparsertypes.is_struct(argument_type.type):
        #     return self._handle_complex(declarations_ast, argument_type.type.name, ctypes.UserDefinedTypes.STRUCT)
        # if pycparsertypes.is_enum(argument_type.type):
        #     return self._handle_complex(declarations_ast, argument_type.type.name, ctypes.UserDefinedTypes.ENUM)
        # if pycparsertypes.is_union(argument_type.type):
        #     return self._handle_complex(declarations_ast, argument_type.type.name, ctypes.UserDefinedTypes.UNION)

        raise Exception("Object not made to handle complex types (enums, structs, union)")
    
    def create_function(self, function_name: str, declarations_ast: pycparser.c_ast, dependency_graph: nx.DiGraph) -> list[pycparser.c_ast.Node]:
        function_node = self._function_finder.find(declarations_ast, function_name)
        function_identifier = dependencyresolver.identifier_of_name(function_name, dependency_graph)

        arguments = function_node.type.args.params
        variables = []
        for argument in arguments:
            argument_type = argument.type
            created_variable = self._treat_variable(declarations_ast, argument_type, dependency_graph)
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
