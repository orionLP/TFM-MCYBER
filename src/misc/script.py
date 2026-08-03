import src.lib.isahandling.isabyteshandler as isbytes

with open('src/misc/shell.bin','rb') as file:
    file_bytes = file.read()

handler = isbytes.X86ISAConversionHandler()
a = handler.convert_to_instructions(file_bytes)
a
