#include "libmx.h"
void *mx_memrchr(const void *s, int c, size_t n)
{
    unsigned char *str = (unsigned char *)s;
    while(*str != '\0')
    {
	str++;
    }
    size_t i = 0;
    while(i < n)
    {
	if (*str == c)
	{
	    return str;
	}
	str--;
	i++;
    }
    return NULL;
}
