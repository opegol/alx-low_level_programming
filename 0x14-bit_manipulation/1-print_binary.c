#include <stdlib.h>
#include "main.h"

/**
 * print_binary - binary representation of a number.
 * @n : num which binary is to be printed
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;

	if (n > 1)
		print_binary(n >> 1);
	n = n & mask;
	_putchar(n + '0');

}
