#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

/**
 * menger - creates a sierpinski carpet
 * @level: level of the sierpinski carpet
 * Return: None
 */
void menger(int level)
{
	int s = 1;
	int count, tmp;
	int r, y;


	if (level == 0)
	{
		printf("#\n");
		return;
	}
	else if (level < 0)
		return;

	for (count = 0; count < level; count++)
		s *= 3;
	for (count = 0; count < s; count++)
	{
		for (tmp = 0; tmp < s; tmp++)
		{
			r = count;
			y = tmp;
			while (r > 0 && y > 0)
			{
				if (r % 3 == 1 && y % 3 == 1)
				{
					printf(" ");
					break;
				}
				r /= 3;
				y /= 3;
			}
			if (y % 3 != 1 || r % 3 != 1)
				printf("#");
		}
		printf("\n");
	}
}
