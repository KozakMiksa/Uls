#include "libmx.h"
char *mx_strjoin(const char *s1, const char *s2) {
    char *str1 = NULL;
    char *str2 = NULL;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    else if (s2 == NULL)
        return mx_strdup(s1);
    str1 = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    str2 = mx_strcpy(str1, s1);
    free(str1);
    return mx_strcat(str2, s2);
}
