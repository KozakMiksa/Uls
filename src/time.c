#include "uls.h"

void mx_time(struct stat *buff) {
    char *time_d = ctime(&buff->st_mtime);
    char **arr = mx_strsplit(time_d, ' ');
    time_t current = time(NULL);

    mx_printstr(arr[1]);
    mx_printstr(" ");
    if (mx_strlen(arr[2]) == 1)
        mx_printchar(' ');
    mx_printstr(arr[2]);
    mx_printchar(' ');
    if ((current - buff->st_mtime) >= MX_HALF_YEAR){
        mx_printchar(' ');
        for (int t = 0; arr[4][t] != '\n'; t++)
            mx_printchar(arr[4][t]);
    }
    else
        for (int i = 0; i < 5; i++)
            mx_printchar(arr[3][i]);
    mx_printchar(' ');
    for (int j = 0; arr[j] != NULL; j++)
        mx_strdel(&arr[j]);
    free(arr);
}
