#include "libmx.h"

char *mx_itoa(int number) {
    int sign = 1;
    int tens = 1;
    int size = 1;
    char *str = NULL;
    int n = 0;

    if (number < 0) 
        sign = -1;
    for (n = number; n / 10 != 0; n /= 10, size++)
        tens *= 10;
    str = mx_strnew(size);
    size = 0;
    if (sign == -1) {
        str[0] = '-';
        size++;
    }
    for (n = number; tens != 0; n %= tens, tens /= 10, size++)
        str[size] = n / tens * sign + '0';
    return str;
}
