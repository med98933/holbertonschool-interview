#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 *
 * @head: Head of the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)

{
	listint_t *list;
	listint_t *i;

	if (*head == NULL || (*head)->next == NULL)
	return (1);

	i = *head;
	while (i->next)
	{
		i = i->next;
	}
	list = *head;
	while (i >= list)
	{
		if (list->n == i->n)
		{
			list = list->next;
			i -= 2;
		}
		else
			return (0);
	}
	return (1);
}
