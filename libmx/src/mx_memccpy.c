#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
                 int c, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    unsigned char *s = (unsigned char *)src;
    size_t i = 0;

    for (; i < n && s[i] != c; i++)
        d[i] = s[i];
    if (s[i] == c) {
        d[i] = s[i];
        return &d[i + 1];
    }
    return NULL;
}
