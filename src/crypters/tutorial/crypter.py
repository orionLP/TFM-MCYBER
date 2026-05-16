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
    KEY = 0xAA
    result = [0] * len(data)
    for i in range(0, len(data)):
        KEY = data[i] ^ KEY
        result[i] = KEY
    return result

# parser = argparse.ArgumentParser(description='Pack PE binary')
# parser.add_argument('input', metavar="FILE", help='input file')
# parser.add_argument('-p', metavar="UNPACKER", help='unpacker .exe', required=True)
# parser.add_argument('-o', metavar="FILE", help='output', default="packed.exe")

# args = parser.parse_args()

input_directory = "data/raw/exe/x86"
output_directory = "data/crypters/exe/x86/tutorial"
unpacker_path = "src/crypters/tutorial/decrypter.exe"

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

    builder = lief.PE.Builder(unpack_PE, lief.PE.Builder.config_t())
    builder.build()
    builder.write(output_filepath)
