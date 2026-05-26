#ifndef PE_FILE
#define PE_FILE

#include <stdint.h>

#define PE_READ_MODE "rb"
#define PE_WRITE_MODE "wb"
#define PE_RW_TRUNC_MODE "rb+"

typedef struct pe_file pe_file;

pe_file *pe_file_open(char *path, char *mode);
void pe_file_destructor(pe_file *file);

int pe_file_number_of_sections(pe_file *file);
const char *pe_file_section_name(pe_file *file, int number);
int pe_file_section_number(pe_file *file, const char *name);
int pe_file_section_size(pe_file *file, const char *name);
int pe_file_header_size(pe_file *file);
int pe_file_header_write_constant(pe_file *file, uint8_t value, int amount, int offset);
int pe_file_section_write_constant(pe_file *file, const char *name, uint8_t value, int amount, int offset);
void pe_file_print_headers(pe_file *file);

#endif