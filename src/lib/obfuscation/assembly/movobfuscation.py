import abc
import src.lib.isahandling.isa as isa
import src.lib.isahandling.x86instructionbuilder as x86instructionbuilder
from src.lib.crypto.rng import prng
import src.lib.isahandling.utils as utils

class MOVObfuscator(abc.ABC):

    @abc.abstractmethod
    def obfuscate(self, mov_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        pass

class StandardX86MOVObfuscator(MOVObfuscator):
    
    def __init__(self):
        self._one_byte = {'mov': isa.X86Instructions.MOVR8IMM8, 'add': isa.X86Instructions.ADDR8IMM8, 'sub': isa.X86Instructions.SUBR8IMM8, 'xor': isa.X86Instructions.XORR8IMM8}
        self._two_bytes = {'mov': isa.X86Instructions.MOVR16IMM16, 'add': isa.X86Instructions.ADDR16IMM16, 'sub': isa.X86Instructions.SUBR16IMM16, 'xor': isa.X86Instructions.XORR16IMM16}
        self._four_bytes = {'mov': isa.X86Instructions.MOVR32IMM32, 'add': isa.X86Instructions.ADDR32IMM32, 'sub': isa.X86Instructions.SUBR32IMM32, 'xor': isa.X86Instructions.XORR32IMM32}
        self._builder = x86instructionbuilder.X86InstructionBuilder()
        
    def _obfuscate_one_mov(self, instructions_dictionary: dict[str, isa.X86Instructions], reg: int, label: isa.Label, target: bytes) -> list[isa.ISAInstruction]:
        chosen_instruction = prng.random_choice(['add', 'sub', 'xor'])
        random_bytes = prng.get_n_bytes(len(target))
        chosen_immidiate = int.from_bytes(random_bytes, 'little') % ((2 ** (len(target) - 1)) - 1)
        target_integer = int.from_bytes(target, 'little')
        
        result_list = []
        if chosen_instruction == 'add':
            offset = target_integer - chosen_immidiate
            result_list.append(self._builder.operation_reg_imm(instructions_dictionary['mov'], reg, chosen_immidiate, False, label))
            result_list.append(self._builder.operation_reg_imm(instructions_dictionary['add'], reg, offset, offset < 0, None))
        elif chosen_instruction == 'sub':
            offset = chosen_immidiate - target_integer
            result_list.append(self._builder.operation_reg_imm(instructions_dictionary['mov'], reg, chosen_immidiate, False, label))
            result_list.append(self._builder.operation_reg_imm(instructions_dictionary['sub'], reg, offset, offset < 0, None))
        else:
            xored_op = target_integer ^ chosen_immidiate
            result_list.append(self._builder.operation_reg_imm(instructions_dictionary['mov'], reg, chosen_immidiate, False, label))
            result_list.append(self._builder.operation_reg_imm(instructions_dictionary['xor'], reg, xored_op, False, None))
        return result_list

    def obfuscate(self, mov_instruction: isa.ISAInstruction) -> list[isa.ISAInstruction]:
        reg = utils.x86_extract_destination_register(mov_instruction.instruction_bytes)
        label = mov_instruction.label
        target = mov_instruction.parsed_bytes.imm

        if mov_instruction.identified_function == isa.X86Instructions.MOVR8IMM8:
            return self._obfuscate_one_mov(self._one_byte, reg, label, target)
        elif mov_instruction.identified_function == isa.X86Instructions.MOVR16IMM16:
            return self._obfuscate_one_mov(self._two_bytes, reg, label, target)
        elif mov_instruction.identified_function == isa.X86Instructions.MOVR32IMM32:
            return self._obfuscate_one_mov(self._four_bytes, reg, label, target)
        
        raise ValueError('obfuscate of mov given an instruction that is not a mov')
