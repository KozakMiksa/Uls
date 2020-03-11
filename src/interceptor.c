#include "uls.h"

char mx_interceptor(void) {
    char c = 'C';

    if (!isatty(1))
        c = '1';
    return c;
}
