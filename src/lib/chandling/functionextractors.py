import re
import abc
import subprocess

from clang.cindex import Index, CursorKind


class HeaderFunctionExtractor(abc.ABC):

    @abc.abstractmethod
    def list_functions(self, header_path: str) -> list[str]:
        pass

class HFileHeaderFunctionExtractor(HeaderFunctionExtractor):

    def list_functions(self, header_path: str) -> list[str]:
        index = Index.create()
        tu = index.parse(header_path)
        return_list = []
        main_file = tu.cursor.extent.start.file.name
        for cursor in tu.cursor.get_children():
            node_location = cursor.location.file.name
            if cursor.kind == CursorKind.FUNCTION_DECL and main_file == node_location:
                return_list.append(cursor.spelling)
        return return_list

class ArchiveHeaderFunctionExtractor(HeaderFunctionExtractor):

    def list_functions(self, header_path: str) -> list[str]:
        result = subprocess.run(
            ['i686-w64-mingw32-nm', header_path],
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
