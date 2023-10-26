#include <stdlib.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits needed to be flipped
 *		to get from one number to another.
 * @n : starting number
 * @m : number to get to
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask;
	int count = 0;


	mask = 1;

	while (n)
	{
		if ((n & mask) != (m & mask))
			count++;
		n >>= 1;
		m >>= 1;
	}
	return (count);
}
