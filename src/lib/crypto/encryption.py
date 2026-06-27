import abc
import secrets
from src.lib.crypto.rng import prng

class EncryptionAlgorithm(abc.ABC):
    '''
    EncryptionAlgorithm represents encryption algorithms. It is assumed that all algorithms need a key. IVs are handled by the class itself, and returned to 
    the client with the ciphertext if necessary. The length of the IV is given by iv_length. An iv length of 0 simply means that the algorithm does not
    use an IV. You can turn on and off using an IV if necessary (if an algorithm always requires an IV, then it is set to a constant) (if turned off, length is
    set to 0). If no key is given a valid one is generated randomly using prng.
    '''
    
    @abc.abstractmethod
    def __init__(self, key: bytes | None) -> None:
        pass

    @property
    def key(self) -> bytes:
        return self._key
    
    @key.setter
    @abc.abstractmethod
    def key(self, new_key: bytes) -> None:
        pass

    @property
    def key_length(self) -> int:
        return self._key_length

    @property
    def iv_length(self) -> int:
        if not self.iv_on:
            return 0
        return self._iv_length

    @property
    def iv_on(self) -> bool:
        return self._iv_on

    @iv_on.setter
    def iv_on(self, new_state: bool) -> None:
        self._iv_on = new_state
    
    @abc.abstractmethod
    def encrypt(self, data: bytes) -> bytes:
        pass

class SimpleMatrixEncryptionAlgorithm(EncryptionAlgorithm):

    def __init__(self, key: bytes | None) -> None:
        self._key_length = 16
        self._iv_length = 16
        self.iv_on = True
        if key is None:
            self.key = secrets.token_bytes(self._key_length)
        else:
            self.key = key

    @EncryptionAlgorithm.key.setter
    def key(self, new_key: bytes) -> None:
        if len(new_key) != self._key_length:
            raise ValueError(f'Tried to give SimpleMatrixEncryptionAlgorithm key with length different than {self._key_length}')