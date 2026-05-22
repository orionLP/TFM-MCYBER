#include "pe_file.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    pe_file *myfile = read_pe_file("../../../data/raw/exe/x86/windows_exec.exe", PE_READWRITE_MODE);
    print_headers(myfile);
    // close_pe_file(myfile);
    return 0;
}