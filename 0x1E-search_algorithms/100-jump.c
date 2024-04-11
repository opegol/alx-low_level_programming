#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an
 *		array of integers using the Jump search algorithm
 * @array :  pointer to the first element of the array to search in
 * @size :  number of elements in array
 * @value : the value to search for
 * Return: the first index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	size_t a, b, sqr, min, i;

	if (array == NULL)
		return (-1);

	a = 0;
	min = 0;
	sqr = (int)sqrt(size);
	b = 0;

	while (array[min] < value)
	{
		printf("Value checked array[%li] = [%d]\n", b, array[b]);
		a = b;
		b += sqr;
		if (a >= size - 1)
			break;
		min = (b < size) ? b : size;
	}
	printf("Value found between indexes [%li] and [%li]\n", a, b);

	for (i = a; i <= min; i++)
	{
		printf("Value checked array[%li] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
