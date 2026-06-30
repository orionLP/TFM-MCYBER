import abc
import pycparser

from src.lib.crypto.rng import prng
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator

class Scope(abc.ABC):
    
    @abc.abstractmethod
    def __init__(self) -> None:
        pass

    @abc.abstractmethod
    def enter_block(self) -> None:
        pass
    
    @abc.abstractmethod
    def exit_block(self) -> None:
        pass
    
    @abc.abstractmethod
    def add_variable(self, variable_name: str) -> None:
        pass
    
    @property
    @abc.abstractmethod
    def depth(self) -> int:
        pass

    @property
    @abc.abstractmethod
    def scope_dict(self) -> dict[namegenerator.VariableNameTypes, list[str]]:
        pass

    @property
    def scope_list(self) -> list[str]:
        pass

class StandardScope(Scope):

    def __init__(self) -> None:
        self._scope = []

    def enter_block(self) -> None:
        self._scope.append([])

    def exit_block(self) -> None:
        del self._scope[-1]

    def add_variable(self, variable_name: str) -> None:
        self._scope[-1].append(variable_name)

    @property
    def depth(self) -> int:
        return len(self._scope)

    @property
    def scope_dict(self) -> dict[namegenerator.VariableNameTypes, list[str]]:
        return_dict = {possible_type: [] for possible_type in namegenerator.VariableNameTypes}
        for block in self._scope:
            for block_variable in block:
                return_dict[namegenerator.variable_type(block_variable)].append(block_variable)
        return return_dict

    @property
    def scope_list(self) -> list[str]:
        return_list = []
        for block in self._scope:
            for block_variable in block:
                return_list.append(block_variable)
        return return_list

def defined_variables_to_line(block: pycparser.c_ast.Compound, item_line: int) -> list[str]:
    return_list = []
    for node in block.block_items:
        if node is pycparser.c_ast.Decl and node.init is not None:
            return_list.append(node.name)
    return return_list