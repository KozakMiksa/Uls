#include "libmx.h"
int mx_count_substr(const char *str, const char *sub)
{
    int count = 0;
    if (str == NULL || sub == NULL)
    {
	return -1;
    }
    while(str != NULL)
    {
	str = mx_strstr(str, sub);
	if (str != NULL)
	{
	    count++;
	    str++;
	}
    }
    return count;
}
