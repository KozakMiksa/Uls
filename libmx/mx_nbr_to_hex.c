#include "libmx.h"
char *mx_nbr_to_hex(unsigned long nbr)
{
    int size = 0;
    unsigned long copy_nbr = nbr;
    while(copy_nbr > 0)
    {
        copy_nbr /= 16;
        size++;
    }
    if (nbr == 0)
    {
      size = 1;  
    }
    char *hex = malloc(size + 1);
    hex[size] = '\0';
    size--;
    while(nbr > 15)
    {
        if (nbr % 16 > 9)
        {
            hex[size] = nbr % 16 + 87;
            nbr /= 16;
            size--;
        }
        else
        {
            hex[size] = nbr % 16 + 48;
            nbr /= 16;
            size--;
        }
    }
    if (nbr > 9)
    {
        hex[size] = nbr + 87;
    }
    else
    {
        hex[size] = nbr + 48;
    }
    return hex;
}
