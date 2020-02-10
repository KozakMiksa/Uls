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
        case 'C':
            if (true_flags->m != 1) {
                true_flags->big_c = 1;
                true_flags->l = 0;
                true_flags->one = 0;
            }
            break ;
    }
}
