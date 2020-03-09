#include "libmx.h"
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    unsigned char *str1 = (unsigned char *)big;
    unsigned char *str2 = (unsigned char *)little;
    size_t i = 0;
    size_t j = 1;
    while(i < big_len && *str1 != '\0')
    {
	if (*str1 == *str2)
	{
	    unsigned char *cs1 = str1;
	    unsigned char *cs2 = str2;
	    while(*cs1 == *cs2 && j < little_len)
	    {
		cs1++;
		cs2++;
		j++;
	    }
	    if (*cs1 == *cs2 && j == little_len)
	    {
		return str1;
	    }
	}
	str1++;
	i++;
    }
    return NULL;
}
