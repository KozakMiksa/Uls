#include "libmx.h"
char *mx_strstr(const char *haystack, const char *needle)
{
    while(*haystack != '\0')
    {
	if (*haystack == *needle)
	{
	    int i = 0;
	    char *s = (char *) haystack;
	    while(*haystack == needle[i])
	    {
		i++;
		haystack++;
		if (needle[i] == '\0')
		{
		    return s;
		}
	    }
	}
	if (*haystack != '\0')
	{
	    haystack++;
	}
    }
    return NULL;
}
