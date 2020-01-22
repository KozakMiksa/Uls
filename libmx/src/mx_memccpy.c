#include "libmx.h"
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	unsigned char *d = dst;
        unsigned char *s  = (unsigned char *)src;
	size_t i = 0;
	while(i < n)
	{
		*d = *s;
		if (*d == c)
		{
			return ++d;
		}
		d++;
		s++;
		i++;
	}
	if (i == n)
	{
	    return NULL;
        }
	return dst;
}
