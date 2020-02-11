#include "uls.h"

void mx_select_flags_first(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'a':
            true_flags->a = 1;
            true_flags->big_a = 0;
            break ;
        case 'A':
            true_flags->big_a = 1;
            if (true_flags->a == 1) 
                true_flags->big_a = 0;
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
