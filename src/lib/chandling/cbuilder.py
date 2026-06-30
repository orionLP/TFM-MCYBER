import abc
import pycparser
import copy

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
    def if_block(self, condition: pycparser.c_ast.Node, true_block: pycparser.c_ast.Compound, false_block: pycparser.c_ast.Compound | None = None) -> pycparser.c_ast.If:
        pass
    
    @abc.abstractmethod
    def while_block(self, condition: pycparser.c_ast.Node, statement_block: pycparser.c_ast.Compound) -> pycparser.c_ast.While:
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
    
    def constant(self, constant_type: ctypes.CTypes, value: int) -> pycparser.c_ast.Constant:
        return pycparser.c_ast.Constant(
            type = self._integer_definitions[constant_type].cname_list,
            value = str(value)
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
    def define_variable_address(self, operand_name: str, variable_name: str, target_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
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
