#include "libmx.h"

char *mx_strdup(const char *str) {
    char *s = mx_strcpy(mx_strnew(mx_strlen(str)), str);

    return s;
}
