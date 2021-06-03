#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
* find_listint_loop - finds the loop in a linked list
* @head: head of the list
*
* Return: The address of the node where the loop starts, or NULL
*
* or NULL if there is no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *s = head, *f = head;
if (head == NULL || head->next == NULL)
return (NULL);
while (f->next && f->next->next)
{
s = s->next;
f = f->next->next;
if (s == f)
{
s = head;
while (f != NULL)
{
if (s == f)
return (s);
s = s->next;
f = f->next;
}
}
}
return (NULL);
}
