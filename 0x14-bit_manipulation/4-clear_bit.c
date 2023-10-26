#include <stdlib.h>
#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n : given number
 * @index : the index, starting from 0 of the bit to set
 * Return: 1 if it worked, or -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (8 * sizeof(mask) < index)
		return (-1);
	mask = 1 << index;
	*n = (*n) & (~mask);
	return (1);
}
