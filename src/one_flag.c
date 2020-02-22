#include "uls.h"

void mx_one_flag(t_list *files, t_list *flags, char *dir) {
    char flag = mx_get_flag(flags, "ftS", 'C');
    t_list *cp_files = NULL;

    mx_select_sort(&files, flags, flag, dir);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    cp_files = files;
    while (files != NULL) {
        mx_printstr(files->data);
        mx_printchar('\n');
        files = files->next;
    }
    while (cp_files != NULL) {
            free(cp_files->data);
            mx_pop_front(&cp_files);
    }
}
