#include "libmx.h"
void *mx_memchr(const void *s, int c, size_t n)
{
    unsigned char *str = (unsigned char *)s;
    size_t i = 0;
    while(i < n)
    {
	if (*str == c)
	{
	    return str;
	}
	str++;
    }
    return NULL;
}
