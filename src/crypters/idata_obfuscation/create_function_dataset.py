import csv
import json

import networkx as nx
import src.lib.chandling.filechecker as filechecker
import src.lib.chandling.headerhandler as headerhandler
import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.functionextractors as functionextractors

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

#└─$ tai
INCLUDES = './data/preprocessed_headers/'
LIBRARIES = '/usr/i686-w64-mingw32/lib/'
CSV_FILE = 'src/crypters/idata_obfuscation/functions.csv'
TMP_LOCATION = '/tmp/'
CLANG_FILE = TMP_LOCATION + 'clang_output.c'
PYCPARSER_FILE = TMP_LOCATION + 'pycparser_output.c'
OUTPUT_JSON = 'src/crypters/idata_obfuscation/usable_functions.json'
ORIGINAL_FOLDER = '/usr/i686-w64-mingw32/include/'
TMP_INPUT_FILE = './src/crypters/idata_obfuscation/merged.c'
TMP_OUTPUT_FILE = '/tmp/apply_transform_output.c'
FAKE_IMPORTS = '-I./src/fake_imports'

def create_example_file(input_file: str, output_file: str, headers_file: str, original_headers_folder: str, function_name: str) -> None:

    extractor = dependencyresolver.ClangDependencyResolver()
    extractor.parse(headers_file, original_headers_folder)

    graph = extractor.resolve_dependencies(function_name)

    handler = headerhandler.StandardHeaderResolver()
    clang_text, pycparser_text = handler.print_code(graph)
    dependencies_ast = pycparser.CParser().parse(pycparser_text)
    ast = pycparser.parse_file(
        input_file,
        use_cpp=True,
        cpp_path='cpp',
        cpp_args=[FAKE_IMPORTS]
    )

    integer_types = ctypes.I686PCWindowsGNU
    builder = cbuilder.StandardCBuilder(integer_types)
    frequent_builder = cbuilder.StandardFrequentCodeCBuilder(builder, integer_types)
    variable_type = ctypes.CTypes.UNSIGNED_INT
    name_generator = namegenerator.StandardVariableNameGenerator(16)
    
    residue_variable = opaquevariable.ResidueTrueOpaqueVariable(integer_types, builder, frequent_builder, name_generator)
    raprime_variable = opaquevariable.RAPrimeOpaqueVariable(integer_types, builder, frequent_builder, name_generator)
    random_address_variable = opaquevariable.AddressRandomOpaqueVariable(integer_types, builder, frequent_builder, name_generator)

    is_odd_or_two_predicate = opaquepredicate.IsOddOrTwoOpaquePredicate(builder)
    pythagorean_triple_predicate = opaquepredicate.PythagoreanTripleOpaquePredicate(builder)
    dummy_predicate = opaquepredicate.DummyOpaquePredicate(builder)

    scope_handler = scope.StandardScope()

    variable_injection_visitors = []
    for opaque_variable in [residue_variable]:
        variable_injection_visitors.append(opaquevariablevisitor.InjectOpaqueVariableVisitor(builder, opaque_variable, variable_type, scope_handler, 3, 1))

    for viv in variable_injection_visitors:
        viv.visit(ast)

    classifier = variableclassifier.StandardVariableClassifier()
    function_finder = pycparserfinder.FunctionDeclarationFinder()
    integer_types = ctypes.I686PCWindowsGNU
    name_generator = namegenerator.RandomNameGenerator(16)
    builder = cbuilder.StandardCBuilder(integer_types)
    frequent_builder = cbuilder.StandardFrequentCodeCBuilder(builder, integer_types)
    rfcb = opaquefunctioncall.NoCallOpaqueFunctionCall(builder, frequent_builder, name_generator, integer_types, function_finder, classifier, [function_name], dependencies_ast, graph)

    function_call_visitor = opaquefunctioncallvisitor.OpaqueFunctionCallVisitor(dummy_predicate, rfcb, ctypes.CTypes.UNSIGNED_INT, scope_handler, 4, 1)

    function_call_visitor.visit(ast)

    gen = c_generator.CGenerator()
    result = gen.visit(ast)

    with open(output_file, 'w') as f:
        f.write(result)

    with open(output_file, 'r') as f:
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
    with open(output_file, 'w') as f:
        f.write(content)
    


if __name__ == "__main__":
    relation_header_libraries = {}

    with open(CSV_FILE) as csv_functions:
        parsed_csv = csv.reader(csv_functions, delimiter = ',')
        header = True
        for row in parsed_csv:
            if header:
                header = False
                continue
            header_file = row[0]
            archive_file = row[1]
            library = row[2]
            relation_header_libraries[header_file] = (archive_file, library)

    header_function_extractor = functionextractors.HFileHeaderFunctionExtractor()
    archive_function_extractor = functionextractors.ArchiveHeaderFunctionExtractor()
    dependencies_extractor = dependencyresolver.ClangDependencyResolver()
    header_printer = headerhandler.StandardHeaderResolver()

    usable_functions = {}
    for header_name, lib_link in relation_header_libraries.items():
        print(f'Processing header file {header_name}')
        number_of_functions = 0
        number_of_accepted_functions = 0

        library, compilation_flag = lib_link

        usable_functions[header_name] = {"header_path":INCLUDES + header_name, "command":compilation_flag, "functions":[]}
        
        compilation_checker = filechecker.CompilationFileChecker([compilation_flag])
        parser_checker = filechecker.PyParserFileChecker()

        path_to_include = INCLUDES + header_name
        path_to_library = LIBRARIES + library

        functions_in_header = None
        functions_in_archive = None
        try:
            functions_in_header = set(header_function_extractor.list_functions(path_to_include))
            functions_in_archive = set(archive_function_extractor.list_functions(path_to_library))
            dependencies_extractor.parse(path_to_include, '/usr/i686-w64-mingw32/include/')
        except Exception as e:
            print('Ignoring header due to incapability of parsing either headers or libraries')
            continue

        intersection_of_functions = functions_in_header.intersection(functions_in_archive)

        for function_name in intersection_of_functions:
            try:
                print(f'Processing function {function_name}')

                graph = dependencies_extractor.resolve_dependencies(function_name)
                clang_text, pycparser_text = header_printer.print_code(graph)

                clang_text = clang_text + '\nint main(void){return 0;}'
                pycparser_text = pycparser_text + '\nint main(void){return 0;}'
                
                with open(CLANG_FILE, 'w') as file_clang:
                    file_clang.write(clang_text)

                with open(PYCPARSER_FILE, 'w') as file_pycparser:
                    file_pycparser.write(pycparser_text)

                create_example_file(TMP_INPUT_FILE, TMP_OUTPUT_FILE, path_to_include, ORIGINAL_FOLDER, function_name)

                if compilation_checker.check_file(CLANG_FILE) and compilation_checker.check_file(TMP_OUTPUT_FILE) and parser_checker.check_file(PYCPARSER_FILE):
                    print('Accepted this function')
                    usable_functions[header_name]["functions"].append(function_name)
                    number_of_accepted_functions += 1
                    
                number_of_functions += 1
            except nx.exception.NetworkXUnfeasible as e:
                print('Ignoring this function due to loops')
            except Exception as e:
                print(e)
                print('Ignoring this function due to errors')

        print(f'Accepted {number_of_accepted_functions / number_of_functions} of header file {header_name}. Total accepted functions is {number_of_accepted_functions}, and checked functions {number_of_functions}')

    with open(OUTPUT_JSON, 'w') as output_file:
        json.dump(usable_functions, output_file, indent = 2)