#include "uls.h"

static void print_total(t_list *files, char *dir) {
    t_list *cp_files = files;
    int total = 0;
    char *str = NULL;
    struct stat buff;

    while (cp_files != NULL) {
        if (dir != NULL)
            str = mx_path_to_dir(cp_files->data, dir);
        else
            str = cp_files->data;
        stat(str, &buff);
        total += buff.st_blocks;
        cp_files = cp_files->next;
    }
    mx_printstr("total ");
    mx_printint(total);
    mx_printchar('\n');
}

void mx_print_for_dir(t_list *files, t_list *flags, char *dir) {
    struct winsize ws;
    char flag = mx_get_flag(flags, "l1m", 'C');

    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    if (files != NULL)
        switch (flag) {
        case 'l':
            print_total(files, dir);
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
