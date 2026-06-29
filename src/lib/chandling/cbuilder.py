import abc
import pycparser

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.coperators as coperators

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
    def if_block(self, condition: pycparser.c_ast.Node, true_block: pycparser.c_ast.Compound, false_block: pycparser.c_ast.Compound) -> pycparser.c_ast.If:
        pass
    
    @abc.abstractmethod
    def while_block(self, condition: pycparser.c_ast.Node, statement_block: pycparser.c_ast.Compound) -> pycparser.c_ast.While:
        pass
    
    @abc.abstractmethod
    def declaration(self, variable_name: str, integer_type: ctypes.CTypes, initializer: pycparser.c_ast.Node | None = None) -> pycparser.c_ast.Decl:
        pass

class StandardCBuilder(CBuilder):

    def variable(self, variable_name: str) -> pycparser.c_ast.ID:
        return pycparser.c_ast.ID(
            name = variable_name
        )
    
    def constant(self, constant_type: ctypes.CTypes, value: int) -> pycparser.c_ast.Constant:
        return pycparser.c_ast.Constant(
            type = constant_type,
            value = value
        )
    
    def unary_operation(self, operator: coperators.UnaryCOperator, operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        return pycparser.c_ast.UnaryOp(
            op = operator,
            expr = operand
        )
    
    def binary_operation(self, operator: coperators.BinaryCOperator, left_operand: pycparser.c_ast.Node, right_operand: pycparser.c_ast.Node) -> pycparser.c_ast.Node:
        return pycparser.c_ast.BinaryOp(
            op = operator,
            left = left_operand,
            right = right_operand
        )

    def block(self, items_list: list[pycparser.c_ast.Node]) -> pycparser.c_ast.Compound:
        return pycparser.c_ast.Compound(
            block_items = items_list
        )
    
    def assignment(self, operator: coperators.AssignmentCOperator, left_value: pycparser.c_ast.Node, right_value: pycparser.c_ast.Node) -> pycparser.c_ast.Assignment:
        return pycparser.c_ast.Assignment(
            op = operator,
            lvalue = left_value,
            rvalue = right_value
        )
    
    def if_block(self, condition: pycparser.c_ast.Node, true_block: pycparser.c_ast.Compound, false_block: pycparser.c_ast.Compound) -> pycparser.c_ast.If:
        return pycparser.c_ast.If(
            cond = condition,
            iftrue = true_block,
            iffalse = false_block
        )
    
    def while_block(self, condition: pycparser.c_ast.Node, statement_block: pycparser.c_ast.Compound) -> pycparser.c_ast.While:
        return pycparser.c_ast.While(
            cond = condition,
            stmt = statement_block
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
                    names = [integer_type.cname]
                )
            ),
            init = initializer,
            bitsize = None
        )
