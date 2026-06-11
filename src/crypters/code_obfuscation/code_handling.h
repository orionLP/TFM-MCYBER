#ifndef CODE_HANDLING
#define CODE_HANDLING

#include <stdlib.h>
#include <windows.h>

typedef struct in_memory_pe in_memory_pe;

in_memory_pe *code_handling_load_pe(const char *pe_data, DWORD size);
void code_handling_execute(in_memory_pe *new_pe);

#endif