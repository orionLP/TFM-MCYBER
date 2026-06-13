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
#   __opaque_true_xxx : the variable represents a true value, any value different than 0
#   __opaque_false_xxx : the variable represents a false value any value 
#   __opaque_prime_xxx : the variable represents a prime value
#   __opaque_random_xxx : the variable value is random
#   __opaque_unusable_xxx : variable that is not meant to be used later
#

class OpaqueNames(StrEnum):
    TRUE = 'true'
    FALSE = 'false'
    PRIME = 'prime'
    RANDOM = 'random'
    UNUSABLE = 'unusable'

DEFAULT_BYTE_ENTROPY = 32 

class OpaqueFactory(abc.ABC):

    @abc.abstractmethod
    def create_opaque_variable(self, integer_type: CType) -> list[c_ast.Node]:
        pass
    
    def create_opaque_name(self, nametype: str) -> str:
        return "__opaque_" + nametype + "_" + secrets.token_hex(DEFAULT_BYTE_ENTROPY)

    def random_integer(low: int, high: int) -> int:
        span = high - low + 1
        return low + secrets.randbelow(span)

class TrueOpaqueFactory(OpaqueFactory):
    pass

class ConstantTrueOpaqueFactory(TrueOpaqueFactory):

    def create_opaque_variable(self, integer_type: CType) -> list[c_ast.Node]:
        return_value = self.random_integer(integer_type.min_val, integer_type.max_val)
        while return_value == 0:
            return_value = self.random_integer(integer_type.min_val, integer_type.max_val)

        variable_name = self.create_opaque_name(OpaqueNames.TRUE)
        decl = c_ast.Decl(
            name=variable_name,
            quals=[],
            align=[],
            storage=[],
            funcspec=[],
            type=c_ast.TypeDecl(
                declname=variable_name,
                quals=[],
                align=None,
                type=c_ast.IdentifierType(names=[integer_type.cname])
            ),
            init=c_ast.Constant(type=integer_type.cname, value=return_value),
            bitsize=None
        )
        return [decl]

class InjectIfVisitor(c_ast.NodeVisitor):
    def visit_Compound(self, node):
        self.generic_visit(node)  

        cond    = c_ast.Constant(type='int', value='1')
        body    = c_ast.Compound(block_items=[])
        if_node = c_ast.If(cond=cond, iftrue=body, iffalse=None)

        if node.block_items is None:
            node.block_items = []
        node.block_items.insert(0, if_node)

parser = pycparser.CParser()
ast = parser.parse("""
    int main(void){
        int x = 3;
        if(x > 1){
            exit(-1);
        }
        return 0;
    }
""")

InjectIfVisitor().visit(ast)

gen = c_generator.CGenerator()
print(gen.visit(ast))