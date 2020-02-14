#include "uls.h"

static void if_last_l_or_one(t_flags *true_flags, char *str) {
    if (mx_get_index(str, 'l') > mx_get_index(str, 'C') &&
        mx_get_index(str, 'l') > mx_get_index(str, '1') &&
        mx_get_index(str, 'l') > mx_get_index(str, 'm') &&
        (mx_get_index(str, 'l') > mx_get_index(str, 'n') ||
        mx_get_index(str, 'l') < mx_get_index(str, 'n')) &&
        (mx_get_index(str, 'l') > mx_get_index(str, 'o') ||
        mx_get_index(str, 'l') < mx_get_index(str, 'o')))
        true_flags->l = 1;
    if (mx_get_index(str, '1') > mx_get_index(str, 'C') &&
        mx_get_index(str, '1') > mx_get_index(str, 'l') &&
        mx_get_index(str, '1') > mx_get_index(str, 'm') &&
        mx_get_index(str, '1') > mx_get_index(str, 'n') &&
        mx_get_index(str, '1') > mx_get_index(str, 'o')) 
        true_flags->one = 1;
}

static void if_last_big_c_or_m(t_flags *true_flags, char *str) {
    if (mx_get_index(str, 'C') > mx_get_index(str, 'l') &&
        mx_get_index(str, 'C') > mx_get_index(str, '1') &&
        mx_get_index(str, 'C') > mx_get_index(str, 'n') &&
        mx_get_index(str, 'C') > mx_get_index(str, 'o'))
        true_flags->big_c = 1;
    if (mx_get_index(str, 'm') > mx_get_index(str, 'l') &&
        mx_get_index(str, 'm') > mx_get_index(str, '1') &&
        mx_get_index(str, 'm') > mx_get_index(str, 'n') &&
        mx_get_index(str, 'm') > mx_get_index(str, 'o') &&
        (mx_get_index(str, 'm') > mx_get_index(str, 'C') ||
        mx_get_index(str, 'm') < mx_get_index(str, 'C'))) 
        true_flags->m = 1;
}

static void if_last_n_or_o(t_flags *true_flags, char *str) {
    if (mx_get_index(str, 'n') > mx_get_index(str, 'C') &&
        mx_get_index(str, 'n') > mx_get_index(str, '1') &&
        mx_get_index(str, 'n') > mx_get_index(str, 'm') &&
        (mx_get_index(str, 'n') > mx_get_index(str, 'l') ||
        mx_get_index(str, 'n') < mx_get_index(str, 'l'))) 
        true_flags->n = 1;
    if (mx_get_index(str, 'o') > mx_get_index(str, 'C') &&
        mx_get_index(str, 'o') > mx_get_index(str, '1') &&
        mx_get_index(str, 'o') > mx_get_index(str, 'm') &&
        (mx_get_index(str, 'o') > mx_get_index(str, 'l') ||
        mx_get_index(str, 'o') < mx_get_index(str, 'l'))) 
        true_flags->o = 1;
}

static void for_flag_u_and_c(t_flags *true_flags, char *str) {
    if ((mx_get_index(str, 't') != -1 || mx_get_index(str, 'l') != -1) &&
        mx_get_index(str, 'u') != -1 && mx_get_index(str, 'c') == -1)
        true_flags->u = 1;
    if ((mx_get_index(str, 't') != -1 || mx_get_index(str, 'l') != -1) &&
        mx_get_index(str, 'c') != -1 && mx_get_index(str, 'u') == -1)
        true_flags->c = 1;
    if ((mx_get_index(str, 't') != -1 || mx_get_index(str, 'l') != -1) &&
        mx_get_index(str, 'c') != -1 && mx_get_index(str, 'u') != -1) {
        if (true_flags->c != 1)
            true_flags->u = 1;
        if (true_flags->u != 1)
            true_flags->c = 1;
        }
}

void mx_principal_printable_flag(t_flags *true_flags, char *str) {
    if_last_l_or_one(true_flags, str);
    if_last_big_c_or_m(true_flags, str);
    if_last_n_or_o(true_flags, str);
    if (true_flags->l == 1 || true_flags->m == 1 || true_flags->one == 1)
        true_flags->big_c = 0;
    for_flag_u_and_c(true_flags, str);
}


