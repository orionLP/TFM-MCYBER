import abc
import src.lib.isahandling.isa as isa
import src.lib.isahandling.x86instructionbuilder as x86instructionbuilder
from src.lib.crypto.rng import prng
import src.lib.isahandling.utils as utils

class FlowManglingObfuscator(abc.ABC):

    @abc.abstractmethod
    def obfuscate(self, instruction_list: list[isa.ISAInstruction]) -> None:
        pass

class StandardX86FlowManglingObfuscator(FlowManglingObfuscator):
   
    def __init__(self) -> None:
        self._builder = x86instructionbuilder.X86InstructionBuilder()

    def obfuscate(self, instruction_list: list[isa.ISAInstruction]) -> None:
        length_instruction_list = len(instruction_list)
        if length_instruction_list < 3:
            raise ValueError('obfuscate of StandardX86PUSH needs at least 3 instructions')

        starting_label_identifer = utils.get_max_label_identifier(instruction_list) + 1
        
        # both inclusive
        start_index = prng.get_range_unsigned_integer(length_instruction_list - 1, 1)
        length_mangled_instructions = prng.get_range_unsigned_integer(length_instruction_list - start_index, 1)
        index_instruction_after_mangle = start_index + length_mangled_instructions

        if instruction_list[index_instruction_after_mangle].label is None:
            instruction_list[index_instruction_after_mangle].label = isa.Label('flow mangle', starting_label_identifer)
            starting_label_identifer += 1
        after_mangle_instruction_label = instruction_list[index_instruction_after_mangle].label
        
        if instruction_list[start_index].label is None:
            instruction_list[start_index].label = isa.Label('flow mangle', starting_label_identifer)
            starting_label_identifer += 1
        first_mangled_instruction_label = instruction_list[start_index].label

        copy_of_mangled_instructions = instruction_list[start_index:index_instruction_after_mangle]
        del instruction_list[start_index:index_instruction_after_mangle]
        
        jump_to_after_mangle = self._builder.jmp_rel32(None, after_mangle_instruction_label) 
        jump_to_mangled_instructions = self._builder.jmp_rel32(None, first_mangled_instruction_label)

        instruction_list.insert(start_index, jump_to_mangled_instructions)
        copy_of_mangled_instructions.append(jump_to_after_mangle)

        length_instruction_list = len(instruction_list)
        index_copied_mangled = prng.get_range_unsigned_integer(length_instruction_list - 1, 1)
        if instruction_list[index_copied_mangled].label is None:
            instruction_list[index_copied_mangled].label = isa.Label('flow mangle', starting_label_identifer)
            starting_label_identifer += 1
        label_instruction_after_mangle = instruction_list[index_copied_mangled].label
        
        for instruction in reversed(copy_of_mangled_instructions):
            instruction_list.insert(index_copied_mangled, instruction)

        jump_bypass_mangled = self._builder.jmp_rel32(None, label_instruction_after_mangle)

        instruction_list.insert(index_copied_mangled, jump_bypass_mangled)


