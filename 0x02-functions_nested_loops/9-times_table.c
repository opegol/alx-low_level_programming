/*
 * File: 9-times_table.c
 */
#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 */
void times_table(void)
{
	int n, times, prod;

	for (n = 0; n <= 9; n++)
	{
		_putchar('0');

		for (times = 1; times <= 9; times++)
		{
			_putchar(',');
			_putchar(' ');

			prod = n * times;

			if (prod <= 9)
				_putchar(' ');
			else
				_putchar((prod / 10) + '0');

			_putchar((prod % 10) + '0');

		}

		_putchar('\n');

	}
}
