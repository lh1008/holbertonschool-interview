#include "menger.h"

/**
 * menger - entry to menger
 * Desc: menger function that draws a 2D Menger Sponge
 * @level: int type level of the Menger to draw
 * Return: the menger drawn represented by '#'
 */
void menger(int level)
{
	int i = 0, x, j;
	char p[] = "###\n# #\n###";

	if (level < 0)
	{}
	if (level == 0)
		puts("#");
	else
		while (i < level)
		{
			if (level == 1)
			{
				printf("%s\n", p);
				break;
			}
			else if (level > 1)
				for (j = 0; j < level; j++)
					for (x = 0; x < level; x++)
					{
						printf("%s\n", p);
					}
			++i;
		}
}
