import src.lib.isahandling.isa as isa

def get_jump_delta_between_instructions(instruction_list: list[isa.ISAInstruction], jumping_instruction_index: int, jump_to_instruction_index: int) -> int:
    delta = 0
    bytes_between_instructions = get_bytes_between_instructions(instruction_list, jumping_instruction_index, jump_to_instruction_index)
    if jump_to_instruction_index < jumping_instruction_index:
        delta = - (bytes_between_instructions + instruction_list[jump_to_instruction_index].size + instruction_list[jumping_instruction_index].size)
    elif jumping_instruction_index < jump_to_instruction_index:
        delta = bytes_between_instructions
    return delta
        
def get_bytes_between_instructions(instruction_list: list[isa.ISAInstruction], start_instruction_index: int, end_instruction_index: int) -> int:
    added_number_of_bytes = 0
    if end_instruction_index < start_instruction_index:
        for i in range(end_instruction_index + 1, start_instruction_index):
            added_number_of_bytes += instruction_list[i].size
    elif start_instruction_index < end_instruction_index:
        for i in range(start_instruction_index + 1, end_instruction_index):
            added_number_of_bytes += instruction_list[i].size
    return added_number_of_bytes

def get_instruction_index_by_label(instruction_list: list[isa.ISAInstruction], label_identifier: int) -> int:
    index = 0
    for instruction in instruction_list:
        if not instruction.label is None and instruction.label.identifier == label_identifier:
            return index
        index += 1
    raise ValueError('get_instruction_index_by_label given a label_identifier that does not exist')
    
def get_instruction_index_by_offset(instruction_list: list[isa.ISAInstruction], offset: int) -> int:
    total_size = 0
    index = 0
    while total_size < offset:
        total_size += instruction_list[index].size
        index += 1

    if total_size == offset:
        return index

    raise ValueError('get_instruction_index_by_offset has been given an offset that does not correspond to any instruction')
    
def get_signed_int(number: int, original_bytes_lenght: int) -> int:
    if original_bytes_lenght == 1:
        if number >= 0x80:
            return (0x100 - number) * (-1)
        else:
            return number
    elif original_bytes_lenght == 2:
        if number >= 0x8000:
            return (0x10000 - number) * (-1)
        else:
            return number
    elif original_bytes_lenght == 4:
        if number >= 0x80000000:
            return (0x100000000 - number) * (-1)
        else:
            return number
    raise ValueError('get_signed_int has been given a original_bytes_length it does not support')

def x86_extract_destination_register(instruction: bytes) -> int:
    """Extract destination register (0-7) from instruction bytes."""
    i = 0

    # Skip operand-size prefix
    if instruction[i] == 0x66:
        i += 1

    opcode = instruction[i]

    # MOV reg, imm: register in opcode
    if 0xB0 <= opcode <= 0xBF:
        return opcode & 0x07

    # All others: register in ModR/M byte
    modrm = instruction[i + 1]
    return modrm & 0x07
