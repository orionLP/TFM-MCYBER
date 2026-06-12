#ifndef FAKE_WINDOWS_H
#define FAKE_WINDOWS_H

typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef int             BOOL;
typedef void*           HANDLE;
typedef void*           HMODULE;
typedef void*           LPVOID;
typedef char*           LPSTR;
typedef const char*     LPCSTR;

#define NULL 0
#define TRUE  1
#define FALSE 0

#define WINAPI __stdcall

typedef unsigned int  SIZE_T;
typedef void*         HMODULE;
typedef void*         HANDLE;

#define PAGE_READONLY           0x02
#define PAGE_READWRITE          0x04
#define PAGE_EXECUTE_READ       0x20
#define PAGE_EXECUTE_READWRITE  0x40
#define MEM_COMMIT              0x1000
#define MEM_RESERVE             0x2000

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16
#define IMAGE_SIZEOF_SHORT_NAME          8
#define IMAGE_DIRECTORY_ENTRY_IMPORT     1
#define IMAGE_DIRECTORY_ENTRY_BASERELOC  5
#define IMAGE_ORDINAL_FLAG               0x80000000UL
#define IMAGE_REL_BASED_HIGHLOW          3
#define IMAGE_SCN_MEM_EXECUTE            0x20000000UL
#define IMAGE_SCN_MEM_WRITE              0x80000000UL

typedef struct {
    WORD  e_magic;
    WORD  e_cblp;
    WORD  e_cp;
    WORD  e_crlc;
    WORD  e_cparhdr;
    WORD  e_minalloc;
    WORD  e_maxalloc;
    WORD  e_ss;
    WORD  e_sp;
    WORD  e_csum;
    WORD  e_ip;
    WORD  e_cs;
    WORD  e_lfarlc;
    WORD  e_ovno;
    WORD  e_res[4];
    WORD  e_oemid;
    WORD  e_oeminfo;
    WORD  e_res2[10];
    DWORD e_lfanew;
} IMAGE_DOS_HEADER;

typedef struct {
    DWORD VirtualAddress;
    DWORD Size;
} IMAGE_DATA_DIRECTORY;

typedef struct {
    WORD  Machine;
    WORD  NumberOfSections;
    DWORD TimeDateStamp;
    DWORD PointerToSymbolTable;
    DWORD NumberOfSymbols;
    WORD  SizeOfOptionalHeader;
    WORD  Characteristics;
} IMAGE_FILE_HEADER;

typedef struct {
    WORD   Magic;
    BYTE   MajorLinkerVersion;
    BYTE   MinorLinkerVersion;
    DWORD  SizeOfCode;
    DWORD  SizeOfInitializedData;
    DWORD  SizeOfUninitializedData;
    DWORD  AddressOfEntryPoint;
    DWORD  BaseOfCode;
    DWORD  BaseOfData;
    DWORD  ImageBase;
    DWORD  SectionAlignment;
    DWORD  FileAlignment;
    WORD   MajorOperatingSystemVersion;
    WORD   MinorOperatingSystemVersion;
    WORD   MajorImageVersion;
    WORD   MinorImageVersion;
    WORD   MajorSubsystemVersion;
    WORD   MinorSubsystemVersion;
    DWORD  Win32VersionValue;
    DWORD  SizeOfImage;
    DWORD  SizeOfHeaders;
    DWORD  CheckSum;
    WORD   Subsystem;
    WORD   DllCharacteristics;
    DWORD  SizeOfStackReserve;
    DWORD  SizeOfStackCommit;
    DWORD  SizeOfHeapReserve;
    DWORD  SizeOfHeapCommit;
    DWORD  LoaderFlags;
    DWORD  NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER;

typedef struct {
    DWORD              Signature;
    IMAGE_FILE_HEADER  FileHeader;
    IMAGE_OPTIONAL_HEADER OptionalHeader;
} IMAGE_NT_HEADERS;

typedef struct {
    BYTE  Name[IMAGE_SIZEOF_SHORT_NAME];
    union {
        DWORD PhysicalAddress;
        DWORD VirtualSize;
    } Misc;
    DWORD VirtualAddress;
    DWORD SizeOfRawData;
    DWORD PointerToRawData;
    DWORD PointerToRelocations;
    DWORD PointerToLinenumbers;
    WORD  NumberOfRelocations;
    WORD  NumberOfLinenumbers;
    DWORD Characteristics;
} IMAGE_SECTION_HEADER;

typedef struct {
    DWORD OriginalFirstThunk;
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;
    DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;

typedef struct {
    union {
        DWORD Function;
        DWORD Ordinal;
        DWORD AddressOfData;
    } u1;
} IMAGE_THUNK_DATA;

typedef struct {
    WORD Hint;
    BYTE Name[1];
} IMAGE_IMPORT_BY_NAME;

typedef struct {
    DWORD VirtualAddress;
    DWORD SizeOfBlock;
} IMAGE_BASE_RELOCATION;


BOOL  WINAPI VirtualProtect(LPVOID, DWORD, DWORD, DWORD*);
LPVOID WINAPI VirtualAlloc(LPVOID, SIZE_T, DWORD, DWORD);
HMODULE WINAPI GetModuleHandleA(const char*);
HMODULE WINAPI LoadLibraryA(const char*);
void* WINAPI GetProcAddress(HMODULE, const char*);

#endif