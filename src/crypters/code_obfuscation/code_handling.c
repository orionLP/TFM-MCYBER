#include "code_handling.h"

#include <string.h>

struct in_memory_pe{
    IMAGE_DOS_HEADER *pe_dos_header;
    IMAGE_NT_HEADERS *pe_nt_header;
    IMAGE_SECTION_HEADER* sections;
    IMAGE_DATA_DIRECTORY* data_directory;
    IMAGE_IMPORT_DESCRIPTOR* import_descriptors;
    char *data; // this is the image base
    void *entry_point;
};

static void copy_to_virtual(const char *pe_data, char *image_base){
    IMAGE_DOS_HEADER* source_pe_dos_header = (IMAGE_DOS_HEADER *) pe_data;
    IMAGE_NT_HEADERS* source_pe_nt_header = (IMAGE_NT_HEADERS *) (pe_data + source_pe_dos_header->e_lfanew);
    IMAGE_SECTION_HEADER* source_sections = (IMAGE_SECTION_HEADER *) (source_pe_nt_header + 1); 

    // First copy the headers
    memcpy(image_base, pe_data, source_pe_nt_header->OptionalHeader.SizeOfHeaders);
    
    // Now copy each section
    for(int i = 0; i < source_pe_nt_header->FileHeader.NumberOfSections; i++){
        // Copy section to BASE + RVA = virtual address
        char *dest = image_base + source_sections[i].VirtualAddress;

        // Copy raw data or set to 0 if there is none
        if(source_sections[i].SizeOfRawData > 0){
            memcpy(dest, pe_data + source_sections[i].PointerToRawData, source_sections[i].SizeOfRawData);
        } else {
            memset(dest, 0, source_sections[i].Misc.VirtualSize);
        }
    }
}

static char *copy_to_pages(const char *pe_data){
    IMAGE_DOS_HEADER *pe_dos_header = (IMAGE_DOS_HEADER *) pe_data;
    IMAGE_NT_HEADERS *pe_nt_header = (IMAGE_NT_HEADERS *) (pe_data + pe_dos_header->e_lfanew);

    char *image_base = VirtualAlloc(NULL, pe_nt_header->OptionalHeader.SizeOfImage, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if(image_base == NULL)
        return NULL;

    copy_to_virtual(pe_data, image_base);

    return image_base;
}

static int load_libraries(in_memory_pe *new_pe){
    // For each module to import
    for(int i = 0; new_pe->import_descriptors[i].OriginalFirstThunk != 0; i++){
        // Get the dll name and import it
        char *module_name = new_pe->data + new_pe->import_descriptors[i].Name;
        HMODULE import_module = LoadLibraryA(module_name);
        if(import_module == NULL)
            return -1;
        
        // IDT and IAT of module
        IMAGE_THUNK_DATA *lookup_table = (IMAGE_THUNK_DATA *) (new_pe->data + new_pe->import_descriptors[i].OriginalFirstThunk);
        IMAGE_THUNK_DATA *address_table = (IMAGE_THUNK_DATA *) (new_pe->data + new_pe->import_descriptors[i].FirstThunk);

        // get the address of each function
        for(int i = 0; lookup_table[i].u1.AddressOfData != 0; i++){
            void* function_handle = NULL;
            DWORD lookup_addr = lookup_table[i].u1.AddressOfData;
            if((lookup_addr & IMAGE_ORDINAL_FLAG) == 0) {
                // import by name : get the IMAGE_IMPORT_BY_NAME struct
                IMAGE_IMPORT_BY_NAME* image_import =(IMAGE_IMPORT_BY_NAME*) (new_pe->data + lookup_addr);
                char* funct_name = (char *) &(image_import->Name);
                function_handle = GetProcAddress(import_module, funct_name);
            } else {
                // import by ordinal, directly
                function_handle = GetProcAddress(import_module, (LPSTR) lookup_addr);
            }
            
            if(function_handle == NULL) {
                return -1;
            }

            // change the IAT, and put the function address inside.
            address_table[i].u1.Function = (DWORD) function_handle;
        }
    }

    return 0;
}

static void resolve_relocations(in_memory_pe *new_pe){
    DWORD delta_reloc = ((DWORD) (new_pe->data)) - new_pe->pe_nt_header->OptionalHeader.ImageBase;

    // do this if there is a relocation table and the there is a need to relocate
    if(new_pe->data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress != 0 && delta_reloc != 0){
        // Find the relocation address table
        IMAGE_BASE_RELOCATION* p_reloc = (IMAGE_BASE_RELOCATION*) (new_pe->data + new_pe->data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);

        while(p_reloc->VirtualAddress != 0) {
            DWORD size = (p_reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION))/2;
            WORD* reloc = (WORD*) (p_reloc + 1);
            for(int i=0; i<size; ++i) {
                int type = reloc[i] >> 12;
                int offset = reloc[i] & 0x0fff;
                DWORD* change_addr = (DWORD*) (new_pe->data + p_reloc->VirtualAddress + offset);

                // there is only one type used that needs to make a change
                switch(type){
                    case IMAGE_REL_BASED_HIGHLOW :
                        *change_addr += delta_reloc;
                        break;
                    default:
                        break;
                }
            }

            // switch to the next relocation block, based on the size
            p_reloc = (IMAGE_BASE_RELOCATION*) (((DWORD) p_reloc) + p_reloc->SizeOfBlock);
        }        
    }
}

static int set_protections(in_memory_pe *new_pe){
    DWORD oldProtect;

    // Set protection of the headers
    if(VirtualProtect(new_pe->data, new_pe->pe_nt_header->OptionalHeader.SizeOfHeaders, PAGE_READONLY, &oldProtect) == 0)
        return -1;

    for(int i=0; i<new_pe->pe_nt_header->FileHeader.NumberOfSections; ++i) {
        char* dest = new_pe->data + new_pe->sections[i].VirtualAddress;
        DWORD s_perm = new_pe->sections[i].Characteristics;
        DWORD v_perm = 0; 
        if(s_perm & IMAGE_SCN_MEM_EXECUTE) {
            v_perm = (s_perm & IMAGE_SCN_MEM_WRITE) ? PAGE_EXECUTE_READWRITE : PAGE_EXECUTE_READ;
        } else {
            v_perm = (s_perm & IMAGE_SCN_MEM_WRITE) ? PAGE_READWRITE : PAGE_READONLY;
        }
        if(VirtualProtect(dest, new_pe->sections[i].Misc.VirtualSize, v_perm, &oldProtect) == 0)
            return -1;
    }

    return 0;
}

in_memory_pe *code_handling_load_pe(const char *pe_data, DWORD size){
    in_memory_pe *new_pe = malloc(size);
    if(new_pe == NULL)
        goto error;
    
    new_pe->data = copy_to_pages(pe_data);
    if(new_pe->data == NULL)
        goto error;

    new_pe->pe_dos_header = (IMAGE_DOS_HEADER *) new_pe->data;
    new_pe->pe_nt_header = (IMAGE_NT_HEADERS *) (new_pe->data + new_pe->pe_dos_header->e_lfanew);
    new_pe->sections = (IMAGE_SECTION_HEADER *) (new_pe->pe_nt_header + 1);    
    new_pe->data_directory = new_pe->pe_nt_header->OptionalHeader.DataDirectory;
    new_pe->import_descriptors = (IMAGE_IMPORT_DESCRIPTOR *) (new_pe->data + new_pe->data_directory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
    
    if(load_libraries(new_pe) != 0)
        goto error;

    resolve_relocations(new_pe);

    if(set_protections(new_pe) != 0)
        goto error;

    new_pe->entry_point = new_pe->data + new_pe->pe_nt_header->OptionalHeader.AddressOfEntryPoint;

    return new_pe;
error:
    free(new_pe);
    return NULL;
}

void code_handling_execute(in_memory_pe *new_pe){
    void (*execute_entry_point)(void) = (void(*)()) new_pe->entry_point;
    execute_entry_point();
}
