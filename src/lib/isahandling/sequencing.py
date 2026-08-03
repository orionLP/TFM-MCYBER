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
    
    @abc.abstractmethod
    def fix_jump(self, jumping_instruction: isa.ISAInstruction, destination_instruction: isa.ISAInstruction) -> None:
        pass

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
        jump_lenght = self.relative_jump_length(instruction)
        delta = int.from_bytes(instruction.parsed_bytes.imm, 'little')
        return utils.get_signed_int(delta, jump_lenght)

    def modify_jump_delta(self, instruction: isa.ISAInstruction, delta: int) -> None:
        jump_length = self.relative_jump_length(instruction)
        diff = 0

        if -128 <= delta <= 127:
            if jump_lenght == 1:
                instruction.modify_field(1, 'imm', struct.pack('<b', delta))
            elif jump_lenght == 4:
                if instruction.identified_function == isa.X86Instructions.CALLrel32:
                    instruction.modify_field(1, 'imm', struct.pack('<b', delta))
                if instruction.identified_function == isa.X86Instructions.Jccrel32:
                    if delta < 0:
                        diff = 4
                    lsb_opcode = instruction.parsed_bytes.opcode[1]
                    instruction.modify_field(0, 'opcode', bytes([(lsb_opcode & 0x0f) | 0x70]))
                    instruction.modify_field(1, 'imm', struct.pack('<i', delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.bytes)
                if instruction.identified_function == isa.X86Instructions.JMPrel32:
                    if delta < 0:
                        diff = 3
                    instruction.modify_field(0, 'opcode', bytes([0xeb]))
                    instruction.modify_field(1, 'imm', struct.pack('<b', delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.bytes)
        else:
            if jump_lenght == 1:
                if instruction.identified_function == isa.X86Instructions.Jccrel8:
                    if delta < 0:
                        diff -4
                    msb_opcode = instruction.parsed_bytes.opcode[0]
                    instruction.modify_field(0, 'opcode', bytes([0x0f, (msb_opcode & 0x0f) | 0x80]))
                    instruction.modify_field(2, 'imm', struct.pack('<i',delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.bytes)
                if instruction.identified_function == isa.X86Instructions.JMPrel8:
                    if delta < 0:
                        diff = -3
                    instruction.modify_field(0, 'opcode', bytes([0xe9]))
                    instruction.modify_field(1, 'imm', struct.pack('<i', delta + diff))
                    instruction.identified_function = self._classifier.classify(instruction.bytes)
            if jump_lenght == 4:
                if instruction.identified_function == isa.X86Instructions.Jccrel32:
                    lsb_opcode = instruction.parsed_bytes.opcode[1]
                    instruction.modify_field(0, 'opcode', bytes([0x0f, lsb_opcode]))
                    instruction.modify_field(2, 'imm', struct.pack('<i', delta))
                    instruction.identified_function = self._classifier.classify(instruction.bytes)
                else:
                    msb_opcode = instruction.parsed_bytes.opcode[0]
                    instruction.modify_field(0, 'opcode', bytes([msb_opcode]))
                    instruction.modify_field(1, 'imm', delta)
                    instruction.identified_function = self._classifier.classify(instruction.bytes)

    def fix_jump(self, jumping_instruction: isa.ISAInstruction, destination_instruction: isa.ISAInstruction) -> None:
        pass   
    
