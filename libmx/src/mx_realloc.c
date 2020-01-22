#include "libmx.h"
void *mx_realloc(void *ptr, size_t size)
{
    if (!ptr && size) return malloc(size);
    
    if (size == 0 && ptr) {
        free(ptr);
        return NULL;
    }
    unsigned char *s = ptr;
    unsigned char *ss = (unsigned char *)malloc(size);
    unsigned char *sss = ss;
    for(size_t i = 0; *s != '\0' && i < size; i++)
    {
        *ss = *s;
        ss++;
        s++;
    }
    ptr = sss;
    return ptr;
}
