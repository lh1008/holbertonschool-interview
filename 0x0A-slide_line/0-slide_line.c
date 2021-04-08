#include "slide_line.h"

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
	size_t i, sum = 0;
	(void)direction;

	for (i = 0; i < size; ++i)
	{
		printf("%d\n", line[i]);
		if ((line[i] % 2) == 0)
			sum += line[i];
	}
	printf("%ld\n", sum);
	return (sum);
}
