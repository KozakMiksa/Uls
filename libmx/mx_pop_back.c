#include "libmx.h"
void mx_pop_back(t_list **head)
{
/*	if (*head == NULL)
	{
		return;
	}*/
	t_list *s = *head;
	/*if (*head->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{*/
        while(s->next->next != NULL)
        {
            s = s->next;
        }
        t_list *ss = s;
        s = s->next;
        free(s);
        ss->next = NULL;
   // }
}
