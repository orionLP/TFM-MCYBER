import abc

import src.lib.isahandling.instructionparser as instructionparser
import src.lib.isahandling.isa as isa
from typing import Any

class InstructionClassifier(abc.ABC):

    @abc.abstractmethod
    def classify(self, instruction_bytes: bytes) -> Any:
        pass

class X86InstructionClassifier(InstructionClassifier):

    def __init__(self) -> None:
        self._instruction_parser = instructionparser.X86InstructionParser()

    def classify(self, instruction_bytes: bytes) -> Any:
        instruction_format = self._instruction_parser.parse(instruction_bytes)
        opcode = instruction_format.opcode
        prefix = instruction_format.prefix
        modrm = instruction_format.modrm
        sib = instruction_format.sib
        
        if len(instruction_bytes) >= 2:
            if (opcode[0] & 0xf0) == 0x70:
                return isa.X86Instructions.Jccrel8
            if opcode[0] == 0xe0:
                return isa.X86Instructions.LOOPNErel8
            if opcode[0] == 0xe1:
                return isa.X86Instructions.LOOPErel8
            if opcode[0] == 0xe2:
                return isa.X86Instructions.LOOPrel8
            if opcode[0] == 0xe3:
                return isa.X86Instructions.JECXZrel8
            if opcode[0] == 0xe8:
                return isa.X86Instructions.CALLrel32
            if opcode[0] == 0xe9:
                return isa.X86Instructions.JMPrel32
            if opcode[0] == 0xeb:
                return isa.X86Instructions.JMPrel8
            # This might cause trouble
            if opcode[0] == 0x0f and (opcode[1] & 0xf0) == 0x80:
                return isa.X86Instructions.Jccrel32
            if opcode[0] in range(0xb0,0xb8):
                return isa.X86Instructions.MOVR8IMM8
            if prefix[0] == 0x66 and opcode[0] in range(0xb8, 0xc0):
                return isa.X86Instructions.MOVR16IMM16
            if opcode[0] in range(0xb8, 0xc0):
                return isa.X86Instructions.MOVR32IMM32
            if opcode[0] == 0x83 and modrm in range(0xc0, 0xc0+8):
                return isa.X86Instructions.ADDR8IMM8
            if prefix[0] == 0x66 and opcode[0] == 0x81 and modrm in range(0xc0, 0xc0+8):
                return isa.X86Instructions.ADDR16IMM16
            if opcode[0] == 0x81 and modrm in range(0xc0, 0xc0+8):
                return isa.X86Instructions.ADDR32IMM32
            if opcode[0] == 0x83 and modrm in range(0xf0, 0xf0+8):
                return isa.X86Instructions.XORR8IMM8
            if prefix[0] == 0x66 and opcode[0] == 0x81 and modrm in range(0xf0, 0xf0+8):
                return isa.X86Instructions.XORR16IMM16
            if opcode[0] == 0x81 and modrm in range(0xf0, 0xf0+8):
                return isa.X86Instructions.XORR32IMM32
            if opcode[0] == 0x83 and modrm in range(0xe8, 0xe8+8):
                return isa.X86Instructions.SUBR8IMM8
            if prefix[0] == 0x66 and opcode[0] == 0x81 and modrm in range(0xe8, 0xe8+8):
                return isa.X86Instructions.SUBR16IMM16
            if opcode[0] == 0x81 and modrm in range(0xe8, 0xe8+8):
                return isa.X86Instructions.SUBR32IMM32
            if opcode[0] == 0x6a:
                return isa.X86Instructions.PUSHIMM8
            if opcode[0] == 0x68:
                return isa.X86Instructions.PUSHIMM32
            if opcode[0] == 0x89 and sib in range(0x20, 0x20 + 8) and (modrm & 0xC7) == 0x44:
                return isa.X86Instructions.MOVR32DISP8R32
            if opcode[0] == 0x89 and sib in range(0x20, 0x20 + 8) and (modrm & 0xC7) == 0x84:
                return isa.X86Instructions.MOVR32DISP32R32
            if opcode[0] == 0x8a and (modrm & 0b11000000) == 0b01000000 and (modrm & 0b00000111) != 0b100:
                return isa.X86Instructions.MOVR8DISP8MEM
            if opcode[0] == 0x8a and (modrm & 0b11000000) == 0b10000000 and (modrm & 0b00000111) != 0b100:
                return isa.X86Instructions.MOVR8DISP32MEM
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000000) == 0b01000000 and (modrm & 0b00000111) != 0b100:
                return isa.X86Instructions.MOVR16DISP8MEM
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000000) == 0b10000000 and (modrm & 0b00000111) != 0b100:
                return isa.X86Instructions.MOVR16DISP32MEM
            if opcode[0] == 0x8b and (modrm & 0b11000000) == 0b01000000 and (modrm & 0b00000111) != 0b100:
                return isa.X86Instructions.MOVR32DISP8MEM
            if opcode[0] == 0x8b and (modrm & 0b11000000) == 0b10000000 and (modrm & 0b00000111) != 0b100:
                return isa.X86Instructions.MOVR32DISP32MEM
            if opcode[0] == 0x8d and (modrm & 0b11000111) == 0b00000100:
                return isa.X86Instructions.LEAR32BIS
            if prefix[0] == 0x66 and opcode[0] == 0x8d and (modrm & 0b11000111) == 0b00000100:
                return isa.X86Instructions.LEAR16BIS
            if opcode[0] == 0x8a and (modrm & 0b11000111) == 0b00000100 and (sib & 0b11000000) == 0:
                return isa.X86Instructions.MOVR8BI
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000111) == 0b00000100 and (sib & 0b11000000) == 0:
                return isa.X86Instructions.MOVR16BI
            if opcode[0] == 0x8b and (modrm & 0b11000111) == 0b00000100 and (sib & 0b11000000) == 0:
                return isa.X86Instructions.MOVR32BI
            if opcode[0] == 0x8a and (modrm & 0b11000111) == 0b00000100 and (sib & 0b11000000) != 0 and (sib & 0b00000111) != 0b101:
                return isa.X86Instructions.MOVR8BIS
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000111) == 0b00000100 and (sib & 0b11000000) != 0 and (sib & 0b00000111) != 0b101:
                return isa.X86Instructions.MOVR16BIS
            if opcode[0] == 0x8b and (modrm & 0b11000111) == 0b00000100 and (sib & 0b11000000) != 0 and (sib & 0b00000111) != 0b101:
                return isa.X86Instructions.MOVR32BIS
            if opcode[0] == 0x8a and (modrm & 0b11000111) == 0b00000100 and (sib & 0b00000111) == 0b101:
                return isa.X86Instructions.MOVR8IS
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000111) == 0b00000100 and (sib & 0b00000111) == 0b101:
                return isa.X86Instructions.MOVR16IS
            if opcode[0] == 0x8b and (modrm & 0b11000111) == 0b00000100 and (sib & 0b00000111) == 0b101:
                return isa.X86Instructions.MOVR32IS
            if opcode[0] == 0x8a and (modrm & 0b11000111) == 0b01000100:
                return isa.X86Instructions.MOVR8BISDISP8
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000111) == 0b01000100:
                return isa.X86Instructions.MOVR16BISDISP8
            if opcode[0] == 0x8b and (modrm & 0b11000111) == 0b01000100:
                return isa.X86Instructions.MOVR32BISDISP8
            if opcode[0] == 0x8a and (modrm & 0b11000111) == 0b10000100:
                return isa.X86Instructions.MOVR8BISDISP32
            if prefix[0] == 0x66 and opcode[0] == 0x8b and (modrm & 0b11000111) == 0b10000100:
                return isa.X86Instructions.MOVR16BISDISP32
            if opcode[0] == 0x8b and (modrm & 0b11000111) == 0b10000100:
                return isa.X86Instructions.MOVR32BISDISP32
        return None
