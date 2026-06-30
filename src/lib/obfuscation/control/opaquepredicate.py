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

    @abc.abstractmethod
    def create_predicate(self, predicate_variables: list[str]) -> c_ast.Node:
        pass

class IsOddOrTwoPredicateTemplate(OpaquePredicate):

