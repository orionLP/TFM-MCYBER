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

        return None
