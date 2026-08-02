import abc
import src.lib.isahandling.instructionclassifier as instructionclassifier
import src.lib.isahandling.isa as isa
import src.lib.isahandling.instructionparser as instructionparser
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
    
    def __init__(self):
        self._classifier = instructionclassifier.X86InstructionClassifier()
        self._parser = instructionparser.X86InstructionParser()
        
    def convert_to_instructions(self, bytes_string: bytes) -> list[isa.ISAInstruction]:
        result_list = []
        decoded_instructions = distorm3.Decode(0, bytes_string, distorm3.Decode32Bits)
        for (offset, size, instr, hexdump) in decoded_instructions:
            result_list.append(
                    isa.ISAInstruction(
                        bytes_string[offset:offset+size],
                        size,
                        None,
                        None,
                        isa.AvailableISA.X86,
                        self._classifier.classify(bytes_string[offset:offset+size]),
                        self._parser.parse(bytes_string[offset:offset+size])
                    )
            )
        return result_list
