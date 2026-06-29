import abc
import pycparser

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.coperators as coperators

class CBuilder(abc.ABC):

    def __init__(self, integer_definitions: ctype.CTypeTable) -> None:
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
    def assignment(self, operator: coperators.AssignmentCOperator, left_value: pycparser.c_ast.Node, right_value: pycparser.c_ast.Node) -> pycparser.c_ast.Assignment:
        pass
    
    @abc.abstractmethod
    def if_block(self, condition: pycparser.c_ast.Node, true_block: pycparser.c_ast.Compound, false_block: pycparser.c_ast.Compound) -> pycparser.c_ast.If:
        pass
    
    @abc.abstractmethod
    def while_block(self, condition: pycparser.c_ast.Node, statement_block: pycparser.c_ast.Compound) -> pycparser.c_ast.While:
        pass
    
    @abc.abstractmethod
    def declaration(self, name: str, integer_type: ctype.CTypes, initializer: pycparser.c_ast.Node | None) -> pycparser.c_ast.Decl:
        pass

class StandardCBuilder(CBuilder):

    def binary_operation(self, operator: coperators.BinaryCOperator, left_operand: pycparser.c_ast.Node, right_operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        return c_ast.BinaryOp(
                    operator,
                    left_operand,
                    right_operand
                )