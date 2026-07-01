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
    def variables_in_scope(self) -> int:
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
    def variables_in_scope(self) -> int:
        return len(self.scope_list)
    
    @property
    def depth(self) -> int:
        return len(self._scope)

    @property
    def scope_dict(self) -> dict[namegenerator.VariableNameTypes, list[str]]:
        # return_dict = {possible_type: [] for possible_type in namegenerator.VariableNameTypes}
        return_dict = {}
        for block in self._scope:
            for block_variable in block:
                this_type = namegenerator.variable_type(block_variable)
                if not this_type in return_dict:
                    return_dict[this_type] = []
                return_dict[this_type].append(block_variable)
        return return_dict

    @property
    def scope_list(self) -> list[str]:
        return_list = []
        for block in self._scope:
            for block_variable in block:
                return_list.append(block_variable)
        return return_list

def _is_initalized_variable(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.Decl) and node.init is not None

def first_line_with_variable(block: pycparser.c_ast.Compound) -> int | None:
    for i in range(len(block.block_items)):
        if _is_initalized_variable(block.block_items[i]):
            return i
    return None        

def defined_variables_to_line(block: pycparser.c_ast.Compound, item_line: int) -> list[str]:
    '''Defined variables between [0,item_line)'''
    
    if(item_line > len(block.block_items)):
        raise ValueError("defined_variables_to_line given an item_line out of index")
    
    return_list = []
    for i in range(item_line):
        node = block.block_items[i]
        if _is_initalized_variable(node):
            return_list.append(node.name)
    return return_list