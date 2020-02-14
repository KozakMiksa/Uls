#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <errno.h>
//#include <string.h>

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MX_ISVTX 00001
#define MX_ISGID 02000
#define MX_ISUID 04000

typedef struct s_flags {
    int a;
    int f;
    int l;
    int one;
    int big_r;
    int big_a;
    int h;
    int big_t;
    int big_c;
    int big_f;
    int m;
    int p;
    int r;
    int t;
    int u;
    int c;
    int big_s;
    int o;
    int n;
} t_flags;

t_list **mx_usage_error(int argc, char **argv, char *usage_flags);
void mx_principal_printable_flag(t_flags *true_flags, char *str);
void mx_select_flags(t_flags *true_flags, char flag);
void mx_select_flags_first(t_flags *true_flags, char flag);
void mx_select_flags_second(t_flags *true_flags, char flag);
void mx_select_flags_third(t_flags *true_flags, char flag);
void mx_select_flags_fourth(t_flags *true_flags, char flag);
void mx_select_flags_fifth(t_flags *true_flags, char flag);
t_list **mx_parsing(int i, int argc, char **argv, t_flags *true_flags);
void mx_check_flags_first(t_list **parser, t_flags *true_flags);
void mx_check_flags_second(t_list **parser, t_flags *true_flags);

void mx_uls(t_list **parser);
  void mx_for_big_r(t_list ***parser);
  void mx_no_such_file_or_dir(t_list *names);
  void mx_all_files(t_list *files, t_list *flags);
    void mx_l_flag(t_list *files, t_list *flags);
    void mx_big_c_flag(t_list *files, t_list *flags);

    void mx_one_flag(t_list *files, t_list *flags);
    void mx_m_flag(t_list *files, t_list *flags);
void mx_permission(t_list *names);
void mx_all_directory(t_list *dir, t_list *flags);

void mx_ascii_sort(t_list **l);
char mx_get_flag(t_list *flags, char *corect_flags, char default_f);
char mx_get_flag(t_list *flags, char *corect_flags, char default_f);
void mx_mult_colum(t_list *names, int win_size, int longest, int size_list);
void mx_r_sort(t_list **names);

#endif
