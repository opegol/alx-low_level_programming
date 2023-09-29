#include <stdlib.h>
#include "main.h"

/**
 * print_binary - binary representation of a number.
 * @n : num which binary is to be printed
 */
void print_binary(unsigned long int n)
{
	int j, t = 0;
	unsigned long int i;
	unsigned long int num;
	unsigned int mask;

	if (n == 0)
	{
		_putchar(n + '0');
		return;
	}


	num = (8 * sizeof(int));
	mask = 1 << (num - 1);

	for (i = 0; i < num; i++)
	{
		j = (n & mask) ? 1 : 0;

		if (j == 0 && t == 0)
		{
			mask >>= 1;
			continue;
		}
		if (j == 1 && t == 0)
			t = 1;
		_putchar(j + '0');
		mask >>= 1;
	}
}
