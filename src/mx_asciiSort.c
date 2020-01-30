#include "uls.h"

t_list *mx_asciiSort(t_list *l) {
    char *tmp = NULL;
    t_list *list = l;

    for (t_list *i = list; i->next != NULL; i = i->next) {
        for (t_list *j = list; j->next != NULL; j = j->next) {
            if (mx_strcmp(j->data, j->next->data) > 0) {
            	tmp = j->data;
            	j->data = j->next->data;
            	j->next->data = tmp;
            }
        }
    }
    return list;
}
