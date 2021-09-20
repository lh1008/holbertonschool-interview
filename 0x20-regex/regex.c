#include "regex.h"

/**
 * regex_match - entry to function
 * Desc: regex_match function that checks whether a
 * diven pattern matches a given string
 * @str: pointer char for string
 * @pattern: pointer char for pattern to search
 * Return: 1 if the pattern matches, 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	int pos = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			pos = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || pos);
	}
	return (0);
}
