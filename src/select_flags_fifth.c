#include "uls.h"

void mx_select_flags_fifth(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'f':
            true_flags->f = 1;
            true_flags->a = 1;
            true_flags->big_a = 0;
            true_flags->r = 0;
            true_flags->t = 0;
            true_flags->big_s = 0;
            break ;
        case 'R':
            true_flags->big_r = 1;
            break ;
        case 'G':
            true_flags->big_g = 1;
            break ;
    }
}
