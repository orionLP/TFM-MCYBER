import abc
import enum
import clang
import pycparser

import networkx as nx

from clang.cindex import Index, CursorKind, TypeKind
from src.lib.chandling.clangtypes import is_primitive, is_function_declaration

class DependencyResolver(abc.ABC):

    def __init__(self) -> None:
        self._tu = None
        self._file_path = None
        self._function_nodes = {}
        self._index = Index.create()
        self._cursor_by_usr = {} 

    def _build_cursor_map(self, cursor: clang.cindex.Cursor) -> None:
        usr = cursor.get_usr()
        if usr:
            self._cursor_by_usr[usr] = cursor
        for child in cursor.get_children():
            self._build_cursor_map(child)
    
    @abc.abstractmethod
    def parse(self, file_path: str, include_dirs: list[str]) -> None:
        pass

    @abc.abstractmethod
    def resolve_dependencies(self, func_name: str, previous_graph: nx.DiGraph | None = None) -> nx.DiGraph:
        '''Return a graph for type dependencies'''
        pass
    
class ClangDependencyResolver(DependencyResolver):

    def parse(self, file_path: str, include_dirs: list[str]) -> None:
        args = [f"-I{directory}" for directory in include_dirs]
        self._tu = self._index.parse(file_path, args=args)

        self._build_cursor_map(self._tu.cursor)

        for cursor in self._tu.cursor.get_children():
            if is_function_declaration(cursor):
                self._function_nodes[cursor.spelling] = cursor
    
    def _unwrap(self, t: clang.cindex.Type) -> list[clang.cindex.Type]:
        while True:
            if t.kind == TypeKind.POINTER:
                t = t.get_pointee()
            elif t.kind in (TypeKind.CONSTANTARRAY, TypeKind.INCOMPLETEARRAY):
                t = t.get_array_element_type()
            elif t.kind == TypeKind.ELABORATED:
                t = t.get_named_type()
            else:
                return t
    
    def _clean_types(self, type_list: list[clang.cindex.Type]) -> list[clang.cindex.Type]:
        clean_list = []

        for item in type_list:
            unwrapped = self._unwrap(item)
            if is_primitive(unwrapped.kind):
                continue
            elif unwrapped.kind in (TypeKind.FUNCTIONPROTO, TypeKind.FUNCTIONNOPROTO):
                if unwrapped.kind == TypeKind.FUNCTIONPROTO:
                    for argument in unwrapped.argument_types():
                        clean_list += self._clean_types([argument])
                clean_list += self._clean_types([unwrapped.get_result()])
            else:
                clean_list += [unwrapped]
        
        return clean_list

    def _construct_dependencies(self, dependency_graph: nx.DiGraph, start_node: str) -> None:
        cursor = dependency_graph.nodes[start_node]['cursor']
        needed_types = []
        if is_function_declaration(cursor):
            needed_types += self._clean_types(list(cursor.type.argument_types()) + [cursor.result_type])
        if cursor.kind == CursorKind.TYPEDEF_DECL:
            dependency_graph.nodes[start_node]['underlying_kind'] = cursor.underlying_typedef_type.kind
            needed_types += self._clean_types([cursor.underlying_typedef_type])
        if cursor.kind in (CursorKind.STRUCT_DECL, CursorKind.UNION_DECL):
            for field in cursor.get_children():
                if field.kind == CursorKind.FIELD_DECL:
                    needed_types += self._clean_types([field.type])
        
        dependency_graph.nodes[start_node]['kind'] = cursor.kind
        dependency_graph.nodes[start_node]['spelling'] = cursor.spelling

        types_declarations = [item.get_declaration() for item in needed_types]
        for item in needed_types:
            cursor = item.get_declaration()
            identifier = cursor.get_usr()

            # Look up the cursor from the AST map (has location info) (sometimes with get_declaration there are no extensions)
            if identifier in self._cursor_by_usr:
                cursor = self._cursor_by_usr[identifier]

            was_before = identifier in dependency_graph.nodes
            if not was_before:
                dependency_graph.add_node(identifier, cursor = cursor)
            dependency_graph.add_edge(start_node, identifier)
            if not was_before:
                self._construct_dependencies(dependency_graph, identifier)

    def _construct_dependency_graph(self, function_node: clang.cindex.Cursor, previous_graph: nx.DiGraph | None = None) -> nx.DiGraph:
        dependency_graph = None
        if previous_graph is None:
            dependency_graph = nx.DiGraph()
        else:
            dependency_graph = previous_graph
        dependency_graph.add_node(function_node.get_usr(), cursor = function_node, spelling = function_node.spelling)
        self._construct_dependencies(dependency_graph, function_node.get_usr())
        return dependency_graph
    
    def resolve_dependencies(self, func_name: str, previous_graph: nx.DiGraph | None = None) -> nx.DiGraph:
        function_node = self._function_nodes[func_name]
        dependency_graph = self._construct_dependency_graph(function_node, previous_graph)
        return dependency_graph

# import src.lib.chandling.pycparserfinder as pycparserfinder
# import src.lib.chandling.pycparsertypes as pycparsertypes

# # In the end i have put this part on hold, as it would take a bit of time to do
# class FunctionVariableNodeTypes(enum.StrEnum):
#     FUNCTION = 'function'
#     ARGUMENT = 'argument'
#     RETURN_VARIABLE = 'return_variable'
#     TYPE = 'type'
#     STRUCT = 'struct'

# class FunctionVariableResolver():

#     def __init__(self, function_finder: pycparserfinder.ItemFinder) -> None:
#         self._function_finder = function_finder

#     def _resolve_node(self, node_name: str, ast: pycparser.c_ast.FileAST, graph: nx.DiGraph):
#         pycparser_node = graph.nodes[node_name]['pycparser_node']

#         if pycparsertypes.is_function_declaration(pycparser_node):
#             arguments = pycparser_node.type.args.params
#             return_node = pycparser_node.type.type
#             for argument in arguments:
#                 graph.add_node(argument.name, nodetype = FunctionVariableNodeTypes.ARGUMENT, pycparser_node = argument)
#                 graph.add_edge(node_name, argument.name)
#                 self._resolve_node(argument.name, ast, graph)
#             graph.add_node(FunctionVariableNodeTypes.RETURN_VARIABLE.value, nodetype = FunctionVariableNodeTypes.RETURN_VARIABLE, pycparser_node = return_node)
#             graph.add_edge(node_name, FunctionVariableNodeTypes.RETURN_VARIABLE.value)
#             self._resolve_node(argument.name, ast, graph)
        
        
    
#     def resolve_dependencies(self, func_name: str, ast: pycparser.c_ast.FileAST, type_dependency_graph: nx.DiGraph) -> nx.DiGraph:
#         '''
#         return a graph with root nodes representing functions, and the other nodes eventually having a type that can be used to create a variable. There
#         must be a function declaration at some point of the code.
#         '''
#         dependency_graph = nx.DiGraph()
        
#         function_node = self._function_finder.find(ast, func_name)
#         dependency_graph.add_node(func_name, nodetype = FunctionVariableNodeTypes.FUNCTION, pycparser_node = function_node)

#         self._resolve_node(func_name, ast, dependency_graph)

#         print(dependency_graph)

