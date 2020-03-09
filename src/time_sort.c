#include "uls.h"

static void get_time(t_list **names, int list_size, char *dir, t_list *flags) {
    struct stat buff;
    t_time *with_t = malloc(sizeof(t_time) * list_size);
    char flag = mx_get_flag(flags, "uc", 't');
    char *str = NULL;

    for (int i = 0; i < list_size; i++) {
        str = (*names)->data;
        if (dir != NULL)
            str = mx_path_to_dir((*names)->data, dir);
        lstat(str, &buff);
        with_t[i].name = (*names)->data;
        if (flag == 't')
            with_t[i].t = buff.st_mtime;
        if (flag == 'c')
            with_t[i].t = buff.st_ctime;
        if (flag == 'u')
            with_t[i].t = buff.st_atime;
        mx_pop_front(names);
        mx_push_back(names, &with_t[i]);
    }
}

void mx_time_sort(t_list **names, char *dir, t_list *flags) {
    t_time *tmp = NULL;
    t_list *list = *names;
    int list_size = mx_list_size(*names);

    get_time(names, list_size, dir, flags);
    for (t_list *i = list; i->next != NULL; i = i->next) {
        for (t_list *j = list; j->next != NULL; j = j->next) {
            if (((t_time *)(j)->data)->t < ((t_time *)(j)->next->data)->t) {
                tmp = j->data;
                j->data = j->next->data;
                j->next->data = tmp;
            }
        }
    }
   	while (list_size > 0) {
        mx_push_back(names, ((t_time *)(*names)->data)->name);
        mx_pop_front(names);
        list_size--;
    }
}
