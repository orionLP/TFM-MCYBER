import abc
import copy
import struct

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

    def jz_rel8(self, instruction_label: isa.Label, jump_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x74\x00'
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jnz_rel8(self, instruction_label: isa.Label, jump_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x75\x00'
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)
    
    def jmp_rel32(self, instruction_label: isa.Label, jump_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\xe9\x00\x00\x00\x00'
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def test_ecx_ecx(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x85\xc9'
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def nop(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x90'
        return self._build_instruction(instruction_bytes, instruction_label, None)
    
    def _mov_reg_imm(self, operation_type: isa.X86Instructions, reg: int, immidiate: bytes, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''
        if operation_type == isa.X86Instructions.MOVR8IMM8:
            instruction_bytes += bytes([0xb0 + reg])
        elif operation_type == isa.X86Instructions.MOVR16IMM16:
            instruction_bytes += bytes([0x66, 0xb8 + reg])
        elif operation_type == isa.X86Instructions.MOVR32IMM32:
            instruction_bytes += bytes([0xb8 + reg])

        instruction_bytes += immidiate
        
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def _add_reg_imm(self, operation_type: isa.X86Instructions, reg: int, immidiate: bytes, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''
        if operation_type == isa.X86Instructions.ADDR8IMM8:
            instruction_bytes += bytes([0x83, 0xc0 + reg])
        elif operation_type == isa.X86Instructions.ADDR16IMM16:
            instruction_bytes += bytes([0x66, 0x81, 0xc0 + reg])
        elif operation_type == isa.X86Instructions.ADDR32IMM32:
            instruction_bytes += bytes([0x81, 0xc0 + reg])

        instruction_bytes += immidiate
        
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def _sub_reg_imm(self, operation_type: isa.X86Instructions, reg: int, immidiate: bytes, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''
        if operation_type == isa.X86Instructions.SUBR8IMM8:
            instruction_bytes += bytes([0x83, 0xe8 + reg])
        elif operation_type == isa.X86Instructions.SUBR16IMM16:
            instruction_bytes += bytes([0x66, 0x81, 0xe8 + reg])
        elif operation_type == isa.X86Instructions.SUBR32IMM32:
            instruction_bytes += bytes([0x81, 0xe8 + reg])

        instruction_bytes += immidiate
        
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def _xor_reg_imm(self, operation_type: isa.X86Instructions, reg: int, immidiate: bytes, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''
        if operation_type == isa.X86Instructions.XORR8IMM8:
            instruction_bytes += bytes([0x83, 0xf0 + reg])
        elif operation_type == isa.X86Instructions.XORR16IMM16:
            instruction_bytes += bytes([0x66, 0x81, 0xf0 + reg])
        elif operation_type == isa.X86Instructions.XORR32IMM32:
            instruction_bytes += bytes([0x81, 0xf0 + reg])

        instruction_bytes += immidiate
        
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def operation_reg_imm(self, operation_type: isa.X86Instructions, reg: int, immidiate: int, signed: bool, instruction_label: isa.Label) -> isa.ISAInstruction:
        operation_immidiate_bytes = None
        
        if operation_type in [isa.X86Instructions.MOVR8IMM8, isa.X86Instructions.ADDR8IMM8, isa.X86Instructions.XORR8IMM8, isa.X86Instructions.SUBR8IMM8]:
            if signed:
                operation_immidiate_bytes = struct.pack('<b', immidiate)
            else:
                operation_immidiate_bytes = struct.pack('<B', immidiate)
        if operation_type in [isa.X86Instructions.MOVR16IMM16, isa.X86Instructions.ADDR16IMM16, isa.X86Instructions.XORR16IMM16, isa.X86Instructions.SUBR16IMM16]:
            if signed:
                operation_immidiate_bytes = struct.pack('<h', immidiate)
            else:
                operation_immidiate_bytes = struct.pack('<H', immidiate)
        if operation_type in [isa.X86Instructions.MOVR32IMM32, isa.X86Instructions.ADDR32IMM32, isa.X86Instructions.XORR32IMM32, isa.X86Instructions.SUBR32IMM32]:
            if signed:
                operation_immidiate_bytes = struct.pack('<i', immidiate)
            else:
                operation_immidiate_bytes = struct.pack('<I', immidiate)

        if operation_type in [isa.X86Instructions.MOVR8IMM8, isa.X86Instructions.MOVR16IMM16, isa.X86Instructions.MOVR32IMM32]:
            return self._mov_reg_imm(operation_type, reg, operation_immidiate_bytes, instruction_label)
        elif operation_type in [isa.X86Instructions.ADDR8IMM8, isa.X86Instructions.ADDR16IMM16, isa.X86Instructions.ADDR32IMM32]:
            return self._add_reg_imm(operation_type, reg, operation_immidiate_bytes, instruction_label)
        elif operation_type in [isa.X86Instructions.SUBR8IMM8, isa.X86Instructions.SUBR16IMM16, isa.X86Instructions.SUBR32IMM32]:
            return self._sub_reg_imm(operation_type, reg, operation_immidiate_bytes, instruction_label)
        elif operation_type in [isa.X86Instructions.XORR8IMM8, isa.X86Instructions.XORR16IMM16, isa.X86Instructions.XORR32IMM32]:
            return self._xor_reg_imm(operation_type, reg, operation_immidiate_bytes, instruction_label)
