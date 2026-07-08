import csv
import json

import networkx as nx
import src.lib.chandling.filechecker as filechecker
import src.lib.chandling.headerhandler as headerhandler
import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.functionextractors as functionextractors

#└─$ tail -n +2 src/crypters/idata_obfuscation/functions.csv | cut -d, -f1 | while read -r h; do clang --target=i686-pc-windows-gnu -E -I/usr/i686-w64-mingw32/include "/usr/i686-w64-mingw32/include/${h}" -o "./src/preprocessed_headers/${h}" ; done 

INCLUDES = './data/preprocessed_headers/'
LIBRARIES = '/usr/i686-w64-mingw32/lib/'
CSV_FILE = 'src/crypters/idata_obfuscation/functions.csv'
TMP_LOCATION = '/tmp/'
CLANG_FILE = TMP_LOCATION + 'clang_output.c'
PYCPARSER_FILE = TMP_LOCATION + 'pycparser_output.c'
OUTPUT_JSON = 'src/crypters/idata_obfuscation/usable_functions.json'

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

        library, compilation_flag = lib_link

        usable_functions[header_name] = {"command":compilation_flag, "functions":[]}
        
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

                if compilation_checker.check_file(CLANG_FILE) and parser_checker.check_file(PYCPARSER_FILE):
                    print('Accepted this function')
                    usable_functions[header_name]["functions"].append(function_name)
            
            except nx.exception.NetworkXUnfeasible as e:
                print('Ignoring this function due to loops')
            except Exception as e:
                print(e)
                print('Ignoring this function due to errors')

    with open(OUTPUT_JSON, 'w') as output_file:
        json.dump(usable_functions, output_file, indent = 2)