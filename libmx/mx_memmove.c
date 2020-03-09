#include "libmx.h"
void *mx_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d = dst;
    const unsigned char *s = src;
    int i = len;
    unsigned char *copy1 = malloc(i);
    unsigned char *copy2 = copy1;
    for(int j = 0; j < i; j++)
    {
	*copy1 = *s;
	s++;
	copy1++;
    }
    for(int j = 0; j < i; j++)
    {
	*d = *copy2;
	d++;
	copy2++;
    }
    return dst;
}
