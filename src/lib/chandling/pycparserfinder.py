import abc
import pycparser
import src.lib.chandling.pycparsertypes as pycparsertypes

class ItemFinder(abc.ABC, pycparser.c_ast.NodeVisitor):

    def find(self, ast: pycparser.c_ast.FileAST, name: str) -> pycparser.c_ast.Node | None:
        self._item_to_search = name
        self._found_item = None
        self.visit(ast)
        return self._found_item

    def visit_body(self, node):
        if self._found_condition(node):
            print(node)
            self._found_item = node
        if self._found_item is None:
            self.generic_visit(node)

    @abc.abstractmethod
    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        pass 

class FunctionDeclarationFinder(ItemFinder):

    def visit_Decl(self, node):
        self.visit_body(node)

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        return pycparsertypes.is_function_declaration(node) and node.name == self._item_to_search
    
class StructFinder(ItemFinder):

    def visit_Struct(self, node):
        self.visit_body(node)

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        return node.name == self._item_to_search

class EnumFinder(ItemFinder):

    def visit_Enum(self, node):
        self.visit_body(node)

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        return node.name == self._item_to_search

