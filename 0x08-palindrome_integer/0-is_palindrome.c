#include "palindrome.h"

/**
 * is_palindrome - entry to is palindrome
 * Desc: is_palindrome function to check if a number is palindrome
 * @n: unsigned long type integer
 * Return: 1 if n is palindrome and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long i, reverse = 0, remainder;

	i = n;

	while (n != 0)
	{
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n /= 10;
	}

	if (i  == reverse )
		return (1);
	else
		return (0);
}
