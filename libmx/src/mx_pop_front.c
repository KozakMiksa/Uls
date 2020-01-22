#include "libmx.h"
void mx_pop_front(t_list **head)
{
    t_list *tmp = *head;
    *head = tmp->next;
    free(tmp);
}
