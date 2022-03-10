#include <stdio.h>
#include "holberton.h"

/**
* wildcmp - Compares 2 strings
*
* identical, otherwise return 0.
*
* @s1: 1st string
*
* @s2: 2nd string
*
* Return:  0 otherwise
*/

int wildcmp(char *s1, char *s2)
{
	int x, i;

	if (!*s1)
	{
		if (*s2 == '*')
		{
			x = wildcmp(s1, s2 + 1);
			return (x);
		}

		i = (*s2 == '\0') ? 1 : 0;

		return (i);
	}

	if (*s2 == '*')
	{
		x = wildcmp(s1, s2 + 1);
		i = wildcmp(s1 + 1, s2);
		return (x || i);
	}
	if (*s1 == *s2)
	{
		x = wildcmp(s1 + 1, s2 + 1);
		return (x);
	}

	return (0);
}
