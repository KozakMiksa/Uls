#include "libmx.h"
char *mx_strncpy(char *dst, const char *src, int len)
{
    char *s = dst;
    for(int i = 0; i < len; i++)
    {
	if (*src != '\0')
	{
	    *dst = *src;
	    dst++;
	    src++;
	}
	else
	{
	    *dst = '\0';
	    dst++;
	}
    }
    return s;
}
