#include "sort.h"
#include <limits.h>
/**
 * current_digit_sort - sort by current digit
 * @array: array
 * @size: size of array
 * @tmp: temporal array
 * @exp: actual exponent digit
 * Return: array sort
 */
int current_digit_sort(int *array, ssize_t size, int *tmp, long exp)
{
	ssize_t x;
	int aux[10] = {0};

	for (x = 0; x < size; x++)
		aux[(array[x] / exp) % 10]++, tmp[x] = 0;
	for (x = 1; x < 10; x++)
		aux[x] += aux[x - 1];
	for (x = size - 1; x >= 0; x--)
		tmp[--aux[(array[x] / exp) % 10]] = array[x];
	for (x = 0; x < size; x++)
		array[x] = tmp[x];
	return (0);
}
/**
 * radix_sort - radix sort
 * @array: array
 * @size: size of array
 *
 */
void radix_sort(int *array, size_t size)
{
	size_t x;
	long e = 1;
	int *t, max = INT_MIN;

	if (!array || size < 2)
		return;

	t = malloc(sizeof(int *) * size);
	if (!t)
		return;

	for (x = 0; x < size; x++)
		max = array[x] > max ? array[x] : max;

	while (max / e > 0)
	{
		current_digit_sort(array, size, t, e);
		print_array(array, size);
		e *= 10;
	}
	free(t);
}
