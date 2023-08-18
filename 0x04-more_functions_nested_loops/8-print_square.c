/* 8-print_square.c */

#include "main.h"

/**
 * print_square - draws a diagonprints a square,
 *               followed by a new line.
 * @size : size of the square
 */

void print_square(int size)
{
	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				_putchar(35);

			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
