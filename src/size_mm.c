#include "uls.h"

static char *get_minor(int minornum, char *cn) {
    char *minor;
    char *tmp = NULL;
    if (minornum > 256) {
        minor = mx_strnew(10);
        mx_strcpy(minor, "0x00000000");
        tmp = mx_nbr_to_hex(minornum); // нужен робочий нбр
        mx_strcpy(minor + (10 - mx_strlen(tmp)), tmp);
        free(tmp);
    }
    // else if (mx_strcmp("autofs_homedirmounter", cn) == 0 || 
    //          mx_strcmp("autofs_notrigger", cn) == 0 ||
    //          mx_strcmp("dtrace", cn) == 0) {
    //     minor = mx_itoa(minornum - 5);
    // }
    else
        minor = mx_itoa(minornum);
    if (cn == NULL)
        printf(" ");
    return minor;
}

static void minor_major(struct stat *buff, int maj, int min, char *check_name) {
    int major_num = MX_MAJOR(buff->st_rdev);
    int minor_num = MX_MINOR(buff->st_rdev);
    char *major = mx_itoa(major_num);
    char *minor = get_minor(minor_num, check_name);
min = 0;
    major_num = mx_size_colum(major_num);
    minor_num = mx_size_colum(minor_num);
    for (; major_num < maj; maj--)
        mx_printchar(' ');
    mx_printstr(major);
    mx_printstr(",");
    for (int k = 3; minor_num < k; k--)
        mx_printchar(' ');
    mx_printchar(' ');
    mx_printstr(minor);
    mx_printchar(' ');
    mx_strdel(&major);
    mx_strdel(&minor);
}

void mx_size_mm(struct stat *buff, struct s_size_colum *sc, char *cn) {
    int i = mx_size_colum(buff->st_size);
    int size = sc->size;

    if ((buff->st_mode & MX_IFMT) == MX_ISCHR ||
        (buff->st_mode & MX_IFMT) == MX_ISBLK)
        minor_major(buff, sc->maj, sc->min, cn);
    else {
    	for (; sc->maj + sc->min > i; i++)
    	    mx_printchar(' ');
        while (i < size) {
            mx_printchar(' ');
            size--;
        }
        mx_printint(buff->st_size);
        mx_printchar(' ');
    }
}
