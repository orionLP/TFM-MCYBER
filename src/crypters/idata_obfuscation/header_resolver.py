#!/usr/bin/env python3
import clang
from clang.cindex import Index, CursorKind, TypeKind
import sys
from collections import defaultdict

import src.lib.chandling.variableclassifier as variableclassifier

from clang.cindex import TypeKind

import networkx as nx

import pycparser
import src.lib.chandling.pycparserfinder as pycparserfinder
import matplotlib.pyplot as plt

# i have no idea why but with preprocessing it finally works
# 
# command used:
# clang  --target=i686-pc-windows-gnu -E -I/usr/i686-w64-mingw32/include /usr/i686-w64-mingw32/include/windows.h -o preprocessed.i

from pycparser import c_generator

import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.headerhandler as headerhandler
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.ctypes as ctypes

import src.lib.obfuscation.utils.namegenerator as namegenerator


if __name__ == "__main__":
    extractor = dependencyresolver.ClangDependencyResolver()
    extractor.parse('./src/crypters/idata_obfuscation/file.c', '/usr/i686-w64-mingw32/include/')

    graph = extractor.resolve_dependencies('notmyname')

    handler = headerhandler.StandardHeaderResolver()
    clang_text, pycparser_text = handler.print_code(graph)
    
    ast = pycparser.CParser().parse(pycparser_text)
    
    classifier = variableclassifier.StandardVariableClassifier()
        
    fdf = pycparserfinder.FunctionDeclarationFinder()
    sf = pycparserfinder.StructFinder()
    ef = pycparserfinder.EnumFinder()

    integer_types = ctypes.I686PCWindowsGNU
    name_generation = namegenerator.RandomNameGenerator(16)
    builder = cbuilder.StandardCBuilder(integer_types)
    frequent_builder = cbuilder.StandardFrequentCodeCBuilder(builder, integer_types)
    rfcb = cbuilder.StandardRandomFunctionCallBuilder(
        builder,
        frequent_builder,
        name_generation,
        integer_types,
        fdf,
        sf,
        ef,
        classifier
    )

    ast_res = rfcb.create_function('notmyname', ast, graph)

    print(ast_res)
    gen = pycparser.c_generator.CGenerator()
    result = ''
    for item in ast_res:
        result += gen.visit(item) + ';\n'
    print(result)
    # Create layout with better spacing
    pos = nx.spring_layout(graph, seed=42, k=2, iterations=50)

    # Or increase the repulsive force
    pos = nx.spring_layout(graph, seed=42, k=3, iterations=50)

    # Draw the graph
    labels = {node:[node,graph.nodes[node]['spelling'], graph.nodes[node]['kind'], graph.nodes[node]['underlying_kind'] if 'underlying_kind' in graph.nodes[node] else None] for node in graph.nodes()}
    nx.draw_networkx_nodes(graph, pos, node_color='lightblue', node_size=300)
    nx.draw_networkx_edges(graph, pos, edge_color='gray', arrows=True, arrowsize=20)
    nx.draw_networkx_labels(graph, pos, labels, font_size=10)

    plt.title("Control Flow Graph")
    plt.axis('off')
    plt.tight_layout()
    plt.show()