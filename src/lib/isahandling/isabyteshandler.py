import abc
import src.lib.isahandling.isa as isa
import distorm3

class ISAConversionHandler(abc.ABC):
    
    def convert_to_bytes(self, instructions_list: list[isa.ISAInstruction]) -> bytes:
        result_string = b''
        for next_instruction in instructions_list:
            result_string += next_instruction.instruction_bytes
        return result_string

    @abc.abstractmethod
    def convert_to_instructions(self, bytes_string: bytes) -> list[isa.ISAInstruction]:
        pass

class X86ISAConversionHandler(ISAConversionHandler):

    def convert_to_instructions(self, bytes_string: bytes) -> list[isa.ISAInstruction]:
        decoded_instructions = distorm3.Decode(0, )

