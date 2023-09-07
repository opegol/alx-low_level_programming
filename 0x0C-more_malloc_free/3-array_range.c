#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min : minimum value of range
 * @max : maximum value of range
 * Return: pointer to newly created array
 */
int *array_range(int min, int max)
{
	int d, i;
	int *r;

	if (min > max)
		return (NULL);

	d = max - min + 1;
	r = malloc(sizeof(int) * d);
	if (r == NULL)
		return (NULL);

	for (i = 0; i < d; i++)
		r[i] = min + i;

	return (r);
}

