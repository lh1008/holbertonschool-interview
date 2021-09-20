#include "my_regex.h"

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
	regex_t regex;
	int return_value;

	return_value = regcomp(&regex, str, 0);
	return_value = regexec(&regex, pattern, 0, NULL, 0);

	if (return_value == 0)
		return (1);
	else
		return (0);
}
