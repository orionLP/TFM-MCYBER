import csv

import src.lib.chandling.functionextractors as fe

if __name__ == "__main__":
    relation_header_libraries = {}

    with open('src/crypters/idata_obfuscation/functions.csv') as csv_functions:
        parsed_csv = csv.reader(csv_functions, delimiter = ',')
        header = True
        for row in parsed_csv:
            if header:
                header = False
                continue
            header_file = row[0]
            archive_file = row[1]
            relation_header_libraries[header_file] = archive_file

    extractor = fe.HFileHeaderFunctionExtractor()
    pah = fe.ArchiveHeaderFunctionExtractor()
    for header, library in relation_header_libraries.items():

        path_to_include = '/usr/i686-w64-mingw32/include/' + header
        path_to_library = '/usr/i686-w64-mingw32/lib/' + library
        
        functions_in_header = set(extractor.list_functions(path_to_include))
        
        functions_in_archive = set(pah.list_functions(path_to_library))

        print(f'Header: {header}, Library {library}')
        print(f'Number of functions {len(functions_in_header.intersection(functions_in_archive))}')
