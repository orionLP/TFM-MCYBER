import abc
import capstone
import src.lib.isahandling.isa as isa
from typing import Any

class InstructionParser(abc.ABC):

    @abc.abstractmethod
    def parse(self, instruction_bytes: bytes) -> Any:
        pass

class X86InstructionParser(InstructionParser):

    def __init__(self) -> None:
        self._md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self._md.detail = True

    def parse(self, instruction_bytes: bytes) -> Any:
        prefix = b''
        opcode = b''
        modrm = 0
        sib = 0
        disp = 0
        imm = b''
        
        instruction = [item for item in self._md.disasm(instruction_bytes, 0)][0]
        
        prefix = bytes(instruction.prefix)
        opcode = bytes(instruction.opcode)
        modrm = instruction.modrm
        sib = instruction.sib
        disp = instruction.disp
        if instruction.imm_size > 0:
            offset = instruction.imm_offset
            size = instruction.imm_size
            imm = bytes(instruction.bytes[offset:offset+size])

        return isa.X86InstructionFields(prefix, opcode, modrm, sib, disp, imm)



