#include <stdlib.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n : given number
 * @index : the index, starting from 0 of the bit to get
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (8 * sizeof(mask) < index)
		return (-1);
	mask = 1 << index;
	return ((n & mask) ? 1 : 0);
}
