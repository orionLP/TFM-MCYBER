import abc
import pycparser

import src.lib.chandling.ctypes as ctypes

class CBuilder(abc.ABC):

    @abc.abstractmethod
    def __init__(self, integer_definitions) -> None:
        pass
    
    @abc.abstractmethod
    def unary_operation(self, operator, operand):
        pass
    
    @abc.abstractmethod
    def binary_operation(self, operator, left_operand, right_operand):
        pass

    @abc.abstractmethod
    def assignment(self, operator, left_value, right_value):
        pass
    
    @abc.abstractmethod
    def if_block(self, condition, true_block, false_block):
        pass
    
    @abc.abstractmethod
    def while_block(self, condition, statement_block):
        pass
    
    @abc.abstractmethod
    def declaration(self, name, integer_type, initializer):
        pass