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
    
    def push_reg(self, reg: int, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = bytes([0x50 + reg])
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def pop_reg(self, reg: int, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = bytes([0x58 + reg])
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def dec_ecx(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x49'
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def jz_rel8(self, instruction_label: isa.Label, jump_label: isa.Label, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = b'\x74\x00'
        if not offset is None:
            instruction_bytes = b'\x74' + struct.pack('<b', offset)

        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jnz_rel8(self, instruction_label: isa.Label, jump_label: isa.Label, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = b'\x75\x00'
        if not offset is None:
            instruction_bytes = b'\x75' + struct.pack('<b', offset)

        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jcc_rel8(self, instruction_label: isa.Label, jump_label: isa.Label, conditional: int, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = bytes([0x70 + conditional])
        if not offset is None:
            instruction_bytes += struct.pack('<b', offset)
        else:
            instruction_bytes += b'\x00'

        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jcc_rel32(self, instruction_label: isa.Label, jump_label: isa.Label, conditional: int, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = bytes([0x0f, 0x80 + conditional])
        if not offset is None:
            instruction_bytes += struct.pack('<i', offset)
        else:
            instruction_bytes += b'\x00\x00\x00\x00'

        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def call_rel32(self, instruction_label: isa.Label, jump_label: isa.Label, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = b'\xe8\x00\x00\x00\x00'
        if not offset is None:
            instruction_bytes = b'\xe8' + struct.pack('<i', offset)

        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jmp_rel8(self, instruction_label: isa.Label, jump_label: isa.Label, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = b'\xeb\x00'
        if not offset is None:
            instruction_bytes = b'\xeb' + struct.pack('<b', offset)
        
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def jmp_rel32(self, instruction_label: isa.Label, jump_label: isa.Label, offset: int | None = None) -> isa.ISAInstruction:
        instruction_bytes = b'\xe9\x00\x00\x00\x00'
        if not offset is None:
            instruction_bytes = b'\xe9' + struct.pack('<i', offset)
            
        return self._build_instruction(instruction_bytes, instruction_label, jump_label)

    def test_ecx_ecx(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x85\xc9'
        return self._build_instruction(instruction_bytes, instruction_label, None)

    def nop(self, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b'\x90'
        return self._build_instruction(instruction_bytes, instruction_label, None)
   
    def _lea_reg_reg_index_scale(self, operation_type: isa.X86Instructions, dest_reg: int, base_reg: int, index_reg: int, scale: int, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''
        if operation_type == isa.X86Instructions.LEAR16BIS:
            instruction_bytes += bytes([0x66, 0x8d])
        elif operation_type == isa.X86Instructions.LEAR32BIS:
            instruction_bytes += bytes([0x8d])

        instruction_bytes += bytes([0b00000100 + (dest_reg << 3), (scale << 6) + (index_reg << 3) + base_reg])

        return self._build_instruction(instruction_bytes, instruction_label, None)
            
    def _mov_reg_base_index(self, operation_type: isa.X86Instructions, dest_reg: int, base_reg: int, index_reg: int, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''
        if operation_type == isa.X86Instructions.MOVR8BI:
            instruction_bytes += bytes([0x8a])
        elif operation_type == isa.X86Instructions.MOVR16BI:
            instruction_bytes += bytes([0x66, 0x8b])
        elif operation_type == isa.X86Instructions.MOVR32BI:
            instruction_bytes += bytes([0x8b])

        instruction_bytes += bytes([0b00000100 + (dest_reg << 3), (index_reg << 3) + base_reg])

        return self._build_instruction(instruction_bytes, instruction_label, None)

    def _mov_reg_disp_reg(self, operation_type: isa.X86Instructions, displacement_reg: int, source_reg: int, displacement: bytes, instruction_label: isa.Label) -> isa.ISAInstruction:
        instruction_bytes = b''

        if operation_type == isa.X86Instructions.MOVR32DISP8R32:
            instruction_bytes += bytes([0x89, 0b01000100 + (source_reg << 3), 0x20 + displacement_reg])
        elif operation_type == isa.X86Instructions.MOVR32DISP32R32:
            instruction_bytes += bytes([0x89, 0b10000100 + (source_reg << 3), 0x20 + displacement_reg])

        instruction_bytes += displacement

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
