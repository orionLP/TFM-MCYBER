import abc
import pycparser

class ItemFinder(abc.ABC, pycparser.c_ast.NodeVisitor):

    def __init__(self) -> None:
        self._item_to_search = None
        self._found_item = None

    @property
    def item_to_search(self) -> str:
        return self._item_to_search
    
    @item_to_search.setter
    def item_to_search(self, name: str) -> None:
        self._item_to_search = name
        self._found_item = None
    
    @property
    def found_item(self) -> pycparser.c_ast.Node | None:
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
        self.generic_visit(node)