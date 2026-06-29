import abc
import pycparser

import src.lib.chandling.ctypes as ctypes

class OpaqueVariable(abc.ABC):

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
