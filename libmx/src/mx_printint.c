#include "libmx.h"
void mx_printint(int n)
{
    int count = 1;
    long int nn = n;
    if (nn < 0)
    {
	nn = nn * -1;
	mx_printchar('-');
    }
    while(nn / count > 9)
    {
	count *= 10;
    }
    while(count >= 1)
    {
	mx_printchar(nn / count + 48);
	nn %= count;
	count /= 10;
    }
}
