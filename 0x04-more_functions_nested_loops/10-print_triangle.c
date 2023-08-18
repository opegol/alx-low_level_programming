/* 10-print_triangle.c */

#include "main.h"

/**
 * print_triangle - draws a diagonal line on the terminal,
 *               followed by a new line.
 * @size : size of triangle
 */

void print_triangle(int size)
{
	int i, j, k;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 1; j < (size - i); j++)
				_putchar(32);

			for (k = 0; k < (i + 1); k++)
				_putchar(35);

			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
