#include "libmx.h"
char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (str == NULL || sub == NULL || replace == NULL)
    {
	   return NULL;
    }
    int size_str = mx_strlen(str);
    int size_sub = mx_strlen(sub);
    int size_replace = mx_strlen(replace);
    int count = mx_count_substr(str, sub);
    int size = size_str + (size_replace - size_sub) * count;
    char *s = mx_strnew(size);
    char *copys = s;
    int j = 0;
    while(j < count)
    {
        int i = 0;
        int k = 0;
        char *sc = mx_strstr(str, sub);
        while(str != sc)
        {
            *copys = *str;
            copys++;
            str++;
        }
        while(i < size_replace)
        {
              *copys = replace[i];
              i++;
              copys++;
              str++;
        }
        j++;
	while(k < size_sub - size_replace)
	{
	    k++;
	    str++;
	}
    }
    while(*str != '\0')
    {
	*copys = *str;
	copys++;
        str++;
    }
    return s;
}
