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

static void uid(struct stat *buff, int size) {
    struct passwd *pw = getpwuid(buff->st_uid);
    int i = mx_strlen(pw->pw_name);
    
    mx_printstr(pw->pw_name);
    while (i < size) {
    	mx_printchar(' ');
    	i++;
    }
    mx_printstr("  ");
}

static void gid(struct stat *buff, int size) {
    struct group *gr;
    int i = 0;

    gr = getgrgid(buff->st_gid);
    if (gr != NULL) {
    	i = mx_strlen(gr->gr_name);
    	mx_printstr(gr->gr_name);
    	while (i < size) {
    	    mx_printchar(' ');
    	    size--;
    	}
    }
    else {
    	i = mx_size_colum(buff->st_gid);
    	mx_printint(buff->st_gid);
    	while (i < size) {
    	    mx_printchar(' ');
    	    size--;
    	}
    }
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

    mx_printstr(arr[1]);
    mx_printstr(" ");
    if (mx_strlen(arr[2]) == 1)
    	mx_printchar(' ');
    mx_printstr(arr[2]);
    mx_printchar(' ');
    for (int i = 0; i < 5; i++)
        mx_printchar(arr[3][i]);
    mx_printchar(' ');
}

void mx_print_l(t_list *files, char *str, struct s_size_colum *sc) {
    struct stat buff;
    char *link = NULL;

    lstat(str, &buff);
    link = linkname(&buff, str);
    mx_socets(&buff, str);
    nlink(&buff, sc->nlink);
    uid(&buff, sc->uid);
    gid(&buff, sc->gid);
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
