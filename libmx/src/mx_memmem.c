#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, 
                const void *little, size_t little_len) {
    unsigned int j = 1;
    unsigned char *b = (unsigned char *)big;
    unsigned char *l = (unsigned char *)little;
    
    while (*b != '\0' && 0 < big_len--) {
        if(*b == *l) {
            unsigned char *cb = b;
            unsigned char *cl = l;

            for (; *cb == *cl && j < little_len; j++) {
                cb++;
                cl++;
            }
            if (j == little_len && *cb == *cl)
                return b;
        }
        b++;
    }      
    return NULL;
}
