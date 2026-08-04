import abc
import copy

import src.lib.isahandling.isa as isa
import src.lib.isahandling.instructionclassifier as instructionclassifier
import src.lib.isahandling.instructionparser as instructionparser

class X86InstructionBuilder():
    
    def __init__(self) -> None:
        self._classifier = instructionclassifier.X86InstructionClassifier()
        self._parser = instructionparser.X86InstructionParser()
    
    def _build_instruction(self, instruction_bytes: bytes, instruction_label: isa.Label, jump_label: isa.Label) -> isa.ISAInstruction:
        return isa.ISAInstruction(
               instruction_bytes,
               len(instruction_bytes),
               copy.deepcopy(instruction_label),
               copy.deepcopy(jump_label),
               isa.AvailableISA.X86,
               self._classifier.classify(instruction_bytes),
               self._parser.parse(instruction_bytes)
        )

    def dec_ecx(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x49'
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def jz(self, instruction_label: isa.Label, jump_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x74\x00'
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jnz(self, instruction_label: isa.Label, jump_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x75\x00'
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def test_ecx_ecx(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x85\xc9'
        return self._build_instruction(instruction_bytes, instruction_label, None)

    

