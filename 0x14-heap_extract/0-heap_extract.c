#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: Address of the root pointer
*
* Return: returns the root value or 0 on failure
*/

int heap_extract(heap_t **root)
{
int i, n, z;
heap_t **array;

if (!root || !*root)
return (0);
n = (*root)->n;
z = get_size(*root);
array = malloc(1024 * sizeof(heap_t *));
if (!array)
return (0);
for (i = 0; i < z; i++)
array[i] = NULL;
arr_convert(array, *root, 0);
if (array[z - 1] == (*root))
{
free(array);
free(*root);
*root = NULL;
return (n);
}
(*root)->n = array[z - 1]->n;
if (array[z - 1]->parent->left == array[z - 1])
array[z - 1]->parent->left = NULL;
else
array[z - 1]->parent->right = NULL;
free(array[z - 1]);
free(array);
reconstruct_heap(*root);
return (n);
}


/**
 * get_size - returns the size of a heap
 * @root: the first node of the heap
 *
 * Return: heap's z
 */

int get_size(heap_t *root)
{
if (!root)
return (0);
else
return (get_size(root->left) + 1 + get_size(root->right));
}

/**
 * arr_convert - converts a heap into an array
 * @array: array
 * @root: first node of the heap
 * @x: whree to fill
 *
 * Return: void
 */
void arr_convert(heap_t **array, heap_t *root, int y)
{
array[y] = root;
if (root)
{
arr_convert(array, root->left, (y * 2) + 1);
arr_convert(array, root->right, (y * 2) + 2);
}
}

/**
 * reconstruct_heap -  heap in an array
 * @node: root of the heap
 *
 * Return: void
 */

void reconstruct_heap(heap_t *node)
{
int t;

if (!node->left)
{
return;
}
else if (!node->right || node->left->n >= node->right->n)
{
if (node->n < node->left->n)
{
t = node->n;
node->n = node->left->n;
node->left->n = t;
}
reconstruct_heap(node->left);
}
else if (node->left->n < node->right->n)
{
if (node->n < node->right->n)
{
t = node->n;
node->n = node->right->n;
node->right->n = t;
}
reconstruct_heap(node->right);
}
}
