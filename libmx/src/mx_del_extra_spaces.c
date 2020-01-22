#include "libmx.h"
char *mx_del_extra_spaces(const char *str)
{
    if (str == NULL)
    {
	return NULL;
    }
    char *str_trimed = mx_strtrim(str);
    if (str_trimed == NULL)
    {
	return NULL;
    }
    char *st_copy = mx_strnew(mx_strlen(str_trimed));
    int i = 0;
    int j = 0;
    while(str_trimed[i] != '\0')
    {
	st_copy[j] = str_trimed[i];
	if (mx_isspace(str_trimed[i]) == 1)
	{
	    while(mx_isspace(str_trimed[i]) == 1)
	    {
		i++;
	    }
	}
	else
	{
	    i++;
	}
            j++;
    }
    i = 0;
    mx_strdel(&str_trimed);
    char *new_str = mx_strnew(mx_strlen(st_copy));
    while(st_copy[i] != '\0')
    {
	new_str[i] = st_copy[i];
	i++;
    }
    mx_strdel(&st_copy);
    return new_str;
}
