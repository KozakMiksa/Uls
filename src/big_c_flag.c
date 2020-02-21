#include "uls.h"

static int longest_name(t_list *list) {
    int lenght = 0;
    int tmp = 0;

    while (list != NULL) {
        tmp = mx_strlen(list->data);
        if (tmp > lenght)
            lenght = tmp;
        list = list->next;
    }
    if (lenght % 8 == 0)
        lenght++;
    while (lenght % 8 != 0)
        lenght++;
    return lenght;
}

void mx_big_c_flag(t_list *files, t_list *flags, int ws_size) {
    int size_list = mx_list_size(files);
    int lenght = longest_name(files);
    char flag = mx_get_flag(flags, "ftS", 'C');

    mx_select_sort(&files, flags, flag);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    mx_mult_colum(files, ws_size, lenght, size_list);
    while (files != NULL) {
        free(files->data);
        mx_pop_front(&files);
    }
}
