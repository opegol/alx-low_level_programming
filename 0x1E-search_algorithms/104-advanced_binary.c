#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * bslr - searches for a value, using left & right parameters, in an
 *		array of integers using the Binary search algorithm
 * @array :  pointer to the first element of the array to search in
 * @left :  beginning of array
 * @size :  number of elements in array
 * @value : the value to search for
 * Return: the first index where value is located
 */
int bslr(int *array, int left, size_t size, int value)
{
	size_t i, s;
	int l, r, m, ret, offset;

	if (size == 0)
		return (-1);

	l = 0;
	r = size - 1;

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);
	m = (l + r) / 2;
	if (array[m] == value)
	{
		if (m > 0 && array[m - 1] == array[m])
		{
			s = (size_t)m + 1;
			offset = left;
			m = (bslr(array, offset, s, value));
		}
		return (m + left);
	}
	else if (value < array[m])
	{
		s = (size_t)m;
		offset = left;
		ret = bslr(array, offset, s, value);
	}
	else
	{
		s = (size_t)(r - m);
		offset = m + 1 + left;
		ret = bslr((array + (m + 1)), offset, s, value);
	}

	return (ret);
}

/**
 * advanced_binary - searches for a value in an array of integers using
 *	the Binary search algorithm.
 * @array :  pointer to the first element of the array to search in
 * @size :  number of elements in array
 * @value : the value to search for
 * Return: the first index where value is located (even
 *	if this value appears more than once in the array)
 */
int advanced_binary(int *array, size_t size, int value)
{
	int ret;

	if (array == NULL)
		return (-1);

	ret = bslr(array, 0, size, value);

	return (ret);
}
