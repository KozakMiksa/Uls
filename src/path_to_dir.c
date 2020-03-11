#include "uls.h"

char *mx_path_to_dir(char *str, char *dir) {
    int i = mx_strlen(dir);
    char *trs = NULL;

    if (dir[0] != '.') {
        if (dir[i - 1] != '/')
            dir = mx_strcat(dir, "/");
        trs = mx_strjoin(dir, str);
    }
    else if (dir[1] == '.') {
        if (dir[i - 1] != '/')
            dir = mx_strcat(dir, "/");
        trs = mx_strjoin(dir, str);
    }
    else
        trs = str;
    return trs;
}
