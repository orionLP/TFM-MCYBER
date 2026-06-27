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
    
    @property
    def nonce(self) -> bytes | None:
        return self._nonce
    
    @abc.abstractmethod
    def get_uchar(self) -> int:
        pass

CHACHA20_KEY_LENGTH = 32
CHACHA20_NONCE_LENGTH = 12

class ChaCha20PRNG(PRNG):

    def __init__(self, key: bytes = None, nonce: bytes = None) -> None:
        if key is None:
            self._key = secrets.token_bytes(CHACHA20_KEY_LENGTH)
        else:
            self._key = key
        
        if nonce is None:
            self._nonce = secrets.token_bytes(CHACHA20_NONCE_LENGTH)
        else:
            self._nonce = nonce
        
        self._cipher = ChaCha20.new(key=self._key, nonce=self._nonce)

    def _get_n_keystream_bytes(self, n: int) -> bytes:
        return self._cipher.encrypt(b'\x00' * n)

    def get_uchar(self) -> int:
        return int.from_bytes(self._get_n_keystream_bytes(1))

prng = ChaCha20PRNG()