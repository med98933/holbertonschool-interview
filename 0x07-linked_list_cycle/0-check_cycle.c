#include "lists.h"

/**
* check_cycle 
*
* @list:  pointer to linked list
*
* Return: 0 if there is no cycle
*/

int check_cycle(listint_t *list)

{
	listint_t *s = list, *f = list;
	

	while (s && f && f->next)
	{
		
		s = s->next;
		f = f->next->next;

		
		if (s == f)
		{
			return (1);
		}
	}
	return (0);
}