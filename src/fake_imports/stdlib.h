#ifndef FAKE_STDLIB
#define FAKE_STDLIB

#define EXIT_FAILURE (-1)

void *malloc(unsigned int size);
void free(void *ptr);
void exit(int code);

#endif