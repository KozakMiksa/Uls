#include "uls.h"

void mx_select_flags(t_flags *true_flags, char flag) {
    mx_select_flags_first(true_flags, flag);
    mx_select_flags_second(true_flags, flag);
    mx_select_flags_third(true_flags, flag);
    mx_select_flags_fourth(true_flags, flag);
    mx_select_flags_fifth(true_flags, flag);
    mx_select_flags_sixth(true_flags, flag);
}
