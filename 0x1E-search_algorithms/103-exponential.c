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
		return (m + left);
	else if (value < array[m])
	{
		/* r = m - 1; */
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
 * exponential_search - searches for a value in an array of
 *		integers using the Exponential search algorithm
 * @array :  pointer to the first element of the array to search in
 * @size :  number of elements in array
 * @value : the value to search for
 * Return: the first index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	int ret;
	size_t n_size, upper = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (upper < size && array[upper] < value)
	{
		printf("Value checked array[%li] = [%i]\n", upper, array[upper]);
		upper *= 2;
	}
	if (upper >= size)
	{
		printf("Value found between indexes [%li] and [%li]\n",
			upper / 2, upper - 1);

		n_size = upper - (upper / 2);
		ret = bslr(array + (int)(upper / 2), upper / 2, n_size, value);
	}
	else
	{
		printf("Value found between indexes [%li] and [%li]\n",
			upper / 2, upper);

		n_size = upper + 1 - (upper / 2);
		ret = bslr(array + (int)(upper / 2), upper / 2, n_size, value);
	}
	return (ret);
}
