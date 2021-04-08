#include "slide_line.h"

/**
 * swap_integers - entry to swap_integers
 * Desc: swap_integers function to switch integers
 * @n: pointer to an int
 * @n2: pointer to an int
 */
void swap_integers(int *n, int *n2)
{
	int temp = *n;

	*n = *n2;
	*n2 = temp;
}

/**
 * slide_left - endtry to slide_left
 * Desc: slide_left function that shifts nonzero numbers to the left
 * @line: array of integers.
 * @size: size of the array
 */
void slide_left(int *line, size_t size)
{
	size_t i, pos = 0;

	for (i = 0; i < size && pos < size; i++)
	{
		while (line[pos] == 0 && pos < size && pos + 1 < size)
			pos++;
		if (!line[i])
			swap_integers(&line[pos], &line[i]);
		pos++;
	}
}

/**
 * slide_right - entry to slide_right
 * Desc: slide_right function to shift nonzero numbers in an
 * array to the right
 * @line: array of integers.
 * @size: size of the array
 */
void slide_right(int *line, size_t size)
{
	size_t i;
	size_t pos = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) pos >= 0; i--)
	{
		while (line[pos] == 0 && (int) pos > 0)
			pos--;
		if (!line[i])
			swap_integers(&line[pos], &line[i]);
		pos--;
	}
}

/**
 * slide_line - entry to slide_line
 * Desc: slide_line function that slides and merges an array of integers
 * @line: pointer int type that points to an array of integers
 * @size: size_t size type object
 * @direction: int type direction to move SLIDE_LEFT - SLIDE_RIGHT
 * Return: return 1 in success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
		return (1);
	}
	return (0);
}
