#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    int diff = mx_strlen(sub) - mx_strlen(replace);
    char *res = NULL;

    if (str == NULL || sub == NULL || replace == NULL) 
        return NULL;
    if (diff < 0)
        diff = -diff;
    res = mx_strnew(mx_strlen(str) + mx_count_substr(str, sub) * diff);
    for (int i = 0, k = 0; i < mx_strlen(str); i++) {
        if (!mx_get_substr_index(&str[i], sub)) {
            for (int j = 0; j < mx_strlen(replace); j++, k++)
                res[k] = replace[j];
            i = i + mx_strlen(sub) - 1;
        } 
        else
            res[k++] = str[i];
    }
    return res;
}
