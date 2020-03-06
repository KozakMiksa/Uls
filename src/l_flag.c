#include "uls.h"

void mx_l_flag(t_list *files, t_list *flags, char *dir) {
    char *str = NULL;

    mx_select_sort(&files, flags, mx_get_flag(flags, "ftS", 'C'), dir);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    while (files != NULL) {
        if (dir != NULL)
            str = mx_path_to_dir(files->data, dir);
        else
            str = files->data;
        mx_print_l(files, str);
        files = files->next;
    }
}
