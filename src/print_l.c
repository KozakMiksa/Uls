#include "uls.h"

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

static void gid(struct stat *buff, int size, int next) {
    struct group *gr = getgrgid(buff->st_gid);
    int i = 0;

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
    if (next > 3)
		mx_printstr("  ");
	else
		mx_printstr("   ");
}

void mx_print_l(t_list *files, char *str, struct s_size_colum *sc) {
    struct stat buff;
    char *link = NULL;

    lstat(str, &buff);
    link = linkname(&buff, str);
    mx_socets(&buff, str);
    nlink(&buff, sc->nlink);
    uid(&buff, sc->uid);
    gid(&buff, sc->gid, sc->size);
    mx_size_mm(&buff, sc, files->data);
    mx_time(&buff);
    mx_printstr(files->data);
    if ((buff.st_mode & MX_IFMT) == MX_ISLNK) {
    	mx_printstr(" -> ");
    	mx_printstr(link);
    	mx_strdel(&link);
    }
    mx_printchar('\n');
    // mx_strdel(&str);
}
