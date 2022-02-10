#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
* add_node_end - adds a node at the end of a double circular
* @list: the double circular linked list
* @str: the string to instert in the node
* Return: the address of the new insterted node or
*/
List *add_node_end(List **list, char *str)
{
	List *n;

	if (!list || !str)
		return (NULL);
	n = malloc(sizeof(List));
	if (!n)
		return (NULL);
	n->str = strdup((const char *)str);
	if (!(n->str))
	{
		free(n);
		return (NULL);
	}
	if (!*list)
	{
		*list = n;
		n->prev = n;
		n->next = n;
	}
	else
	{
		n->prev = (*list)->prev;
		n->next = *list;
		n->prev->next = n;
		n->next->prev = n;
	}
	return (n);
}
/**
 * add_node_begin - adds a node at the beginning of a double circular linked
 *                  list
 * @list: the double circular linked list
 * @str: the string to instert in the node
 * Return: the address
 */
List *add_node_begin(List **list, char *str)
{
	List *n;

	if (!list || !str)
		return (NULL);
	n = malloc(sizeof(List));
	if (!n)
		return (NULL);
	n->str = strdup((const char *)str);
	if (!n->str)
	{
		free(n);
		return (NULL);
	}
	if (!*list)
	{
		*list = n;
		n->prev = n;
		n->next = n;
	}
	else
	{
		n->prev = (*list)->prev;
		n->next = *list;
		n->prev->next = n;
		n->next->prev = n;
		*list = n;
	}
	return (n);
}
