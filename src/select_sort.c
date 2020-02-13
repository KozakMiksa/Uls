#include "uls.h"

void mx_select_sort(t_list **names, t_list *flags, char flag) { 
    	char str;
    	if (flags != NULL)
    		str = flag;

    switch (flag) {
        case 'f':
            write(1, "f\n", 2);
            break ;
        case 't':
            write(1, "t\n", 2);
            break ;
        case 'S':
            write(1, "S\n", 2);
            break ;
        default:
            mx_ascii_sort(names);
    }
}
