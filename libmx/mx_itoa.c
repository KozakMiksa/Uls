#include "libmx.h"
char *mx_itoa(int number)
{
	int size = 1;
	int numbers = 1;
	long copy_n = number;
	if (copy_n < 0)
	{
		copy_n *= -1;
	}
	while(copy_n / numbers > 9)
	{
		numbers *= 10;
		size++;
	}
	char *s;
	if (number < 0)
	{
		s = malloc(size + 2);
		s[size + 1] = '\0';
		s[0] = '-';
		size = 1;
	}
	else
	{
		s = malloc(size + 1);
		s[size] = '\0';
		size = 0;
	}
	while(numbers != 0)
	{
		s[size] = copy_n / numbers + 48;
		copy_n %= numbers;
		numbers /= 10;
		size++;
	}
	return s;
}
