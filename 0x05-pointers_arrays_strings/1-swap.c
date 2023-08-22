#include "main.h"

/**
 * swap_int - a function that swaps the values of two integers.
 * @a : pointer to first integer
 * @b : ponter to second integer
 */
void swap_int(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
}

