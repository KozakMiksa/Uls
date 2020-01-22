#include "libmx.h"
char *mx_strtrim(const char *str)
{
    if (str == NULL)
    {
	return NULL;
    }
    int i = 0;
    int size = mx_strlen(str);
    char *copy_str = mx_strnew(size);
    while(mx_isspace(str[i]) == 1)
    {
        i++;
    }
    while(mx_isspace(str[size - 1]) == 1)
    {
        size--;
    }
    for(int j = 0; i < size; )
    {
        copy_str[j] = str[i];
        i++;
        j++;
    }
    if (copy_str[0] == '\0')
    {
        return NULL;
    }
    char *new = mx_strcpy(mx_strnew(mx_strlen(copy_str)), copy_str);
    mx_strdel(&copy_str);
    return new;
}
