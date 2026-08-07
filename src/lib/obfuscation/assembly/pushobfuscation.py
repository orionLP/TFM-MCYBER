import abc
import src.lib.isahandling.isa as isa
import src.lib.isahandling.x86instructionbuilder as x86instructionbuilder
from src.lib.crypto.rng import prng
import src.lib.isahandling.utils as utils

class PUSHObfuscator(abc.ABC):

    @abc.abstractmethod
    def obfuscate(self, push_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        pass

class StandardX86PUSHObfuscator(PUSHObfuscator):
    
    def __init__(self) -> None:
        self._source_reg_mask = 0b00111000
        self._displacement_reg_mask = 0b00000111
        self._builder = x86instructionbuilder.X86InstructionBuilder()

    def obfuscate(self, push_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        source_reg = (self._source_reg_mask & push_instruction.parsed_bytes.modrm) >> 3
        displacement_reg_mask = (self._displacement_reg_mask & push_instruction.parsed_bytes.sib)
        instruction_label = push_instruction.label

        dummy_push = self._builder.push_reg(prng.get_range_unsigned_integer(len(isa.X86Registers)), instruction_label)
       
        selected_register = prng.random_choice([possible_register.value.register_identifier for possible_register in isa.X86Registers if not possible_register in [isa.X86Registers.ESP, isa.X86Registers.EBP]])
        value_push = self._builder.push_reg(selected_register, None)

        chosen_mov = None
        if push_instruction.identified_function == isa.X86Instructions.PUSHIMM8:
            chosen_mov = isa.X86Instructions.MOVR8IMM8
        elif push_instruction.identified_function == isa.X86Instructions.PUSHIMM32:
            chosen_mov = isa.X86Instructions.MOVR32IMM32
        else:
            raise ValueError('StandardX86PUSHObfuscator given an instruction that is not a recognized push')

        push_immidiate = push_instruction.parsed_bytes.imm
        mov_treg_val = self._builder.operation_reg_imm(chosen_mov, selected_register, int.from_bytes(push_immidiate, 'little'), False, None)
        
        chosen_disp_mov = None
        displacement_bytes = None
        if prng.get_range_unsigned_integer(2) == 0:
            chosen_disp_mov = isa.X86Instructions.MOVR32DISP8R32
            displacement_bytes = bytes([4])
        else:
            chosen_disp_mov = isa.X86Instructions.MOVR32DISP32R32
            displacement_bytes = bytes([4,0,0,0])

        mov_esp_4_treg = self._builder._mov_reg_disp_reg(chosen_disp_mov, isa.X86Registers.ESP.value.register_identifier, selected_register, displacement_bytes, None)
        pop_treg = self._builder.pop_reg(selected_register, None)

        return [
                dummy_push,
                value_push,
                mov_treg_val,
                mov_esp_4_treg,
                pop_treg
            ]
 
