import abc
import pycparser

class ItemFinder(abc.ABC, pycparser.c_ast.NodeVisitor):

    def find(self, ast: pycparser.c_ast.FileAST, name: str) -> pycparser.c_ast.Node | None:
        self._item_to_search = name
        self._found_item = None
        self.visit(ast)
        return self._found_item

    @abc.abstractmethod
    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        pass 

class FunctionDeclarationFinder(ItemFinder):

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        return isinstance(node.type, pycparser.c_ast.FuncDecl) and node.name == self._item_to_search
    
    def visit_Decl(self, node):
        if self._found_condition(node):
            self._found_item = node
        if self._found_item is None:
            self.generic_visit(node)