import abc
import pycparser

from src.lib.crypto.rng import prng
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator

class OpaqueVariable(abc.ABC):

    def __init__(self, integer_definitions: ctypes.CTypeTable, used_cbuilder: cbuilder.CBuilder, frequent_cbuilder: cbuilder.FrequentCodeCBuilder, variable_name_generator: namegenerator.VariableNameGenerator) -> None:
        self._integer_definitions = integer_definitions
        self._cbuilder = used_cbuilder
        self._frequent_cbuilder = frequent_cbuilder
        self._variable_name_generator = variable_name_generator

    def generate_opaque_variable(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Node]:
        self._refresh()
        
        initial_variables = self._declare_algorithm_variables(target_variable_type)
        opaque_variable = self._declare_opaque_variable(target_variable_type)
        compute_variable_algorithm = self._create_opaque_algorithm(target_variable_type)

        return initial_variables + compute_variable_algorithm + [opaque_variable]

    @abc.abstractmethod
    def _refresh(self) -> None:
        pass

    @abc.abstractmethod
    def _declare_algorithm_variables(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Decl]:
        pass
    
    @abc.abstractmethod
    def _declare_opaque_variable(self, target_variable_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        pass
    
    @abc.abstractmethod
    def _create_opaque_algorithm(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Node]:
        pass

class TrueOpaqueVariable(OpaqueVariable):
    pass

class ResidueTrueOpaqueVariable(TrueOpaqueVariable):
    
    def _refresh(self) -> None:
        self._sentinel_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.USELESS
        )

        self._address_variable_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.COMPUTATION
        )

        self._result_variable_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.TRUE
        )


    def _declare_algorithm_variables(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Decl]:
        sentinel_variable = self._frequent_cbuilder.define_initialized_variable(
            prng.get_unsigned_integer(self._integer_definitions[target_variable_type].size),
            self._sentinel_name,
            target_variable_type
        )

        random_value_variable = self._frequent_cbuilder.define_variable_address(
            self._sentinel_name,
            self._address_variable_name,
            target_variable_type
        )

        return [
            sentinel_variable,
            random_value_variable
        ]

    def _declare_opaque_variable(self, target_variable_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        x = self._cbuilder.variable(self._result_variable_name)

        square = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.MULTIPLICATION,
            x,
            x
        )

        addition_operation = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.ADDITION,
            square,
            x
        )

        constant2 = self._cbuilder.constant(
            target_variable_type,
            2
        )

        constant0 = self._cbuilder.constant(
            target_variable_type,
            0
        )

        modulo_operation = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.MODULO,
            addition_operation,
            constant2
        )

        final_operation = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.EQUAL,
            modulo_operation,
            constant0
        )

        return self._cbuilder.declaration(
            self._result_variable_name,
            target_variable_type,
            final_operation
        )
    
    def _create_opaque_algorithm(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Node]:
        return []

class PrimeOpaqueVariable(OpaqueVariable):
    pass

class RAPrimeOpaqueVariable(PrimeOpaqueVariable):

    def _refresh(self) -> None:
        self._sentinel_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.USELESS
        )

        self._d_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.COMPUTATION
        )

        self._i_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.COMPUTATION
        )

        self._temp_prime_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.COMPUTATION
        )

        self._prime_name = self._variable_name_generator.generate_name(
            namegenerator.VariableNameTypes.PRIME
        )


    def _declare_algorithm_variables(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Decl]:
        sentinel_variable = self._frequent_cbuilder.define_initialized_variable(
            prng.get_unsigned_integer(self._integer_definitions[target_variable_type].size),
            self._sentinel_name,
            target_variable_type
        )

        d_variable = self._frequent_cbuilder.define_initialized_variable(
            0,
            self._d_name,
            target_variable_type
        )

        i_variable = self._frequent_cbuilder.define_initialized_variable(
            3,
            self._i_name,
            target_variable_type
        )

        temp_prime_variable = self._frequent_cbuilder.define_variable_address(
            self._sentinel_name,
            self._temp_prime_name,
            target_variable_type
        )

        return [
            sentinel_variable,
            d_variable,
            i_variable,
            temp_prime_variable
        ]
    
    def _declare_opaque_variable(self, target_variable_type: ctypes.CTypes) -> pycparser.c_ast.Decl:
        temporary_prime = self._cbuilder.variable(
            self._temp_prime_name
        )

        return self._cbuilder.declaration(
            self._prime_name,
            target_variable_type,
            temporary_prime
        )
    
    def _preamble_algorithm(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Node]:
        half_max = self._cbuilder.constant(
            target_variable_type,
            self._integer_definitions[target_variable_type].max_value // 2
        )
        
        temp_prime_variable = self._cbuilder.variable(
            self._temp_prime_name
        )

        modulo_operation = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.MODULO,
            temp_prime_variable,
            half_max
        )

        constant1 = self._cbuilder.constant(
            target_variable_type,
            1
        )

        always_odd = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.BITWISEOR,
            modulo_operation,
            constant1
        )

        assignment_temp_prime = self._cbuilder.assignment(
            coperators.AssignmentCOperator.ASSIGNMENT,
            temp_prime_variable,
            always_odd
        )

        constant3 = self._cbuilder.constant(
            target_variable_type,
            3
        )

        assign_3 = self._cbuilder.assignment(
            coperators.AssignmentCOperator.ASSIGNMENT,
            temp_prime_variable,
            constant3
        )

        assign_3_block = self._cbuilder.block(
            [assign_3]
        )

        lessthan_3 = self._cbuilder.binary_operation(
            coperators.BinaryCOperator.LESS,
            temp_prime_variable,
            constant3
        )

        if_block = self._cbuilder.if_block(
            lessthan_3,
            assign_3_block
        )

        return [assignment_temp_prime,if_block]

    def _create_opaque_algorithm(self, target_variable_type: ctypes.CTypes) -> list[pycparser.c_ast.Node]:

        return self._preamble_algorithm(target_variable_type)