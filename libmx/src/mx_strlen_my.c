#include "libmx.h"

int mx_strlen_my(const char *s, char c) {
    int i = 0;

    while (s[i] != '\0' && s[i] != c)
        i++;
    return i;
}
