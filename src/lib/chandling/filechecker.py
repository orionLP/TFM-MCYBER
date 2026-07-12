import abc
import subprocess
import pycparser

import src.lib.chandling.compilationhandler as compilationhandler

class FileChecker(abc.ABC):

    @abc.abstractmethod
    def check_file(self, file_path: str) -> bool:
        pass

class CompilationFileChecker(FileChecker):

    def __init__(self, compilation_handler: compilationhandler.CompilationHandler) -> None:
        self._compilation_handler = compilation_handler
    
    def check_file(self, file_path: str) -> bool:
        status_code = self._compilation_handler.compile_file(file_path, '/tmp/tmpfile_compilation_checker.exe')
        return status_code

class PyParserFileChecker(FileChecker):

    def check_file(self, file_path: str) -> bool:
        try:
            ast = pycparser.parse_file(
                file_path,
                use_cpp=True,
                cpp_path='cpp'
            )
            return True
        except Exception as e:
            return False
