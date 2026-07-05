#!/usr/bin/env python3
import clang
from clang.cindex import Index, CursorKind, TypeKind
import sys
from collections import defaultdict


from clang.cindex import TypeKind

import networkx as nx


import matplotlib.pyplot as plt

# i have no idea why but with preprocessing it finally works
# 
# command used:
# clang  --target=i686-pc-windows-gnu -E -I/usr/i686-w64-mingw32/include /usr/i686-w64-mingw32/include/windows.h -o preprocessed.i

import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.headerhandler as headerhandler

if __name__ == "__main__":
    extractor = dependencyresolver.ClangDependencyResolver()
    extractor.parse('./data/preprocessed_headers/winbase.h', '/usr/i686-w64-mingw32/include/')


    # graph = extractor.resolve_dependencies('BeginUpdateResourceA')
    graph = extractor.resolve_dependencies('AccessCheckAndAuditAlarmA')
    # graph = extractor.resolve_dependencies('GetProcAddress', graph)

    handler = headerhandler.StandardHeaderResolver()
    clang_text, pycparser_text = handler.print_code(graph)

    # print(clang_text)
    print(pycparser_text)
  
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