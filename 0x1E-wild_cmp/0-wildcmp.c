#include "holberton.h"

/**
 * wildcmp - entry to function
 * Desc: wildcmp function that compares two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: 1 if the strings are identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	int flag = 0;

	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if ((*s1 == '\0' && *s2 != '\0')
			 || (*s1 != '\0' && *s2 == '\0')
			 || *s1 != *s2)
		{
			flag = 1;
			return (0);
		}
	}

	if (flag == 0)
		return (1);

	return (0);
}
