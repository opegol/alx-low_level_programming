/* 101-print_number.c */
#include "main.h"

/**
 * print_number - prints an integer
 * @n : integer to be printed
 */

void print_number(int n)
{
	unsigned int d = 1;
	unsigned int s = 1;
	unsigned int g;

	if (n < 0)
	{
		n = n * -1;
		s = 0;
	}
	while (n / d >= 10)
		d *= 10;

	if (s == 0)
		_putchar('-');

	while (d > 0)
	{
		g = (n / d);
		_putchar(g + '0');
		n = n - (g * d);
		d = d / 10;
	}
}
