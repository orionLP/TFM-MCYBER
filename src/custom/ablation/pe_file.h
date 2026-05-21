#ifndef PE_FILE
#define PE_FILE

#define PE_READ_MODE "rb"
#define PE_WRITE_MODE "wb"
#define PE_READWRITE_MODE "rb+"

struct pe_file;

struct pe_file *read_pe_file(char *path, char *mode);
void delete_pe_file(struct pe_file *file);

#endif