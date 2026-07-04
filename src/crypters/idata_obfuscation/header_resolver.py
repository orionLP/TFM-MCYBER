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
            elif unwrapped.kind == TypeKind.FUNCTIONPROTO:
                for argument in unwrapped.argument_types():
                    clean_list += self._clean_types(argument)
                clean_list += self._clean_types(unwrapped.get_result())
            else:
                clean_list += [unwrapped]
        
        print(f'Clean list {[item.spelling for item in clean_list]}')
        
        return clean_list

    def _construct_dependencies(self, dependency_graph: nx.DiGraph, start_node: str) -> None:
        cursor = dependency_graph.nodes[start_node]['cursor']
        needed_types = []
        if is_function_declaration(cursor): 
            needed_types = self._clean_types(list(cursor.type.argument_types()) + [cursor.result_type])
        



    def _construct_dependency_graph(self, function_node: clang.cindex.Cursor) -> nx.DiGraph:
        dependency_graph = nx.DiGraph()
        dependency_graph.add_node(function_node.get_usr(), cursor = function_node)
        self._construct_dependencies(dependency_graph, function_node.get_usr())
        return dependency_graph
    
    def resolve_dependencies(self, func_name: str) -> list[clang.cindex.Cursor]:
        '''Returns a list of all dependencies and the function node'''
        function_node = self._function_nodes[func_name]
        dependency_graph = self._construct_dependency_graph(function_node)
        
        
        # type_nodes = self._resolve_types(needed_types)

        return type_nodes + [function_node]

if __name__ == "__main__":
    extractor = HeaderResolver()
    extractor.parse('/usr/i686-w64-mingw32/include/windows.h', '/usr/i686-w64-mingw32/include/')
    # print(extractor._function_nodes)
    # print([extractor._function_nodes[e].get_usr() for e in extractor._function_nodes])
    # print(extractor._file_path)
    print(extractor.resolve_dependencies('VirtualAlloc'))