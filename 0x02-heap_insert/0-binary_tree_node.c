#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @value: value  node
 * @parent: node's parent
 * Return: pointer that refer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *N;

		N = malloc(sizeof(binary_tree_t));


	if (!N)
		return (NULL);
	N->parent = parent;
	N->n = value;
	N->left = NULL;
	N->right = NULL;
	return (N);
}