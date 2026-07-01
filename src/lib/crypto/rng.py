import abc
import secrets
import math
import copy

from typing import Any
from Crypto.Cipher import ChaCha20

class PRNG(abc.ABC):
    '''
    PRNG represents pseudo-random number generators. It is assumed that PRNGs need a key (seed) and optionally a nonce.
    '''

    @abc.abstractmethod
    def __init__(self, key: bytes = None, nonce: bytes = None) -> None:
        pass

    @property
    def key(self) -> bytes:
        return self._key
    
    @key.setter
    @abc.abstractmethod
    def key(self, new_key: bytes) -> None:
        pass

    @property
    def nonce(self) -> bytes | None:
        return self._nonce
    
    @property
    def key_length(self) -> int:
        return self._key_length
    
    @property
    def nonce_length(self) -> int:
        return self._nonce_length

    @nonce.setter
    @abc.abstractmethod
    def nonce(self, new_nonce: bytes | None) -> None:
        pass

    @abc.abstractmethod
    def get_n_bytes(self, n: int) -> bytes:
        pass

    def get_unsigned_integer(self, number_bytes: int) -> int:
        return int.from_bytes(self.get_n_bytes(number_bytes), byteorder = 'little', signed = False)
    
    def get_range_unsigned_integer(self, upper_limit: int, lower_limit: int | None = None) -> int:
        '''Number between [0,upper_limit) if lower_limit is none and [lower_limit, upper_limit) otherwise'''
        effective_range = None
        if lower_limit is None:
            effective_range = upper_limit
        else:
            effective_range = upper_limit - lower_limit

        needed_bytes = math.ceil(effective_range.bit_length() / 8)
        number_in_range = self.get_unsigned_integer(needed_bytes) % effective_range

        if lower_limit is None:
            return number_in_range
        else:
            return number_in_range + lower_limit

    def random_choice(self, item_list: list[Any]) -> Any:
        list_length = len(item_list)
        return item_list[self.get_range_unsigned_integer(list_length)]

    def random_selection(self, item_list: list[Any], number_of_items: int) -> list[Any]:
        if number_of_items > len(item_list):
            raise ValueError("Given PRNG a number_of_items too big for the list")
        if number_of_items < 0:
            raise ValueError("Given PRNG a negative number_of_items")
        
        new_list = copy.deepcopy(item_list)

        while len(new_list) != number_of_items:
            random_index = self.get_range_unsigned_integer(len(new_list))
            del new_list[random_index]

        return new_list

    def chance(self, probability: float) -> bool:
        chosen = self.get_range_unsigned_integer(100 + 1) / 100
        return probability < chosen

    def get_uchar(self) -> int:
        return self.get_unsigned_integer(1)
    
    @abc.abstractmethod
    def commit_changes(self) -> None:
        pass

class ChaCha20PRNG(PRNG):
    '''
    ChaCha20PRNG is a PRNG based on the ChaCha20 algorithm. It works by simply extracting the keystream of chacha20 by encrypting 0 bytes.
    '''

    def __init__(self, key: bytes = None, nonce: bytes = None) -> None:
        self._key_length = 32
        self._nonce_length = 12

        if key is None:
            self.key = secrets.token_bytes(self._key_length)
        else:
            self.key = key
        
        self.nonce = nonce
        
        self.commit_changes()

    @PRNG.key.setter
    def key(self, new_key: bytes) -> None:
        if len(new_key) != self._key_length:
            raise ValueError(f'Tried to give ChaCha20PRNG key with length different than {self._key_length}')

        self._key = new_key

    @PRNG.nonce.setter
    def nonce(self, new_nonce: bytes | None) -> None:
        if new_nonce is None:
            self._nonce = secrets.token_bytes(self._nonce_length)
        else:
            if len(new_nonce) != self._nonce_length:
                raise ValueError(f'Tried to give ChaCha20PRNG nonce with length different than {self._nonce_length}')

            self._nonce = new_nonce

    def get_n_bytes(self, n: int) -> bytes:
        return self._cipher.encrypt(b'\x00' * n)
    
    def commit_changes(self) -> None:
        self._cipher = ChaCha20.new(key=self._key, nonce=self._nonce)

prng: PRNG = ChaCha20PRNG()