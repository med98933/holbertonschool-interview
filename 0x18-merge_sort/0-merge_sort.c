#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_worker - sorts an array of integers in ascending order
 * @array: the unsorted array
 * @s: the temporary array that contains subarrays
 * @x: x index
 * @tmp: pointer to a working array
 * Return: nothing
 */
void merge_worker(int *array, int s, int x, int *tmp)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array, x);
	printf("[right]: ");
	print_array(array + x, s - x);
	for (i = 0, j = x, k = 0; k < s; k++)
	{

		if (j == s)
		{
			tmp[k] = array[i];
			i++;
		}
		else if (i == x)
		{
			tmp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			tmp[k] = array[j];
			j++;
		}
		else
		{
			tmp[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < s; i++)
	{
		array[i] = tmp[i];
	}
	printf("[Done]: ");
	print_array(tmp, s);
}

/**
 * merge_rec - merge sort using recursion
 * @array: pointer to the array
 * @s: s of the array
 * @tmp: pointer to a working array
 * Return: nothing
 */
void merge_rec(int *array, size_t s, int *tmp)
{
	int x;

	if (s < 2)
		return;
	x = s / 2;
	merge_rec(array, x, tmp);
	merge_rec(array + x, s - x, tmp);
	merge_worker(array, s, x, tmp);
}

/**
 * merge_sort - merge sort
 * @array: pointer to the array
 * @size: s of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	merge_rec(array, size, tmp);
	free(tmp);
}
