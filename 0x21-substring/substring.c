#include "substring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * find_substring -  Function that compare two values
 * @s: the string to scan
 * @words: first value
 * @nb_words: array of words to search in the string
 * @n: pointer to which to store the number of elements in the returned array
 *
 * Return: array storing each index in s at which a substring was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word = 0, i = 0, match = 0, count = 0, b = 0, k = 0, I = 0;
	int *word_used = NULL, *indices = NULL;

	*n = 0;
	if (words == NULL)
		return (NULL);
	b = (nb_words * string_length(words[0]));
	i = allocate(&word_used, nb_words, &indices, (string_length(s) / b) + 1);
	if (i == -1)
		return (NULL);
	for (i = 0; s[i]; i++)
	{
		I = i;
		for (reset(&word_used, nb_words), word = 0; word < nb_words && s[i]; word++)
		{
			match = string_compare(s, i, words[word]);
			while (match != 0)
			{
				word_used[word] = 1;
				i += match;
				if (s[i] == '\0')
					break;
				for (count = 0, word = 0; word < nb_words; word++)
				{
					if (word_used[word] != -1)
						count++;
					match = string_compare(s, i, words[word]);
					if (match != 0)
						break;
				}
				if (count == nb_words)
					indices[k++] = (i - b);
			}
		}
		if (i != I || s[i] == '\0')
			i--;
	}
	free(word_used);
	*n = k;
	return (indices);
}


/**
 * allocate - allocates memory for int arrays
 * @word_used: pointer to first memory to allocate
 * @nb_words: number of words to allocate space for
 * @indices: pointer to second memory to allocate
 * @max_index: maximum number of indices possible to allocate for
 *
 * Return: -1 if failed, 0 if successful
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
 * string_compare -Function that search_word words in string
 * @s1: string base
 * @i: the index
 * @s2: array
 *
 * Return: array with index
 */
int string_compare(char const *s1, unsigned int i, char const *s2)
{
	unsigned int b = 0;

	for (b = 0; s1[i] && s2[b]; i++, b++)
	{
		if (s1[i] != s2[b])
			return (0);
	}
	return (b);
}


/**
 * string_length - finds the length of a string
 * @str: the string to get length of
 *
 * Return: length of the string
 */
int string_length(char const *str)
{
	unsigned int c = 0;

	for (c = 0; str[c]; c++)
		continue;
	return (c);
}


/**
 * reset - sets all elements
 * @array: pointer to the array
 * @size: the size of the array
 *
 */
void reset(int **array, int size)
{
	int c = 0;

	for (c = 0; c < size; c++)
		(*array)[c] = -1;
}
