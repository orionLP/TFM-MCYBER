import abc
import pycparser

from src.lib.crypto.rng import prng

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.utils.scope as scope
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate

class OpaqueIf(abc.ABC):

    def __init__(self, used_cbuilder: cbuilder.StandardCBuilder) -> None:
        self._cbuilder = used_cbuilder

    @abc.abstractmethod
    def use_opaque_if(self, upper_blocks_variables: scope.Scope, used_predicate: pycparser.c_ast.Node, current_block: pycparser.c_ast.Compound) -> None:
        pass

class JunkOpaqueIf(OpaqueIf):

    def __init__(self, used_cbuilder: cbuilder.StandardCBuilder) -> None:
        super().__init__(used_cbuilder)
        self._expected_junk_length = 4

    def _generate_random_operation(self, available_variables: list[str]) -> pycparser.c_ast.Node:
        # unary_chosen = bool(prng.get_range_unsigned_integer(2))
        # final_operation = None
        # if unary_chosen:
        #     chosen_operator = prng.random_choice(list(coperators.UnaryCOperator))
        #     variable1 = self._cbuilder.variable(prng.random_choice(available_variables))
        #     final_operation = self._cbuilder.unary_operation(chosen_operator, variable1)
        # else:
        variables_following_format = [var for var in available_variables if namegenerator.follows_format(var)]
        chosen_operator = prng.random_choice(list(coperators.BinaryCOperator))
        variable1 = self._cbuilder.variable(prng.random_choice(variables_following_format))
        variable2 = self._cbuilder.variable(prng.random_choice(variables_following_format))
        final_operation = self._cbuilder.binary_operation(chosen_operator, variable1, variable2)
        assign_variable = self._cbuilder.variable(prng.random_choice(variables_following_format))
        
        return self._cbuilder.assignment(
            coperators.AssignmentCOperator.ASSIGNMENT,
            assign_variable,
            final_operation
        )

    def _generate_junk_block(self, available_variables: list[str]) -> pycparser.c_ast.Compound:
        number_iterations = max(prng.get_range_unsigned_integer(self._expected_junk_length * 2), 1)
        new_block_items = []
        for i in range(number_iterations):
            new_block_items.append(self._generate_random_operation(available_variables))
        return self._cbuilder.block(new_block_items)

    def use_opaque_if(self, upper_blocks_variables: scope.Scope, used_predicate: pycparser.c_ast.Node, current_block: pycparser.c_ast.Compound) -> None:
        min_index = 0
        if upper_blocks_variables.variables_in_scope == 0:
            first_variable_line = scope.first_line_with_variable(current_block)
            if first_variable_line is None:
                raise ValueError("Given JunkOpaqueIf a block with no variables in scope")
            min_index = first_variable_line + 1
        
        max_index = len(current_block.block_items)
        chosen_index = prng.get_range_unsigned_integer(max_index + 1, min_index)
        available_variables = upper_blocks_variables.scope_list + scope.defined_variables_to_line(current_block, chosen_index)

        negated_predicate = self._cbuilder.unary_operation(coperators.UnaryCOperator.NOT, used_predicate)
        bogus_if = self._cbuilder.if_block(negated_predicate, self._generate_junk_block(available_variables))
        current_block.block_items.insert(chosen_index, bogus_if)

class BogusFlowOpaqueIf(OpaqueIf):

    def use_opaque_if(self, upper_blocks_variables: scope.Scope, used_predicate: pycparser.c_ast.Node, current_block: pycparser.c_ast.Compound) -> None:
        '''Get everything between [chosen_start, chosen_end]'''
        if current_block.block_items is None or len(current_block.block_items) == 0:
            raise ValueError("Given BogusFlowOpaqueIf a block with nothing in it")
        
        chosen_start = prng.get_range_unsigned_integer(len(current_block.block_items))
        chosen_end = len(current_block.block_items) - 1

        selected_nodes = current_block.block_items[chosen_start: (chosen_end + 1)]
        new_block = self._cbuilder.block(selected_nodes)
        new_if = self._cbuilder.if_block(used_predicate, new_block)

        del current_block.block_items[chosen_start: (chosen_end + 1)]

        current_block.block_items.insert(chosen_start, new_if)