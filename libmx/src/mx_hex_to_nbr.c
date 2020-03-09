#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long res = 0;
    long int pow = mx_strlen(hex) - 1;

    for (int i = 0; pow >= 0; i++) {
        if ((hex[i] > 64 && hex[i] < 71) || (hex[i] > 96 && hex[i] < 103)) {
            if (hex[i] >= 65 && hex[i] <= 70)
                res = res + (hex[i] - 55) * mx_pow(16, pow--);
            else
                res = res + (hex[i] - 87) * mx_pow(16, pow--);
        }
        else if (hex[i] >= 48 && hex[i] <= 57) 
            res = res + (hex[i] - 48) * mx_pow(16, pow--);
        else
            return 0;
    }
    return res;
}
