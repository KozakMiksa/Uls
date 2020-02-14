#include "uls.h"

static void get_size(t_list **names, int list_size) {
    struct stat buff;
    t_size *with_s = malloc(sizeof(t_size) * list_size);

    for (int i = 0; i < list_size; i++) {
        stat((*names)->data, &buff);
        with_s[i].name = (*names)->data;
        with_s[i].size = buff.st_size;
        mx_pop_front(names);
        mx_push_back(names, &with_s[i]);
    }
}

void mx_size_sort(t_list **names) {
    t_size *tmp = NULL;
    t_list *list = *names;
    int list_size = mx_list_size(*names);

    get_size(names, list_size);
    for (t_list *i = list; i->next != NULL; i = i->next) {
        for (t_list *j = list; j->next != NULL; j = j->next) {
            if (((t_size *)(j)->data)->size < ((t_size *)(j)->next->data)->size) {
                tmp = j->data;
                j->data = j->next->data;
                j->next->data = tmp;
            }
        }
    }
   	while (list_size > 0) {
        mx_push_back(names, ((t_size *)(*names)->data)->name);
        mx_pop_front(names);
        list_size--;
    }
}

// while (*names != NULL) {
//         mx_printstr(((t_size *)(*names)->data)->name);
//         mx_printchar(' ');
//         mx_printint(((t_size *)(*names)->data)->size);
//         mx_printchar('\n');
//         *names = (*names)->next;
//     }
