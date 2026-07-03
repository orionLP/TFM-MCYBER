from clang.cindex import Index, CursorKind, TypeKind
from collections import defaultdict
import abc

class HeaderExtractor(abc.ABC):

    @abc.abstractmethod
    def parse(self, header_path: str) -> None:
        pass

    @abc.abstractmethod
    def list_functions(self):
        pass

class StandardHeaderExtractor(HeaderExtractor):

    def __init__(self) -> None:
        self._processed_headers = None
        self._tu = None
        self._index = Index.create()

    def parse(self, header_path: str) -> None:
        tu = self._index.parse(header_path)
        self._tu = tu
        self._processed_headers = header_path

    def list_functions(self):
        return_list = []
        main_file = self._tu.cursor.extent.start.file.name
        for cursor in self._tu.cursor.get_children():
            function_location = cursor.location.file.name
            if cursor.kind == CursorKind.FUNCTION_DECL and main_file == function_location:
                return_list.append(cursor.spelling)
        return return_list

import subprocess
import re

class ArchiveHandler(abc.ABC):

    @abc.abstractmethod
    def list_functions(self, file_path: str) -> list[str]:
        pass
    
class ProcessArchiveHandler(ArchiveHandler):

    def list_functions(self, file_path: str) -> list[str]:
        result = subprocess.run(
            ['i686-w64-mingw32-nm', file_path],
            capture_output=True,
            text=True,
            check=False
        )

        return_list = []
        for line in result.stdout.split('\n'):
            found = not re.match("[0-9]* I __imp__[A-Z]", line) is None
            if found:
                name = re.search("__imp__.*@",line)
                if not name is None:
                    return_list.append(name.group(0)[7:-1])

        return return_list            

import csv

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

    extractor = StandardHeaderExtractor()
    pah = ProcessArchiveHandler()
    for header, library in relation_header_libraries.items():

        path_to_include = '/usr/i686-w64-mingw32/include/' + header
        path_to_library = '/usr/i686-w64-mingw32/lib/' + library
        
        extractor.parse(path_to_include)
        functions_in_header = set(extractor.list_functions())
        
        functions_in_archive = set(pah.list_functions(path_to_library))

        print(f'Header: {header}, Library {library}')
        print(f'Number of functions {len(functions_in_header.intersection(functions_in_archive))}')
        # print(functions_in_header.intersection(functions_in_archive))
