import abc
import pycparser
import copy

from src.lib.crypto.rng import prng

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.utils.scope as scope

'''
A family of predicates that always returns true
'''

class OpaquePredicate(abc.ABC):

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        self._cbuilder = used_cbuilder

    @property
    def needed_variables(self) -> dict[namegenerator.VariableNameTypes, int]:
        return self._needed_variables

    def chosen_variables(self, used_scope: scope.Scope) -> list[str] | None:
        available_variables = used_scope.scope_dict

        return_list = []

        for vartype in self.needed_variables:
            if not vartype in available_variables:
                return None
            
            if not len(available_variables[vartype]) >= self.needed_variables[vartype]:
                return None
            else:
                return_list = return_list + prng.random_selection(available_variables[vartype], self.needed_variables[vartype])
        
        return return_list

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

class TrueOpaquePredicate(OpaquePredicate):
    pass

class IsOddOrTwoOpaquePredicate(TrueOpaquePredicate):

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        super().__init__(used_cbuilder)
        self._needed_variables = {
            namegenerator.VariableNameTypes.PRIME: 1
        }
    
    def create_predicate(self, predicate_variables: list[str], used_type: ctypes.CTypes) -> pycparser.c_ast.Node:
        available_variables = self._list_to_dict(predicate_variables)
        if not self._check_input_variables(available_variables):
            raise ValueError("Did not give IsOddOrTwoOpaquePredicate the necessary variables")

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

class BogusBooleanExpressionOpaquePredicate(TrueOpaquePredicate):

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        super().__init__(used_cbuilder)
        self._needed_variables = {
            namegenerator.VariableNameTypes.TRUE: 1  
        }
        self._max_depth = 3
    
    def _recursive_bogus_boolean(self, variables_chosen: list[str], level: int) -> pycparser.c_ast.Node:
        if level == 0:
            return self._cbuilder.variable(prng.random_choice(variables_chosen))
        
        left_operator = self._recursive_bogus_boolean(variables_chosen, level - 1)
        right_operator = self._recursive_bogus_boolean(variables_chosen, level - 1)

        chosen_route = prng.get_range_unsigned_integer(3)
        if chosen_route == 0:
            negation = self._cbuilder.unary_operation(coperators.UnaryCOperator.NOT, left_operator) 
            return self._cbuilder.binary_operation(coperators.BinaryCOperator.OR, negation, right_operator)
        if chosen_route == 1:
            negation = self._cbuilder.unary_operation(coperators.UnaryCOperator.NOT, right_operator) 
            return self._cbuilder.binary_operation(coperators.BinaryCOperator.OR, left_operator, negation)
        if chosen_route == 2:
            return self._cbuilder.binary_operation(coperators.BinaryCOperator.AND, left_operator, right_operator) 

    def create_predicate(self, predicate_variables: list[str], used_type: ctypes.CTypes) -> pycparser.c_ast.Node:
        available_variables = self._list_to_dict(predicate_variables)
        if not self._check_input_variables(available_variables):
            raise ValueError("Did not give BogusBooleanExpressionOpaquePredicate the necessary variables to be used")
        
        available_true_variables = available_variables[namegenerator.VariableNameTypes.TRUE]
        number_variables_chosen = prng.get_range_unsigned_integer(len(available_true_variables) + 1, 1)
        variables_chosen = prng.random_selection(available_true_variables, number_variables_chosen)
        chosen_depth = prng.get_range_unsigned_integer(self._max_depth)
        return self._recursive_bogus_boolean(variables_chosen, chosen_depth)

        
class PythagoreanTripleOpaquePredicate(TrueOpaquePredicate):

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        super().__init__(used_cbuilder)
        self._needed_variables = {
            namegenerator.VariableNameTypes.RANDOM: 1
        }

    def create_predicate(self, predicate_variables: list[str], used_type: ctypes.CTypes) -> pycparser.c_ast.Node:
        available_variables = self._list_to_dict(predicate_variables)
        if not self._check_input_variables(available_variables):
            raise ValueError("Did not give PythagoreanTripleOpaquePredicate the necessary variables")

        constant9 = self._cbuilder.constant(used_type, 9)
        constant16 = self._cbuilder.constant(used_type, 16)
        constant25 = self._cbuilder.constant(used_type, 25)

        random_variable = self._cbuilder.variable(available_variables[namegenerator.VariableNameTypes.RANDOM][0])
        square_random = self._cbuilder.binary_operation(coperators.BinaryCOperator.MULTIPLICATION, random_variable, random_variable)

        mult_9 = self._cbuilder.binary_operation(coperators.BinaryCOperator.MULTIPLICATION, square_random, constant9)
        mult_16 = self._cbuilder.binary_operation(coperators.BinaryCOperator.MULTIPLICATION, square_random, constant16)
        mult_25 = self._cbuilder.binary_operation(coperators.BinaryCOperator.MULTIPLICATION, square_random, constant25)

        addition_9_16 = self._cbuilder.binary_operation(coperators.BinaryCOperator.ADDITION, mult_9, mult_16)

        return self._cbuilder.binary_operation(coperators.BinaryCOperator.EQUAL, addition_9_16, mult_25)

class DummyOpaquePredicate(TrueOpaquePredicate):

    def __init__(self, used_cbuilder: cbuilder.CBuilder) -> None:
        super().__init__(used_cbuilder)
        self._needed_variables = {
            namegenerator.VariableNameTypes.TRUE: 1
        }

    def create_predicate(self, predicate_variables: list[str], used_type: ctypes.CTypes) -> pycparser.c_ast.Node:
        available_variables = self._list_to_dict(predicate_variables)
        if not self._check_input_variables(available_variables):
            raise ValueError("Did not give TrueOpaquePredicate the necessary variables")

        return self._cbuilder.variable(available_variables[namegenerator.VariableNameTypes.TRUE][0])
