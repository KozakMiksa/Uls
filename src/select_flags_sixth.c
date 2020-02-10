#include "uls.h"

void mx_select_flags_sixth(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'c':
            true_flags->c = 1;
            true_flags->u = 0;
            break ;
        case 'u':
            true_flags->u = 1;
            true_flags->c = 0;
            break ;
        case 'F':
            true_flags->big_f = 1;
            true_flags->p = 0;
            break ;
        case 'p':
            true_flags->p = 1;
            true_flags->big_f = 0;
            break ;
    }
}
