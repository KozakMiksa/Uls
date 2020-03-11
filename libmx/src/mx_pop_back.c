#include "libmx.h"

void mx_pop_back(t_list **head) {
    if((*head)->next == NULL) {
        free(*head);
    }
    t_list *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
