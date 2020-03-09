#include "libmx.h"

static int strlen_mod(const char *s, char c) {
    int count = 0;

    while(*s != c && *s != '\0') {
        count++;
        s++;
    }
    return count;
}

char **mx_strsplit(const char *s, char c) {
    int size = mx_count_words(s, c);
    char **arr = malloc((size + 1) * sizeof(char *));
    int j = 0;

    if (s == NULL)
        return NULL;
    for(int i = 0; i < size; i++) {
        while (*s == c && *s != '\0')
             s++;
        arr[i] = mx_strnew(strlen_mod(s, c));
        while (*s != c && *s != '\0') {
            arr[i][j] = *s;
            s++;
            j++;
        }
    }
    arr[size] = NULL;
    return arr;
}
