import pycparser
from pycparser import c_ast, c_generator
import abc
import secrets
from enum import StrEnum

from enum import Enum
import copy
from dataclasses import dataclass
import sys
import re
from tqdm import tqdm

@dataclass
class CTypeInfo:
    cname:   str
    min_val: int
    max_val: int

class CType(Enum):
    # INT           = CTypeInfo('int', -(2**31), 2**31 - 1)
    UNSIGNED_INT  = CTypeInfo('unsigned int', 0, 2**32 - 1)
    # CHAR          = CTypeInfo('char', -128, 127)
    UNSIGNED_CHAR = CTypeInfo('unsigned char', 0, 255)

    @property
    def cname(self):   
        return self.value.cname
    
    @property
    def min_val(self): 
        return self.value.min_val
    
    @property
    def max_val(self): 
        return self.value.max_val

# About names:
#
#   vXXX_true_opaque : the variable represents a true value, any value different than 0
#   vXXX_false_opaque : the variable represents a false value any value 
#   vXXX_prime_opaque : the variable represents a prime value
#   vXXX_random_opaque : the variable value is random
#   vXXX_unusable_opaque : variable that is not meant to be used later
#

class OpaqueNames(StrEnum):
    TRUE = 'true'
    # FALSE = 'false'
    PRIME = 'prime'
    RANDOM = 'random'
    USELESS = 'useless'
    COMPUTATION = 'computation'

DEFAULT_BYTE_ENTROPY = 16
AGGRESSIVENESS = 0.3
EXPECTED_LENGTH_JUNK = 32
DO_ANYTHING_PROBABILITY = 0.3
OPAQUE_NAME_PATTERN = re.compile(r'^v[0-9a-f]+_(' + '|'.join(OpaqueNames) + r')_opaque$')

def create_opaque_name(nametype: str) -> str:
    return "v" + secrets.token_hex(DEFAULT_BYTE_ENTROPY) + "_" + nametype + "_opaque" 

def random_integer(low: int, high: int) -> int:
    span = high - low + 1
    return low + secrets.randbelow(span)

def create_variable_definition(variable_name: str, integer_type: CType, init: c_ast.Node) -> c_ast.Decl:
    return c_ast.Decl(name=variable_name, quals=[], align=[], storage=[], funcspec=[],
            type=c_ast.TypeDecl(
                declname=variable_name,
                quals=[],
                align=None,
                type=c_ast.IdentifierType(names=[integer_type.cname])
            ), init=init, bitsize=None
        )

class OpaqueTemplate(abc.ABC):

    def opaque_variable_algorithm(self, integer_type: CType) -> list[c_ast.Node]:
        self.refresh()
        start_variables = self.define_algorithm_variables(integer_type)
        opaque_variable = self.define_opaque_variable(integer_type)
        compute_algorithm = self.compute_opaque(integer_type, start_variables, opaque_variable)
        return start_variables + compute_algorithm + [opaque_variable]

    @abc.abstractmethod
    def refresh(self) -> None:
        pass 

    @abc.abstractmethod
    def define_algorithm_variables(self, integer_type: CType) -> list[c_ast.Decl]:
        pass

    @abc.abstractmethod
    def define_opaque_variable(self, integer_type: CType) -> c_ast.Decl:
        pass
    
    @abc.abstractmethod
    def compute_opaque(self, integer_type: CType, initial_variables: list[c_ast.Decl], opaque_variable: c_ast.Decl) -> list[c_ast.Node]:
        pass
    

class TrueOpaqueTemplate(OpaqueTemplate):
    pass

class ResidueTrueOpaqueTemplate(TrueOpaqueTemplate):

    def refresh(self) -> None:
        self._sentinel_name = create_opaque_name(OpaqueNames.USELESS)
        self._pointer_value_name = create_opaque_name(OpaqueNames.COMPUTATION)
        self._true_name = create_opaque_name(OpaqueNames.TRUE)

    def define_algorithm_variables(self, integer_type: CType) -> list[c_ast.Decl]:
        return [
            create_variable_definition(
                self._sentinel_name,
                integer_type,
                c_ast.Constant(type=integer_type.cname.split(), value=str(random_integer(integer_type.min_val, integer_type.max_val)))
            ),
            create_variable_definition(
                self._pointer_value_name,
                integer_type,
                c_ast.Cast(
                    to_type=c_ast.Typename(
                        name=None, quals=[], align=None,
                        type=c_ast.TypeDecl(
                            declname=None, quals=[], align=None,
                            type=c_ast.IdentifierType(names=integer_type.cname.split())
                        )
                    ),
                    expr=c_ast.UnaryOp(op='&', expr=c_ast.ID(name=self._sentinel_name))
                )
            )
        ]
    
    def define_opaque_variable(self, integer_type: CType) -> c_ast.Decl:
        # (x * x + x) % 2 == 0    x(x+1) always even 
        return create_variable_definition(
            self._true_name,
            integer_type,
            c_ast.BinaryOp('==',
                c_ast.BinaryOp('%',
                    c_ast.BinaryOp('+',
                        c_ast.BinaryOp('*',
                            c_ast.ID(name=self._pointer_value_name),
                            c_ast.ID(name=self._pointer_value_name)
                        ),
                        c_ast.ID(name=self._pointer_value_name)
                    ),
                    c_ast.Constant(type=integer_type.cname.split(), value='2')
                ),
                c_ast.Constant(type=integer_type.cname.split(), value='0')
            )
        )

    def compute_opaque(self, integer_type: CType, initial_variables: list[c_ast.Decl], opaque_variable: c_ast.Decl) -> list[c_ast.Node]:
        return []


class PrimeOpaqueTemplate(OpaqueTemplate):
    pass

class RandomAddressPrimeOpaqueTemplate(PrimeOpaqueTemplate):

    def refresh(self) -> None:
        self._sentinel_name = create_opaque_name(OpaqueNames.USELESS)
        self._d_name = create_opaque_name(OpaqueNames.COMPUTATION)
        self._i_name = create_opaque_name(OpaqueNames.COMPUTATION)
        self._temporary_prime_name = create_opaque_name(OpaqueNames.COMPUTATION)
        self._prime_name = create_opaque_name(OpaqueNames.PRIME)

    def define_algorithm_variables(self, integer_type: CType) -> list[c_ast.Decl]:
        return [
            create_variable_definition(
                self._sentinel_name,
                integer_type,
                c_ast.Constant(type=integer_type.cname.split(), value=str(random_integer(integer_type.min_val, integer_type.max_val)))
            ), 
            create_variable_definition(
                self._d_name,
                integer_type,
                c_ast.Constant(type=integer_type.cname.split(), value=str(0))
            ), 
            create_variable_definition(
                self._i_name,
                integer_type, 
                c_ast.Constant(type=integer_type.cname.split(), value=str(3))
            ), 
            create_variable_definition(
                self._temporary_prime_name,
                integer_type, 
                c_ast.BinaryOp('|',
                    c_ast.BinaryOp('%',
                        c_ast.Cast(
                            to_type=c_ast.Typename(
                                name=None, quals=[], align=None,
                                type=c_ast.TypeDecl(
                                    declname=None, quals=[], align=None,
                                    type=c_ast.IdentifierType(names=integer_type.cname.split())
                                )
                            ),
                            expr=c_ast.UnaryOp(op='&', expr=c_ast.ID(name=self._sentinel_name))
                        ),
                        c_ast.Constant(type=integer_type.cname.split(), value='2147418112')  # 0x7FFF0000
                    ),
                    c_ast.Constant(type=integer_type.cname.split(), value='1')
                )
            )
        ]

    def define_opaque_variable(self, integer_type: CType) -> c_ast.Decl:
        return create_variable_definition(
            self._prime_name,
            integer_type,
            c_ast.ID(name=self._temporary_prime_name)
        )

    def compute_opaque(self, integer_type, initial_variables, opaque_variable) -> list[c_ast.Node]:


        # inner while (i * i <= prime) { if (prime % i == 0) d = 0; i = i + 2; }
        inner = c_ast.While(
            cond=c_ast.BinaryOp('<=',
                c_ast.BinaryOp('*', c_ast.ID(name=self._i_name), c_ast.ID(name=self._i_name)),
                c_ast.ID(name=self._temporary_prime_name)
            ),
            stmt=c_ast.Compound(block_items=[
                c_ast.If(
                    cond=c_ast.BinaryOp('==',
                        c_ast.BinaryOp('%', c_ast.ID(name=self._temporary_prime_name), c_ast.ID(name=self._i_name)),
                        c_ast.Constant(type=integer_type.cname.split(), value='0')
                    ),
                    iftrue=c_ast.Compound(block_items=[
                        c_ast.Assignment(op='=',
                            lvalue=c_ast.ID(name=self._d_name),
                            rvalue=c_ast.Constant(type=integer_type.cname.split(), value='0')
                        )
                    ]),
                    iffalse=None
                ),
                c_ast.Assignment(op='=',
                    lvalue=c_ast.ID(name=self._i_name),
                    rvalue=c_ast.BinaryOp('+',
                        c_ast.ID(name=self._i_name),
                        c_ast.Constant(type=integer_type.cname.split(), value='2')
                    )
                )
            ])
        )

        # outer while (d != 1) { prime = prime + 2; d = 1; i = 3; <inner> }
        outer = c_ast.While(
            cond=c_ast.BinaryOp('!=',
                c_ast.ID(name=self._d_name),
                c_ast.Constant(type=integer_type.cname.split(), value='1')
            ),
            stmt=c_ast.Compound(block_items=[
                c_ast.Assignment(op='=',
                    lvalue=c_ast.ID(name=self._temporary_prime_name),
                    rvalue=c_ast.BinaryOp('+',
                        c_ast.ID(name=self._temporary_prime_name),
                        c_ast.Constant(type=integer_type.cname.split(), value='2')
                    )
                ),
                c_ast.Assignment(op='=',
                    lvalue=c_ast.ID(name=self._d_name),
                    rvalue=c_ast.Constant(type=integer_type.cname.split(), value='1')
                ),
                c_ast.Assignment(op='=',
                    lvalue=c_ast.ID(name=self._i_name),
                    rvalue=c_ast.Constant(type=integer_type.cname.split(), value='3')
                ),
                inner
            ])
        )

        guard = c_ast.If(
            cond=c_ast.BinaryOp('<',
                c_ast.ID(name=self._temporary_prime_name),
                c_ast.Constant(type=integer_type.cname.split(), value='3')
            ),
            iftrue=c_ast.Compound(block_items=[
                c_ast.Assignment(op='=',
                    lvalue=c_ast.ID(name=self._temporary_prime_name),
                    rvalue=c_ast.Constant(type=integer_type.cname.split(), value='3')
                )
            ]),
            iffalse=None
        )

        return [guard, outer]

class RandomOpaqueTemplate(OpaqueTemplate):
    pass

class AddressRandomOpaqueTemplate(RandomOpaqueTemplate):
    
    def refresh(self) -> None:
        self._sentinel_name = create_opaque_name(OpaqueNames.USELESS)
        self._pointer_name = create_opaque_name(OpaqueNames.RANDOM)
    
    def define_algorithm_variables(self, integer_type: CType) -> list[c_ast.Decl]:
        return [
            create_variable_definition(
                self._sentinel_name,
                integer_type,
                c_ast.Constant(type=integer_type.cname.split(), value=str(random_integer(integer_type.min_val, integer_type.max_val)))
            )
        ]
    
    def define_opaque_variable(self, integer_type: CType) -> c_ast.Decl:
        return create_variable_definition(
            self._pointer_name,
            integer_type,
            c_ast.Cast(
                to_type=c_ast.Typename(
                    name=None, quals=[], align=None,
                    type=c_ast.TypeDecl(
                        declname=None, quals=[], align=None,
                        type=c_ast.IdentifierType(names=integer_type.cname.split())
                    )
                ),
                expr=c_ast.UnaryOp(op='&', expr=c_ast.ID(name=self._sentinel_name))
            )
        )

    def compute_opaque(self, integer_type, initial_variables, opaque_variable) -> list[c_ast.Node]:
        return []

class PredicateTemplate(abc.ABC):

    def __init__(self) -> None:
        self.needed_type = OpaqueNames.TRUE
        self.num_variables_needed = 1
        
    @abc.abstractmethod
    def create_predicate(self, predicate_variables: list[c_ast.Decl]) -> c_ast.Node:
        pass

class IsOddOrTwoPredicateTemplate(PredicateTemplate):
    # Always returns true
    def __init__(self) -> None:
        self.needed_type = OpaqueNames.PRIME
        self.num_variables_needed = 1
    
    def create_predicate(self, predicate_variables: list[c_ast.Decl]) -> c_ast.Node:
        prime_name = predicate_variables[0].name
        prime_type = predicate_variables[0].type.type.names
        return c_ast.BinaryOp(
            '||',
            c_ast.BinaryOp(
                '!=',
                c_ast.BinaryOp(
                    '%',
                    c_ast.ID(name=prime_name),
                    c_ast.Constant(type=prime_type, value='2')
                ),
                c_ast.Constant(type=prime_type, value='0')
            ),
            c_ast.BinaryOp(
                '==',
                c_ast.ID(name=prime_name),
                c_ast.Constant(type=prime_type, value='2')
            )
        )

class PythagoreanTriplePredicateTemplate(PredicateTemplate):
    # Always returns true
    def __init__(self) -> None:
        self.needed_type = OpaqueNames.RANDOM
        self.num_variables_needed = 1

    def create_predicate(self, predicate_variables: list[c_ast.Decl]) -> c_ast.Node:
        name = predicate_variables[0].name
        ptype = predicate_variables[0].type.type.names
        # 9*x*x + 16*x*x == 25*x*x — always true (overflow safe, both sides identical mod 2^32)
        xx = c_ast.BinaryOp('*', c_ast.ID(name=name), c_ast.ID(name=name))
        return c_ast.BinaryOp('==',
            c_ast.BinaryOp('+',
                c_ast.BinaryOp('*', c_ast.Constant(type=ptype, value='9'), xx),
                c_ast.BinaryOp('*', c_ast.Constant(type=ptype, value='16'), xx)
            ),
            c_ast.BinaryOp('*', c_ast.Constant(type=ptype, value='25'), xx)
        )

class TruePredicateTemplate(PredicateTemplate):
    # Always returns true
    def __init__(self) -> None:
        self.needed_type = OpaqueNames.TRUE
        self.num_variables_needed = 1

    def create_predicate(self, predicate_variables: list[c_ast.Decl]) -> c_ast.Node:
        name = predicate_variables[0].name
        return c_ast.ID(name=name)


class OpaqueIf(abc.ABC):

    def __init__(self, predicate: PredicateTemplate) -> None:
        self.predicate = predicate
    
    @abc.abstractmethod
    def insert_opaque_if(self, variables_in_scope: list[list[c_ast.Decl]], variables_for_predicate: list[c_ast.Decl], block: list[c_ast.Node], min_index: int) -> bool:
        pass
    
class JunkOpaqueIf(OpaqueIf):

    def junk(self, variable1: c_ast.Decl, variable2: c_ast.Decl, variable3: c_ast.Decl) -> c_ast.Assignment:
        name_var1 = variable1.name
        name_var2 = variable2.name
        name_var3 = variable3.name

        op_choice = secrets.randbelow(3)
        rvalue = None
        if op_choice == 0:
            rvalue = c_ast.BinaryOp('+', c_ast.ID(name=name_var1), c_ast.ID(name=name_var2))
        elif op_choice == 1:
            rvalue = c_ast.BinaryOp('-', c_ast.ID(name=name_var1), c_ast.ID(name=name_var2))
        elif op_choice == 2:
            rvalue = c_ast.BinaryOp('*', c_ast.ID(name=name_var1), c_ast.ID(name=name_var2))
        
        return c_ast.Assignment(op='=', lvalue=c_ast.ID(name=name_var3), rvalue=rvalue)

    def select_3_vars(self, usable_variables: list[c_ast.Decl]) -> tuple[c_ast.Decl, c_ast.Decl, c_ast.Decl]:
        resulting_tuple = ()
        for i in range(3):
            resulting_tuple = resulting_tuple + (secrets.choice(usable_variables), )

        return resulting_tuple

    def insert_opaque_if(self, variables_in_scope: list[list[c_ast.Decl]], variables_for_predicate: list[c_ast.Decl], block: list[c_ast.Node], min_index: int) -> bool:
        if len(variables_for_predicate) < self.predicate.num_variables_needed:
            return False
        
        usable_variables = []
        for i in range(len(variables_in_scope)):
            for candidate in variables_in_scope[i]:
                if OPAQUE_NAME_PATTERN.match(candidate.name):
                    usable_variables.append(candidate)
        if len(usable_variables) == 0:
            return False
        
        chosen_variable = secrets.choice(variables_for_predicate)
        generated_predicate = c_ast.UnaryOp('!', self.predicate.create_predicate([chosen_variable]))

        num_junk_instructions = max(EXPECTED_LENGTH_JUNK + (secrets.randbelow(EXPECTED_LENGTH_JUNK) - EXPECTED_LENGTH_JUNK) // 2,1)
        useless_computations = []
        for i in range(num_junk_instructions):
            variable1, variable2, variable3 = self.select_3_vars(usable_variables)
            useless_computations.append(self.junk(variable1, variable2, variable3))

        block.insert(
            min_index, 
            c_ast.If(
                cond=generated_predicate,
                iftrue=c_ast.Compound(block_items=useless_computations),
                iffalse=None
            )
        )
        return True

class BogusFlowOpaqueIf(OpaqueIf):

    def insert_opaque_if(self, variables_in_scope: list[list[c_ast.Decl]], variables_for_predicate: list[c_ast.Decl], block: list[c_ast.Node], min_index: int) -> bool:
        if len(variables_for_predicate) < self.predicate.num_variables_needed:
            return False

        # statements after min_index are the ones to duplicate
        statements_after = block[min_index:]
        if len(statements_after) == 0:
            return False

        chosen_variable = secrets.choice(variables_for_predicate)
        generated_predicate = self.predicate.create_predicate([chosen_variable])

        true_branch = copy.deepcopy(statements_after)

        if_node = c_ast.If(
            cond=generated_predicate,
            iftrue=c_ast.Compound(block_items=true_branch),
            iffalse=None
        )

        del block[min_index:]
        block.insert(min_index, if_node)
        return True

class MyOpaqueIfVisitor(c_ast.NodeVisitor):

    def __init__(self, modifier: OpaqueIf, max_depth: int = 6):
        self._variables_in_scope = []
        self._modifier = modifier
        self._depth = max_depth

    def available_variables(self, variables_in_scope: list[list[c_ast.Decl]], type_needed: OpaqueNames) -> list[c_ast.Decl]:
        return_variables = []
        for block in variables_in_scope:
            for variable_in_block in block:
                variable_name = variable_in_block.name

                for available_type in OpaqueNames:
                    if variable_name.endswith(f'_{type_needed}_opaque'):
                        return_variables.append(variable_in_block)

        return return_variables

    def visit_Compound(self, node):
        if self._depth == 0:
            return
        self._depth -= 1
        self._variables_in_scope.append([])

        if node.block_items is None:
            node.block_items = []

        i = 0
        used_in_block = False
        while i < len(node.block_items):
            statement = node.block_items[i]

            # track variables in scope
            if isinstance(statement, c_ast.Decl) and statement.name is not None:
                self._variables_in_scope[-1].append(statement)
            
            if not used_in_block and secrets.randbelow(101) <= AGGRESSIVENESS * 100:
                variables_to_use = self.available_variables(self._variables_in_scope, self._modifier.predicate.needed_type)
                if len(variables_to_use) > 0:
                    used_in_block = self._modifier.insert_opaque_if(self._variables_in_scope, variables_to_use, node.block_items, i + 1) # commit if changes were made

            self.visit(statement)   # descend into nested blocks
            i += 1

        self._variables_in_scope.pop()
        self._depth += 1

class MyOpaqueVariableVisitor(c_ast.NodeVisitor):

    def __init__(self, opaque_variable: OpaqueTemplate, max_depth: int = 6) -> None:
        self._opaque_variable = opaque_variable
        self._depth = max_depth

    def visit_Compound(self, node):
        if self._depth == 0:
            return
        self._depth -= 1

        if node.block_items is None:
            node.block_items = []
        
        if secrets.randbelow(101) <= DO_ANYTHING_PROBABILITY * 100:
            new_variable_block = self._opaque_variable.opaque_variable_algorithm(CType.UNSIGNED_INT)
            for block in reversed(new_variable_block):
                node.block_items.insert(0, block)

        self.generic_visit(node)  
        self._depth += 1

def general_probability():
    return secrets.randbelow(101) <= DO_ANYTHING_PROBABILITY * 100

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <input.c> <output.c>")
        sys.exit(1)

    input_file  = sys.argv[1]
    output_file = sys.argv[2]

    ast = pycparser.parse_file(
        input_file,
        use_cpp=True,
        cpp_path='cpp',
        cpp_args=['-I./fake_imports']
    )

    for i in range(4):
        if general_probability():
            MyOpaqueVariableVisitor(ResidueTrueOpaqueTemplate()).visit(ast)
        if general_probability():
            MyOpaqueVariableVisitor(RandomAddressPrimeOpaqueTemplate()).visit(ast)
        if general_probability():
            MyOpaqueVariableVisitor(AddressRandomOpaqueTemplate()).visit(ast)
    for i in range(3):
        if general_probability():
            MyOpaqueIfVisitor(BogusFlowOpaqueIf(IsOddOrTwoPredicateTemplate())).visit(ast)
        if general_probability():
            MyOpaqueIfVisitor(BogusFlowOpaqueIf(PythagoreanTriplePredicateTemplate())).visit(ast)
        if general_probability():
            MyOpaqueIfVisitor(BogusFlowOpaqueIf(TruePredicateTemplate())).visit(ast)
    for i in range(2):
        if general_probability():
            MyOpaqueIfVisitor(JunkOpaqueIf(IsOddOrTwoPredicateTemplate())).visit(ast)
        if general_probability():
            MyOpaqueIfVisitor(JunkOpaqueIf(PythagoreanTriplePredicateTemplate())).visit(ast)
        if general_probability():
            MyOpaqueIfVisitor(JunkOpaqueIf(TruePredicateTemplate())).visit(ast)




    gen = c_generator.CGenerator()
    result = gen.visit(ast)

    with open(output_file, 'w') as f:
        f.write(result)

    with open(output_file, 'r') as f:
        content = f.read()

    replacements = [
        ('BOOL VirtualProtect(',        'BOOL __stdcall VirtualProtect('),
        ('LPVOID VirtualAlloc(',        'LPVOID __stdcall VirtualAlloc('),
        ('HMODULE GetModuleHandleA(',   'HMODULE __stdcall GetModuleHandleA('),
        ('HMODULE LoadLibraryA(',       'HMODULE __stdcall LoadLibraryA('),
        ('void *GetProcAddress(',       'void * __stdcall GetProcAddress('),
    ]
    for old, new in replacements:
        content = content.replace(old, new)

    with open(output_file, 'w') as f:
        f.write(content)
    
    print(f"Written to {output_file}")
