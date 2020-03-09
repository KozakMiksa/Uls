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
char **mx_strsplit(const char *s, char c) {
    char *ss = s;

    if (s == NULL)
    {
	return NULL;
    }
    int size = mx_count_words(ss, c);
    char **arr = malloc((size + 1) * sizeof(char *));
    for(int i = 0; i < size; i++)
    {
	while(*ss == c && *ss != '\0')
	{
	    ss++;
	}
	arr[i] = mx_strnew(strlen_mod(ss, c));
	int j = 0;
	while(*ss != c && *ss != '\0')
	{
	    arr[i][j] = *ss;
	    ss++;
	    j++;
	}
    }
    arr[size] = NULL;
    return arr;
}
