#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * create_node - Builds an AVL tree
 * @val: value
 * @parent: parent
 *
 * Return: pointer
 */
avl_t *create_node(int val, avl_t *parent)
{
	avl_t *ptr = malloc(sizeof(avl_t));

	if (!ptr)
		return (NULL);
	ptr->n = val;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->parent = parent;
	return (ptr);
}

/**
 * construct_tree - Recursive function that constructs
 * a balanced tree based on a sorted array
 * @parent: parent node
 * @array: array of ints
 * @l: index used as left boundary
 * @r: index used as right boundary
 *
 * Return: pointer to the root node of the created tree
 */
avl_t *construct_tree(avl_t *parent, int *array, int l, int r)
{
	avl_t *ptr;
	int m = (r - l) / 2 + l;

	if (l > r)
		return (NULL);
	ptr = create_node(array[m], parent);
	if (!ptr)
		return (NULL);
	ptr->left = construct_tree(ptr, array, l, m - 1);
	ptr->right = construct_tree(ptr, array, m + 1, r);

	return (ptr);
}

/**
 * sorted_array_to_avl - Builds an AVL tree
 * @array: pointer to the first element
 * @size: number of element in the array
 * Return: a pointer
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int l = 0;
	int r = size - 1;

	root = construct_tree(root, array, l, r);
	if (!root)
		return (NULL);
	return (root);
}
