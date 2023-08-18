/* 7-print_diagonal.c */

#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal,
 *               followed by a new line.
 * @n : number of times the character '\' should be printed
 */

void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
				_putchar(32);

			_putchar(92);
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
