import abc
import pycparser

from src.lib.crypto.rng import prng

import networkx as nx
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.obfuscation.utils.scope as scope
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.control.opaqueif as opaqueif
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.control.opaquefunctioncall as opaquefunctioncall

class FunctionCallVisitor(pycparser.c_ast.NodeVisitor):

    def __init__(
        self,
        predicate_generator: opaquepredicate.TrueOpaquePredicate,
        function_call_generator: opaquefunctioncall.NoCallOpaqueFunctionCall,
        target_variable_type: ctypes.CTypes,
        upper_block_scope: scope.Scope,
        max_depth: int = 16, 
        aggressiveness: float = 0.3
    ) -> None:
        if aggressiveness < 0 or aggressiveness > 1:
            raise ValueError("OpaqueIfVisitor: aggressiveness needs to be in the range [0,1]")
        if max_depth < 0:
            raise ValueError("OpaqueIfVisitor: max_depth needs to be positive")
            
        self._predicate_generator = predicate_generator
        self._function_call_generator = function_call_generator
        self._variable_type = target_variable_type
        self._upper_block_scope = upper_block_scope
        self._max_depth = max_depth
        self._aggressiveness = aggressiveness

    def visit_Compound(self, node):
        self._upper_block_scope.enter_block()
        
        if node.block_items is None:
            node.block_items = []
        
        if self._upper_block_scope.depth == self._max_depth:
            self._upper_block_scope.exit_block()
            return

        selected_variables = self._predicate_generator.chosen_variables(self._upper_block_scope)
        if not selected_variables is None:
            if prng.chance(self._aggressiveness):
                predicate = self._predicate_generator.create_predicate(selected_variables, self._variable_type)
                self._function_call_generator.use_opaque_call(predicate, node)

        for i in range(len(node.block_items)):
            if scope.is_initalized_variable(node.block_items[i]):
                self._upper_block_scope.add_variable(node.block_items[i].name)

            self.visit(node.block_items[i])
        
        self._upper_block_scope.exit_block()
