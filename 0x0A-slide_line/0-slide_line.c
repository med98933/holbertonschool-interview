#include "slide_line.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * slide_line_left - slides and merges an array of integers to the left
 * @line: points to an array of integers
 * @size: Number of elements in array
 * Return: 1 success, 0 Fail
 */
int slide_line_left(int *line, size_t size)
{
	int num1 = 0, num2 = 0;
	size_t c = 0, i;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && num1 == 0)
			num1 = line[i];
		else if (line[i] != 0 && num1 != 0)
			num2 = line[i];
		if (num1 != 0 && num2 != 0)
		{
			if (num1 == num2)
			{
				line[c++] = num1 + num2;
				num1 = 0;
				num2 = 0;
			}
			else
			{
				line[c++] = num1;
				num1 = num2;
				num2 = 0;
				if (i == size - 1)
					line[c++] = num1;
			}
		}
		else if (num1 != num2 && i == size - 1)
			line[c++] = num1;
	}
	for (i = c; i < size; i++)
		line[i] = 0;

	return (1);
}


/**
 * slide_line_right - sAdd numbers once
 * @line: Number of elements in @line
 * @size: Number of elements in @line
 * Return: 1 success, 0 Fail
 */
int slide_line_right(int *line, size_t size)
{
	int num1 = 0, num2 = 0;
	size_t c = size - 1, i;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && num1 == 0)
			num1 = line[i];
		else if (line[i] != 0 && num1 != 0)
			num2 = line[i];
		if (num1 != 0 && num2 != 0)
		{
			if (num1 == num2)
			{
				line[c--] = num1 + num2;
				num1 = 0;
				num2 = 0;
			}
			else
			{
				line[c--] = num1;
				num1 = num2;
				num2 = 0;
				if (i == 0)
					line[c--] = num1;
			}
		}
		else if (num1 != num2 && i == 0)
			line[c--] = num1;
	}
	for (i = 0; i < c + 1; i++)
		line[i] = 0;

	return (1);
}


/**
 * slide_line - move right or left (2048 game)
 * @line: move right or left (2048 game)
 * @size: Number of elements in array
 * @direction:  direction to slide and merge
 * Return:  Your function must return 1 upon success,
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (slide_line_left(line, size));
	return (slide_line_right(line, size));
}
