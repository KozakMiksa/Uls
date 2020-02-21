#include "uls.h"

void mx_m_flag(t_list *files, t_list *flags, int ws_size) {
    char flag = mx_get_flag(flags, "ftS", 'C');
    int check = 0;
    int tmp = 0;

    mx_select_sort(&files, flags, flag);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    while (files != NULL) {
        tmp = mx_strlen(files->data) + 2;
        check =  check + tmp;
        if (check < ws_size) {
            mx_printstr(files->data);
        }
        else {
        	check = tmp;
            mx_printchar('\n');
            mx_printstr(files->data);
        }
        if (files->next != NULL)
            mx_printstr(", ");

        files = files->next;
    }
    mx_printchar('\n');
}
