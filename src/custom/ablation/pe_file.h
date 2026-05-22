#ifndef PE_FILE
#define PE_FILE

#define PE_READ_MODE "rb"
#define PE_WRITE_MODE "wb"
#define PE_READWRITE_MODE "rb+"

typedef struct pe_file pe_file;

pe_file *read_pe_file(char *path, char *mode);
void close_pe_file(pe_file *file);

void print_headers(pe_file *file);

#endif