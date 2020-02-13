#include "uls.h"

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

void mx_who_last_flag_l_big_c_m_one(t_flags *true_flags, char *str) {
    if (mx_get_index(str, 'l') > mx_get_index(str, 'C') &&
        mx_get_index(str, 'l') > mx_get_index(str, '1') &&
        mx_get_index(str, 'l') > mx_get_index(str, 'm')) 
        true_flags->l = 1;
    if (mx_get_index(str, 'C') > mx_get_index(str, 'l') &&
        mx_get_index(str, 'C') > mx_get_index(str, '1'))
        true_flags->big_c = 1;
    if (mx_get_index(str, 'm') > mx_get_index(str, 'l') &&
        mx_get_index(str, 'm') > mx_get_index(str, '1') &&
        (mx_get_index(str, 'm') > mx_get_index(str, 'C') ||
        mx_get_index(str, 'm') < mx_get_index(str, 'C'))) 
        true_flags->m = 1;
    if (mx_get_index(str, '1') > mx_get_index(str, 'C') &&
        mx_get_index(str, '1') > mx_get_index(str, 'l') &&
        mx_get_index(str, '1') > mx_get_index(str, 'm')) 
        true_flags->one = 1;
    if (true_flags->l == 1 || true_flags->m == 1 || true_flags->one == 1)
        true_flags->big_c = 0;
    for_flag_u_and_c(true_flags, str);
}
