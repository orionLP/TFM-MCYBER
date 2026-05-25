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

def pack_data(data):
    result = [0] * len(data)

    key = [64, 122, 39, 136, 79, 179, 145, 80, 220, 25, 31, 22, 165, 204, 59, 187, 139, 76, 113, 81, 100, 8, 201, 91, 107, 143, 43, 30, 186, 78, 19, 167, 46, 26, 83, 231, 41, 103, 119, 203, 205, 4, 162, 250, 86, 101, 133, 200, 156, 195, 144, 0, 112, 149, 108, 12, 157, 213, 77, 142, 68, 193, 166, 242, 7, 18, 28, 182, 84, 14, 116, 154, 56, 176, 206, 53, 221, 252, 243, 124, 211, 194, 35, 104, 62, 66, 15, 63, 23, 212, 226, 128, 218, 2, 246, 137, 210, 164, 102, 51, 17, 169, 214, 92, 253, 197, 73, 215, 127, 33, 192, 95, 244, 189, 109, 161, 131, 199, 60, 146, 72, 175, 61, 37, 239, 24, 1, 58, 38, 236, 241, 177, 180, 20, 5, 235, 88, 230, 110, 184, 52, 117, 49, 174, 85, 97, 106, 114, 13, 89, 190, 254, 148, 118, 227, 237, 65, 158, 40, 217, 178, 105, 94, 255, 163, 71, 10, 93, 27, 208, 147, 172, 183, 160, 126, 188, 45, 233, 29, 48, 229, 6, 36, 170, 50, 67, 196, 151, 240, 129, 202, 90, 98, 57, 141, 130, 198, 99, 111, 120, 140, 96, 16, 123, 32, 70, 159, 125, 207, 173, 134, 222, 216, 234, 132, 42, 153, 181, 249, 47, 225, 75, 168, 171, 82, 228, 21, 238, 150, 224, 11, 245, 191, 69, 155, 209, 248, 54, 232, 55, 247, 9, 44, 219, 185, 138, 251, 223, 34, 121, 115, 74, 152, 135, 3, 87]
    for i in range(0, len(data)):
        result[i] = key[data[i]]

    KEY = 0xCB
    for i in range(0, len(data)):
        KEY = result[i] ^ KEY
        result[i] = KEY

    key2 = [197, 66, 207, 74, 209, 99, 123, 98, 10, 120, 12, 129, 214, 89, 68, 187, 71, 191, 87, 81, 45, 130, 47, 17, 172, 215, 5, 212, 113, 77, 192, 185, 180, 253, 78, 114, 102, 60, 142, 146, 64, 8, 73, 27, 134, 2, 128, 32, 57, 217, 55, 119, 83, 174, 239, 226, 177, 246, 166, 124, 211, 85, 21, 40, 107, 149, 228, 210, 188, 132, 251, 243, 4, 1, 156, 90, 157, 224, 118, 65, 50, 105, 116, 131, 29, 213, 133, 75, 79, 229, 206, 250, 58, 193, 24, 16, 220, 254, 247, 216, 222, 240, 242, 230, 202, 56, 35, 76, 62, 176, 51, 249, 145, 143, 20, 126, 70, 169, 167, 125, 195, 138, 159, 140, 190, 82, 97, 49, 110, 25, 148, 184, 18, 218, 115, 96, 227, 67, 203, 91, 232, 255, 196, 19, 153, 69, 7, 37, 53, 144, 231, 100, 30, 238, 147, 6, 34, 93, 14, 165, 164, 194, 0, 28, 80, 46, 248, 162, 22, 15, 208, 139, 109, 117, 141, 136, 237, 59, 163, 223, 26, 52, 23, 252, 41, 245, 151, 170, 95, 84, 219, 3, 92, 200, 201, 111, 205, 171, 158, 39, 72, 122, 234, 48, 108, 44, 155, 181, 94, 101, 199, 43, 135, 63, 86, 225, 103, 236, 152, 42, 112, 160, 186, 235, 244, 198, 104, 137, 183, 121, 189, 38, 13, 31, 127, 233, 204, 178, 168, 11, 9, 221, 106, 154, 175, 61, 161, 36, 88, 179, 150, 33, 241, 54, 182, 173]
    for i in range(0, len(data)):
        result[i] = key2[result[i]]

    return result

# parser = argparse.ArgumentParser(description='Pack PE binary')
# parser.add_argument('input', metavar="FILE", help='input file')
# parser.add_argument('-p', metavar="UNPACKER", help='unpacker .exe', required=True)
# parser.add_argument('-o', metavar="FILE", help='output', default="packed.exe")

# args = parser.parse_args()

input_directory = "data/raw/exe/x86"
output_directory = "data/crypters/exe/x86/tutorial_sbox"
unpacker_path = "src/crypters/tutorial_sbox/decrypter.exe"

os.makedirs(output_directory, exist_ok=True)

for file in os.listdir(input_directory):
    input_filepath = input_directory + "/" + file
    output_filepath = output_directory + "/" + file

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
    packed_data = pack_data(packed_data)
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

# config = lief.PE.Builder.config_t()
# config.imports      = False   # don't rewrite IAT
# config.relocations  = False   # don't rewrite relocs
# config.exports      = False
# config.resources    = False
# config.overlay      = True
    builder = lief.PE.Builder(unpack_PE, lief.PE.Builder.config_t())
    builder.build()
    builder.write(output_filepath)
