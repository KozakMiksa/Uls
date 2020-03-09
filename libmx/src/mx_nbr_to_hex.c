#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int size = 0;
    char *s = NULL;
    char *hex = NULL;

    if (nbr == 0) {
        s = mx_strnew(1);
        s[0] = 48;
        return s;    
    }
    for (unsigned long newnbr = nbr; newnbr; size++)
        newnbr = newnbr / 16;
    hex = mx_strnew(size);
    for (int i = size - 1; i >= 0; i--) {
        if (nbr % 16 <= 9) 
            hex[i] = nbr % 16 + 48;
        else if (nbr % 16 > 9)
            hex[i] = nbr % 16 + 87;
        nbr = nbr / 16;
    }
    return hex;
}
