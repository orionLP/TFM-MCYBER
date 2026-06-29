import enum
import abc

import src.lib.crypto.rng.prng as prng

class NameTypes(Enum.StrEnum):
    TRUE = 'true'
    FALSE = 'false'
    PRIME = 'prime'
    RANDOM = 'random'
    USELESS = 'useless'
    COMPUTATION = 'computation'

class NameGenerator(abc.ABC):

    def __init__(self, *args) -> None:
        pass

    @abc.abstractmethod
    def generate_name(self, name_type: NameTypes) -> str:
        pass

class StandardNameGenerator(NameGenerator):

    def __init__(self, *args) -> None:
        if len(args) != 1:
            raise ValueError("StandardNameGenerator needs to be initalized with an int parameter")
        
        self._len_random_string = args[0]

    def generate_name(self, name_type: NameTypes) -> str:
        random_part = prng.get_n_bytes(self._len_random_string)
        random_part = random_part.hex()

        return 'v' + random_part + '_' + name_type.value