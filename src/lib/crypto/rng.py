import abc
import secrets
from Crypto.Cipher import ChaCha20

class PRNG(abc.ABC):

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
    
    @nonce.setter
    @abc.abstractmethod
    def nonce(self, new_nonce: bytes) -> None:
        pass

    @abc.abstractmethod
    def get_uchar(self) -> int:
        pass
    
    @abc.abstractmethod
    def commit_changes(self) -> None:
        pass

CHACHA20_KEY_LENGTH = 32
CHACHA20_NONCE_LENGTH = 12

class ChaCha20PRNG(PRNG):

    def __init__(self, key: bytes = None, nonce: bytes = None) -> None:
        if key is None:
            self.key = secrets.token_bytes(CHACHA20_KEY_LENGTH)
        else:
            self.key = key
        
        if nonce is None:
            self.nonce = secrets.token_bytes(CHACHA20_NONCE_LENGTH)
        else:
            self.nonce = nonce
        
        self._cipher = ChaCha20.new(key=self._key, nonce=self._nonce)

    @PRNG.key.setter
    def key(self, new_key: bytes) -> None:
        if len(new_key) != CHACHA20_KEY_LENGTH:
            raise ValueError(f'Tried to give ChaCha20PRNG key with length different than {CHACHA20_KEY_LENGTH}')

        self._key = new_key

    @PRNG.nonce.setter
    def nonce(self, new_nonce: bytes) -> None:
        if len(new_nonce) != CHACHA20_NONCE_LENGTH:
            raise ValueError(f'Tried to give ChaCha20PRNG nonce with length different than {CHACHA20_NONCE_LENGTH}')

        self._nonce = new_nonce

    def _get_n_keystream_bytes(self, n: int) -> bytes:
        return self._cipher.encrypt(b'\x00' * n)

    def get_uchar(self) -> int:
        return int.from_bytes(self._get_n_keystream_bytes(1))

    def commit_changes(self) -> None:
        self._cipher = ChaCha20.new(key=self._key, nonce=self._nonce)

prng: PRNG = ChaCha20PRNG()