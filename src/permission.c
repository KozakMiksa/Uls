#include "uls.h"

void mx_permission(t_list *names) {
	
    while (names != NULL) {
        write(2, "uls: ", 5);
        write(2, names->data, mx_strlen(names->data));
        write(2, ": Permission denied\n", 20);
        names = names->next;
    }
}
