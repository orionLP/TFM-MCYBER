import abc
import src.lib.isahandling.isa as isa
import src.lib.isahandling.utils as utils
import src.lib.isahandling.instructionclassifier as instructionclassifier
import struct

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
    def modify_jump_delta(self, instruction: isa.ISAInstruction, delta: int) -> None:
        pass

    def fix_jump(self, instruction_list: list[isa.ISAInstruction], jumping_instruction_index: int) -> None:
        jump_to_label_identifier = instruction_list[jumping_instruction_index].jump_label.identifier
        jump_to_instruction_index = utils.get_instruction_index_by_label(instruction_list, jump_to_label_identifier)
        new_delta = utils.get_jump_delta_between_instructions(instruction_list, jumping_instruction_index, jump_to_instruction_index)
        self.modify_jump_delta(instruction_list[jumping_instruction_index], new_delta)

    def fix_jumps(self, instruction_list: list[isa.ISAInstruction]) -> None:
        for i in range(len(instruction_list)):
            if not instruction_list[i].jump_label is None:
                self.fix_jump(instruction_list, i)

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

        self._classifier = instructionclassifier.X86InstructionClassifier()

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

    def modify_jump_delta(self, instruction: isa.ISAInstruction, delta: int) -> None:
        jump_length = self.relative_jump_length(instruction)
        diff = 0

        if -128 <= delta <= 127:
            if jump_length == 1:
                instruction.modify_field(1, 'imm', struct.pack('<b', delta))
            elif jump_length == 4:
                if instruction.identified_function == isa.X86Instructions.CALLrel32:
                    instruction.modify_field(1, 'imm', struct.pack('<b', delta))
                if instruction.identified_function == isa.X86Instructions.Jccrel32:
                    if delta < 0:
                        diff = 4
                    lsb_opcode = instruction.parsed_bytes.opcode[1]
                    instruction.modify_field(0, 'opcode', bytes([(lsb_opcode & 0x0f) | 0x70]))
                    instruction.modify_field(1, 'imm', struct.pack('<i', delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.instruction_bytes)
                if instruction.identified_function == isa.X86Instructions.JMPrel32:
                    if delta < 0:
                        diff = 3
                    instruction.modify_field(0, 'opcode', bytes([0xeb]))
                    instruction.modify_field(1, 'imm', struct.pack('<b', delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.instruction_bytes)
        else:
            if jump_length == 1:
                if instruction.identified_function == isa.X86Instructions.Jccrel8:
                    if delta < 0:
                        diff -4
                    msb_opcode = instruction.parsed_bytes.opcode[0]
                    instruction.modify_field(0, 'opcode', bytes([0x0f, (msb_opcode & 0x0f) | 0x80]))
                    instruction.modify_field(2, 'imm', struct.pack('<i',delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.instruction_bytes)
                if instruction.identified_function == isa.X86Instructions.JMPrel8:
                    if delta < 0:
                        diff = -3
                    instruction.modify_field(0, 'opcode', bytes([0xe9]))
                    instruction.modify_field(1, 'imm', struct.pack('<i', delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.instruction_bytes)
            if jump_length == 4:
                if instruction.identified_function == isa.X86Instructions.Jccrel32:
                    lsb_opcode = instruction.parsed_bytes.opcode[1]
                    instruction.modify_field(0, 'opcode', bytes([0x0f, lsb_opcode]))
                    instruction.modify_field(2, 'imm', struct.pack('<i', delta))
                    instruction.identified_function = self._classifier.classify(instruction.instruction_bytes)
                else:
                    msb_opcode = instruction.parsed_bytes.opcode[0]
                    instruction.modify_field(0, 'opcode', bytes([msb_opcode]))
                    instruction.modify_field(1, 'imm', struct.pack('<i',delta))
                    instruction.identified_function = self._classifier.classify(instruction.instruction_bytes)
            
    
