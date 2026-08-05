import abc
import enum
import dataclasses

from typing import Any

@dataclasses.dataclass
class ISA():
    name: str

class AvailableISA(enum.Enum):
    X86 = ISA('x86')
    CUSTOM = ISA('custom')

@dataclasses.dataclass
class Label():
    name: str
    identifier: int

# The following is not the entire instrucitons of an ISA, just some ones i needed to reference in the code

@dataclasses.dataclass
class MachineInstruction():
    operation: str

class X86Instructions(enum.Enum):
    Jccrel8 = MachineInstruction('Jcc rel8')
    LOOPrel8 = MachineInstruction('LOOP rel8')
    LOOPNErel8 = MachineInstruction('LOOPNE rel8')
    LOOPErel8 = MachineInstruction('LOOPE rel8')
    JECXZrel8 = MachineInstruction('JECXZ rel8')
    MOVR8IMM8 = MachineInstruction('MOV r8, imm8')
    MOVR16IMM16 = MachineInstruction('MOV r16, imm16')
    MOVR32IMM32 = MachineInstruction('MOV r32, imm32')
    ADDR8IMM8 = MachineInstruction('ADD r8, imm8')
    ADDR16IMM16 = MachineInstruction('ADD r16, imm16')
    ADDR32IMM32 = MachineInstruction('ADD r32, imm32')
    XORR8IMM8 = MachineInstruction('XOR r8, imm8')
    XORR16IMM16 = MachineInstruction('XOR r16, imm16')
    XORR32IMM32 = MachineInstruction('XOR r32, imm32')
    SUBR8IMM8 = MachineInstruction('SUB r8, imm8')
    SUBR16IMM16 = MachineInstruction('SUB r16, imm16')
    SUBR32IMM32 = MachineInstruction('SUB r32, imm32')
    CALLrel32 = MachineInstruction('CALL rel32')
    JMPrel32 = MachineInstruction('JMP rel32')
    JMPrel8 = MachineInstruction('JMP rel8')
    Jccrel32 = MachineInstruction('Jcc rel32')

@dataclasses.dataclass
class X86InstructionFields():
    prefix: bytes
    opcode: bytes
    modrm: int
    sib: int
    disp: int
    imm: bytes

@dataclasses.dataclass
class ISAInstruction():
    instruction_bytes: bytes
    size: int
    label: Label | None
    jump_label: Label | None
    isa: AvailableISA
    identified_function: Any
    parsed_bytes: Any

    def modify_field(self, bytes_offset: int, field: str, new_byte_string: bytes) -> None:
        # this does not update the identifed function o 
        self.parsed_bytes.__dict__[field] = new_byte_string
        new_string = self.instruction_bytes[:bytes_offset] + new_byte_string + self.instruction_bytes[bytes_offset + len(new_byte_string):]
        self.instruction_bytes = new_string
        self.size = len(self.instruction_bytes)


