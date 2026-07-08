import sys
import clang
import pycparser

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
    labels = {node:[node,graph.nodes[node]['spelling'], graph.nodes[node]['kind'], graph.nodes[node]['underlying_kind'] if 'underlying_kind' in graph.nodes[node] else None] for node in graph.nodes()}
    nx.draw_networkx_nodes(graph, pos, node_color='lightblue', node_size=300)
    nx.draw_networkx_edges(graph, pos, edge_color='gray', arrows=True, arrowsize=20)
    nx.draw_networkx_labels(graph, pos, labels, font_size=10)

    plt.title("Control Flow Graph")
    plt.axis('off')
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":

    HEADERS_FILE = './data/preprocessed_headers/memoryapi.h'
    ORIGINAL_FOLDER = '/usr/i686-w64-mingw32/include/'
    FUNCTIONS_TO_EXTRACT = ['VirtualProtect', 'VirtualAlloc', 'VirtualFree', 'VirtualQuery']
    TARGET_FILE = './src/crypters/idata_obfuscation/merged.c'
    OUTPUT_FILE = './src/crypters/idata_obfuscation/output.c'

    extractor = dependencyresolver.ClangDependencyResolver()
    extractor.parse(HEADERS_FILE, ORIGINAL_FOLDER)

    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[0])
    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[1], graph)
    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[2], graph)
    graph = extractor.resolve_dependencies(FUNCTIONS_TO_EXTRACT[3], graph)

    pretty_plot(graph)

    handler = headerhandler.StandardHeaderResolver()
    clang_text, pycparser_text = handler.print_code(graph)
    
    dependencies_ast = pycparser.CParser().parse(pycparser_text)
    ast = pycparser.parse_file(
        TARGET_FILE,
        use_cpp=True,
        cpp_path='cpp',
        cpp_args=['-I./src/fake_imports']
    )

    print('Configuring objects...')

    integer_types = ctypes.I686PCWindowsGNU
    builder = cbuilder.StandardCBuilder(integer_types)
    frequent_builder = cbuilder.StandardFrequentCodeCBuilder(builder, integer_types)
    variable_type = ctypes.CTypes.UNSIGNED_INT
    name_generator = namegenerator.StandardVariableNameGenerator(16)

    print('Creating opaque variable objects...')
    
    residue_variable = opaquevariable.ResidueTrueOpaqueVariable(integer_types, builder, frequent_builder, name_generator)
    raprime_variable = opaquevariable.RAPrimeOpaqueVariable(integer_types, builder, frequent_builder, name_generator)
    random_address_variable = opaquevariable.AddressRandomOpaqueVariable(integer_types, builder, frequent_builder, name_generator)

    print('Creating opaque predicate objects...')

    is_odd_or_two_predicate = opaquepredicate.IsOddOrTwoOpaquePredicate(builder)
    pythagorean_triple_predicate = opaquepredicate.PythagoreanTripleOpaquePredicate(builder)
    dummy_predicate = opaquepredicate.DummyOpaquePredicate(builder)

    # print('Creating opaque if objects...')

    # junk_if = opaqueif.JunkOpaqueIf(builder)
    # bogus_flow_if = opaqueif.BogusFlowOpaqueIf(builder)

    print('Creating scope...')
    scope_handler = scope.StandardScope()

    print('Creating visitors to inject variables...')
    variable_injection_visitors = []
    for opaque_variable in [residue_variable, raprime_variable, random_address_variable]:
        variable_injection_visitors.append(opaquevariablevisitor.InjectOpaqueVariableVisitor(builder, opaque_variable, variable_type, scope_handler, 3, 0.5))

    print('Injecting variables...')
    for viv in variable_injection_visitors:
        viv.visit(ast)

    # print('Creating visitors to inject opaque true ifs...')
    # if_injection_visitors = []
    # for opaque_predicate in [is_odd_or_two_predicate, pythagorean_triple_predicate, dummy_predicate]:
    #     for opaque_if in [junk_if, bogus_flow_if]:
    #         if_injection_visitors.append(opaqueifvisitor.TrueOpaqueIfVisitor(opaque_predicate, opaque_if, variable_type, scope_handler, 16, 0.3))

    # for iiv in if_injection_visitors:
    #     iiv.visit(ast)

    classifier = variableclassifier.StandardVariableClassifier()
    function_finder = pycparserfinder.FunctionDeclarationFinder()
    integer_types = ctypes.I686PCWindowsGNU
    name_generator = namegenerator.RandomNameGenerator(16)
    builder = cbuilder.StandardCBuilder(integer_types)
    frequent_builder = cbuilder.StandardFrequentCodeCBuilder(builder, integer_types)
    rfcb = opaquefunctioncall.NoCallOpaqueFunctionCall(builder, frequent_builder, name_generator, integer_types, function_finder, classifier, FUNCTIONS_TO_EXTRACT, dependencies_ast, graph)

    function_call_visitor = opaquefunctioncallvisitor.OpaqueFunctionCallVisitor(dummy_predicate, rfcb, ctypes.CTypes.UNSIGNED_INT, scope_handler, 16, 0.5)

    function_call_visitor.visit(ast)

    gen = c_generator.CGenerator()
    result = gen.visit(ast)

    with open(OUTPUT_FILE, 'w') as f:
        f.write(result)

    with open(OUTPUT_FILE, 'r') as f:
        content = f.read()

    replacements = [
        ('BOOL VirtualProtect(',        'BOOL __stdcall VirtualProtect('),
        ('LPVOID VirtualAlloc(',        'LPVOID __stdcall VirtualAlloc('),
        ('HMODULE GetModuleHandleA(',   'HMODULE __stdcall GetModuleHandleA('),
        ('HMODULE LoadLibraryA(',       'HMODULE __stdcall LoadLibraryA('),
        ('void *GetProcAddress(',       'void * __stdcall GetProcAddress('),
    ]
    for old, new in replacements:
        content = content.replace(old, new)

    content = clang_text + '\n' + content
    with open(OUTPUT_FILE, 'w') as f:
        f.write(content)
    
