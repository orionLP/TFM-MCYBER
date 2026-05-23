#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "pe_file.h"

#define TRY_IO(io_call, expected_result, label) if((io_call) != (expected_result)) { goto label;}

// The following definitions are taken from wine 

#define BYTE uint8_t
#define WORD uint16_t
#define DWORD uint32_t
#define IMAGE_SIZEOF_SHORT_NAME 8

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

typedef struct _IMAGE_SECTION_HEADER {
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
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

// end of code from wine

struct pe_file{
    FILE *contents;
    IMAGE_DOS_HEADER dos_header;
    DWORD signature;
    IMAGE_FILE_HEADER file_header;
    // for now i do not need the optional directories
    IMAGE_SECTION_HEADER *section_headers;
    char **section_names;
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
    TRY_IO(fseek(file->contents, (long int) (file->dos_header.e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + file->file_header.SizeOfOptionalHeader), SEEK_SET), 0, error);
    
    file->section_headers = malloc(sizeof(IMAGE_SECTION_HEADER) * file->file_header.NumberOfSections);
    if(file->section_headers == NULL) 
        goto error;

    TRY_IO(fread(file->section_headers, sizeof(IMAGE_SECTION_HEADER), file->file_header.NumberOfSections, file->contents), file->file_header.NumberOfSections, error_free);

    return 0;
error:
    return -1;
error_free:
    free(file->section_headers);
    file->section_headers = NULL;
    return -1;
}

pe_file *pe_file_open(char *path, char *mode){
    if(!is_mode(mode)){
        return NULL;
    }
    
    pe_file *new_file = malloc(sizeof(pe_file));
    if(new_file == NULL){
        return NULL;
    }
    
    new_file->contents = NULL;
    new_file->section_headers = NULL;
    new_file->section_names = NULL;

    new_file->contents = fopen(path, mode);
    if(new_file->contents == NULL){
        pe_file_destructor(new_file);
        return NULL;
    }

    if(read_data_structures(new_file) != 0){
        pe_file_destructor(new_file);
        return NULL;
    }

    new_file->section_names = malloc(sizeof(char *) * new_file->file_header.NumberOfSections);
    if(new_file->section_names != NULL){
        for(int i = 0; i < new_file->file_header.NumberOfSections; i++){
            new_file->section_names[i] = NULL;
        }

        for(int i = 0; i < new_file->file_header.NumberOfSections; i++){
            new_file->section_names[i] = malloc(sizeof(char) * (IMAGE_SIZEOF_SHORT_NAME + 1));
            if(new_file->section_names[i] != NULL){
                for(int j = 0; j < IMAGE_SIZEOF_SHORT_NAME; j++)
                    new_file->section_names[i][j] = new_file->section_headers[i].Name[j];
                new_file->section_names[i][IMAGE_SIZEOF_SHORT_NAME] = '\0';
            } else{
                pe_file_destructor(new_file);
                return NULL;
            }
        }
    } else{
        pe_file_destructor(new_file);
        return NULL;
    }

    return new_file;
}

void pe_file_destructor(pe_file *file){
    fclose(file->contents);
    free(file->section_headers);
    
    if(file->section_names != NULL){
    for(int i = 0; i < file->file_header.NumberOfSections; i++)
        free(file->section_names[i]);
    }
    free(file->section_names);

    free(file);
}

int pe_file_number_of_sections(pe_file *file){
    return file->file_header.NumberOfSections;
}

const char *pe_file_section_name(pe_file *file, int number){
    return file->section_names[number];
}

int pe_file_section_number(pe_file *file, const char *name){
    for(int i = 0; i < pe_file_number_of_sections(file); i++){
        if(strcmp(name, pe_file_section_name(file, i)) == 0){
            return i;
        }
    }
    return -1;
}

int pe_file_section_size(pe_file *file, const char *name){
    int number = pe_file_section_number(file, name);
    if(number == -1)
        return -1;
    return file->section_headers[number].SizeOfRawData;
}

bool in_bounds(pe_file *file, int section_number, int amount, int offset){
    return amount + offset <= file->section_headers[section_number].SizeOfRawData;
}

int pe_file_write_constant(pe_file *file, const char *name, uint8_t value, int amount, int offset){
    int number = pe_file_section_number(file, name);
    if(!in_bounds(file, number, amount, offset) == -1)
        return -1;

    int start_pointer = file->section_headers[number].PointerToRawData;
    TRY_IO(fseek(file->contents, start_pointer + offset, SEEK_SET), 0, error);
    for(int i = 0; i < amount; i++)
        TRY_IO(fwrite(&value, sizeof(value), 1, file->contents), 1, error);
error:
    return -1;
}

static void print_hex_contents(uint8_t *from, int times){
    for(int i = 0; i < times; i++){
        printf("%02x ", *(from + i));
    }
    printf("\n");
}

void pe_file_print_headers(pe_file *file){
    printf("The DOS header has the following bytes:\n");
    print_hex_contents((uint8_t *) &(file->dos_header), sizeof(IMAGE_DOS_HEADER));

    printf("The bytes of the signature are:\n");
    print_hex_contents((uint8_t *) &(file->signature), sizeof(file->signature));

    printf("The file header has the following bytes:\n");
    print_hex_contents((uint8_t *) &(file->file_header), sizeof(file->file_header));

    printf("The bytes of the sections are the following:\n");
    for(int i = 0; i < file->file_header.NumberOfSections; i++){
        printf("Section %d %s:\n", i, file->section_headers[i].Name);
        print_hex_contents((uint8_t *) (file->section_headers + i), sizeof(IMAGE_SECTION_HEADER));
        printf("%s\n", file->section_names[i]);
    }
}