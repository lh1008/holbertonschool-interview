#include "holberton.h"


int _strlen(char *s)
{
	int count = 0;

	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

int long_number(char first_argv[], char second_argv[])
{
	int x = _strlen(first_argv), y = _strlen(second_argv), a = 0;

	printf("%d\n", x);
	printf("%d\n", y);

	int arr[x + y];

	while (a != x)
	{
		arr[a] = first_argv[a] - '0';
		printf("%d", arr[a]);
		a++;
	}
	puts("");
	a = 0;
	while (a != y)
	{
		arr[a] = second_argv[a] - '0';
		printf("%d", arr[a]);
		a++;
	}
	puts("");
}

/**
 * main - entry to main
 * Desc: main function that passes base
 * base 10 numbers to be multiplied
 * @argc: number of arguments
 * @argv: arguments
 * Return: multiplied numbers
 * https://www.geeksforgeeks.org/how-to-store-a-very-large-number-of-more-than-100-digits-in-c/
 */
int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	{

		int arr = long_number(argv[1], argv[2]);
	}
	return (1);
}
