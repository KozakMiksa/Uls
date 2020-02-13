#include "uls.h"

char mx_get_flag(t_list *flags, char *corect_flags) {
    t_list *cp_flags = flags;
    char our_flag = 'C';
    char *tmp;

    while (cp_flags != NULL) {
        for (int j = 0; corect_flags[j] != '\0'; j++) {
        	tmp = cp_flags->data;
            if (tmp[0] == corect_flags[j])
                our_flag = corect_flags[j];
        }
        cp_flags = cp_flags->next;
    }
    return our_flag;
}
