#include "uls.h"

void mx_no_such_file_or_dir(t_list *names) {
    while (names != NULL) {
        write(2, "uls: ", 5);
        write(2, names->data, mx_strlen(names->data));
        write(2, ": No such file or directory\n", 28);
        names = names->next;
    }
}
