
/**
 Compile with :
 
 mingw32-gcc.exe unpack.c -o unpacker.exe "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32
 
 **/

void *memcpy(void *dst, const void *src, unsigned int n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    while (n--) *d++ = *s++;
    return dst;
}

#include <windows.h>
#include <winnt.h>

// loads a PE in memory, returns the entry point address
void* load_PE (char* PE_data);

// some basic functions intended to limits the external libraries needed
int mystrcmp(char* a, char* b);
void mymemcpy(char* dst, char* src, unsigned int size);
void mymemset(char* dst, char c, unsigned int size);


void unpack_data(char* src, DWORD size) {
    DWORD oldProtect;
    //make sure we can write on the destination
    VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
    
    const int sbox_1[256] = {64, 122, 39, 136, 79, 179, 145, 80, 220, 25, 31, 22, 165, 204, 59, 187, 139, 76, 113, 81, 100, 8, 201, 91, 107, 143, 43, 30, 186, 78, 19, 167, 46, 26, 83, 231, 41, 103, 119, 203, 205, 4, 162, 250, 86, 101, 133, 200, 156, 195, 144, 0, 112, 149, 108, 12, 157, 213, 77, 142, 68, 193, 166, 242, 7, 18, 28, 182, 84, 14, 116, 154, 56, 176, 206, 53, 221, 252, 243, 124, 211, 194, 35, 104, 62, 66, 15, 63, 23, 212, 226, 128, 218, 2, 246, 137, 210, 164, 102, 51, 17, 169, 214, 92, 253, 197, 73, 215, 127, 33, 192, 95, 244, 189, 109, 161, 131, 199, 60, 146, 72, 175, 61, 37, 239, 24, 1, 58, 38, 236, 241, 177, 180, 20, 5, 235, 88, 230, 110, 184, 52, 117, 49, 174, 85, 97, 106, 114, 13, 89, 190, 254, 148, 118, 227, 237, 65, 158, 40, 217, 178, 105, 94, 255, 163, 71, 10, 93, 27, 208, 147, 172, 183, 160, 126, 188, 45, 233, 29, 48, 229, 6, 36, 170, 50, 67, 196, 151, 240, 129, 202, 90, 98, 57, 141, 130, 198, 99, 111, 120, 140, 96, 16, 123, 32, 70, 159, 125, 207, 173, 134, 222, 216, 234, 132, 42, 153, 181, 249, 47, 225, 75, 168, 171, 82, 228, 21, 238, 150, 224, 11, 245, 191, 69, 155, 209, 248, 54, 232, 55, 247, 9, 44, 219, 185, 138, 251, 223, 34, 121, 115, 74, 152, 135, 3, 87};
    const int sbox_2[256] = {197, 66, 207, 74, 209, 99, 123, 98, 10, 120, 12, 129, 214, 89, 68, 187, 71, 191, 87, 81, 45, 130, 47, 17, 172, 215, 5, 212, 113, 77, 192, 185, 180, 253, 78, 114, 102, 60, 142, 146, 64, 8, 73, 27, 134, 2, 128, 32, 57, 217, 55, 119, 83, 174, 239, 226, 177, 246, 166, 124, 211, 85, 21, 40, 107, 149, 228, 210, 188, 132, 251, 243, 4, 1, 156, 90, 157, 224, 118, 65, 50, 105, 116, 131, 29, 213, 133, 75, 79, 229, 206, 250, 58, 193, 24, 16, 220, 254, 247, 216, 222, 240, 242, 230, 202, 56, 35, 76, 62, 176, 51, 249, 145, 143, 20, 126, 70, 169, 167, 125, 195, 138, 159, 140, 190, 82, 97, 49, 110, 25, 148, 184, 18, 218, 115, 96, 227, 67, 203, 91, 232, 255, 196, 19, 153, 69, 7, 37, 53, 144, 231, 100, 30, 238, 147, 6, 34, 93, 14, 165, 164, 194, 0, 28, 80, 46, 248, 162, 22, 15, 208, 139, 109, 117, 141, 136, 237, 59, 163, 223, 26, 52, 23, 252, 41, 245, 151, 170, 95, 84, 219, 3, 92, 200, 201, 111, 205, 171, 158, 39, 72, 122, 234, 48, 108, 44, 155, 181, 94, 101, 199, 43, 135, 63, 86, 225, 103, 236, 152, 42, 112, 160, 186, 235, 244, 198, 104, 137, 183, 121, 189, 38, 13, 31, 127, 233, 204, 178, 168, 11, 9, 221, 106, 154, 175, 61, 161, 36, 88, 179, 150, 33, 241, 54, 182, 173};
    
    for(DWORD i = 0; i < size; i++){
        for(int j = 0; j < 256; j++)
            if(sbox_2[j] == (unsigned char) src[i]){
                src[i] = j;
                break;
            }
    }

    
    DWORD KEY = 0xCB;
    DWORD new_key = 0;
    for(DWORD i=0; i<size; ++i) {
        new_key = src[i];
        src[i] = src[i] ^ KEY;
        KEY = new_key;
    }

    for(DWORD i = 0; i < size; i++){
        for(int j = 0; j < 256; j++)
            if(sbox_1[j] == (unsigned char) src[i]){
                src[i] = j;
                break;
            }
    }
}


int _start(void) { //Entrypoint for the program

    // Get the current module VA (ie PE header addr)
    char* unpacker_VA = (char*) GetModuleHandleA(NULL);

    // get to the section header
    IMAGE_DOS_HEADER* p_DOS_HDR  = (IMAGE_DOS_HEADER*) unpacker_VA;
    IMAGE_NT_HEADERS* p_NT_HDR = (IMAGE_NT_HEADERS*) (((char*) p_DOS_HDR) + p_DOS_HDR->e_lfanew);
    IMAGE_SECTION_HEADER* sections = (IMAGE_SECTION_HEADER*) (p_NT_HDR + 1);

    char* packed_PE = NULL;
    char packed_section_name[] = ".packed";
    
    // search for the ".packed" section
    for(int i=0; i<p_NT_HDR->FileHeader.NumberOfSections; ++i) {
        if (mystrcmp(sections[i].Name, packed_section_name)) {
            packed_PE = unpacker_VA + sections[i].VirtualAddress;
            unpack_data(packed_PE, sections[i].SizeOfRawData);
            break;
        }
    }


    //load the data located at the .packed section
    if(packed_PE != NULL) {
        void (*packed_entry_point)(void) = (void(*)()) load_PE(packed_PE);
        packed_entry_point();
    }
}


void* load_PE (char* PE_data) {

    /** Parse header **/
    
    IMAGE_DOS_HEADER* p_DOS_HDR  = (IMAGE_DOS_HEADER*) PE_data;
    IMAGE_NT_HEADERS* p_NT_HDR = (IMAGE_NT_HEADERS*) (((char*) p_DOS_HDR) + p_DOS_HDR->e_lfanew);

    DWORD hdr_image_base = p_NT_HDR->OptionalHeader.ImageBase;
    DWORD size_of_image = p_NT_HDR->OptionalHeader.SizeOfImage;
    DWORD entry_point_RVA = p_NT_HDR->OptionalHeader.AddressOfEntryPoint;
    DWORD size_of_headers = p_NT_HDR->OptionalHeader.SizeOfHeaders;

    /** Allocate Memory **/
    char* ImageBase = (char*) VirtualAlloc(NULL, size_of_image, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if(ImageBase == NULL) {
        // Allocation failed
        return NULL;
    }

    /** Map PE sections in memory **/
    
    mymemcpy(ImageBase, PE_data, p_NT_HDR->OptionalHeader.SizeOfHeaders);
    

    // Section headers starts right after the IMAGE_NT_HEADERS struct, so we do some pointer arithmetic-fu here.
    IMAGE_SECTION_HEADER* sections = (IMAGE_SECTION_HEADER*) (p_NT_HDR + 1); 

    // For each sections
    for(int i=0; i<p_NT_HDR->FileHeader.NumberOfSections; ++i) {
        // calculate the VA we need to copy the content, from the RVA 
        // section[i].VirtualAddress is a RVA, mind it
        char* dest = ImageBase + sections[i].VirtualAddress; 

        // check if there is Raw data to copy
        if(sections[i].SizeOfRawData > 0) {
            // We copy SizeOfRaw data bytes, from the offset PointertoRawData in the file
            mymemcpy(dest, PE_data + sections[i].PointerToRawData, sections[i].SizeOfRawData);
        } else {
            mymemset(dest, 0, sections[i].Misc.VirtualSize);
        }
    }
    
    IMAGE_DATA_DIRECTORY* data_directory = p_NT_HDR->OptionalHeader.DataDirectory;
    
    /** Handle imports **/
    
    // load the address of the import descriptors array
    IMAGE_IMPORT_DESCRIPTOR* import_descriptors = (IMAGE_IMPORT_DESCRIPTOR*) (ImageBase + data_directory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
    
    // this array is null terminated
    for(int i=0; import_descriptors[i].OriginalFirstThunk != 0; ++i) {

        // Get the name of the dll, and import it
        char* module_name = ImageBase + import_descriptors[i].Name;
        HMODULE import_module = LoadLibraryA(module_name);
        if(import_module == NULL) {
            return NULL;
        }

        // the lookup table points to function names or ordinals => it is the IDT
        IMAGE_THUNK_DATA* lookup_table = (IMAGE_THUNK_DATA*) (ImageBase + import_descriptors[i].OriginalFirstThunk);

        // the address table is a copy of the lookup table at first
        // but we put the addresses of the loaded function inside => that's the IAT
        IMAGE_THUNK_DATA* address_table = (IMAGE_THUNK_DATA*) (ImageBase + import_descriptors[i].FirstThunk);

        // null terminated array, again
        for(int i=0; lookup_table[i].u1.AddressOfData != 0; ++i) {
            void* function_handle = NULL;
            
            // Check the lookup table for the adresse of the function name to import
            DWORD lookup_addr = lookup_table[i].u1.AddressOfData;

            if((lookup_addr & IMAGE_ORDINAL_FLAG) == 0) { //if first bit is not 1
                // import by name : get the IMAGE_IMPORT_BY_NAME struct
                IMAGE_IMPORT_BY_NAME* image_import = (IMAGE_IMPORT_BY_NAME*) (ImageBase + lookup_addr);
                // this struct points to the ASCII function name
                char* funct_name = (char*) &(image_import->Name);
                // get that function address from it's module and name
                function_handle = (void*) GetProcAddress(import_module, funct_name);
            } else {
                // import by ordinal, directly
                function_handle = (void*) GetProcAddress(import_module, (LPSTR) lookup_addr);
            }

            if(function_handle == NULL) {
                return NULL;
            }

            // change the IAT, and put the function address inside.
            address_table[i].u1.Function = (DWORD) function_handle;
        }
    }
    
    /** Handle relocations **/

    //this is how much we shifted the ImageBase
    DWORD delta_VA_reloc = ((DWORD) ImageBase) - p_NT_HDR->OptionalHeader.ImageBase;

    // if there is a relocation table, and we actually shitfted the ImageBase
    if(data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress != 0 && delta_VA_reloc != 0) {

        //calculate the relocation table address
        IMAGE_BASE_RELOCATION* p_reloc = (IMAGE_BASE_RELOCATION*) (ImageBase + data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
        
        //once again, a null terminated array
        while(p_reloc->VirtualAddress != 0) {

            // how any relocation in this block
            // ie the total size, minus the size of the "header", divided by 2 (those are words, so 2 bytes for each)
            DWORD size = (p_reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION))/2;
            // the first relocation element in the block, right after the header (using pointer arithmetic again)
            WORD* reloc = (WORD*) (p_reloc + 1);
            for(int i=0; i<size; ++i) {
                //type is the first 4 bits of the relocation word
                int type = reloc[i] >> 12;
                // offset is the last 12 bits
                int offset = reloc[i] & 0x0fff;
                //this is the address we are going to change
                DWORD* change_addr = (DWORD*) (ImageBase + p_reloc->VirtualAddress + offset);
                
                // there is only one type used that needs to make a change
                switch(type){
                    case IMAGE_REL_BASED_HIGHLOW :
                        *change_addr += delta_VA_reloc;
                        break;
                    default:
                        break;
                }
            }
            
            // switch to the next relocation block, based on the size
            p_reloc = (IMAGE_BASE_RELOCATION*) (((DWORD) p_reloc) + p_reloc->SizeOfBlock);
        }
    }
    
    /** Map PE sections privileges **/
    
    //Set permission for the PE hader to read only
    DWORD oldProtect;
    VirtualProtect(ImageBase, p_NT_HDR->OptionalHeader.SizeOfHeaders, PAGE_READONLY, &oldProtect);

    for(int i=0; i<p_NT_HDR->FileHeader.NumberOfSections; ++i) {
        char* dest = ImageBase + sections[i].VirtualAddress;
        DWORD s_perm = sections[i].Characteristics;
        DWORD v_perm = 0; //flags are not the same between virtal protect and the section header
        if(s_perm & IMAGE_SCN_MEM_EXECUTE) {
            v_perm = (s_perm & IMAGE_SCN_MEM_WRITE) ? PAGE_EXECUTE_READWRITE : PAGE_EXECUTE_READ;
        } else {
            v_perm = (s_perm & IMAGE_SCN_MEM_WRITE) ? PAGE_READWRITE : PAGE_READONLY;
        }
        VirtualProtect(dest, sections[i].Misc.VirtualSize, v_perm, &oldProtect);
    }

    return (void*) (ImageBase + entry_point_RVA);
}

int mystrcmp(char* a, char* b) {
    while(*a == *b && *a) {
        a++;
        b++;
    }
    return (*a == *b);
}

void mymemcpy(char* dst, char* src, unsigned int size) {
    for(unsigned int i=0; i<size; ++i) {
        dst[i] = src[i];
    }
}

void mymemset(char* dst, char c, unsigned int size) {
    for(unsigned int i=0; i<size; ++i) {
        dst[i] = c;
    }   
}

