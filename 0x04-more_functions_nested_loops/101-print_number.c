/* 101-print_number.c */
#include "main.h"

/**
 * print_number - prints an integer
 * @n : integer to be printed
 */

void print_number(int n)
{
	int d = 1;
	int s = 1;
	int g;

	if (n < 0)
	{
		n = n * -1;
		s = 0;
	}
	while (n / d >= 10)
		d *= 10;

	if (s == 0)
		_putchar(45);

	while (d > 0)
	{
		g = (n / d);
		_putchar(g + '0');
		n = n - (g * d);
		d = d / 10;
	}
}
