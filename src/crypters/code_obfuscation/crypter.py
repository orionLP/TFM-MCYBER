import argparse
import os

def matrix_xor(mat1, mat2):
    xor_result = [[0 for j in range(4)] for i in range(4)]
    for i in range(4):
        for j in range(4):
            xor_result[i][j] = mat1[i][j] ^ mat2[i][j]
    return xor_result

def matrix_mul(mat1, mat2):
    mul_result = [[0 for j in range(4)] for i in range(4)]
    for i in range(4):
        for j in range(4):
            for k in range(4):
                mul_result[i][j] += mat1[i][k] * mat2[k][j]
            mul_result[i][j] = mul_result[i][j] % 256
    return mul_result

def array_sub(array1, array2):
    return [(array1[i] - array2[i]) % 256 for i in range(16)]

def array_add(dest, constant, start_index, amount):
    for i in range(amount):
        dest[i + start_index] += constant
        dest[i + start_index] %= 256
    
def array_mult(dest, constant, start_index, amount):
    for i in range(amount):
        dest[i + start_index] *= constant
        dest[i + start_index] %= 256

def arrays_xor(dest, source, dest_index_start, source_index_start, amount):
    for i in range(amount):
        dest[dest_index_start + i] ^= source[source_index_start + i]

def array_xor(dest, constant, start_index, amount):
    for i in range(amount):
        dest[i + start_index] ^= constant

key1_matrix = [
    [  112,    42,   123,   202 ],
    [  153,   128,   168,    93 ],
    [  116,   191,     4,   160 ],
    [  247,   192,   100,   116 ]
]

def enc_algo1(data):

    key_matrix = key1_matrix

    result = [byte_data for byte_data in data]

    number_multiplications = len(data) // 16
    bytes_remaining = len(data) % 16

    data_matrix = None
    last_matrix = None
    for i in range(number_multiplications):
        data_matrix = [[result[j] for j in range(k * 4, (k + 1) * 4)] for k in range(i * 4, (i + 1) * 4)]
        if i != 0:
            data_matrix = matrix_xor(data_matrix, last_matrix)
        last_matrix = matrix_mul(data_matrix, key_matrix)
        for k in range(i * 4, (i+1) * 4):
            for j in range(k * 4, (k+1) * 4):
                result[j] = last_matrix[(j % 16) // 4][(j%16) % 4]

    for i in range(number_multiplications - 1):
        result[i * 16:(i+1) * 16] = array_sub(result[i * 16:(i+1) * 16], result[(number_multiplications - 1) * 16: number_multiplications * 16])
    
    for i in range(0, bytes_remaining // 4 + 1):
        j_range = 4
        if i == (bytes_remaining // 4):
            j_range = bytes_remaining % 4
        for j in range(j_range):
            result[(len(data) - (len(data) % 16)) + (i * 4) + j] = result[(len(data) - (len(data) % 16)) + (i * 4) + j] ^ last_matrix[i][j] 

    return result

parser = argparse.ArgumentParser(description='Encrypt PE binary and output as C source file')
parser.add_argument('input', metavar="INFILE", help='input file')
parser.add_argument('-o', metavar="OUTFILE", help='output file')

args = parser.parse_args()

input_file = args.input
output_file = args.o

print('----------------------------INPUTS-----------------------------')
print(' ')
print(f'The selected data is {input_file}')
print(f'The output directory is {output_file}')
print(' ')
print('--------------------------RUNNING------------------------------')
print(' ')

with open(input_file, "rb") as f:
    input_PE_data = f.read()

encrypted_data = list(input_PE_data)
encrypted_data = enc_algo1(encrypted_data)
size = len(encrypted_data)
bytes_str = "".join(f"\\x{b:02x}" for b in encrypted_data)

c_source = f'#include "executable.h"\n'
c_source += f'char executable_pe[] = "{bytes_str}";\n'
c_source += f'DWORD executable_size = {size};\n'

with open(output_file, "w") as f:
    f.write(c_source)

print(f'Written {size} bytes to {output_file}')
print(' ')