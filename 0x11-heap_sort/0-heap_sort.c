#include "sort.h"
#include <stddef.h>
#include <unistd.h>

/**
 * swap_values - interchange 2 values of a given list
 * @array: list of numbers
 * @i: index of the value1 to swap
 * @last: index of the value2 to swap
 * @size: original len arr
 * Return: nothing
 */
void swap_values(int *array, int i, int last, int size)
{
	int tmp = 0;

	tmp = array[i];
	array[i] = array[last];
	array[last] = tmp;
	print_array(array, size);
}

/**
 * heapify - recursively makes the array a max-heap
 * @array: the array is treated as a complete binary tree
 * @i: size of the array
 * @y: index of the parent node (it will be compared with its children)
 * @size: oindex to mark the end of the unsorted part of the array
 */
void heapify(int *array, int i, int y, int size)
{
	int x = y, z = (y * 2) + 1, c = (y * 2) + 2;

	if (z < i && array[z] > array[x])
		x = z;

	if (c < i && array[c] > array[x])
		x = c;

	if (x != y)
	{
		swap_values(array, y, x, size);
		heapify(array, i, x, size);
	}
}

/**
 * heap_sort -  sorts an array using the sift-down heap sort algorithm
 * @array: he array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int y = 0, i = size;

	for (y = (size / 2) - 1; y >= 0; y--)
		heapify(array, i, y, size);

	for (y = size - 1; y >= 0; y--)
	{
		if (y != 0)
			swap_values(array, y, 0, size);
		heapify(array, y, 0, size);
	}
}
