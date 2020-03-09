#include "libmx.h"
void mx_str_reverse(char *s)
{
	int size = mx_strlen(s);
	for(int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			mx_swap_char(&s[j], &s[j + 1]);
		}
	}
}
