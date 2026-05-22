#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "pe_file.h"

#define WORD uint16_t
#define DWORD uint32_t

#define TRY_IO(io_call, expected_result, label) if((io_call) != (expected_result)) { goto label;}

// The following definitions are taken from wine 

typedef struct _IMAGE_DOS_HEADER {
    WORD  e_magic;      /* 00: MZ Header signature */
    WORD  e_cblp;       /* 02: Bytes on last page of file */
    WORD  e_cp;         /* 04: Pages in file */
    WORD  e_crlc;       /* 06: Relocations */
    WORD  e_cparhdr;    /* 08: Size of header in paragraphs */
    WORD  e_minalloc;   /* 0a: Minimum extra paragraphs needed */
    WORD  e_maxalloc;   /* 0c: Maximum extra paragraphs needed */
    WORD  e_ss;         /* 0e: Initial (relative) SS value */
    WORD  e_sp;         /* 10: Initial SP value */
    WORD  e_csum;       /* 12: Checksum */
    WORD  e_ip;         /* 14: Initial IP value */
    WORD  e_cs;         /* 16: Initial (relative) CS value */
    WORD  e_lfarlc;     /* 18: File address of relocation table */
    WORD  e_ovno;       /* 1a: Overlay number */
    WORD  e_res[4];     /* 1c: Reserved words */
    WORD  e_oemid;      /* 24: OEM identifier (for e_oeminfo) */
    WORD  e_oeminfo;    /* 26: OEM information; e_oemid specific */
    WORD  e_res2[10];   /* 28: Reserved words */
    DWORD e_lfanew;     /* 3c: Offset to extended header */
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER {
  WORD  Machine;
  WORD  NumberOfSections;
  DWORD TimeDateStamp;
  DWORD PointerToSymbolTable;
  DWORD NumberOfSymbols;
  WORD  SizeOfOptionalHeader;
  WORD  Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

// end of code from wine

struct pe_file{
    FILE *contents;
    IMAGE_DOS_HEADER dos_header;
    DWORD signature;
    IMAGE_FILE_HEADER file_header;
};

static bool is_mode(char *mode){
    return ((strcmp(mode, PE_READ_MODE) == 0) ||\
        (strcmp(mode, PE_WRITE_MODE) == 0) ||\
        (strcmp(mode, PE_READWRITE_MODE) == 0));
}

static int read_data_structures(pe_file *file){
    TRY_IO(fread(&(file->dos_header), sizeof(IMAGE_DOS_HEADER), 1, file->contents), 1, error);
    TRY_IO(fseek(file->contents, (long int) file->dos_header.e_lfanew, SEEK_SET), 0, error);
    TRY_IO(fread(&(file->signature), sizeof(DWORD), 1, file->contents), 1, error);
    TRY_IO(fread(&(file->file_header), sizeof(IMAGE_FILE_HEADER), 1, file->contents), 1, error);
    return 0;
error:
    return -1;
}

pe_file *read_pe_file(char *path, char *mode){
    if(!is_mode(mode)){
        return NULL;
    }
    
    pe_file *new_file = malloc(sizeof(pe_file));
    if(new_file == NULL){
        return NULL;
    }
    
    new_file->contents = fopen(path, mode);
    if(new_file->contents == NULL){
        free(new_file);
        return NULL;
    }

    if(read_data_structures(new_file) != 0){
        fclose(new_file->contents);
        free(new_file);
        return NULL;
    }

    return new_file;
}

void close_pe_file(pe_file *file){
    fclose(file->contents);
    free(file);
}

void print_hex_contents(uint8_t *from, int times){
    for(int i = 0; i < times; i++){
        printf("%02x ", *(from + i));
    }
}

void print_headers(pe_file *file){
    printf("The DOS header has the following bytes:\n");
    print_hex_contents((uint8_t *) &(file->dos_header), sizeof(IMAGE_DOS_HEADER));

    printf("\nThe bytes of the signature are:\n");
    print_hex_contents((uint8_t *) &(file->signature), sizeof(file->signature));

    printf("\nThe file header has the following bytes:\n");
    print_hex_contents((uint8_t *) &(file->file_header), sizeof(file->file_header));
}