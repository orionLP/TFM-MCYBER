#include "pe_file.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    pe_file *myfile = open_pe_file("./windows_exec.exe", PE_READWRITE_MODE);
    print_headers(myfile);
    // close_pe_file(myfile);
    return 0;
}