#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "pe_file.h"

struct pe_file{
    FILE *contents;
    int size;
};

static bool is_mode(char *mode){
    return !((strcmp(mode, PE_READ_MODE) == 0) ||\
        (strcmp(mode, PE_WRITE_MODE) == 0) ||\
        (strcmp(mode, PE_READWRITE_MODE) == 0));
}

struct pe_file *read_pe_file(char *path, char *mode){
    if(!is_mode(mode)){
        return NULL;
    }
    
    struct pe_file *new_file = malloc(sizeof(struct pe_file));
    if(new_file == NULL){
        return NULL;
    }
    
    new_file->contents = fopen(path, mode);
    if(new_file->contents == NULL){
        free(new_file);
        return NULL;
    }

    return new_file;
}

void delete_pe_file(struct pe_file *file){
    fclose(file->contents);
    free(file);
}
