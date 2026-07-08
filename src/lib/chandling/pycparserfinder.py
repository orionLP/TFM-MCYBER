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
    
class UserDefinedFinder(ItemFinder):

    def visit_body(self, node):
        if self._found_condition(node):
            if pycparsertypes.is_typedef(node):
                self._found_item =  node.type.type
            if pycparsertypes.is_decl(node):
                self._found_item =  node.type
        if self._found_item is None:
            self.generic_visit(node)

    def visit_TypeDef(self, node):
        self.visit_body(node)

    def visit_Decl(self, node):
        self.visit_body(node)

class StructFinder(UserDefinedFinder):

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        if pycparsertypes.is_typedef(node) and pycparsertypes.is_struct(node.type.type):
            return node.type.type.name == self._item_to_search
        if pycparsertypes.is_decl(node) and pycparsertypes.is_struct(node.type):
            return node.type.name == self._item_to_search
        
class EnumFinder(UserDefinedFinder):

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        if pycparsertypes.is_typedef(node) and pycparsertypes.is_enum(node.type.type):
            return node.type.type.name == self._item_to_search
        if pycparsertypes.is_decl(node) and pycparsertypes.is_enum(node.type):
            return node.type.name == self._item_to_search

class UnionFinder(UserDefinedFinder):

    def _found_condition(self, node: pycparser.c_ast.Node) -> bool:
        if pycparsertypes.is_typedef(node) and pycparsertypes.is_union(node.type.type):
            return node.type.type.name == self._item_to_search
        if pycparsertypes.is_decl(node) and pycparsertypes.is_union(node.type):
            return node.type.name == self._item_to_search
