#ifndef CRYPTO_INTERFACE
#define CRYPTO_INTERFACE

#include <stdint.h>

#define DWORD uint32_t

void decrypt_data(char* src, DWORD size);

#endif