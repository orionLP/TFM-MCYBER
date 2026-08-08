

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "shell_output.h"



// Shellcode size: 324 bytes

/* Function pointer type for executing shellcode */
typedef int (*shellcode_func_t)(void);

int execute_shellcode(unsigned char *code, unsigned int code_len) {
    void *exec_mem;
    shellcode_func_t shellcode_func;
    int result;
    DWORD old_protect;
    
    printf("[*] Shellcode size: %u bytes\n", code_len);
    printf("[*] Allocating executable memory...\n");
    
    /* Allocate memory with RWX permissions */
    exec_mem = VirtualAlloc(NULL, code_len, MEM_COMMIT | MEM_RESERVE,
                            PAGE_EXECUTE_READWRITE);
    
    if (!exec_mem) {
        fprintf(stderr, "[-] VirtualAlloc failed: %ld\n", GetLastError());
        return -1;
    }
    
    printf("[+] Allocated memory at: %p\n", exec_mem);
    
    /* Copy shellcode into executable memory */
    memcpy(exec_mem, code, code_len);
    printf("[+] Shellcode copied to executable memory\n");
    
    /* Cast to function pointer and execute */
    shellcode_func = (shellcode_func_t)exec_mem;
    
    printf("[*] Executing shellcode...\n");
    fflush(stdout);
    
    /* Execute shellcode */
    result = shellcode_func();
    
    printf("[*] Shellcode returned: %d (0x%x)\n", result, result);
    
    /* Cleanup */
    VirtualFree(exec_mem, 0, MEM_RELEASE);
    printf("[+] Freed executable memory\n");
    
    return result;
}

int main(int argc, char *argv[]) {
    printf("=== Shellcode Executor (Windows) ===\n");
    printf("[*] Global shellcode array: %p\n", (void *) shellcode);
    printf("[*] Array length: %u bytes\n", sizeof(shellcode));
    
    execute_shellcode(shellcode, sizeof(shellcode));
    
    return 0;
}

