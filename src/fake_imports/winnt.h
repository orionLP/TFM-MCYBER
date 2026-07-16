#ifndef FAKE_WINNT_H
#define FAKE_WINNT_H

#if defined(_ARM_) || defined(_ARM64_)
#define NTAPI
#else
#define NTAPI __stdcall
#endif
#define NTAPI_INLINE NTAPI

#ifndef _LIST_ENTRY_DEFINED
#define _LIST_ENTRY_DEFINED

  typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
  } LIST_ENTRY,*PLIST_ENTRY,*RESTRICTED_POINTER PRLIST_ENTRY;

  typedef struct _SINGLE_LIST_ENTRY {
    struct _SINGLE_LIST_ENTRY *Next;
  } SINGLE_LIST_ENTRY,*PSINGLE_LIST_ENTRY;

  typedef struct LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  typedef LIST_ENTRY32 *PLIST_ENTRY32;

  typedef struct LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  typedef LIST_ENTRY64 *PLIST_ENTRY64;

#endif /* _LIST_ENTRY_DEFINED */

#endif
