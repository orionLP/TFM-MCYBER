import abc
import src.lib.isahandling.isa as isa
from src.lib.crypto.rng import prng

class MOVObfuscator(abc.ABC):

    @abc.abstractmethod
    def obfuscate(self, mov_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        pass

class StandardX86MOVObfuscator(MOVObfuscator):
    
    def _obfuscate_movr8imm8(self, mov_instruction: isa.ISAInstruction):
        pass
    
    def _obfuscate_movr16imm16(self, mov_instruction: isa.ISAInstruction):
        pass
    
    def _obfuscate_movr32imm32(self, mov_instruction: isa.ISAInstruction):
        pass

    def obfuscate(self, mov_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        a = 1
