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
    UNUSABLE = 'unusable'

DEFAULT_BYTE_ENTROPY = 16

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
        return start_variables + [opaque_variable] + compute_algorithm

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

class ConstantTrueOpaqueTemplate(TrueOpaqueTemplate):

    def refresh(self) -> None:
        pass 
    
    def define_algorithm_variables(self, integer_type: CType) -> list[c_ast.Decl]:
        return []

    def define_opaque_variable(self, integer_type: CType) -> c_ast.Decl:
        return_value = random_integer(integer_type.min_val, integer_type.max_val)
        while return_value == 0:
            return_value = random_integer(integer_type.min_val, integer_type.max_val)

        variable_name = create_opaque_name(OpaqueNames.TRUE)
        definition = create_variable_definition(
            variable_name, 
            integer_type,
            c_ast.Constant(type=integer_type.cname.split(), value=str(return_value))
        )
        
        return definition

    def compute_opaque(self, integer_type: CType, initial_variables: list[c_ast.Decl], opaque_variable: c_ast.Decl) -> list[c_ast.Node]:
        return []

class PrimeOpaqueTemplate(OpaqueTemplate):
    pass

class RandomAddressPrimeOpaqueTemplate(PrimeOpaqueTemplate):

    def refresh(self) -> None:
        self._sentinel_name = create_opaque_name(OpaqueNames.UNUSABLE)
        self._d_name = create_opaque_name(OpaqueNames.UNUSABLE)
        self._i_name = create_opaque_name(OpaqueNames.UNUSABLE)
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
            )       
        ]

    def define_opaque_variable(self, integer_type: CType) -> c_ast.Decl:
        return create_variable_definition(
            self._prime_name,
            integer_type,
            c_ast.BinaryOp('|',
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
                c_ast.Constant(type=integer_type.cname.split(), value='1')
            ) 
        )


    def compute_opaque(self, integer_type, initial_variables, opaque_variable) -> list[c_ast.Node]:

        # inner while (i * i <= prime) { if (prime % i == 0) d = 0; i = i + 2; }
        inner = c_ast.While(
            cond=c_ast.BinaryOp('<=',
                c_ast.BinaryOp('*', c_ast.ID(name=self._i_name), c_ast.ID(name=self._i_name)),
                c_ast.ID(name=self._prime_name)
            ),
            stmt=c_ast.Compound(block_items=[
                c_ast.If(
                    cond=c_ast.BinaryOp('==',
                        c_ast.BinaryOp('%', c_ast.ID(name=self._prime_name), c_ast.ID(name=self._i_name)),
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
                    lvalue=c_ast.ID(name=self._prime_name),
                    rvalue=c_ast.BinaryOp('+',
                        c_ast.ID(name=self._prime_name),
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

        return [outer]

class RandomOpaqueTemplate(OpaqueTemplate):
    pass

class AddressRandomOpaqueTemplate(RandomOpaqueTemplate):
    pass

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