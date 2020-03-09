#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *s = b;

    for (unsigned int i = 0; i < len; i++)
        s[i] = c;
    return b;  
}
