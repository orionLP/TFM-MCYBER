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
    LOOPNErel8 = MachineInstruction('LOOPN rel8')
    LOOPErel8 = MachineInstruction('LOOPE rel8')
    JECXZrel8 = MachineInstruction('JECXZ rel8')
    CALLrel32 = MachineInstruction('CALL rel32')
    JMPrel32 = MachineInstruction('JMP rel32')
    JMPrel8 = MachineInstruction('JMP rel8')
    Jccrel32 = MachineInstruction('Jcc rel32')

@dataclasses.dataclass
class ISAInstruction():
    instruction_bytes: bytes
    size: int
    label: Label | None
    jump_label: Label | None
    isa: AvailableISA
    identified_function: Any
    parsed_bytes: tuple[bytes, ...]

