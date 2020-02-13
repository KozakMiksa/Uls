#include "uls.h"

void mx_r_sort(t_list **names) {
    t_list *tmp = NULL;

    while (*names != NULL) {
        if (tmp == NULL)
            tmp = mx_create_node((*names)->data);
        else
            mx_push_front(&tmp, (*names)->data);

        mx_pop_front(names);
    }
    *names = tmp;
}
