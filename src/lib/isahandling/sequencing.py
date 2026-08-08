import abc
import src.lib.isahandling.isa as isa
import src.lib.isahandling.utils as utils
import src.lib.isahandling.x86instructionbuilder as x86instructionbuilder
import struct
import copy

class SequencingHandler(abc.ABC):
    
    @abc.abstractmethod
    def is_relative_jump(self, instruction: isa.ISAInstruction) -> bool:
        pass

    @abc.abstractmethod
    def relative_jump_length(self, instruction: isa.ISAInstruction) -> int:
        pass

    @abc.abstractmethod
    def relative_jump_delta(self, instruction: isa.ISAInstruction) -> int:
        pass

    @abc.abstractmethod
    def modify_jump_delta(self, instruction_list: list[isa.ISAInstruction], instruction_index: int, delta: int) -> None:
        pass

    def fix_jump(self, instruction_list: list[isa.ISAInstruction], jumping_instruction_index: int) -> None:
        jump_to_label_identifier = instruction_list[jumping_instruction_index].jump_label.identifier
        jump_to_instruction_index = utils.get_instruction_index_by_label(instruction_list, jump_to_label_identifier)
        new_delta = utils.get_jump_delta_between_instructions(instruction_list, jumping_instruction_index, jump_to_instruction_index)
        self.modify_jump_delta(instruction_list, jumping_instruction_index, new_delta)

    def _fix_jumps_individual_step(self, instruction_list: list[isa.ISAInstruction]) -> None:
         for i in range(len(instruction_list)):
            if not instruction_list[i].jump_label is None:
                self.fix_jump(instruction_list, i)

    def fix_jumps(self, instruction_list: list[isa.ISAInstruction]) -> None:
        copied_code = copy.deepcopy(instruction_list)
        self._fix_jumps_individual_step(instruction_list)
        while copied_code != instruction_list:
            copied_code = copy.deepcopy(instruction_list)
            self._fix_jumps_individual_step(instruction_list)

class X86SequencingHandler(SequencingHandler):
     
    def __init__(self) -> None:
        self._jumping_instructions = {
            isa.X86Instructions.Jccrel8,
            isa.X86Instructions.LOOPrel8,
            isa.X86Instructions.LOOPNErel8,
            isa.X86Instructions.LOOPErel8,
            isa.X86Instructions.JECXZrel8,
            isa.X86Instructions.CALLrel32,
            isa.X86Instructions.JMPrel32,
            isa.X86Instructions.JMPrel8,
            isa.X86Instructions.Jccrel32
        }

        self._jumping_one_byte_instructions = {
            isa.X86Instructions.Jccrel8,
            isa.X86Instructions.LOOPrel8,
            isa.X86Instructions.LOOPNErel8,
            isa.X86Instructions.LOOPErel8,
            isa.X86Instructions.JECXZrel8,
            isa.X86Instructions.JMPrel8
        }

        self._jumping_four_bytes_instructions = {
            isa.X86Instructions.CALLrel32,
            isa.X86Instructions.JMPrel32,
            isa.X86Instructions.Jccrel32
        }
        
        self._builder = x86instructionbuilder.X86InstructionBuilder()

    def is_relative_jump(self, instruction: isa.ISAInstruction) -> bool:
        return instruction.identified_function in self._jumping_instructions 

    def relative_jump_length(self, instruction: isa.ISAInstruction) -> int:
        if not self.is_relative_jump(instruction):
            raise ValueError('Given relative_jump_length an instruction that does not perform a jump')
        if instruction.identified_function in self._jumping_one_byte_instructions:
            return 1
        if instruction.identified_function in self._jumping_four_bytes_instructions:
            return 4

    def relative_jump_delta(self, instruction: isa.ISAInstruction) -> int:
        if not self.is_relative_jump(instruction):
            raise ValueError('Given relative_jump_delta an instruction that does not perform a jump')
        jump_length = self.relative_jump_length(instruction)
        delta = int.from_bytes(instruction.parsed_bytes.imm, 'little')
        return utils.get_signed_int(delta, jump_length)

    def modify_jump_delta(self, instruction_list: list[isa.ISAInstruction], instruction_index: int, delta: int) -> None:
        original_instruction = instruction_list[instruction_index]
        original_label = original_instruction.label
        original_jump_to_label = original_instruction.jump_label
        new_instruction = None

        jump_length = self.relative_jump_length(original_instruction)
        diff = 0
        
        if -128 <= delta <= 127:
            if jump_length == 1:
                if original_instruction.identified_function == isa.X86Instructions.Jccrel8:
                    new_instruction = self._builder.jcc_rel8(original_label, original_jump_to_label, original_instruction.parsed_bytes.opcode[0] & 0x0f, delta)
                elif original_instruction.identified_function == isa.X86Instructions.JMPrel8:
                    new_instruction = self._builder.jmp_rel8(original_label, original_jump_to_label, delta)
            elif jump_length == 4:
                if original_instruction.identified_function == isa.X86Instructions.CALLrel32:
                    new_instruction = self._builder.call_rel32(original_label, original_jump_to_label, delta)
                if original_instruction.identified_function == isa.X86Instructions.Jccrel32:
                    if delta < 0:
                        diff = 6 - 2
                    new_instruction = self._builder.jcc_rel8(original_label, original_jump_to_label, original_instruction.parsed_bytes.opcode[1] & 0x0f, delta + diff)
                if original_instruction.identified_function == isa.X86Instructions.JMPrel32:
                    if delta < 0:
                        diff = 5 - 2
                    new_instruction = self._builder.jmp_rel8(original_label, original_jump_to_label, delta + diff)
        else:
            if jump_length == 1:
                if original_instruction.identified_function == isa.X86Instructions.Jccrel8:
                    if delta < 0:
                        diff = 2 - 6
                    new_instruction = self._builder.jcc_rel32(original_label, original_jump_to_label, original_instruction.parsed_bytes.opcode[0] & 0x0f, delta + diff)
                if original_instruction.identified_function == isa.X86Instructions.JMPrel8:
                    if delta < 0:
                        diff = 2 - 5
                    new_instruction = self._builder.jmp_rel32(original_label, original_jump_to_label, delta + diff)
            if jump_length == 4:
                if original_instruction.identified_function == isa.X86Instructions.Jccrel32:
                    new_instruction = self._builder.jcc_rel32(original_label, original_jump_to_label, original_instruction.parsed_bytes.opcode[1] & 0x0f, delta)
                elif original_instruction.identified_function == isa.X86Instructions.JMPrel32:
                    new_instruction = self._builder.jmp_rel32(original_label, original_jump_to_label, delta)
                elif original_instruction.identified_function == isa.X86Instructions.CALLrel32:
                    new_instruction = self._builder.call_rel32(original_label, original_jump_to_label, delta)
        instruction_list[instruction_index] = new_instruction
    
