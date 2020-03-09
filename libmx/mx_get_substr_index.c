#include "libmx.h"
int mx_get_substr_index(const char *str, const char *sub)
{
    int index = 0;
    if (str == NULL || sub == NULL)
    {
	return -2;
    }
    char *s = mx_strstr(str, sub);
    if (s == NULL)
    {
	return -1;
    }
    while(str[index] != '\0')
    {
	if (str[index] == *s)
	{
	    return index;
	}
	else
	{
	    index++;
	}
    }
    return -1;
}
