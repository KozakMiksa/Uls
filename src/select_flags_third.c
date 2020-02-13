#include "uls.h"

void mx_select_flags_third(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'h':
            if (true_flags->l == 1)
                true_flags->h = 1;
            break ;
        case '@':
            if (true_flags->l == 1)
                true_flags->dog = 1;
            break ;
        case 'e':
            if (true_flags->l == 1)
                true_flags->e = 1;
            break ;
        case 'T':
            if (true_flags->l == 1)
                true_flags->big_t = 1;
            break ;
    }
}
