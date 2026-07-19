#ifndef FAKE_WINTERNL_H
#define FAKE_WINTERNL_H

#include <windows.h>
#include <winnt.h>

#ifndef __UNICODE_STRING_DEFINED
#define __UNICODE_STRING_DEFINED
struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
};
typedef struct _UNICODE_STRING UNICODE_STRING;
#endif

struct _PEB_LDR_DATA {
    BYTE Reserved1[8];
    PVOID Reserved2[3];
    LIST_ENTRY InMemoryOrderModuleList;
};

typedef struct _PEB_LDR_DATA PEB_LDR_DATA;
typedef struct _PEB_LDR_DATA *PPEB_LDR_DATA;

struct _LDR_DATA_TABLE_ENTRY {
    PVOID Reserved1[2];
    LIST_ENTRY InMemoryOrderLinks;
    PVOID Reserved2[2];
    PVOID DllBase;
    PVOID Reserved3[2];
    UNICODE_STRING FullDllName;
    BYTE Reserved4[8];
    PVOID Reserved5[3];
    __C89_NAMELESS union {
      ULONG CheckSum;
      PVOID Reserved6;
    };
    ULONG TimeDateStamp;
};

typedef struct _LDR_DATA_TABLE_ENTRY LDR_DATA_TABLE_ENTRY;
typedef struct _LDR_DATA_TABLE_ENTRY *PLDR_DATA_TABLE_ENTRY;

typedef VOID (NTAPI *PPS_POST_PROCESS_INIT_ROUTINE)(VOID);

struct _PEB {
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    BYTE Reserved2[1];
    PVOID Reserved3[2];
    PPEB_LDR_DATA Ldr;
    PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    PVOID Reserved4[3];
    PVOID AtlThunkSListPtr;
    PVOID Reserved5;
    ULONG Reserved6;
    PVOID Reserved7;
    ULONG Reserved8;
    ULONG AtlThunkSListPtr32;
    PVOID Reserved9[45];
    BYTE Reserved10[96];
    PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
    BYTE Reserved11[128];
    PVOID Reserved12[1];
    ULONG SessionId;
};

typedef struct _PEB PEB;
typedef struct _PEB *PPEB;

struct _RTL_USER_PROCESS_PARAMETERS {
    BYTE Reserved1[16];
    PVOID Reserved2[10];
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
};

typedef struct _RTL_USER_PROCESS_PARAMETERS RTL_USER_PROCESS_PARAMETERS;
typedef struct _RTL_USER_PROCESS_PARAMETERS *PRTL_USER_PROCESS_PARAMETERS;

#endif

