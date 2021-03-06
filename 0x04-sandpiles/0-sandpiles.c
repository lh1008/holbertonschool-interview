#include "sandpiles.h"

/**
 * sum_sandpiles - sum 2 sandpiles
 * Desc: sum_sandpiles function to sum grids
 * @grid1: int type first matrix
 * @grid2: int type second matrix
 * Return: void function sum of two grids
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_add(grid1, grid2);
	while (check_grid(grid1) == '\0')
	{
		print_(grid1);
		change_value(grid1);
	}
}

/**
 * grid_add - entry to adding grids
 * Desc: grid_add function to add two grids
 * @grid1: int type first matrix
 * @grid2: int type second matrix
 * Return: add matrix
 */
void grid_add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * check_grid - entry to check a grid
 * Desc: check_grid function if grid is a matrix
 * @grid: int type matrix
 * Return: returns 1 if is okay or 0 if not
 */
int check_grid(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * print_grid - entry to print a grid
 * Desc: print_grid function that prints
 * @grid: matrix
 * Return: returns a printed grid
 */
void print_(int grid[3][3])
{
	int i = 0;
	int j = 0;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * change_value - entry to change a grid value
 * Desc: change_value function to change grid's value
 * @grid1: matrix
 * Return: returns new value to grid
 */
void change_value(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int gridx[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			gridx[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1) >= 0 && (i - 1) < 3)
					gridx[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					gridx[i][j - 1] += 1;
				if ((i + 1) >= 0 && (i + 1) < 3)
					gridx[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					gridx[i][j + 1] += 1;
			}
		}
	}
	grid_add(grid1, gridx);
}
