#ifndef PE_FILE
#define PE_FILE

#include <stdint.h>

// errors returned by the functions 
#define PE_FILE_SUCCESS (0)
#define PE_FILE_ERROR (-1)
#define PE_FILE_SECTION_NOT_FOUND (-2)
#define PE_FILE_OUT_OF_BOUNDS (-3)
#define PE_FILE_IO_ERROR (-4)

// modes to open pe files with
#define PE_FILE_READ_MODE "rb"
#define PE_FILE_WRITE_MODE "wb"
#define PE_FILE_RW_TRUNC_MODE "rb+"

typedef struct pe_file pe_file;

/// @brief open a pe file for reading/writing to headers or sections
/// @param path filepath to the pe file
/// @param mode one of the modes indicated above
/// @return a pointer to a pe_file structure or NULL if there was some error
pe_file *pe_file_open(const char *path, const char *mode);

/// @brief close a file and free resources
/// @param file the file to close
void pe_file_destructor(pe_file *file);

/// @brief return the number of sections that a file has
/// @param file the pe file
/// @return the number of sections
int pe_file_number_of_sections(const pe_file *file);

/// @brief give the name of the section given its index in the file
/// @param file the pe file
/// @param number the index of the section (as they are ordered in the pe file)
/// @return a pointer to its name or NULL if the section with number index does not exist
const char *pe_file_section_name(const pe_file *file, int number);

/// @brief return the index of a section of a pe file given its name
/// @param file the pe file
/// @param name the name of the section
/// @return the index of the section in the order it appears in the file or PE_FILE_SECTION_NOT_FOUND if section name does not exist
int pe_file_section_number(const pe_file *file, const char *name);

/// @brief return the size of the section of a pe file given its name in number of bytes
/// @param file the pe file
/// @param name the name of the section
/// @return the size of the section in bytes or PE_FILE_SECTION_NOT_FOUND if section name is not found
int pe_file_section_size(const pe_file *file, const char *name);

/// @brief return the size in bytes of the entire header of a pe file
/// @param file the pe file
/// @return the size in bytes of the entire header (DOS_HEADER + DOS_PROGRAM + FILE_HEADER + OPTIONAL_HEADER + SECTION_HEADERS)
int pe_file_header_size(const pe_file *file);

/// @brief write a byte constant to the header times some amount (does not update the pe_file structure)
/// @param file the pe file to write to
/// @param value the constant to write
/// @param amount the number of times
/// @param offset the offset within the header
/// @return the number of bytes written, PE_FILE_OUT_OF_BOUNDS if write would go beyond the header, and PE_FILE_IO_ERROR if there is some error with io operations
int pe_file_header_write_constant(pe_file *file, uint8_t value, int amount, int offset);

/// @brief write a byte constant to a section name times some amount
/// @param file the pe file
/// @param name the name of the section to write to
/// @param value the value to write
/// @param amount the number of times to do it
/// @param offset the offset within the section to write to
/// @return the number of bytes written, PE_FILE_OUT_OF_BOUNDS if write would go anywhere other than the section, PE_FILE_IO_ERROR if there is some error with io operations
int pe_file_section_write_constant(pe_file *file, const char *name, uint8_t value, int amount, int offset);

/// @brief do a print of headers within the pe file
/// @param file the pe file
void pe_file_print_headers(const pe_file *file);

#endif