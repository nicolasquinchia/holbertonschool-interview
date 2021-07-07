#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to array
 * @size: size of array
 * @direction: direction to slide
 * Return: 1 on success 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	else if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	else if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	else
		return (0);
}

/**
 * slide_left - slides and merges an array of integers
 * @line: pointer to array
 * @size: size of array
 * Return: 1 on success 0 otherwise
 */
int slide_left(int *line, size_t size)
{
	int i, j;
	int ssize = (int)size;

	for (i = 0; i <= ssize - 1; i++)
	{
		if (line[i] != 0 && i != ssize - 1)
		{
			for (j = i + 1; j <= ssize - 1; j++)
			{
				if (line[j] == line[i])
				{
					line[i] += line[j];
					line[j] = 0;
					break;
				}
			}
		}

		if (line[i] != 0 && i != 0)
		{
			for (j = 0; j < i; j++)
			{
				if (line[j] == 0)
				{
					line[j] = line[i];
					line[i] = 0;
					break;
				}
			}
		}
	}
	return (1);
}

/**
 * slide_right - slides and merges an array of integers
 * @line: pointer to array
 * @size: size of array
 * Return: 1 on success 0 otherwise
 */
int slide_right(int *line, size_t size)
{
	int i, j;
	int ssize = (int)size;

	for (i = ssize - 1; i >= 0; i--)
	{
		if (line[i] != 0 && i != 0)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (line[j] == line[i])
				{
					line[i] += line[j];
					line[j] = 0;
					break;
				}
			}
		}

		if (line[i] != 0 && i != ssize - 1)
		{
			for (j = ssize - 1; j > i; j--)
			{
				if (line[j] == 0)
				{
					line[j] = line[i];
					line[i] = 0;
					break;
				}
			}
		}
	}
	return (1);
}
