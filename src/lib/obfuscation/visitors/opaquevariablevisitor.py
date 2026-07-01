import abc
import pycparser

from src.lib.crypto.rng import prng

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.utils.scope as scope
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.control.opaquevariable as opaquevariable

class InjectOpaqueVariableVisitor(pycparser.c_ast.NodeVisitor):

    def __init__(
        self,
        used_cbuilder: cbuilder.CBuilder,
        used_opaque_variables: opaquevariable.OpaqueVariable,
        target_variable_type: ctypes.CTypes,
        upper_block_scope: scope.Scope,
        max_depth: int = 16, 
        aggressiveness: float = 0.3
    ) -> None:

        self._cbuider = used_cbuilder
        self._opaque_variable = used_opaque_variables
        self._upper_block_scope = upper_block_scope
        self._target_type = target_variable_type
        self._max_depth = max_depth
        self._aggressiveness = aggressiveness

    def visit_Compound(self, node):
        self._upper_block_scope.enter_block()
        
        if node.block_items is None:
            node.block_items = []

        if self._upper_block_scope.depth == self._max_depth:
            return
        
        if self._upper_block_scope.depth == 1:
            new_block = self._cbuider.block(node.block_items)
            node.block_items = [new_block]

        if prng.chance(self._aggressiveness):
            position_to_place = prng.get_range_unsigned_integer(len(node.block_items) + 1)
            nodes_to_insert = self._opaque_variable.generate_opaque_variable(self._target_type)
            for i in range(len(nodes_to_insert) - 1, -1, -1):
                node.block_items.insert(position_to_place, nodes_to_insert[i])
        
        self.generic_visit(node)

        self._upper_block_scope.enter_block()