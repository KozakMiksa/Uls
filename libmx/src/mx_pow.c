#include "libmx.h"
double mx_pow(double n, unsigned int pow)
{
    if (pow < 0)
    {
	return 0;
    }
    if (pow == 0)
    {
	return 1;
    }
    unsigned int i = 1;
    double num = n;
    while(i < pow)
    {
	num = num * n;
	i++;
    }
    return num;
}
