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
    int i = mx_list_size(names);

    while (names != NULL) {
        str = name_permission(names->data);
        if (flows > 0|| i > 1 ) {
            write(2, names->data, mx_strlen(names->data));
            write(2, ": \n", 3);
        }
        write(2, "uls: ", 5);
        write(2, str, mx_strlen(str));
        write(2, ": Permission denied\n", 20);
        if (flows > 0 || names->next != NULL)
            write(2, "\n", 1);
        names = names->next;
    }
}
