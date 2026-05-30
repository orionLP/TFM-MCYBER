import argparse
import lief
import os

def align(x, al):
    """ return <x> aligned to <al> """
    if x % al == 0:
        return x
    else:
        return x - (x % al) + al

def pad_data(data, al):
    """ return <data> padded with 0 to a size aligned with <al> """
    return data + ([0] * (align(len(data), al) - len(data)))

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

def pad_data(data, al):
    """ return <data> padded with 0 to a size aligned with <al> """
    return data + ([0] * (align(len(data), al) - len(data)))

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

key2_matrix = [
    [  86,    50,    61,   169 ],
    [  10,    80,   242,    15 ],
    [  23,   242,   243,    61 ],
    [ 217,    37,     9,   134 ]
]

key3_matrix = [
    [ 33,   1,    241,   173 ],
    [ 58,   53,   166,   191 ],
    [ 194,  8,    143,   232 ],
    [ 126,  84,   75,    149 ]
]

def enc_algo1(data, key2_use):
    print(f'Running matrix algorithm')
    print(f'Which key will be used? {key2_use}')
    print(' ')

    key_matrix = key1_matrix

    if key2_use == 2:
        key_matrix = key2_matrix
    if key2_use == 3:
        key_matrix = key3_matrix

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

key1_constant_1 = 214
key1_constant_2 = 97

key2_constant_1 = 46
key2_constant_2 = 217

key3_constant_1 = 1
key3_constant_2 = 127

def enc_algo2(data, key2_use):
    print(f'Running constants algorithm')
    print(f'Which key will be used? {key2_use}')
    print(' ')

    constant_1 = key1_constant_1
    constant_2 = key1_constant_2
    if key2_use == 2:
        constant_1 = key2_constant_1
        constant_2 = key2_constant_2
    if key2_use == 3:
        constant_1 = key3_constant_1
        constant_2 = key3_constant_2


    result = [byte_data for byte_data in data]

    number_iterations = len(data) // 16
    bytes_remaining = len(data) % 16
    

    for i in range(number_iterations):
        if i != 0:
            arrays_xor(result, result, i * 16, (i - 1) * 16, 16)

        array_add(result, constant_1, i * 16, 16)
        array_mult(result, constant_2, i * 16, 16)

    array_add(result, constant_1, number_iterations * 16, bytes_remaining)
    array_mult(result, constant_2, number_iterations * 16, bytes_remaining)
    arrays_xor(result, result, number_iterations * 16, (number_iterations - 1) * 16, bytes_remaining)

    sum_constant = sum(result[(number_iterations - 1) * 16:(number_iterations) * 16]) % 256
    for i in range(number_iterations - 1):
        arrays_xor(result, result, i * 16, (number_iterations - 1) * 16, 16)
        array_xor(result, sum_constant, i * 16, 16)

    return result

parser = argparse.ArgumentParser(description='Pack PE binary')
parser.add_argument('input', metavar="INDIR", help='input directory')
parser.add_argument('-p', metavar="DECRYPTER", help='decrypter exe')
parser.add_argument('-o', metavar="DIR", help='output_directory')
parser.add_argument(
    "--KEY",
    type=int,
    choices=[1, 2, 3],
    default=1,
    help="Select encryption key (1, 2, or 3)"
)
parser.add_argument("--algo2", action="store_true")

args = parser.parse_args()

input_directory = args.input      # "data/raw/exe/x86"
output_directory = args.o         # "data/crypters/exe/x86/multiple_information_reveal/algo1"
unpacker_path = args.p            # "src/crypters/multiple_information_reveal/decrypter.exe"
key2_use = args.KEY
algo2_use = args.algo2

print('----------------------------INPUTS-----------------------------')
print(' ')

print(f'The selected data is {input_directory}')
print(f'The output directory is {output_directory}')
print(f'The selected decryption/unpacking executable is {unpacker_path}')
print(f'Key number 2 will be used {key2_use}, default is key 1')
print(f'Constant encryption will be used {algo2_use}, default is matrix')

print(' ')
print('--------------------------RUNNING------------------------------')
print(' ')

os.makedirs(output_directory, exist_ok=True)

for file in os.listdir(input_directory):
    input_filepath = input_directory + "/" + file
    output_filepath = output_directory + "/" + file

    print(f'Processing file {input_filepath}')
    print(f'Output file {output_filepath}')

    # open the unpack.exe binary
    unpack_PE = lief.PE.parse(unpacker_path)

    # we're going to keep the same alignment as the ones in unpack_PE,
    # because this is the PE we are modifying
    file_alignment = unpack_PE.optional_header.file_alignment
    section_alignment = unpack_PE.optional_header.section_alignment
    # read the whole file to be packed
    with open(input_filepath, "rb") as f:
        input_PE_data = f.read()

    packed_data = list(input_PE_data) # lief expects a list, not a "bytes" object.
    if algo2_use:
        packed_data = enc_algo2(packed_data, key2_use)
    else:
        packed_data = enc_algo1(packed_data, key2_use)
    packed_data = pad_data(packed_data, file_alignment) # pad with 0 to align with file alignment (removes a lief warning)

    packed_section = lief.PE.Section(".packed")
    packed_section.content =  packed_data
    packed_section.size = len(packed_data)
    packed_section.characteristics = 0xC0000040  # MEM_READ | MEM_WRITE | CNT_INITIALIZED_DATA
    # We don't need to specify a Relative Virtual Address here, lief will just put it at the end, that doesn't matter.
    unpack_PE.add_section(packed_section)

    # remove the SizeOfImage, which should change, as we added a section. Lief will compute this for us.
    unpack_PE.optional_header.sizeof_image = 0


    # save the resulting PE
    if(os.path.exists(output_filepath)):
        # little trick here : lief emits no warning when it cannot write because the output
        # file is already opened. Using this function ensure we fail in this case (avoid errors).
        os.remove(output_filepath)

    builder = lief.PE.Builder(unpack_PE, lief.PE.Builder.config_t())
    builder.build()
    builder.write(output_filepath)
