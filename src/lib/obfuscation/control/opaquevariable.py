import abc
import pycparser

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.crypto.rng.prng as prng
import src.lib.obfuscation.utils.namegenerator as namegenerator

class OpaqueVariable(abc.ABC):

    def __init__(self, used_cbuilder: cbuilder.CBuilder, frequent_cbuilder: cbuilder.FrequentCodeCBuilder, variable_name_generator: namegenerator.VariableNameGenerator) -> None:
        self._cbuilder = used_cbuilder
        self._frequent_cbuilder = frequent_cbuilder
        self._variable_name_generator = variable_name_generator

    def generate_opaque_variable(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Node]:
        start_variables = self._declare_algorithm_variables(target_variable_type)
        opaque_variable = self._declare_opaque_variable(target_variable_type)
        compute_variable_algorithm = self._create_opaque_algorithm(target_variable_type, initial_variables, opaque_variable)

        return start_variables + compute_variable_algorithm + [opaque_variable]

    @abc.abstractmethod
    def _declare_algorithm_variables(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Decl]:
        pass
    
    @abc.abstractmethod
    def _declare_opaque_variable(self, target_variable_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        pass
    
    @abc.abstractmethod
    def _create_opaque_algorithm(self, target_variable_type: ctypes.CTypes, initial_variables: list[pycparser.c_ast.Decl], opaque_variable: pycparser.c_ast.Decl) -> list[pycparser.c_ast.Node]:
        pass

class TrueOpaqueVariable(OpaqueVariable):
    pass

class ResidueTrueOpaqueTemplate(TrueOpaqueTemplate):
    
    def _declare_algorithm_variables(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Decl]:
        dummy_variable = self._frequent_cbuilder.define_variable_with_value(
            prng.get_unsigned_integer(target_variable_type.size),
            self._variable_name_generator.generate_name(
                namegenerator.VariableNameTypes.USELESS
            ),
            target_variable_type
        )
        random_value_variable_name = self._variable_name_generator.generate_name(namegenerator.VariableNameTypes.COMPUTATION)
        
        cast1 = self._cbuilder.cast(
            target_variable_type,
            self._cbuilder.unary_operation(
                coperators.UnaryCOperator.ADDRESS,

            )
        )
        
        declaration_random_value_variable = self._cbuilder.declaration(
            random_value_variable_name,
            target_variable_type,

        )
    
    def _declare_opaque_variable(self, target_variable_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        pass
    
    def _create_opaque_algorithm(self, target_variable_type: ctypes.CTypes, initial_variables: list[pycparser.c_ast.Decl], opaque_variable: pycparser.c_ast.Decl) -> list[pycparser.c_ast.Node]:
        pass