#include "uls.h"

// static int size(int buf) {
//     int size = 1;

//     while (buf / 10 > 0) {
//         size++;
//         buf /= 10;
//     }
//     return size;
// }

// static void size_colum(struct s_size_colum *sc, t_list *files, char *dir) {
//     char *str = NULL;
//     struct stat buff;
//     int s = 0;
//     // struct passwd *pw;
//     // struct group *gr;

//     sc->nlink = 0;
//     while (files != NULL) {
//         if (dir != NULL)
//             str = mx_path_to_dir(files->data, dir);
//         else
//             str = files->data;
//         lstat(str, &buff);
//         s = size(buff.st_nlink);
//         if (sc->nlink < s)
//             sc->nlink = s;
//         //printf("%d\n", buff.st_nlink);
//         files = files->next;
//     }
// }

void mx_l_flag(t_list *files, t_list *flags, char *dir) {
    char *str = NULL;
    // struct s_size_colum sc;

    // size_colum(&sc, files, dir);
    // printf("%d\n", sc.nlink);
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
