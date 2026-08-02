import abc

class InstructionParser(abc.ABC):

    @abc.abstractmethod
    def parse(self, instruction_bytes: bytes) -> tuple[bytes, ...]:
        pass

class X86InstructionParser(InstructionParser):

    def parse(self, instruction_bytes: bytes) -> tuple[bytes, ...]:
        prefix = b''
        opcode = b''
        modrm = b''
        sib = b''
        disp = b''
        imm = b''

        sib_bytes = 0
        disp_bytes = 0
        
        # Extract the prefix first 
        instruction_pointer = 0
        for b in instruction_bytes:
            if b in [0x26, 0x2e, 0x36, 0x3e, 0x64, 0x65, 0x66, 0x67, 0x9b, 0xf0, 0xf1, 0xf2, 0xf3]:
                prefix += bytes([b])
                instruction_pointer += 1
            else:
                break

        # Extract the optcode
        if instruction_bytes[instruction_pointer] == 0x0f: # 2 byte opcode
            opcode = instruction_bytes[instruction_pointer:instruction_pointer+1]
            instruction_pointer+= 2
        else:
            opcode = instruction_bytes[instruction_pointer:instruction_pointer+1]
            instruction_pointer += 1

        # Extract modrm
        modrm = instruction_bytes[instruction_pointer:instruction_pointer+1]
        instruction_pointer += 1
        
        if len(modrm) > 0:
            mod = (modrm[0] & 0xc0) >> 6
            rm = (modrm[0] & 0x07)
            if mod==0:
                if rm==0x05: # 32-bit displacement only
                    disp_bytes = 4
            elif mod==1:
                disp_bytes = 1 # disp8
            elif mod==2:
                disp_bytes = 4 # disp32

            if rm==0x04:
                sib_bytes = 1

        # sib
        if sib_bytes == 1:
            sib = instruction_bytes[instruction_pointer:instruction_pointer+1]
            instruction_pointer += 1

        # disp
        if disp_bytes > 0:
            disp = instruction_bytes[instruction_pointer:instruction_pointer+disp_bytes]
            instruction_pointer += disp_bytes

        # imm
        imm = instruction_bytes[instruction_pointer:]

        return prefix, opcode, modrm, sib, disp, imm



