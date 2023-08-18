/* 5-more_numbers.c */

#include "main.h"

/**
 * more_numbers - prints the numbers, from 0 to 9, 10 times,
 *                 followed by a new line.
 */

void more_numbers(void)
{
	int c, n;

	for (c = 0; c < 10; c++)
	{

		for (n = 0; n <= 14; n++)
		{
			_putchar((n % 10) + '0');
			if (n >= 9 && n <= 13)
				_putchar(1 + '0');
		}

		_putchar('\n');
	}
}
