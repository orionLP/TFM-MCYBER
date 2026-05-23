#include "pe_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int copy_binary_file(const char *source, const char *dest){
    FILE *source_file = fopen(source, "rb");
    FILE *dest_file = fopen(dest, "wb+");
    
    if(source_file == NULL || dest_file == NULL)
        return -1;
    if(fseek(source_file, 0L, SEEK_END) != 0)
    return -1;
    long file_size = ftell(source_file);
    if(fseek(source_file, 0L, SEEK_SET) != 0)
        return -1;

    uint8_t *buff = malloc(file_size);
    if(fread(buff, sizeof(uint8_t), file_size, source_file) != file_size)
        return -1;
    if(fwrite(buff, sizeof(uint8_t), file_size, dest_file) != file_size)
        return -1;

    free(buff);
    fclose(source_file);
    fclose(dest_file);
    return 0;
}

void create_combination_name(char *buff, const char *filepath, pe_file *file, const bool *combination, const int number_of_sections){
    strcpy(buff, filepath);
    if(combination[0])
        strcat(buff, "._header_");
    for(int i = 0; i < number_of_sections; i++)
        if(combination[i + 1])
            strcat(buff, pe_file_section_name(file, i));
}

void do_combination(const char *source_file, const char *destination_file, pe_file *file, bool *combination, const int n, int k, int remaining){
    if(remaining == 0){
        char final_name[256] = {0};
        create_combination_name(final_name, destination_file, file, combination, n - 1);
        copy_binary_file(source_file, final_name);
        if(combination[0])
            pe_file_header_write_constant(file, 0, pe_file_header_size(file), 0);
        for(int i = 1; i < n; i++){
            if(combination[i]){
                const char *section_name = pe_file_section_name(file, i - 1);
                pe_file_section_write_constant(file, section_name, 0, pe_file_section_size(file, section_name), 0);
            }
        }
    } else{
        for(int i = k; i < (n - remaining + 1); i++){
            combination[i] = true;
            do_combination(source_file, destination_file, file, combination, n, i + 1, remaining - 1);
            combination[i] = false;
        }
    }
}

int main(int argc, char **argv){
    if(argc < 3){
        printf("The executable should be called as 'executable input_directory output_directory'\n");
        exit(-1);
    }
    
    DIR *input_dir = opendir(argv[1]);
    if(input_dir == NULL){
        printf("Cannot open the input directory\n");
        exit(-1);
    }
    
    char source_file[256] = {0};
    char destination_file[256] = {0};
    struct dirent *ep;
    errno = 0;
    while((ep = readdir(input_dir)) != NULL){
        if(strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
            continue;

        strcpy(source_file, argv[1]);
        strcat(source_file, ep->d_name);

        pe_file *next_file = pe_file_open(source_file, PE_READ_MODE);
        int number_sections = pe_file_number_of_sections(next_file);
        // int number_combinations = 2 << number_sections; // do a power of 2 ** (number_sections + 1)

        bool *combination = calloc((number_sections + 1), sizeof(bool));
        if(combination == NULL){
            pe_file_destructor(next_file);
            return -1;
        }

        strcpy(destination_file, argv[2]);
        strcat(destination_file, ep->d_name);

        for(int i = 0; i <= number_sections + 1; i++)
            do_combination(source_file, destination_file, next_file, combination, number_sections + 1, 0, i);
        
        pe_file_destructor(next_file);
        free(combination);
    }
    if(errno != 0){
        closedir(input_dir);
        return -1;
    }

    closedir(input_dir);
    return 0;
}