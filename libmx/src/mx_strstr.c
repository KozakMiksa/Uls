#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int i = 0;

    while (*haystack) {
        if (*haystack == *needle) {
            for (; haystack[i] == needle[i]; i++);
            if (needle[i] == '\0')
                return (char*)haystack;
        }
        haystack++;
    }
    return NULL;
}
