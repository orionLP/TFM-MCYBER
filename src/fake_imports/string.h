#ifndef FAKE_STRING
#define FAKE_STRING

void *memcpy(void *dst, const void *src, unsigned int n);
void *memset(void *dst, int c, unsigned int n);
unsigned int strlen(const char *s);
int strcmp(const char *s1, const char *s2);

#endif
