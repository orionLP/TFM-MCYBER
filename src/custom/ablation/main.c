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

int do_combination(const char *source_file, const char *destination_file, pe_file *file, bool *combination, const int n, int k, int remaining){
    if(remaining == 0){
        char final_name[256] = {0};
        create_combination_name(final_name, destination_file, file, combination, n - 1);
        if(copy_binary_file(source_file, final_name) == -1)
            return -1;
        pe_file *new_file = pe_file_open(final_name, PE_READWRITE_MODE);

        if(combination[0])
            if(pe_file_header_write_constant(new_file, 0, pe_file_header_size(new_file), 0) == -1){
                pe_file_destructor(new_file); 
                return -2;
            }
        for(int i = 1; i < n; i++){
            if(combination[i]){
                const char *section_name = pe_file_section_name(new_file, i - 1);
                if(pe_file_section_write_constant(new_file, section_name, 0, pe_file_section_size(new_file, section_name), 0) == -1){
                    pe_file_destructor(new_file);
                    return -2 - i;
                }
            }
        }

        pe_file_destructor(new_file);
    } else{
        for(int i = k; i < (n - remaining + 1); i++){
            combination[i] = true;
            int return_code = do_combination(source_file, destination_file, file, combination, n, i + 1, remaining - 1);
            if(return_code != 0)
                return return_code;
            combination[i] = false;
        }
    }

    return 0;
}

int main(int argc, char **argv){
    if(argc < 3){
        printf("The executable should be called as 'executable input_directory output_directory'\n");
        exit(-1);
    }
    
    printf("Performing ablation from %s to %s\n", argv[1], argv[2]);

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

        printf("Processing file %s\n", ep->d_name);
        
        strcpy(source_file, argv[1]);
        strcat(source_file, ep->d_name);

        pe_file *next_file = pe_file_open(source_file, PE_READ_MODE);
        if(next_file == NULL){
            printf("Unable to open file %s to process headers\n", ep->d_name);
            exit(-1);
        }
        int number_sections = pe_file_number_of_sections(next_file);
        if(number_sections + 1 > 8){
            printf("Cannot do more than 8 combinations, it would produce too many files\n");
            exit(-1);
        }

        printf("The number of combinations needed for this file are %d\n",  2 << number_sections); // do a power of 2 ** (number_sections + 1)

        bool *combination = calloc((number_sections + 1), sizeof(bool));
        if(combination == NULL){
            pe_file_destructor(next_file);
            exit(-1);
        }

        strcpy(destination_file, argv[2]);
        strcat(destination_file, ep->d_name);

        for(int i = 0; i <= number_sections + 1; i++){
            int status_code = do_combination(source_file, destination_file, next_file, combination, number_sections + 1, 0, i);
            if(status_code != 0){
                printf("Error while doing a combination of this file %d\n", status_code);
                for(int j = 0; j < number_sections + 1; j++)
                    printf(" %d ", combination[j]);
                printf("\n");
                exit(-1);
            }
        }
        
        printf("\n");
        
        pe_file_destructor(next_file);
        free(combination);
    }
    if(errno != 0){
        perror("There has been a problem while opening a file of the source directory\n");
        closedir(input_dir);
        return -1;
    }

    closedir(input_dir);
    return 0;
}