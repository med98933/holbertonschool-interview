#ifndef SUBSTRING_h
#define SUBSTRING_h

#include <stdlib.h>
#include <string.h>


int *find_substring(char const *s, char const **words, int nb_words, int *n);
int allocate(int **word_used, int nb_words, int **indices, int max_index);
int string_compare(char const *s1, unsigned int i, char const *s2);
int string_length(char const *str);
void reset(int **array, int size);
#endif
