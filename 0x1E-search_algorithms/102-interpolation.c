#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * isprb - searches for a value in an array of integers using interpolation
 *		probes
 * @array :  pointer to the first element of the array to search in
 * @low : beginning of array
 * @high : end of array
 * @value : the value to search for
 * Return: the first index where value is located
 */
int isprb(int *array, int low, int high, int value)
{
	size_t pos = low
		+ (((double)(high - low)
		/ (array[high] - array[low]))
		* (value - array[low]));

	if (low <= high && value >= array[low] && value <= array[high])
	{
		if (array[pos] == value)
		{
			printf("Value checked array[%li] = [%i]\n", pos, array[pos]);
			return (pos);
		}
		if (array[pos] < value)
		{
			printf("Value checked array[%li] = [%i]\n", pos, array[pos]);
			return (isprb(array, pos + 1, high, value));
		}
		if (array[pos] > value)
		{
			printf("Value checked array[%li] = [%i]\n", pos, array[pos]);
			return (isprb(array, low, pos - 1, value));
		}
	}
	printf("Value checked array[%li] is out of range\n", pos);
	return (-1);
}


/**
 * interpolation_search - searches for a value in an
 *		array of integers using the Interpolation search algorithm
 * @array :  pointer to the first element of the array to search in
 * @size :  number of elements in array
 * @value : the value to search for
 * Return: the first index where value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	int ret;

	if (array == NULL)
		return (-1);

	/*if (value < array[0] || value > array[size - 1])*/
	/*printf("Value checked array[%i] is out of range\n", value);*/

	ret = isprb(array, 0, size - 1, value);

	return (ret);
}
