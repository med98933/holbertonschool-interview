#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - finds all the possible substrings
 * @s: the given string
 * @words: the words that will form the substring
 * @nb_words:  number of words
 * @n: number of indices found
 * Return: an allocated array,
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word = 0, i = 0, x = 0, c = 0, y = 0, z = 0, I = 0;
	int *w = NULL, *in = NULL;

	*n = 0;
	if (words == NULL)
		return (NULL);
	y = (nb_words * string_length(words[0]));
	i = allocate(&w, nb_words, &in, (string_length(s) / y) + 1);
	if (i == -1)
		return (NULL);
	for (i = 0; s[i]; i++)
	{
		I = i;
		for (reset(&w, nb_words), word = 0; word < nb_words && s[i]; word++)
		{
			x = string_compare(s, i, words[word]);
			while (x != 0)
			{
				w[word] = 1;
				i += x;
				if (s[i] == '\0')
					break;
				for (c = 0, word = 0; word < nb_words; word++)
				{
					if (w[word] != -1)
						c++;
					x = string_compare(s, i, words[word]);
					if (x != 0)
						break;
				}
				if (c == nb_words)
					in[z++] = (i - y);
			}
		}
		if (i != I || s[i] == '\0')
			i--;
	}
	free(w);
	*n = z;
	return (in);
}

/**
 * allocate - allocates memory for int arrays
 * @word_used: word used
 * @nb_words:  number of words
 * @indices: indice
 * @max_index: maximum number of indices
 *
 * Return: void
 */
int allocate(int **word_used, int nb_words, int **indices, int max_index)
{
	*word_used = malloc(sizeof(int) * nb_words);
	if (*word_used == NULL)
		return (-1);
	reset(word_used, nb_words);
	*indices = malloc(sizeof(int) * max_index);
	if (*indices == NULL)
	{
		free(word_used);
		return (-1);
	}
	reset(indices, max_index);
	return (0);
}

/**
 * string_compare - checks if the substring word
 * @s1: the string
 * @i: the substring
 * @s2: the second string to compare, the shorter of the strings
 *
 * Return: length of the shorter word contained or 0 if no match
 */
int string_compare(char const *s1, unsigned int i, char const *s2)
{
	unsigned int y = 0;

	for (y = 0; s1[i] && s2[y]; i++, y++)
	{
		if (s1[i] != s2[y])
			return (0);
	}
	return (y);
}

/**
 * string_length - finds the length of a string
 * @str: the string to get length of
 *
 * Return: length of the string
 */
int string_length(char const *str)
{
	unsigned int temp = 0;

	for (temp = 0; str[temp]; temp++)
		continue;
	return (temp);
}

/**
 * reset - sets all elements of array to -1
 * @array: pointer to the array
 * @size: the size of the array
 */
void reset(int **array, int size)
{
	int temp = 0;

	for (temp = 0; temp < size; temp++)
		(*array)[temp] = -1;
}
