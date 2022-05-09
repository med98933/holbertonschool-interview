#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * max - val max
 *
 * @a: val a
 * @b: val b
 * Return: 0 if not
 **/


int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * height- meisure height
 *
 * @N: val N
 * Return: nothing
 */
int height(const binary_tree_t *N)
{
	if (N == NULL)
		return (0);
	return (1 + max(height(N->l), height(N->r)));
}

/**
 * isBST - check if the tree is bst
 *
 * @tree: chek tree
 * @min: min val
 * @max: max val
 * Return: 1 if true else 0
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (isBST(tree->l, min, tree->n - 1) &&
		isBST(tree->r, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - check if th etree
 *
 * @tree: node
 * Return: nothing
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	int l, r;

	if (tree == NULL)
		return (0);

	if (!isBST(tree, INT_MIN, INT_MAX))
		return (0);

	l = height(tree->l);
	r = height(tree->r);

	if (abs(r - l) > 1)
		return (0);

	if (!(tree->l) || !(tree->r))
		return (1);
	else
		return (binary_tree_is_avl(tree->l) && binary_tree_is_avl(tree->r));
}
