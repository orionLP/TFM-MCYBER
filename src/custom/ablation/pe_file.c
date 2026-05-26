#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "pe_header.h"
#include "pe_file.h"
#include "io_handling.h"

// pe file structure holding stream and header information
struct pe_file{
    FILE *contents;
    IMAGE_DOS_HEADER dos_header;
    DWORD signature;
    IMAGE_FILE_HEADER file_header;
    IMAGE_SECTION_HEADER *section_headers;
    char **section_names;
};

/// @brief check if mode exists
/// @param mode the mode
/// @return true if mode exists, false otherwise
static bool is_mode(const char *mode){
    return ((strcmp(mode, PE_FILE_READ_MODE) == 0) ||\
        (strcmp(mode, PE_FILE_WRITE_MODE) == 0) ||\
        (strcmp(mode, PE_FILE_RW_TRUNC_MODE) == 0));
}

/// @brief read the headers of a pe file
/// @param file the pe file
/// @return either PE_FILE_SUCCESS if success, PE_FILE_IO_ERROR or PE_FILE_ERROR in cases of error
static int read_data_structures(pe_file *file){
    TRY_IO_RETURN(
        fread(&(file->dos_header), sizeof(file->dos_header), 1, file->contents),
        1, 
        PE_FILE_IO_ERROR
    );

    TRY_IO_RETURN(
        fseek(file->contents, (long int) file->dos_header.e_lfanew, SEEK_SET), 
        0, 
        PE_FILE_IO_ERROR
    );
    
    TRY_IO_RETURN(
        fread(&(file->signature), sizeof(file->signature), 1, file->contents), 
        1, 
        PE_FILE_IO_ERROR
    );
    
    TRY_IO_RETURN(
        fread(&(file->file_header), sizeof(file->file_header), 1, file->contents), 
        1, 
        PE_FILE_IO_ERROR
    );

    TRY_IO_RETURN(
        fseek(file->contents, (long int) (file->dos_header.e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + file->file_header.SizeOfOptionalHeader), SEEK_SET), 
        0, 
        PE_FILE_IO_ERROR
    );
    
    file->section_headers = malloc(sizeof(*(file->section_headers)) * file->file_header.NumberOfSections);
    if(file->section_headers == NULL) 
        return PE_FILE_ERROR;

    TRY_IO_GOTO(
        fread(file->section_headers, sizeof(*(file->section_headers)), file->file_header.NumberOfSections, file->contents), 
        file->file_header.NumberOfSections, 
        error_free
    );

    return PE_FILE_SUCCESS;
error_free:
    free(file->section_headers);
    file->section_headers = NULL;
    return PE_FILE_IO_ERROR;
}

pe_file *pe_file_open(const char *path, const char *mode){
    if(!is_mode(mode))
        return NULL;
    
    pe_file *new_file = malloc(sizeof(pe_file));
    if(new_file == NULL)
        return NULL;
    
    new_file->contents = NULL;
    new_file->section_headers = NULL;
    new_file->section_names = NULL;

    new_file->contents = fopen(path, mode);
    if(new_file->contents == NULL){
        free(new_file);
        return NULL;
    }

    if(read_data_structures(new_file) != PE_FILE_SUCCESS){
        pe_file_destructor(new_file);
        return NULL;
    }

    new_file->section_names = malloc(sizeof(new_file->section_names) * new_file->file_header.NumberOfSections);
    if(new_file->section_names != NULL){
        for(int i = 0; i < new_file->file_header.NumberOfSections; i++)
            new_file->section_names[i] = NULL;

        for(int i = 0; i < new_file->file_header.NumberOfSections; i++){
            new_file->section_names[i] = malloc(sizeof(*(new_file->section_names[i])) * (IMAGE_SIZEOF_SHORT_NAME + 1));
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

int pe_file_number_of_sections(const pe_file *file){
    return file->file_header.NumberOfSections;
}

const char *pe_file_section_name(const pe_file *file, int number){
    if(number < 0 || number >= pe_file_number_of_sections(file))
        return NULL;
    return file->section_names[number];
}

int pe_file_section_number(const pe_file *file, const char *name){
    for(int i = 0; i < pe_file_number_of_sections(file); i++){
        // printf("The name in section number is %s, the name of section %d is %s, and strcmp is %d\n", name, i, pe_file_section_name(file, i), strcmp(name, pe_file_section_name(file, i)) == 0);
        if(strcmp(name, pe_file_section_name(file, i)) == 0)
            return i;
            
    }

    return PE_FILE_SECTION_NOT_FOUND;
}

int pe_file_section_size(const pe_file *file, const char *name){
    int number = pe_file_section_number(file, name);
    if(number == PE_FILE_SECTION_NOT_FOUND)
        return PE_FILE_SECTION_NOT_FOUND;
    return file->section_headers[number].SizeOfRawData;
}

/// @brief check that write is within size bounds of a part of the pe file
/// @param file the pe file
/// @param part_size the size of the part
/// @param amount how many bytes to write 
/// @param offset offset within the part
/// @return true if write is in bounds otherwise false
static bool in_bounds(pe_file *file, int part_size, int amount, int offset){
    return (offset >= 0) && (amount + offset <= part_size);
}

int pe_file_header_size(const pe_file *file){
    return file->dos_header.e_lfanew + 
        sizeof(file->signature) + 
        sizeof(file->file_header) + 
        file->file_header.SizeOfOptionalHeader +
        file->file_header.NumberOfSections * sizeof(*(file->section_headers));
}

int pe_file_header_write_constant(pe_file *file, uint8_t value, int amount, int offset){
    if(!in_bounds(file, pe_file_header_size(file), amount, offset))
        return PE_FILE_OUT_OF_BOUNDS;
    
    TRY_IO_RETURN(
        fseek(file->contents, 0, SEEK_SET), 
        0, 
        PE_FILE_IO_ERROR
    );
    
    for(int i = 0; i < amount; i++)
        TRY_IO_RETURN(
            fwrite(&value, sizeof(value), 1, file->contents), 
            1, 
            PE_FILE_IO_ERROR
        );

    return PE_FILE_SUCCESS;
}

int pe_file_section_write_constant(pe_file *file, const char *name, uint8_t value, int amount, int offset){
    int number = pe_file_section_number(file, name);
    // printf("name: %s\n", name);
    // printf("number: %d\n", number);
    if(number == PE_FILE_SECTION_NOT_FOUND)
        return PE_FILE_SECTION_NOT_FOUND;
        
    if(!in_bounds(file, file->section_headers[number].SizeOfRawData, amount, offset))
        return PE_FILE_OUT_OF_BOUNDS;
        
    int start_pointer = file->section_headers[number].PointerToRawData;
    TRY_IO_RETURN(
        fseek(file->contents, start_pointer + offset, SEEK_SET), 
        0, 
        PE_FILE_IO_ERROR
    );
    
    for(int i = 0; i < amount; i++)
    TRY_IO_RETURN(
        fwrite(&value, sizeof(value), 1, file->contents), 
        1, 
        PE_FILE_IO_ERROR
    );
        
    return PE_FILE_SUCCESS;
}

/// @brief print in hex byte per byte the contents of an array
/// @param from the contents to print
/// @param times the size of the array
static void print_hex_contents(const uint8_t *from, int times){
    for(int i = 0; i < times; i++){
        printf("%02x ", *(from + i));
    }
    printf("\n");
}

void pe_file_print_headers(const pe_file *file){
    printf("The DOS header has the following bytes:\n");
    print_hex_contents((uint8_t *) &(file->dos_header), sizeof(file->dos_header));

    printf("The bytes of the signature are:\n");
    print_hex_contents((uint8_t *) &(file->signature), sizeof(file->signature));

    printf("The file header has the following bytes:\n");
    print_hex_contents((uint8_t *) &(file->file_header), sizeof(file->file_header));

    printf("The bytes of the sections are the following:\n");
    for(int i = 0; i < file->file_header.NumberOfSections; i++){
        printf("Section %d %s:\n", i, file->section_headers[i].Name);
        print_hex_contents((uint8_t *) (file->section_headers + i), sizeof(*(file->section_headers)));
        printf("%s\n", file->section_names[i]);
    }
}