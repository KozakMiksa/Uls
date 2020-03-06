#include "uls.h"

static char *str_with_true_flags(char **argv, int argc);
static void print_usage_error(char **argv, int i, int k);
static void create_matrix_of_flags(t_flags *true_flags);
static int len_true_flags(char **argv, int argc);

t_list **mx_usage_error(int argc, char **argv, char *usage_flags) {
    int x = 0;
    char *str = str_with_true_flags(argv, argc);
    t_flags true_flags;

    create_matrix_of_flags(&true_flags);
    mx_principal_printable_flag(&true_flags, str);
    mx_strdel(&str);
    for (int i = 1; i < argc && x == 0; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            for (int k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-') {
                    if (mx_get_index(usage_flags, argv[i][k]) == -1) {
                        if (mx_strcmp(argv[i], "--") == 0)
                            x = i;
                        else 
                            print_usage_error(argv, i, k);
                    }
                    else
                        mx_select_flags(&true_flags, argv[i][k]);
                }
        }
        else 
            x = i;
    return mx_parsing(x, argc, argv, &true_flags);
}

static void create_matrix_of_flags(t_flags *true_flags) {
    true_flags->a = 0;
    true_flags->f = 0;
    true_flags->l = 0;
    true_flags->one = 0;
    true_flags->big_r = 0;
    true_flags->big_a = 0;
    true_flags->h = 0;
    true_flags->big_t = 0;
    true_flags->big_c = 0;
    true_flags->big_f = 0;
    true_flags->m = 0;
    true_flags->p = 0;
    true_flags->r = 0;
    true_flags->t = 0;
    true_flags->u = 0;
    true_flags->c = 0;
    true_flags->big_s = 0;
    true_flags->o = 0;
    true_flags->n = 0;
}

static void print_usage_error(char **argv, int i, int k) {
    write(2, "uls: illegal option -- ", 23);
    write(2, &argv[i][k], 1);
    write(2, "\nusage: uls [-ACFRSTacfhlmnoprtu1] [file ...]\n", 46);
    exit(0);
}

static int len_true_flags(char **argv, int argc) {
    int size = 0;
    int i = 1;
    int k = 1;

    for (i = 1; i < argc && argv[i][0] == '-'; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            for (k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-' && argv[i][1] != '-')
                    size = size + mx_strlen(argv[i]) - 1;
    return size;
}

static char *str_with_true_flags(char **argv, int argc) {
    char *str = NULL;
    int size = 0;
    int j = 0;
    int i = 1;
    int k = 1;

    size = len_true_flags(argv, argc);
    str = mx_strnew(size);
    for (i = 1; i < argc && argv[i][0] == '-'; i++)
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            for (k = 1; argv[i][k] != '\0'; k++)
                if (argv[i][0] == '-') {
                    if (mx_strcmp(argv[i],"--") == 0)
                        return str;
                    else {
                        str[j] = argv[i][k];
                        j++;
                    }
                }
    return str;
}
