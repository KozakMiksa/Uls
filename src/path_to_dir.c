#include "uls.h"

char *mx_path_to_dir(char *str, char *argv) {
    int i = 0;
    char *trs = NULL;

    for (; str[i + 1] != '\0'; i++);
    if (argv[0] != '.') {
        if (str[i] == '/') {
            trs = mx_strjoin(argv, str);
        }
        else {
    	    trs = mx_strjoin(mx_strcat(argv, "/"), str);
        }
    }
    else {
    	trs = str;
    }
    return trs;
}
