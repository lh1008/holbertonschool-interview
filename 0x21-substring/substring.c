#include "substring.c"

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
	int size_word, size_words, index_store = 0;

	size_word = strlen(*words);

	size_words = size_word * nb_words;

	if (size_words > strlen(s))
		return (index_store);

}
