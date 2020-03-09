#include "libmx.h"

char *mx_strtrim(const char *str) {
    int i = 0;
    int j = 0;
    char *trim = NULL;

    if (str == NULL)
        return NULL;
    for (; mx_isspace(str[i]) == 1; i++);
    j = mx_strlen(str) - 1;
    for (; mx_isspace(str[j]) == 1; j--);
    trim = mx_strnew(j - i + 1);
    for (int k = 0; i <= j; k++, i++)
        trim[k] = str[i];
    return trim;
}
