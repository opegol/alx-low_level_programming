/* 6-print_line.c */

#include "main.h"

/**
 * print_line - draws a straight line in the terminal,
 *               followed by a new line.
 * @n : number of times the character '_' should be printed
 */

void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
			_putchar(95);
	}
	_putchar('\n');
}
