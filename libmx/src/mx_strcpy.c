#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *s = dst;
    int i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return s;
}
