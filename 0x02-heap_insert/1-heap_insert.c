#include "binary_trees.h"

/**
 * swapNode - return  a given binary node
 * @myNode: pointer
 * Return: void
 *
 */
void swapNode(heap_t **myNode)
{
	heap_t *count;
	int i;

	for (count = *myNode; count->parent; count = count->parent)
		if (count->n > count->parent->n)
		{
			i = count->parent->n;
			count->parent->n = count->n;
			count->n = i;
			*myNode = count->parent;
		}
}

/**
 * testx - find the parent
 * @root: root
 *
 * Return: Pointer to the parent node.
 */
heap_t *testx(heap_t **root)
{
	heap_t *node = NULL;
	heap_t *a[100];
	int tmp = 0, b = 0;



	a[b] = *root;
	while (2021)
	{
		node = a[tmp];
		tmp++;
		if (!node->left)
		{
			tmp = b = 0;
			return (node);
		}
		else if (!node->right)
		{
			tmp = b = 0;
			return (node);
		}
		else
		{
			b = b + 1;
			a[b] = node->left;
			b = b + 1;
			a[b] = node->right;
		}
	}
}
/**
 * heap_insert -  insertion function.
 * @root: root
 *
 * @value: number to be inserted
 * Return: Pointer to the new created node.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newN = NULL, *parent = NULL;


	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	parent = testx(root);
	newN = binary_tree_node(parent, value);
	if (!parent->left)
		parent->left = newN;
	else
		parent->right = newN;

	if (newN->n > parent->n)
		swapNode(&newN);
	return (newN);
}
