import abc
import enum
import clang
import pycparser

import networkx as nx
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.clangtypes as clangtypes

from clang.cindex import Index, CursorKind, TypeKind
from src.lib.chandling.clangtypes import is_primitive, is_function_declaration

class VariableClassifier(abc.ABC):

    @abc.abstractmethod
    def classify_variable(self, identifier: str, graph: nx.DiGraph) -> tuple[str, ctypes.CTypes | ctypes.DerivedCTypes | ctypes.UserDefinedTypes]:
        pass

class StandardVariableClassifier(VariableClassifier):

    def classify_variable(self, identifier: str, graph: nx.DiGraph) -> tuple[str | None, ctypes.CTypes | ctypes.DerivedCTypes | ctypes.UserDefinedTypes]:
        graph_node = graph.nodes[identifier]

        if graph_node['kind'] == CursorKind.TYPEDEF_DECL:
            if graph_node['underlying_kind'] == TypeKind.ELABORATED:
                underlying_kind = list(graph.successors(identifier))[0]
                return self.classify_variable(underlying_kind, graph)
            return (None, clangtypes.CLANG_TO_CUSTOM[graph_node['underlying_kind']] )
        if graph_node['kind'] == CursorKind.STRUCT_DECL:
            return (graph_node['spelling'], ctypes.UserDefinedTypes.STRUCT)
        if graph_node['kind'] == CursorKind.UNION_DECL:
            return (graph_node['spelling'], ctypes.UserDefinedTypes.UNION)
        if graph_node['kind'] == CursorKind.ENUM_DECL:
            return (graph_node['spelling'], ctypes.UserDefinedTypes.ENUM)
        if is_primitive(graph_node['kind']):
            return (None, clangtypes.CLANG_TO_CUSTOM[graph_node['kind']])