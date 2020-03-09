#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned int i = 0;
    unsigned char *str = (unsigned char *)s;

    while (*str != '\0')
        str++;
    while (i < n) {
        if (*str == c)
            return str;
        i++;
        str--;
    }
    return NULL;
}
