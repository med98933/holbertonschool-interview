#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number in a singly linked list
 * @head: address head of the list
 * @number: the number to insert
 * Return: address of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node; 
	listint_t *p;
	listint_t *current_node;
	if (*new_node == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	p = *head;
	*current_node = *head;
	while (p && p->n < number)
	{
		*current_node = p;
		p = p->next;
	}
	if (p == *head)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	new_node->next = *current_node->next;
	*current_node->next = new_node;
	return (new_node);
