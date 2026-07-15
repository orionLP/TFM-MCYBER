import sys
import clang
import pycparser


from clang.cindex import Config
Config.set_library_file("/usr/lib/llvm-21/lib/libclang.so")

from pycparser import c_generator
from clang.cindex import TypeKind
from collections import defaultdict
from clang.cindex import Index, CursorKind, TypeKind

import networkx as nx
import matplotlib.pyplot as plt
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.obfuscation.utils.scope as scope
import src.lib.chandling.headerhandler as headerhandler
import src.lib.chandling.pycparserfinder as pycparserfinder
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.chandling.variableclassifier as variableclassifier
import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.obfuscation.control.opaquevariable as opaquevariable
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.visitors.opaqueifvisitor as opaqueifvisitor
import src.lib.obfuscation.control.opaquefunctioncall as opaquefunctioncall
import src.lib.obfuscation.visitors.opaquevariablevisitor as opaquevariablevisitor
import src.lib.obfuscation.visitors.opaquefunctioncallvisitor as opaquefunctioncallvisitor

def pretty_plot(graph):
    pos = nx.spring_layout(graph, seed=42, k=2, iterations=50)
    pos = nx.spring_layout(graph, seed=42, k=3, iterations=50)

    # Draw the graph
    labels = {node: graph.nodes[node]['spelling'] for node in graph.nodes()}
    nx.draw_networkx_nodes(graph, pos, node_color='lightblue', node_size=300)
    nx.draw_networkx_edges(graph, pos, edge_color='grey', arrows=True, arrowsize=20)

    offset = 0.1
    pos = {node: (x, y + offset) for node, (x, y) in pos.items()}
    nx.draw_networkx_labels(graph, pos, labels, font_size=15)

    plt.title("Type dependencies", fontsize=15)
    plt.axis('off')
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":

    HEADERS_FILE = './data/preprocessed_headers/memoryapi.h'
    ORIGINAL_FOLDER = '/usr/i686-w64-mingw32/include/'
    FUNCTIONS_TO_EXTRACT = ['VirtualProtect', 'VirtualAlloc', 'VirtualFree']
    TARGET_FILE = './src/crypters/idata_obfuscation/merged.c'
    OUTPUT_FILE = './src/crypters/idata_obfuscation/output.c'

    extractor = dependencyresolver.ClangDependencyResolver()
    extractor.parse(HEADERS_FILE, ORIGINAL_FOLDER)

    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[0])
    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[1], graph)
    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[2], graph)

    pretty_plot(graph)


