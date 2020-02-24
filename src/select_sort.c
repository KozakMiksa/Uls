#include "uls.h"

void mx_select_sort(t_list **names, t_list *flags, char flag, char *dir) { 
        char str;
        if (flags != NULL)
            str = flag;

    switch (flag) {
        case 'C':
            mx_ascii_sort(names);
            break;
        case 't':
            mx_time_sort(names, dir, flags);
            break;
        case 'S':
            mx_size_sort(names, dir);
            break;
        default:
            ;
    }
}
