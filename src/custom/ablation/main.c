#include "pe_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

void do_combination(pe_file *file, bool *combination, const int n, int k, int remaining){
    if(remaining == 0){
        //act here
        
    } else{
        for(int i = k; i < (n - remaining + 1); i++){
            combination[i] = true;
            do_combination(file, combination, n, i + 1, remaining - 1);
            combination[i] = false;
        }
    }
}

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

int copy_directory_files(const char *source, const char *dest){
    DIR *input_dir = opendir(source);
    if(input_dir == NULL){
        printf("Cannot open input directory\n");
        exit(-1);
    }
    
    struct dirent *ep;
    errno = 0;
    while((ep = readdir(input_dir)) != NULL){
        if(strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
            continue;

        int source_len = strlen(source) + strlen(ep->d_name) + 1;
        int dest_len = strlen(dest) + strlen(ep->d_name) + 1;
        
        char *full_source = malloc(source_len * sizeof(char));
        if(full_source == NULL)
            return -1;
        char *full_dest = malloc(dest_len * sizeof(char));
        if(full_dest == NULL){
            free(full_source);
            return -1;
        }

        strcpy(full_dest, dest);
        strcpy(full_source, source);
        strcat(full_dest, ep->d_name);
        strcat(full_source, ep->d_name);

        if(copy_binary_file(full_source, full_dest) == -1){
            free(full_source);
            free(full_dest);
            return -1;
        }

        free(full_source);
        free(full_dest);
    }
    if(errno != 0){
        closedir(input_dir);
        return -1;
    }
    return 0;    
}

// DIR *output_dir = opendir(dest);
// if(output_dir == NULL){
//     printf("Cannot open the output directory\n");
//     exit(-1);
// }

int main(int argc, char **argv){
    if(argc < 3){
        printf("The executable should be called as 'executable input_directory output_directory'\n");
        exit(-1);
    }

    if(copy_directory_files(argv[1],argv[2]) == -1){
        printf("Error copying directory\n");
        exit(-1);
    }


    // pe_file *myfile = pe_file_open("./windows_exec.exe", PE_READWRITE_MODE);
    // int number_sections = pe_file_number_of_sections(myfile);
    // int number_combinations = 1;
    // if(number_sections != 0)
    //     number_combinations = 2 << (number_sections - 1); // do a power of 2

    // printf("Number of sections: %d\n", number_sections);
    // printf("Combinations to do: %d\n", number_combinations);

    // bool *combination = malloc(number_combinations * sizeof(bool));
    // if(combination == NULL){
    //     pe_file_destructor(myfile);
    //     return -1;
    // }

    // for(int i = 0; i <= number_sections; i++)
    //     do_combination(myfile, combination, number_sections, 0, i);
    
    // // print_headers(myfile);
    // // write_constant(myfile, ".text", 0xFA, 10, 12);

    // free(combination);
    // pe_file_destructor(myfile);


    // closedir(input_dir);
    // closedir(output_dir);
    return 0;
}