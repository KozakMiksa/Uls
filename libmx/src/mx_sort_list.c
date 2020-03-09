#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    void *tmp;

    if (!lst && !cmp)
        return NULL;
    for (t_list *i = lst; i->next; i = i->next) {
        for (t_list *k = i->next; k; k = k->next) {
            if (cmp(i->data, k->data)) {
                tmp = i->data;
                i->data = k->data;
                k->data = tmp;
            }
        }
    }
    return lst;
}
