#include "libmx.h"
int strlen_mod(const char *s, char c)
{
    int count = 0;
    while(*s != c && *s != '\0')
    {
	count++;
        s++;
    }
    return count;
}
char **mx_strsplit(const char *s, char c)
{
    if (s == NULL)
    {
	return NULL;
    }
    int size = mx_count_words(s, c);
    char **arr = malloc((size + 1) * sizeof(char *));
    for(int i = 0; i < size; i++)
    {
	while(*s == c && *s != '\0')
	{
	    s++;
	}
	arr[i] = mx_strnew(strlen_mod(s, c));
	int j = 0;
	while(*s != c && *s != '\0')
	{
	    arr[i][j] = *s;
	    s++;
	    j++;
	}
    }
    arr[size] = NULL;
    return arr;
}
