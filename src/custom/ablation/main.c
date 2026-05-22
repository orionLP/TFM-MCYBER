#include "pe_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void do_combination(bool *combination, const int n, int k, int remaining){
    if(remaining == 0){
        //act here

        for(int i = 0; i < n; i++){
            printf("%d ", combination[i]);
        }
        printf("\n");
    } else{
        for(int i = k; i < (n - remaining + 1); i++){
            combination[i] = true;
            do_combination(combination, n, i + 1, remaining - 1);
            combination[i] = false;
        }
    }
}

int main(int argc, char **argv){
    pe_file *myfile = pe_file_open("./windows_exec.exe", PE_READWRITE_MODE);
    int number_sections = pe_file_number_of_sections(myfile);
    int number_combinations = 1;
    if(number_sections != 0)
        number_combinations = 2 << (number_sections - 1); // do a power of 2

    bool *combination = malloc(number_combinations * sizeof(bool));
    if(combination == NULL){
        pe_file_destructor(myfile);
        return -1;
    }

    printf("Number of sections: %d\n", number_sections);
    printf("Combinations to do: %d\n", number_combinations);

    for(int i = 0; i <= number_sections; i++)
        do_combination(combination, number_sections, 0, i);
    
    // print_headers(myfile);
    // write_constant(myfile, ".text", 0xFA, 10, 12);

    free(combination);
    pe_file_destructor(myfile);
    return 0;
}