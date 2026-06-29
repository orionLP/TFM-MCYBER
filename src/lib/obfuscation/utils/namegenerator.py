import enum
import abc

from src.lib.crypto.rng import prng

'''

All names generated in this file follow the convention that they are made of CUSTOM + _ + type + _opaque

'''


class VariableNameTypes(enum.StrEnum):
    TRUE = 'true'
    FALSE = 'false'
    PRIME = 'prime'
    RANDOM = 'random'
    USELESS = 'useless'
    COMPUTATION = 'computation'

class VariableNameGenerator(abc.ABC):

    def __init__(self, *args) -> None:
        pass

    @abc.abstractmethod
    def generate_name(self, name_type: VariableNameTypes) -> str:
        pass

class StandardVariableNameGenerator(VariableNameGenerator):

    def __init__(self, *args) -> None:
        if len(args) != 1:
            raise ValueError("VariableNameGenerator needs to be initalized with an int parameter")
        
        self._len_random_string = args[0]

    def generate_name(self, name_type: VariableNameTypes) -> str:
        random_part = prng.get_n_bytes(self._len_random_string)
        random_part = random_part.hex()

        return 'v' + random_part + '_' + name_type.value + '_opaque'