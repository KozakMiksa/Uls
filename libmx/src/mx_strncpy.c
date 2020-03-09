#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    int j = 0;

    while(i != len) {
        if (src[j] != '\0') {
            dst[i] = src[j];
            i++;
            j++;
        }
        else {
            dst[i] = '\0';  
            i++;
        }
    }
    return dst;
}
