#include "menger.h"

/**
 * menger - entry to menger
 * Desc: menger function that draws a 2D Menger Sponge
 * @level: int type level of the Menger to draw
 * Return: the menger drawn represented by '#'
 */
void menger(int level)
{
	int x, y, z, subx, suby;

	if (level < 0)
	{}
	else if (level >= 0)
		for (y = 0; y < pow(3, level); y++)
		{
			for (x = 0; x < pow(3, level); x++)
			{
				subx = x;
				suby = y;
				z = 0;
				while (subx && suby)
				{
					if (subx % 3 == 1 && suby % 3 == 1)
					{
						printf(" ");
						z = 1;
						break;
					}
					subx = subx / 3;
					suby = suby / 3;
				}
				if (z == 0)
					printf("#");
			}
			printf("\n");
		}
}
