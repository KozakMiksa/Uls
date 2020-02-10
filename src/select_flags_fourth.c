#include "uls.h"

void mx_select_flags_fourth(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'r':
            if (true_flags->f != 1)
                true_flags->r = 1;
            break ;
        case 't':
            if (true_flags->big_s != 1 && true_flags->f != 1)
                true_flags->t = 1;
            break ;
        case 'S':
            if (true_flags->f != 1) {
                true_flags->big_s = 1;
                true_flags->t = 0;
            }
            break ;
    }
}
