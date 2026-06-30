import abc
import pycparser

from src.lib.crypto.rng import prng
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator

'''
A family of predicates that always returns true
'''

class OpaquePredicate(abc.ABC):

    @property
    def needed_variables(self) -> dict[namegenerator.VariableNameTypes, int]:
        return self._needed_variables

    def _check_input_variables(self, predicate_variables: list[str]) -> bool:
        for key, value in self.needed_variables.items():
            number_times = 0
            for i in range(len(predicate_variables)):
                number_times += int(namegenerator.is_type(predicate_variables[i], key))
            if number_times != value:
                return False
        return True
    
    @abc.abstractmethod
    def create_predicate(self, predicate_variables: list[str]) -> c_ast.Node:
        pass

class IsOddOrTwoPredicateTemplate(OpaquePredicate):

    def __init__(self) -> None:
        self._needed_variables = {
            namegenerator.VariableNameTypes.PRIME: 1
        }
    
    def create_predicate(self, predicate_variables: list[str]) -> c_ast.Node:
        if not self._check_input_variables(predicate_variables):
            raise ValueError("Did not give IsOddOrTwoPredicateTemplate the necessary variables")
