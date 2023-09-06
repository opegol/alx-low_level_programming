#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes
 *		it with a specific char.
 * @size : size of array
 * @c : char to initialize array with
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	arr = malloc((sizeof(char)) * size);

	if (arr != NULL && size != 0)
	{
		for (i = 0; i < size; i++)
			arr[i] = c;
	}
	else
		return (NULL);

	return (arr);

}
