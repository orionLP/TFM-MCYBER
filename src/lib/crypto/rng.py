import abc
import secrets
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

    @abc.abstractmethod
    def get_uchar(self) -> int:
        pass
    
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
        
    def get_uchar(self) -> int:
        return int.from_bytes(self.get_n_bytes(1))

    def commit_changes(self) -> None:
        self._cipher = ChaCha20.new(key=self._key, nonce=self._nonce)

prng: PRNG = ChaCha20PRNG()