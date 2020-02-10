#include "uls.h"

void mx_select_flags_second(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'l':
            true_flags->l = 1;
            true_flags->big_c = 0;
            true_flags->one = 0;
            true_flags->m = 0;
            break ;
        case '1':
            true_flags->one = 1;
            true_flags->big_c = 0;
            true_flags->l = 0;
            true_flags->m = 0;
            break ;
        case 'm':
            true_flags->m = 1;
            true_flags->big_c = 0;
            true_flags->one = 0;
            true_flags->l = 0;
            break ;
    }
}
