#include "uls.h"

// static void print_total() {
    
// }

void mx_print_for_dir(t_list *files, t_list *flags, char *dir) {
    struct winsize ws;
    char flag = mx_get_flag(flags, "l1m", 'C');

    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    if (files != NULL)
        switch (flag) {
        case 'l':
            mx_l_flag(files, flags, dir);
            break;
        case 'C':
            mx_big_c_flag(files, flags, ws.ws_col, dir);
            break;
        case '1':
             mx_one_flag(files, flags, dir);
            break;
        case 'm':
             mx_m_flag(files, flags, ws.ws_col, dir);
        }
}
