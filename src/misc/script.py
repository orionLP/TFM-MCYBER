import src.lib.isahandling.isabyteshandler as isbytes
import src.lib.obfuscation.assembly.movobfuscation as movobfuscation
import src.lib.obfuscation.assembly.pushobfuscation as pushobfuscation
import src.lib.obfuscation.assembly.movdispobfuscation as movdispobfuscation
import src.lib.isahandling.sequencing as sequencing
import src.lib.isahandling.isa as isa

with open('src/misc/shell.bin','rb') as file:
    file_bytes = file.read()
handler = isbytes.X86ISAConversionHandler()
a = handler.convert_to_instructions(file_bytes)
movobfs = movobfuscation.StandardX86MOVObfuscator()
pushobfs = pushobfuscation.StandardX86PUSHObfuscator()
movdispobfs = movdispobfuscation.StandardX86MOVDISPObfuscator()
final_sequencer = sequencing.X86SequencingHandler()
index = 0
while index < len(a):
    next_instruction = a[index]

    if next_instruction.identified_function in [isa.X86Instructions.PUSHIMM8, isa.X86Instructions.PUSHIMM32]:
        new_instructions = pushobfs.obfuscate(next_instruction)

        del a[index]
       
        for item in reversed(new_instructions):
            a.insert(index, item)
        index += len(new_instructions)
    elif next_instruction.identified_function in [isa.X86Instructions.MOVR8DISP8MEM,isa.X86Instructions.MOVR8DISP32MEM, isa.X86Instructions.MOVR16DISP8MEM, isa.X86Instructions.MOVR16DISP32MEM, isa.X86Instructions.MOVR32DISP8MEM, isa.X86Instructions.MOVR32DISP32MEM, isa.X86Instructions.MOVR8BIS, isa.X86Instructions.MOVR16BIS, isa.X86Instructions.MOVR32BIS, isa.X86Instructions.MOVR8IS, isa.X86Instructions.MOVR16IS, isa.X86Instructions.MOVR32IS, isa.X86Instructions.MOVR8BISDISP8, isa.X86Instructions.MOVR8BISDISP32, isa.X86Instructions.MOVR16BISDISP8, isa.X86Instructions.MOVR16BISDISP32, isa.X86Instructions.MOVR32BISDISP8, isa.X86Instructions.MOVR32BISDISP32]:
        
        new_instructions = movdispobfs.obfuscate(next_instruction)
        
        del a[index]
        for item in reversed(new_instructions):
            a.insert(index, item)
        index += len(new_instructions)
    else:
        index += 1

for i in range(16):
    index = 0
    while index < len(a):
        next_instruction = a[index]
        if next_instruction.identified_function in [isa.X86Instructions.MOVR8IMM8, isa.X86Instructions.MOVR16IMM16, isa.X86Instructions.MOVR32IMM32]:
            new_instructions = movobfs.obfuscate(next_instruction)

            del a[index]
            for item in reversed(new_instructions):
                a.insert(index, item)
            index += len(new_instructions)
        else:
            index += 1
        
final_sequencer.fix_jumps(a)


byte_string = b''
for item in a:
    byte_string += item.instruction_bytes
with open('src/misc/myoutput.bin','wb') as file:
    file.write(byte_string)
