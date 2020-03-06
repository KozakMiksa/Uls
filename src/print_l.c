#include "uls.h"

void mx_print_l(t_list *files, char *str) {
    struct stat buff;
    struct passwd *pw;
    struct group *gr;

    lstat(str, &buff);
    mx_socets(&buff, str);
    mx_printchar(' ');
    mx_printint(buff.st_nlink);
    mx_printchar(' ');
    /////////////////////////////////
    pw = getpwuid(buff.st_uid);
    mx_printstr(pw->pw_name);
    mx_printchar(' ');
    /////////////////////////////////
    gr = getgrgid(buff.st_gid);
    if (gr != NULL)
        mx_printstr(gr->gr_name);
    else
    	mx_printint(buff.st_gid);
    mx_printchar(' ');
    /////////////////////////////////
    mx_printint(buff.st_size);
    mx_printchar(' ');
    /////////////////////////////////
    mx_printstr(files->data);
    mx_printchar('\n');
}
