#ifndef FAKE_WINNT_H
#define FAKE_WINNT_H

#include <ntdef.h>
#include <missingtypes.h>


#define IMAGE_DIRECTORY_ENTRY_EXPORT 0

typedef void *PVOID;

#if defined(_ARM_) || defined(_ARM64_)
#define NTAPI
#else
#define __stdcall
#define NTAPI __stdcall
#endif
#define NTAPI_INLINE NTAPI

#ifndef _LIST_ENTRY_DEFINED
#define _LIST_ENTRY_DEFINED

  struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
  };

  typedef struct _LIST_ENTRY LIST_ENTRY;
  typedef struct _LIST_ENTRY *PLIST_ENTRY;
  typedef struct _LIST_ENTRY *RESTRICTED_POINTER PRLIST_ENTRY;

  struct _SINGLE_LIST_ENTRY {
    struct _SINGLE_LIST_ENTRY *Next;
  };
  
  typedef struct _SINGLE_LIST_ENTRY SINGLE_LIST_ENTRY;
  typedef struct _SINGLE_LIST_ENTRY *PSINGLE_LIST_ENTRY;

#endif /* _LIST_ENTRY_DEFINED */

#endif
