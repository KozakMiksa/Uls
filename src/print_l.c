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
    mx_strdel(&major);
    mx_strdel(&minor);
}

static char *linkname(struct stat *buff, char *str) {
    char *linkname = malloc((128) * sizeof(char));
    int i = 0;
    if ((buff->st_mode & MX_IFMT) == MX_ISLNK) {
        i = readlink(str, linkname, 128);
        linkname[i] = '\0';
    }
    return linkname;
}

static void nlink(struct stat *buff, int size) {
    int i = mx_size_colum(buff->st_nlink);

    while (i < size) {
        mx_printchar(' ');
        size--;
    }
    mx_printint(buff->st_nlink);
    mx_printchar(' ');
}

static void uid(struct stat *buff) {
    struct passwd *pw;

    pw = getpwuid(buff->st_uid);
    mx_printstr(pw->pw_name);
    mx_printstr("  ");
}

static void gid(struct stat *buff) {
    struct group *gr;

    gr = getgrgid(buff->st_gid);
    if (gr != NULL)
        mx_printstr(gr->gr_name);
    else
        mx_printint(buff->st_gid);
    mx_printstr("  ");
}

static void size_mm(struct stat *buff, int size) {
    int i = mx_size_colum(buff->st_size);

    if ((buff->st_mode & MX_IFMT) == MX_ISCHR ||
        (buff->st_mode & MX_IFMT) == MX_ISBLK)
        minor_major(buff);
    else {
    	while (i < size) {
    	    mx_printchar(' ');
    	    size--;
    	}
        mx_printint(buff->st_size);
        mx_printchar(' ');
    }
}

static void mx_time(struct stat *buff) {
    char *time = ctime(&buff->st_mtime);
    char **arr = mx_strsplit(time, ' ');

    for (int i = 0; arr[i] != NULL ; i++)
    {
    	printf("%s\n", arr[i]);
    }
    mx_strdel(&time);
}

void mx_print_l(t_list *files, char *str, struct s_size_colum *sc) {
    struct stat buff;
    char *link = NULL;

    lstat(str, &buff);
    link = linkname(&buff, str);
    mx_socets(&buff, str);
    nlink(&buff, sc->nlink);
    uid(&buff);
    gid(&buff);
    size_mm(&buff, sc->size);
    mx_time(&buff);
    mx_printstr(files->data);
  if ((buff.st_mode & MX_IFMT) == MX_ISLNK) {
    	mx_printstr(" -> ");
    	mx_printstr(link);
    	mx_strdel(&link);
    }
    mx_printchar('\n');
}
