#include "uls.h"

void mx_m_flag(t_list *files, t_list *flags) {
    char flag = mx_get_flag(flags, "ftS", 'C');

    mx_select_sort(&files, flags, flag);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    while (files != NULL) {
        mx_printstr(files->data);
        mx_printstr(", ");
        files = files->next;
    }
}
