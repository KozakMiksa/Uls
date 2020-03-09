#include "libmx.h"
char *mx_strnew(const int size)
{
    if (size < 0)
    {
	return NULL;
    }
    char *s = (char *) malloc(size + 1);
    for(int i = 0; i < size + 1; i++)
    {
	s[i] = '\0';
    }
    return s;
}
