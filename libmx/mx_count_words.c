#include "libmx.h"
int mx_count_words(const char *str, char c)
{
	int count = 0;
	if (str == NULL)
	{
		return -1;
	}
	while(*str != '\0')
	{
		if (*str != c)
		{
			count++;
			while(*str != c && *str != '\0')
			{
				str++;
			}
                        if (*str == '\0')
			{
			    return count;
			}
		}
		str++;
	}
	return count;
}
