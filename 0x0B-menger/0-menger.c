#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 *
 */

void menger(int level)
{
	int i, j, result, x, y;
	char simbol;

	result = pow(3, level);

	for (i = 0; i < result; i++)
	{
		for (j = 0; j < result; j++)
		{
			simbol = '#';
			x = i;
			y = j;
			while (x > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					simbol = ' ';
				x /= 3;
				y /= 3;
			}
			printf("%c", simbol);
		}
		printf("\n");
	}
}
