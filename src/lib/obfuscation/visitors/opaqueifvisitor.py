import abc
import pycparser

from src.lib.crypto.rng import prng

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.utils.scope as scope
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate

class TrueOpaqueIfVisitor(pycparser.c_ast.NodeVisitor):

    def __init__(
        self,
        predicate_generator: opaquepredicate.TrueOpaquePredicate,
        upper_block_scope: scope.Scope,
        max_depth: int = 16, 
        aggressiveness: float = 0.3
    ) -> None:
        if aggressiveness < 0 or aggressiveness > 1:
            raise ValueError("OpaqueIfVisitor: aggressiveness needs to be in the range [0,1]")
        if max_depth < 0:
            raise ValueError("OpaqueIfVisitor: max_depth needs to be positive")
            
        self._max_depth = max_depth
        self._aggressiveness = aggressiveness
        self._predicate_generator = predicate_generator
        self._upper_block_scope = upper_block_scope

    def visit_Compound(self, node):
        self._upper_block_scope.enter_block()

        if node.block_items is None:
            node.block_items = []

        selected_variables = self._predicate_generator.chosen_variables(self._upper_block_scope)
        if not selected_variables is None:
            pass    
        print(f'hello {selected_variables}')

        for i in range(len(node.block_items)):
            self.visit(node.block_items[i])
        
        self._upper_block_scope.exit_block()
