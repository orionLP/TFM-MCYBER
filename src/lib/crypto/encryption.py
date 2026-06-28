import abc
import secrets

import numpy as np

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
    
    @property
    def decrypt_key(self) -> bytes:
        return self._decrypt_key
    
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
        return self._true_iv_length

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
        self._block_size = 16
        self._key_length = self._block_size
        self._true_iv_length = self._block_size
        self.iv_on = True
        if key is None:
            self.key = self._generate_valid_key()
        else:
            self.key = key

    def _matrix_to_bytes(self, matrix: np.ndarray) -> bytes:
        return matrix.astype(np.uint8).tobytes()
    
    def _bytes_to_matrix(self, buff: bytes) -> np.ndarray:
        dimension = round(self._block_size ** (1/2))
        return np.astype(np.frombuffer(buff, dtype=np.uint8).reshape(-1, dimension, dimension), np.int32)

    def _has_inverse_mod256(self, matrix: np.ndarray) -> bool:
        determinant = round(np.linalg.det(matrix))
        return (determinant % 2) == 1

    def _generate_valid_key(self) -> bytes:
        key = prng.get_n_bytes(self.key_length)
        key_matrix = self._bytes_to_matrix(key)[0]
        while not self._has_inverse_mod256(key_matrix):
            key = prng.get_n_bytes(self.key_length)
            key_matrix = self._bytes_to_matrix(key)[0]
        return key

    def _matrix_inverse_mod256(self, matrix: np.ndarray) -> np.ndarray:
        det = round(np.linalg.det(matrix))
        inv_det = pow(det % 256, -1, 256)
        adj = np.round(det * np.linalg.inv(matrix)).astype(np.int32)
        return (inv_det * adj) % 256

    @EncryptionAlgorithm.key.setter
    def key(self, new_key: bytes) -> None:
        if len(new_key) != self.key_length:
            raise ValueError(f'Tried to give SimpleMatrixEncryptionAlgorithm key with length different than {self._key_length}')

        new_matrix = self._bytes_to_matrix(new_key)[0]

        if not self._has_inverse_mod256(new_matrix):
            raise ValueError(f'Tried to give SimpleMatrixEncryptionAlgorithm key which has no inverse as a matrix 4x4 mod 256')

        self._key = new_key
        self._key_matrix = new_matrix
        self._decrypt_key_matrix = self._matrix_inverse_mod256(new_matrix)
        self._decrypt_key = self._matrix_to_bytes(self._decrypt_key_matrix)

    def encrypt(self, data: bytes) -> bytes:
        new_iv = prng.get_n_bytes(self.iv_length)
        padding_needed = self._block_size - (len(data) % self._block_size)

        final_data = new_iv + data + (b'\x00' * padding_needed)
        matrix_final_data = self._bytes_to_matrix()

        num_iterations = matrix_final_data.shape[0]
        for i in range(num_iterations - 1):
            matrix_final_data[i] = (matrix_final_data[i] @ self._key_matrix) % 256
            matrix_final_data[i + 1] = matrix_final_data[i + 1] ^  matrix_final_data[i]
        
        matrix_final_data[num_iterations - 1] = matrix_final_data[num_iterations - 1] @ self._key_matrix
        
        return self._matrix_to_bytes(matrix_final_data)

        

