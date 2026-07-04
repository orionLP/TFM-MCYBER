#!/usr/bin/env python3
import clang
from clang.cindex import Index, CursorKind, TypeKind
import sys
from collections import defaultdict

from clang.cindex import TypeKind

BUILTIN_KINDS = {
    TypeKind.VOID, TypeKind.BOOL, TypeKind.CHAR_U, TypeKind.UCHAR, TypeKind.CHAR16, TypeKind.CHAR32,
    TypeKind.USHORT, TypeKind.UINT, TypeKind.ULONG, TypeKind.ULONGLONG, TypeKind.UINT128,
    TypeKind.CHAR_S, TypeKind.SCHAR, TypeKind.WCHAR, TypeKind.SHORT, TypeKind.INT, TypeKind.LONG, 
    TypeKind.LONGLONG, TypeKind.INT128, TypeKind.FLOAT, TypeKind.DOUBLE, TypeKind.LONGDOUBLE,
    TypeKind.NULLPTR,
}

def is_primitive(cursor: clang.cindex.Cursor) -> bool:
    return cursor in BUILTIN_KINDS

def is_function_declaration(cursor: clang.cindex.Cursor) -> bool:
    return cursor.kind == CursorKind.FUNCTION_DECL and not cursor.is_definition()

import networkx as nx 

class HeaderResolver:
    def __init__(self) -> None:
        self._tu = None
        self._file_path = None
        self._function_nodes = {}
        self._index = Index.create()
        
    def parse(self, file_path: str, include_dirs: list[str]) -> None:
        args = [f"-I{directory}" for directory in include_dirs]
        self._tu = self._index.parse(file_path, args=args)

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

        print(f'Unclean list {[item.spelling for item in type_list]}')
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
        
        print(f'Clean list {[item.spelling for item in clean_list]}')
        
        return clean_list

    def _construct_dependencies(self, dependency_graph: nx.DiGraph, start_node: str) -> None:
        cursor = dependency_graph.nodes[start_node]['cursor']
        needed_types = []
        if is_function_declaration(cursor): 
            needed_types = self._clean_types(list(cursor.type.argument_types()) + [cursor.result_type])
        if cursor.kind == CursorKind.TYPEDEF_DECL:
            needed_types += self._clean_types([cursor.underlying_typedef_type])

        types_declarations = [item.get_declaration() for item in needed_types]
        for item in needed_types:
            cursor = item.get_declaration()
            identifier = cursor.get_usr()
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
        dependency_graph.add_node(function_node.get_usr(), cursor = function_node)
        self._construct_dependencies(dependency_graph, function_node.get_usr())
        return dependency_graph
    
    def resolve_dependencies(self, func_name: str, previous_graph: nx.DiGraph | None = None) -> list[clang.cindex.Cursor]:
        '''Returns a list of all dependencies and the function node'''
        function_node = self._function_nodes[func_name]
        dependency_graph = self._construct_dependency_graph(function_node, previous_graph)
        return dependency_graph
        
        # # type_nodes = self._resolve_types(needed_types)

        # return type_nodes + [function_node]


import matplotlib.pyplot as plt

if __name__ == "__main__":
    extractor = HeaderResolver()
    extractor.parse('/usr/i686-w64-mingw32/include/windows.h', '/usr/i686-w64-mingw32/include/')
    # print(extractor._function_nodes)
    # print([extractor._function_nodes[e].get_usr() for e in extractor._function_nodes])
    # print(extractor._file_path)
    graph = extractor.resolve_dependencies('VirtualAlloc')
    graph = extractor.resolve_dependencies('VirtualProtect', graph)
    graph = extractor.resolve_dependencies('GetProcAddress', graph)



    # Create layout with better spacing
    pos = nx.spring_layout(graph, seed=42, k=2, iterations=50)

    # Or increase the repulsive force
    pos = nx.spring_layout(graph, seed=42, k=3, iterations=50)

    # Draw the graph
    nx.draw_networkx_nodes(graph, pos, node_color='lightblue', node_size=300)
    nx.draw_networkx_edges(graph, pos, edge_color='gray', arrows=True, arrowsize=20)
    nx.draw_networkx_labels(graph, pos, font_size=10)

    plt.title("Control Flow Graph")
    plt.axis('off')
    plt.tight_layout()
    plt.show()