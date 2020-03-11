#include "uls.h"

static void size_name(struct stat *buff, int *uid, int *gid) {
    struct passwd *pw = getpwuid(buff->st_uid);
    struct group *gr = getgrgid(buff->st_gid);

    if (mx_strlen(pw->pw_name) > *uid)
        *uid = mx_strlen(pw->pw_name);
    if (gr != NULL) {
        if (mx_strlen(gr->gr_name) > *gid)
            *gid = mx_strlen(gr->gr_name);
    }
    else
        if (mx_size_colum(buff->st_gid) > *gid)
            *gid = mx_size_colum(buff->st_gid);
}

static void maj_min(struct stat *buff, int *maj, int *min) {
    int major = MX_MAJOR(buff->st_rdev);
    int minor = MX_MINOR(buff->st_rdev);

    if (*maj < mx_size_colum(major))
        *maj = mx_size_colum(major);
    if (*min < mx_size_colum(minor))
        *min = mx_size_colum(minor);
}

static void size_colum(struct s_size_colum *sc, t_list *files, char *dir) {
    char *str = NULL;
    struct stat buff;

    while (files != NULL) {
        if (dir != NULL)
            str = mx_path_to_dir(files->data, dir);
        else
            str = files->data;
        lstat(str, &buff);
        if (sc->nlink < mx_size_colum(buff.st_nlink))
            sc->nlink = mx_size_colum(buff.st_nlink);
        if (sc->size < mx_size_colum(buff.st_size))
            sc->size = mx_size_colum(buff.st_size);
        size_name(&buff, &sc->uid, &sc->gid);
        if ((buff.st_mode & MX_IFMT) == MX_ISCHR ||
        (buff.st_mode & MX_IFMT) == MX_ISBLK)
            maj_min(&buff, &sc->maj, &sc->min); 
        files = files->next;
    }
}

void mx_l_flag(t_list *files, t_list *flags, char *dir) {
    char *str = NULL;
    struct s_size_colum sc = {0, 0, 0, 0, 0, 0};

    size_colum(&sc, files, dir);
    mx_select_sort(&files, flags, mx_get_flag(flags, "ftS", 'C'), dir);
    if (mx_get_flag(flags, "r", 'C') == 'r')
        mx_r_sort(&files);
    while (files != NULL) {
        if (dir != NULL) {
            str = mx_path_to_dir(files->data, dir);
        }
        else
            str = files->data;
        mx_print_l(files, str, &sc);
        files = files->next;
    }
}
