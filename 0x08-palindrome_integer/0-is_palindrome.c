#include "palindrome.h"

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome.
 * @n: unsigned integer to check if is palindrome
 * Return: 1 if is palindome otherwise 0
 */

int is_palindrome(unsigned long n)
{
	char aux[50];
	int index;
	int total;

	for (index = 0; n; index++)
	{
		aux[index] = n % 10;
		n = n / 10;
	}
	aux[index] = '\0';
	total = index;
	for (index = 0; index < (total / 2); index++)
	{
		if (aux[index] != aux[total - 1 - index])
		{
			return (0);
		}
	}
	return (1);
}
