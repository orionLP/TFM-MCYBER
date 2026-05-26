#include "pe_file.h"
#include "io_handling.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define MAIN_SUCCESS (0)
#define MAIN_ERROR (-1)
#define BUFF_SIZSE (1024)
#define MAX_NUM_SECTIONS (8)

char tmpbuff[BUFF_SIZSE] = {0};
const char *header_name = "._header_";

/// @brief copy a file byte per byte
/// @param source the source filepath
/// @param dest the destination filepath
/// @return MAIN_SUCCESS if the operation was successful and MAIN_ERROR otherwise
int copy_binary_file(const char *source, const char *dest){
    FILE *source_file = fopen(source, "rb");
    FILE *dest_file = fopen(dest, "wb+");
    if(source_file == NULL || dest_file == NULL)
        return MAIN_ERROR;

    // get the size of the file
    TRY_IO_RETURN(
        fseek(source_file, 0L, SEEK_END),
        0,
        MAIN_ERROR
    );
    long file_size = ftell(source_file);
    TRY_IO_RETURN(
        fseek(source_file, 0L, SEEK_SET),
        0,
        MAIN_ERROR
    );

    uint8_t *buff = malloc(file_size);
    if(buff == NULL)
        return MAIN_ERROR;
    
    TRY_IO_RETURN(
        fread(buff, sizeof(uint8_t), file_size, source_file),
        file_size,
        MAIN_ERROR
    );
    TRY_IO_RETURN(
        fwrite(buff, sizeof(uint8_t), file_size, dest_file),
        file_size,
        MAIN_ERROR
    );

    free(buff);
    fclose(source_file);
    fclose(dest_file);
    return MAIN_SUCCESS;
}

/// @brief create a name which is the combination of a filepath and the name of the header (the name taken will be header_name) and sections in a pe file. If a section has not name, a number is written
/// @param buff where to store the resulting name
/// @param filepath the filepath
/// @param file the pe file to take section names from
/// @param combination a bool mask of which sections to take. the first index represents the header
/// @param number_of_sections the number of sections present in the pe file
void create_combination_name(char *buff, const char *filepath, const pe_file *file, const bool *combination, const int number_of_sections){
    //TODO: check if the final size of the name fits in the buffer
    // first copy the filepath
    strcpy(buff, filepath);

    // then concatentate the header if we need to
    if(combination[0])
        strcat(buff, header_name);

    // now copy the section's names, use an increasing number for sections with no names
    int iterative_name = 1;
    static char iterative_name_string[9] = {"00000000"};
    for(int i = 0; i < number_of_sections; i++)
        if(combination[i + 1]){
            const char *section_name = pe_file_section_name(file, i);
            if(strcmp(section_name, "") == 0){
                sprintf(iterative_name_string,"%08d",iterative_name);
                strcat(buff, iterative_name_string);
                iterative_name++;
            } else
                strcat(buff, section_name);
        }
}

/// @brief create all combinations C(n,remaining) of files from a source file with the chosen header and sections by n and remaining zeroed out
/// @param source_file the source file
/// @param destination_file the destination file
/// @param file the source file pe structure
/// @param combination a vector of bools set to 0, of lenght n
/// @param n the lenght of combination, n in C(n,remaining)
/// @param k an index, must be set to 0
/// @param remaining remaining value of C(n,remaining)
/// @return MAIN_SUCCESS if successful otherwise MAIN_ERROR
int do_combination(const char *source_file, const char *destination_file, const pe_file *file, bool *combination, const int n, const int k, const int remaining){
    if(remaining == 0){
        create_combination_name(tmpbuff, destination_file, file, combination, n - 1);
        if(copy_binary_file(source_file, tmpbuff) == MAIN_ERROR)
            return MAIN_ERROR;
        pe_file *new_file = pe_file_open(tmpbuff, PE_FILE_RW_TRUNC_MODE);
        if(new_file == NULL)
            return MAIN_ERROR;

        if(combination[0]){
            int bytes_to_write = pe_file_header_size(new_file);
            TRY_IO_GOTO(
                pe_file_header_write_constant(new_file, 0, bytes_to_write, 0),
                bytes_to_write,
                error_file
            );
        }
        for(int i = 1; i < n; i++){
            if(combination[i]){
                const char *section_name = pe_file_section_name(new_file, i - 1);
                int bytes_to_write = pe_file_section_size(new_file, section_name);
                TRY_IO_GOTO(
                    pe_file_section_write_constant(new_file, section_name, 0, bytes_to_write, 0),
                    bytes_to_write,
                    error_file
                );
            }
        }
        
        pe_file_destructor(new_file);
        return MAIN_SUCCESS;
error_file:
        pe_file_destructor(new_file);
        return MAIN_ERROR;
    } else{
        for(int i = k; i < (n - remaining + 1); i++){
            combination[i] = true;
            int return_code = do_combination(source_file, destination_file, file, combination, n, i + 1, remaining - 1);
            if(return_code != MAIN_SUCCESS)
                return return_code;
            combination[i] = false;
        }
    }

    return MAIN_ERROR;
}

int main(int argc, char **argv){
    if(argc < 3){
        printf("The executable should be called as 'executable input_directory output_directory'\n");
        return EXIT_FAILURE;
    }
    
    printf("Performing ablation from %s to %s\n", argv[1], argv[2]);

    DIR *input_dir = opendir(argv[1]);
    if(input_dir == NULL){
        printf("Cannot open the input directory\n");
        return EXIT_FAILURE;
    }
    
    char source_file[BUFF_SIZSE] = {0};
    char destination_file[BUFF_SIZSE] = {0};
    struct dirent *ep;
    errno = 0;
    while((ep = readdir(input_dir)) != NULL){
        if(strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0)
            continue;

        printf("Processing file %s\n", ep->d_name);
        
        strcpy(source_file, argv[1]);
        strcat(source_file, ep->d_name);
    
        pe_file *next_file = pe_file_open(source_file, PE_FILE_READ_MODE);
        if(next_file == NULL){
            printf("Unable to open file %s to process headers\n", ep->d_name);
            return EXIT_FAILURE;
        }
        int number_sections = pe_file_number_of_sections(next_file);
        if(number_sections + 1 > MAX_NUM_SECTIONS){
            printf("Cannot do more than %d combinations, it would produce too many files\n", MAX_NUM_SECTIONS);
            return EXIT_FAILURE;
        }

        printf("The number of combinations needed for this file are %d\n",  2 << number_sections); // do a power of 2 ** (number_sections + 1)

        //important to initialize to 0
        bool *combination = calloc((number_sections + 1), sizeof(bool));
        if(combination == NULL){
            pe_file_destructor(next_file);
            return EXIT_FAILURE;
        }

        strcpy(destination_file, argv[2]);
        strcat(destination_file, ep->d_name);

        for(int i = 0; i <= number_sections + 1; i++){
            if(do_combination(source_file, destination_file, next_file, combination, number_sections + 1, 0, i) != MAIN_SUCCESS){
                printf("Error while doing a combination of this file i: %d, dest %s, source %s\n", i, destination_file, source_file);
                return EXIT_FAILURE;
            }
        }

        printf("\n");
        
        pe_file_destructor(next_file);
        free(combination);
    }
    if(errno != 0){
        perror("There has been a problem while opening a file of the source directory\n");
        closedir(input_dir);
        return EXIT_FAILURE;
    }

    closedir(input_dir);
    return EXIT_SUCCESS;
}