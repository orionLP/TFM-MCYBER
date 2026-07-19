#ifndef WINDOWS_TYPEDEFS_I686_H
#define WINDOWS_TYPEDEFS_I686_H

#ifdef NOSTDLIB
#include <nostdlib.h>
#endif 

/* i686 Windows MinGW type definitions */
#define RESTRICTED_POINTER restrict


/* Basic integer types */
typedef unsigned long long ULONGLONG;
typedef unsigned long ULONG;
typedef signed long LONG;
typedef unsigned int UINT;

/* Pointer-sized types (32-bit on i686) */
typedef unsigned int UINT_PTR;
typedef signed long LONG_PTR;
typedef unsigned long ULONG_PTR;


/* Callback types that depend on pointer-sized types */
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef LONG_PTR LRESULT;

 
/* Basic types */
typedef unsigned short USHORT;
typedef unsigned char BYTE;
typedef void VOID;
 
/* String types */
typedef wchar_t *PWSTR;
typedef const wchar_t *PCWSTR;
 
/* Calling convention (i686/x86) */

#ifndef NTAPI
#define __stdcall
#define NTAPI __stdcall
#endif
 
/* Forward declarations for complex types */
typedef struct _RTL_USER_PROCESS_PARAMETERS *PRTL_USER_PROCESS_PARAMETERS;
typedef struct _LDR_DATA_TABLE_ENTRY *PLDR_DATA_TABLE_ENTRY;
typedef struct _PEB *PPEB;
 
/* Function pointer types */
typedef VOID (NTAPI *PPS_POST_PROCESS_INIT_ROUTINE)(VOID);
 
/* PE/Image header pointer types */
typedef struct _IMAGE_DOS_HEADER *PIMAGE_DOS_HEADER;
typedef struct _IMAGE_NT_HEADERS *PIMAGE_NT_HEADERS;
typedef struct _IMAGE_EXPORT_DIRECTORY *PIMAGE_EXPORT_DIRECTORY;
 
/* Optional: Full struct definitions if needed */
struct _IMAGE_EXPORT_DIRECTORY {
    UINT Characteristics;
    UINT TimeDateStamp;
    USHORT MajorVersion;
    USHORT MinorVersion;
    UINT Name;
    UINT Base;
    UINT NumberOfFunctions;
    UINT NumberOfNames;
    UINT AddressOfFunctions;
    UINT AddressOfNames;
    UINT AddressOfNameOrdinals;
};
 
typedef struct _IMAGE_EXPORT_DIRECTORY IMAGE_EXPORT_DIRECTORY;

#endif /* WINDOWS_TYPEDEFS_I686_H */
