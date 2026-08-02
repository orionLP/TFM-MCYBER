import abc
import src.lib.isahandling.isa as isa

class SequencingHandler(abc.ABC):
    
    @abc.abstractmethod
    def is_relative_jump(self, instruction_bytes: bytes) -> bool:
        pass

    @abc.abstractmethod
    def relative_jump_length(self, instruction_bytes: bytes) -> int:
        pass

    @abc.abstractmethod
    def relative_jump_delta(self, instruction_bytes: bytes) -> int:
        pass

    @abc.abstractmethod
    def modify_jump_delta(self, instruction_bytes: bytes, delta: int) -> bytes:
        pass
    
    @abc.abstractmethod
    def fix_jump(self, jumping_instruction: isa.ISAInstruction, destination_instruction: isa.ISAInstruction) -> None:
        pass

class X86SequencingHandler(SequencingHandler):
    
    def is_relative_jump(self, instruction_bytes: bytes) -> bool:
        if len(instruction_bytes) >= 2:
            byte_0 = instruction_bytes[0]
            byte_1 = instruction_bytes[1]
            return 
        return False

    def relative_jump_length(self, instruction_bytes: bytes) -> int:
        pass

    def relative_jump_delta(self, instruction_bytes: bytes) -> int:
        pass

    def modify_jump_delta(self, instruction_bytes: bytes, delta: int) -> bytes:
        pass
    
    def fix_jump(self, jumping_instruction: isa.ISAInstruction, destination_instruction: isa.ISAInstruction) -> None:
        pass



