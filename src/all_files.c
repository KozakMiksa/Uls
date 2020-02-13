#include "uls.h"

void mx_all_files(t_list *files, t_list *flags) {
    char flag = mx_get_flag(flags, "l1m");

    if (files != NULL)
        switch (flag) {
        case 'l':
            mx_l_flag(files, flags);
                break;
        case 'C':
            mx_big_c_flag(files, flags);
            break;
        case '1':
             mx_one_flag(files, flags);
            break;
        case 'm':
             mx_m_flag(files, flags);
        }
}
