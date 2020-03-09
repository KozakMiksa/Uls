#include "uls.h"

static void minor_major(struct stat *buff) {
    char *major = NULL;
    char *minor = NULL;
    int major_num = MX_MAJOR(buff->st_rdev);
    int minor_num = MX_MINOR(buff->st_rdev);

    major = mx_itoa(major_num);
    minor = mx_itoa(minor_num);
    mx_printstr(major);
    mx_printstr(", ");
    mx_printstr(minor);
    mx_printchar(' ');
}

void mx_print_l(t_list *files, char *str) {
    struct stat buff;
    struct passwd *pw;
    struct group *gr;

    lstat(str, &buff);
    char *linkname = malloc((128) * sizeof(char));
    // printf("%lld\n", buff.st_blocks);
    int i = 0;
    if ((buff.st_mode & MX_IFMT) == MX_ISLNK) {

    	i = readlink(str, linkname, 128);
    	// printf("%lld\n", buff.st_blocks);
    	linkname[i] = '\0';
    }
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
    if ((buff.st_mode & MX_IFMT) == MX_ISCHR ||
        (buff.st_mode & MX_IFMT) == MX_ISBLK)
        minor_major(&buff);
    else {
        mx_printint(buff.st_size);
        mx_printchar(' ');
    }
    /////////////////////////////////
    mx_printstr(files->data);
  if ((buff.st_mode & MX_IFMT) == MX_ISLNK) {
    	mx_printstr(" -> ");
    	mx_printstr(linkname);
    }

   
    // //free(&buff);
    mx_printchar('\n');
}
