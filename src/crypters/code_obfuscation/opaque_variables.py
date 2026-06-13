import pycparser
from pycparser import c_ast, c_generator
import abc

# About names:
#
#   __opaque_true_xxx : the variable represents a true value
#   __opaque_false_xxx : the variable represents a false value
#   __opaque_prime_xxx : the variable represents a prime value
#   __opaque_random_xxx : the variable value is random
#

class OpaqueVariableFactory(abc.ABC):

    @abc.abstractmethod
    def create_opaque_variable(self, integer_type: str, range: tuple(int, int)) -> list[c_ast.Node]:
        pass
    
    def create_name(self) -> str:
        return "__opaque"

class TrueOpaqueVariableFactory(OpaqueVariableFactory):

    def create_name(self) -> str:
        return super().create_name() + "_true"

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