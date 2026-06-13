import pycparser
from pycparser import c_ast, c_generator
import abc
import secrets
from enum import StrEnum

from enum import Enum
from dataclasses import dataclass

@dataclass
class CTypeInfo:
    cname:   str
    min_val: int
    max_val: int

class CType(Enum):
    INT           = CTypeInfo('int', -(2**31), 2**31 - 1)
    UNSIGNED_INT  = CTypeInfo('unsigned int', 0, 2**32 - 1)
    CHAR          = CTypeInfo('char', -128, 127)
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
    FALSE = 'false'
    PRIME = 'prime'
    RANDOM = 'random'
    USELESS = 'useless'
    COMPUTATION = 'computation'

DEFAULT_BYTE_ENTROPY = 16
AGGRESSIVENESS = 0.2

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

class QuadraticResidueTrueOpaqueTemplate(TrueOpaqueTemplate):

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


class InjectIfVisitor(c_ast.NodeVisitor):
    def visit_Compound(self, node):
        self.generic_visit(node)  

        cond    = c_ast.Constant(type='int', value='1')
        body    = c_ast.Compound(block_items=[])
        if_node = c_ast.If(cond=cond, iftrue=body, iffalse=None)

        if node.block_items is None:
            node.block_items = []
        consonant = RandomAddressPrimeOpaqueTemplate().opaque_variable_algorithm(CType.UNSIGNED_INT)
        for i in reversed(consonant):
            node.block_items.insert(0, i)

class OpaqueIf(ABC, c_ast.NodeVisitor):

    def __init__(self):
        self._variables_in_scope = []

    def visit_Compound(self, node):
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
            
            if not used_in_block and secrets.randbelow(0, 101) <= AGGRESSIVENESS * 100:
                used_in_block = True
                self.do_modification(node.block_items, i + 1)

            self.visit(statement)   # descend into nested blocks
            i += 1

        self._variables_in_scope.pop()

    @abc.abstractmethod
    def do_modification(self, body: c_ast.Node, min_index: int) -> None:
        pass

class InjectIfJunkRandomly(c_ast.NodeVisitor):

    def do_modification(self, body: c_ast.Node, min_index: int) -> None:
        pass
        
parser = pycparser.CParser()
ast = parser.parse("""
    int main(void){
        int x = 3;
        if(x < 1){
            return -1;
        }
        return 0;
    }
""")



InjectIfVisitor().visit(ast)

gen = c_generator.CGenerator()
print(gen.visit(ast))