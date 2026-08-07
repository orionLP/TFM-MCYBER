import abc
import src.lib.isahandling.isa as isa
import src.lib.isahandling.x86instructionbuilder as x86instructionbuilder
from src.lib.crypto.rng import prng
import src.lib.isahandling.utils as utils
import struct

class MOVDISPObfuscator(abc.ABC):

    @abc.abstractmethod
    def obfuscate(self, mov_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        pass

class StandardX86MOVDISPObfuscator(MOVDISPObfuscator):
    
    def __init__(self) -> None:
        self._builder = x86instructionbuilder.X86InstructionBuilder()

    def obfuscate(self, mov_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        modrm = mov_instruction.parsed_bytes.modrm
        instruction_label = mov_instruction.label
        destination_reg = (modrm & 0x38) >> 3
        sib = mov_instruction.parsed_bytes.sib
        is_sib_present = (modrm & 0x07) == 0x04
        source_reg = None
        reg_index = None
        reg_scale = None
        if is_sib_present:
            source_reg = (sib & 0x07)
            reg_index = (sib & 0x38) >> 3
            reg_scale = (sib & 0xc0) >> 6
        else:
            source_reg = modrm & 0x07
        disp = mov_instruction.parsed_bytes.disp
    
        excluded_registers = [
            isa.X86Registers.ESP.value.register_identifier,
            isa.X86Registers.EBP.value.register_identifier,
            destination_reg,
            source_reg
        ]
        if not reg_index is None:
            excluded_registers.append(reg_index)
        
        treg = prng.random_choice([register.value.register_identifier for register in isa.X86Registers if not register.value.register_identifier in excluded_registers])
        
        push_treg = self._builder.push_reg(treg, instruction_label)
        mov_treg_disp = self._builder.operation_reg_imm(isa.X86Instructions.MOVR32IMM32, treg, disp, True, None)
        lea_treg_treg_reg_scale = None
        if is_sib_present:
            lea_treg_treg_reg_scale = self._builder._lea_reg_reg_index_scale(isa.X86Instructions.LEAR32BIS, treg, treg, reg_index, reg_scale, None)
        
        chosen_mov_instruction = None
        if mov_instruction in [isa.X86Instructions.MOVR8DISP8MEM, isa.X86Instructions.MOVR8DISP32MEM]:
            chosen_mov_instruction = isa.X86Instructions.MOVR8BI
        elif mov_instruction in [isa.X86Instructions.MOVR16DISP8MEM, isa.X86Instructions.MOVR16DISP32MEM]:
            chosen_mov_instruction = isa.X86Instructions.MOVR16BI
        elif mov_instruction in [isa.X86Instructions.MOVR32DISP8MEM, isa.X86Instructions.MOVR32DISP32MEM]:
            chosen_mov_instruction = isa.X86Instructions.MOVR32BI

        mov_treg_reg_treg = self._builder._mov_reg_base_index(chosen_mov_instruction, destination_reg, source_reg, treg, None)
        pop_treg = self._builder.pop_reg(treg, None)

        if is_sib_present:
            return [push_treg, mov_treg_disp, lea_treg_treg_reg_scale, mov_treg_reg_treg, pop_treg]
        else:
            return [push_treg, mov_treg_disp, mov_treg_reg_treg, pop_treg]
