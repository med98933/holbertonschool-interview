#include "search_algos.h"
/**
 * advanced_binary - searches for a n in a sorted array
 * of integers using the Binary search algorithm - always the first one
 * @array:  pointer to the first element of the array to search in
 * @s: number of elements in array
 * @n: n to search for
 * Return:  index where n is located otherwise -1
 *
 **/
int advanced_binary(int *array, size_t s, int n)
{
	size_t i = 1, j, o = 0;
	int tmp;

	if (array == NULL || s == 0)
		return (-1);
	printf("Searching in array: %d", array[0]);
	while (i < s)
		printf(", %d", array[i++]);
	printf("\n");
	if (s == 1 && array[0] != n)
		return (-1);
	j = (s - 1) / 2;
	if (array[j] == n)
	{
		if (j == 0 || (array[j - 1] < n))
			return (j);
	}
	if (array[j] < n)
	{
		o = o + j + 1;
		array = array + j + 1;
		if (s % 2 != 0)
			j--;
	}
	j++;
	tmp = advanced_binary(array, j, n);
	if (tmp != -1)
		return (tmp + o);
	return (-1);
}
