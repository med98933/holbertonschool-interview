#include <stdio.h>
#include <stdlib.h>
#include "search.h"




/**
 * check_next_list -  function that checks if a value
 *
 *
 * @node: first node
 *
 *
 * @value: value to search for
 *
 *
 * Return: the node that contains the value or NULL
 */
skiplist_t *check_next_list(skiplist_t *node, int value)
{
	for (; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}
	return (NULL);
}

/**
 * linear_skip -   it  search a value in the next pos
 *
 *
 * @list:  pointer to the next list to search in
 *
 * @value: value to search for
 *
 *
 * Return:first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *index, *j, *i;

	if (!list)
		return (NULL);
	index = list;
	while (index)
	{
		if (index->express == NULL)
		{
			j = index->express;
			for (i = list; i; i = i->next)
				if (i->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
					       index->index, i->index);
					break;
				}
			break;
		}
		if (index->express->n >= value)
		{
			j = index->express;
			printf("Value checked at index [%lu] = [%d]\n", j->index, j->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       index->index, j->index);
			break;
		}
		index = index->express;
		printf("Value checked at index [%lu] = [%d]\n", index->index, index->n);
	}

	return (check_next_list(index, value));
}
