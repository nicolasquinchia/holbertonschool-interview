#include "sandpiles.h"

/**
 * print_grid - print the arrays
 * @grid: arrays
 * Return: void function, nothing
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * sum_grids - computes the sum of two sandpiles
 * @grid1: sandpiles stable 1
 * @grid2: sandpiles stable 2
 * Return: void function, nothing
 */

static void sum_grids(int grid1[3][3], int grid2[3][3])
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
 * sandpile_checker - check if a value of the sandpile is greather than 3
 * @grid: sandpile
 * Return: integer
 */

int sandpile_checker(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * sandpile_processor - create a new grid to make the sandpile stable
 * @grid: sandpile
 * Return: void function, nothing
 */

static void sandpile_processor(int grid[3][3])
{
	int i, j;
	int aux_grid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			aux_grid[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] = grid[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					aux_grid[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					aux_grid[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					aux_grid[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					aux_grid[i][j + 1] += 1;
			}
		}
	}
	sum_grids(grid, aux_grid);
}

/**
 * sandpiles_sum - sandpiles sum calculations
 * @grid1: sandpiles stable 1
 * @grid2: sandpiles stable 2
 * Return: void function, nothing
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (sandpile_checker(grid1) == 1)
	{
		print_grid(grid1);
		sandpile_processor(grid1);
	}
}
