import src.lib.isahandling.isabyteshandler as isbytes
with open('src/misc/shell.bin','rb') as file:
    file_bytes = file.read()
handler = isbytes.X86ISAConversionHandler()
a = handler.convert_to_instructions(file_bytes)
byte_string = b''
for item in a:
    byte_string += item.instruction_bytes
with open('src/misc/myoutput.bin','wb') as file:
    file.write(byte_string)
