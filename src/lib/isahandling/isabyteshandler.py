import abc
import src.lib.isahandling.instructionclassifier as instructionclassifier
import src.lib.isahandling.isa as isa
import src.lib.isahandling.x86instructionbuilder as x86instructionbuilder
import src.lib.isahandling.sequencing as sequencing
import src.lib.isahandling.instructionparser as instructionparser
import distorm3
from src.lib.crypto.rng import prng
import src.lib.isahandling.utils as utils

class ISAConversionHandler(abc.ABC):
    
    def convert_to_bytes(self, instructions_list: list[isa.ISAInstruction]) -> bytes:
        result_string = b''
        for next_instruction in instructions_list:
            result_string += next_instruction.instruction_bytes
        return result_string

    @abc.abstractmethod
    def convert_to_instructions(self, bytes_string: bytes) -> list[isa.ISAInstruction]:
        pass

class X86ISAConversionHandler(ISAConversionHandler):
    
    def __init__(self):
        self._classifier = instructionclassifier.X86InstructionClassifier()
        self._parser = instructionparser.X86InstructionParser()
        self._sequencer = sequencing.X86SequencingHandler()
        self._builder = x86instructionbuilder.X86InstructionBuilder()
        self._label_index = 0

    def _parse_jumps(self, instruction_list: list[isa.ISAInstruction]) -> None:
        offset = 0
        for instruction in instruction_list:
            if self._sequencer.is_relative_jump(instruction):
                delta = self._sequencer.relative_jump_delta(instruction)
                instruction_to_jump = offset + delta + instruction.size
                index = utils.get_instruction_index_by_offset(instruction_list, instruction_to_jump)
                if instruction_list[index].label is None:
                    instruction_list[index].label = isa.Label('jump_to', self._label_index)
                    self._label_index += 1
                instruction.jump_label = instruction_list[index].label
            offset += instruction.size

    def _clean_instructions(self, instruction_list: list[isa.ISAInstruction]) -> None:
        index = 0
        current_length = len(instruction_list)
        while index < current_length:
            if instruction_list[index].identified_function == isa.X86Instructions.LOOPrel8:
                dec_ecx = self._builder.dec_ecx(instruction_list[index].label)
                jnz_rel8 = self._builder.jnz_rel8(None, instruction_list[index].jump_label)
                del instruction_list[index]
                instruction_list.insert(index,jnz_rel8)
                instruction_list.insert(index, dec_ecx)
            elif instruction_list[index].identified_function == isa.X86Instructions.JECXZrel8:
                test_ecx_ecx = self._builder.test_ecx_ecx(instruction_list[index].label)
                jz_rel8 = self._builder.jz_rel8(None, instruction_list[index].jump_label)
                del instruction_list[index]
                instruction_list.insert(index, jz_rel8)
                instruction_list.insert(index, test_ecx_ecx)
            elif instruction_list[index].identified_function in [isa.X86Instructions.LOOPNErel8, isa.X86Instructions.LOOPErel8]:
                instruction_label = instruction_list[index].label
                jump_to_instruction_label = instruction_list[index].jump_label
                self._label_index += 1
                dec_label = self._label_index
                self._label_index += 1
                nop_label = self._label_index
                conditional_to_add = None
                if instruction_list[index].identified_function == isa.X86Instructions.LOOPNErel8:
                    conditional_to_add = self._builder.jnz_rel8(instruction_label, dec_label)
                else:
                    conditional_to_add = self._builder.jz_rel8(instruction_label, dec_label)

                del instruction_list[index]
                
                nop = self._builder.nop(nop_label)
                last_dec_ecx = self._builder.dec_ecx(dec_label)
                jmp_rel32 = self._builder.jmp_rel32(None, jump_to_instruction_label)
                jz_rel8 = self._builder.jz_rel8(None, dec_label)
                first_dec_ecx = self._builder.dec_ecx(None)

                instruction_list.insert(index, nop)
                instruction_list.insert(index, last_dec_ecx)
                instruction_list.insert(index, jmp_rel32)
                instruction_list.insert(index, jz_rel8)
                instruction_list.insert(index, first_dec_ecx)
                instruction_list.insert(index, conditional_to_add)

            index += 1
            current_length = len(instruction_list)
        self._sequencer.fix_jumps(instruction_list)

    def convert_to_instructions(self, bytes_string: bytes) -> list[isa.ISAInstruction]:
        result_list = []
        decoded_instructions = distorm3.Decode(0, bytes_string, distorm3.Decode32Bits)
        for (offset, size, instr, hexdump) in decoded_instructions:
            result_list.append(
                    isa.ISAInstruction(
                        bytes_string[offset:offset+size],
                        size,
                        None,
                        None,
                        isa.AvailableISA.X86,
                        self._classifier.classify(bytes_string[offset:offset+size]),
                        self._parser.parse(bytes_string[offset:offset+size])
                    )
            )
        
        self._parse_jumps(result_list)
        self._clean_instructions(result_list)

        return result_list
