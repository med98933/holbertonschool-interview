#include "regex.h"
#include <stdio.h>
#include <string.h>



/**
 * regex_match - recursively checks whether a given pattern
 *
 * matches a given string
 *
 * @str: the string
 *
 * @pattern: Pattern to be compared
 *
 * Return: 1 in match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
		int c1 = 0, c2 = 0;

	if (!str || !pattern)
		return (0);

	c1 = *str && (*str == *pattern || *pattern == '.');
	c2 = *(pattern + 1) == '*';

	if (!*str && !c2)
		return (*pattern ? 0 : 1);

	if (c1 && c2)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (c1 && !c2)
		return (regex_match(str + 1, pattern + 1));
	else if (c2)
		return (regex_match(str, pattern + 2));

	return (0);
}
