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

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        self._cbuilder = used_cbuilder

    @property
    def needed_variables(self) -> dict[namegenerator.VariableNameTypes, int]:
        return self._needed_variables

    def _list_to_dict(self, predicate_variables: list[str]) -> dict[namegenerator.VariableNameTypes, list[str]]:
        result_dict = {}
        for possible_type in namegenerator.VariableNameTypes:
            result_dict[possible_type] = []
            for variable in predicate_variables:
                if namegenerator.is_type(variable, possible_type):
                    result_dict[possible_type].append(variable)
            if len(result_dict[possible_type]) == 0:
                del result_dict[possible_type]
        return result_dict

    def _check_input_variables(self, constructed_dict: dict[namegenerator.VariableNameTypes, list[str]]) -> bool:
        for key in constructed_dict:
            if not key in self.needed_variables:
                return False
        for key, value in self.needed_variables.items():
            if len(constructed_dict[key]) != value:
                return False
        return True
    
    @abc.abstractmethod
    def create_predicate(self, predicate_variables: list[str], used_type: ctypes.CTypes) -> pycparser.c_ast.Node:
        pass

class IsOddOrTwoPredicateTemplate(OpaquePredicate):

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        super().__init__(used_cbuilder)
        self._needed_variables = {
            namegenerator.VariableNameTypes.PRIME: 1
        }
    
    def create_predicate(self, predicate_variables: list[str], used_type: ctypes.CTypes) -> pycparser.c_ast.Node:
        available_variables = self._list_to_dict(predicate_variables)
        if not self._check_input_variables(available_variables):
            raise ValueError("Did not give IsOddOrTwoPredicateTemplate the necessary variables")

        constant0 = self._cbuilder.constant(used_type, 0)
        constant2 = self._cbuilder.constant(used_type, 2)

        prime_variable = self._cbuilder.variable(available_variables[namegenerator.VariableNameTypes.PRIME][0])
        modulo_operation = self._cbuilder.binary_operation(coperators.BinaryCOperator.MODULO, prime_variable, constant2)
        different_operation = self._cbuilder.binary_operation(coperators.BinaryCOperator.NOTEQUAL, modulo_operation, constant0)

        equal_2 = self._cbuilder.binary_operation(coperators.BinaryCOperator.EQUAL, prime_variable, constant2)

        return self._cbuilder.binary_operation(
            coperators.BinaryCOperator.OR,
            different_operation, 
            equal_2
        )

