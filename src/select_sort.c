#include "uls.h"

void mx_select_sort(t_list **names, t_list *flags, char flag) { 
    	char str;
    	if (flags != NULL)
    		str = flag;

    switch (flag) {
        case 'C':
            mx_ascii_sort(names);
            break ;
        case 't':
            write(1, "t\n", 2);
            break ;
        case 'S':
            write(1, "S\n", 2);
            break ;
        default:
            ;
    }
}
