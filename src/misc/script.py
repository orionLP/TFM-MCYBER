import src.lib.isahandling.isabyteshandler as isbytes
import src.lib.obfuscation.assembly.movobfuscation as movobfuscation
import src.lib.isahandling.isa as isa

with open('src/misc/shell.bin','rb') as file:
    file_bytes = file.read()
handler = isbytes.X86ISAConversionHandler()
a = handler.convert_to_instructions(file_bytes)
movobfs = movobfuscation.StandardX86MOVObfuscator()
for instruction in a:
    print(instruction)
    if instruction in [isa.X86Instructions.MOVR8IMM8, isa.X86Instructions.MOVR16IMM16, isa.X86Instructions.MOVR32IMM32]:
        new_instructions = movobfs.obfuscate(instruction)
        print(new_instructions)

byte_string = b''
for item in a:
    byte_string += item.instruction_bytes
with open('src/misc/myoutput.bin','wb') as file:
    file.write(byte_string)
