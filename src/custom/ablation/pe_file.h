#ifndef PE_FILE
#define PE_FILE

#include <stdint.h>

#define PE_READ_MODE "rb"
#define PE_WRITE_MODE "wb"
#define PE_READWRITE_MODE "rb+"

typedef struct pe_file pe_file;

pe_file *open_pe_file(char *path, char *mode);
void destructor_pe_file(pe_file *file);

int number_of_sections(pe_file *file);
const char *section_name(pe_file *file, int number);
int section_number(pe_file *file, const char *name);
int section_size(pe_file *file, const char *name);
int write_constant(pe_file *file, const char *name, uint8_t value, int amount, int offset);

void print_headers(pe_file *file);

#endif