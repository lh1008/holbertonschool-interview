#include "substring.h"

/**
 * find_substring - entry to function
 * Desc: find_subtring function that finds all the possible substrings
 * containing a list of words, within a given string
 * @s: pointer to string to scan
 * @words: double pointer to the array of words all subtrings
 * must be a concatenation arrangement of
 * @nb_words: int type, number of elements in the array words
 * @n: int type, holds the address at which to store the number
 * of elements in the returned array
 * Return: allocated array or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int size_word, s_len, j, i = 0, k;
	int *elements, *found;

	if (!s)
		return (NULL);

	size_word = strlen(words[0]);
	*n = 0;
	s_len = strlen(s);
	found = malloc(nb_words * sizeof(int));
	elements = malloc(s_len * sizeof(int));
	while (i <= s_len - nb_words * size_word)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 &&
					strncmp(s + i + j * size_word,
						words[k], size_word) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			elements[(*n)++] = i;
		i++;
	}
	free(found);
	return (elements);
}
