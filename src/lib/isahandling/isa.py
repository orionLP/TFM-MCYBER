import abc
import enum
import dataclasses

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

@dataclasses.dataclass
class ISAInstruction():
    instruction_bytes: bytes
    size: int
    label: Label | None
    isa: AvailableISA
