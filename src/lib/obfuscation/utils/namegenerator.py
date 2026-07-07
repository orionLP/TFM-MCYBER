import enum
import abc
import dataclasses

from src.lib.crypto.rng import prng

'''

All names generated in this file follow the convention that they are made of CUSTOM + _ + type + _opaque

'''

@dataclasses.dataclass
class NameType():
    name_string: str | None

class VariableNameTypes(enum.Enum):
    TRUE = NameType('true_opaque')
    FALSE = NameType('false_opaque')
    PRIME = NameType('prime_opaque')
    RANDOM = NameType('random_opaque')
    USELESS = NameType('useless_opaque')
    COMPUTATION = NameType('computation_opaque')
    OTHER = NameType(None)

def is_type(variable_name: str, name_type: VariableNameTypes) -> bool:
    if name_type == VariableNameTypes.OTHER:
        for possible_type in VariableNameTypes:
            if possible_type != VariableNameTypes.OTHER and variable_name.endswith(possible_type.value.name_string):
                return False
        return True

    return variable_name.endswith(name_type.value.name_string)

def follows_format(name: str) -> bool:
    for available_type in VariableNameTypes:
        if available_type != VariableNameTypes.OTHER and is_type(name, available_type):
            return True
    return False

def variable_type(variable_name: str) -> VariableNameTypes:
    for available_type in VariableNameTypes:
        if is_type(variable_name, available_type):
            return available_type
    
    raise ValueError('Given string to variable_type that does not conform to variable name rules')

class NameGenerator(abc.ABC):

    def __init__(self, name_length) -> None:        
        self._name_length = name_length

    @abc.abstractmethod
    def generate_name(self) -> str:
        pass

class RandomNameGenerator(NameGenerator):

    def generate_name(self) -> str:
        return 'v' + prng.get_n_bytes(self._name_length).hex()

class VariableNameGenerator(abc.ABC):

    def __init__(self, *args) -> None:
        pass

    @abc.abstractmethod
    def generate_name(self, name_type: VariableNameTypes) -> str:
        pass

class StandardVariableNameGenerator(VariableNameGenerator):

    def __init__(self, *args) -> None:
        if len(args) != 1:
            raise ValueError("StandardVariableNameGenerator needs to be initalized with an int parameter")
        
        self._len_random_string = args[0]

    def generate_name(self, name_type: VariableNameTypes) -> str:
        random_part = prng.get_n_bytes(self._len_random_string)
        random_part = random_part.hex()

        return 'v' + random_part + '_' + name_type.value.name_string
