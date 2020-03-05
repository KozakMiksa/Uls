#include "uls.h"

static char *name_permission(char *str) {
    char *cp_str = str;
    char *tmp = NULL;

    while (*cp_str != '\0') {
        if (*cp_str == '/')
            tmp = cp_str;
        cp_str++;
    }
    return ++tmp;
}

void mx_permission(t_list *names, int flows) {
    char *str = NULL;

    while (names != NULL) {
        str = name_permission(names->data);
        if (flows > 0) {
            write(2, names->data, mx_strlen(names->data));
            write(2, ": \n", 3);
        }
        write(2, "uls: ", 5);
        write(2, str, mx_strlen(str));
        write(2, ": Permission denied\n", 20);
        names = names->next;
        if (flows > 0)
            write(2, "\n", 1);
    }
}
