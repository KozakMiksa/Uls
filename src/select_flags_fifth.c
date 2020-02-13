#include "uls.h"

void mx_select_flags_fifth(t_flags *true_flags, char flag) {
    switch(flag) {
        case 'c':
            if (true_flags->t == 1 || true_flags->l == 1) {
                true_flags->c = 1;
                true_flags->u = 0;
            }
            break;
        case 'u':
            if (true_flags->t == 1 || true_flags->l == 1) {
                true_flags->u = 1;
                true_flags->c = 0;
            }
            break;
    }
}
