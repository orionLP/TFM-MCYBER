import abc
import subprocess
import pycparser

class FileChecker(abc.ABC):

    @abc.abstractmethod
    def check_file(self, file_path: str) -> bool:
        pass

class CompilationFileChecker(FileChecker):

    def __init__(self, library_commands: list[str]) -> None:
        self._libraries = library_commands
    
    def check_file(self, file_path: str) -> bool:
        try:
            cmd = ["clang", "--target=i686-pc-windows-gnu", "-o", "/tmp/tmpfile_compilation_checker.exe"] + self._libraries + [file_path]

            result = subprocess.run(
                cmd,
                capture_output=True,
                timeout=30
            )
 
            return result.returncode == 0
        except Exception as e:
            return False

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