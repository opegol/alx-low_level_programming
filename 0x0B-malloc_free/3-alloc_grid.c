#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width : number of columns in array
 * @height : number of rows of array
 * Return: pointer to 2 dimensional array
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **arr;

	if (width == 0 || height == 0)
		return (NULL);
	arr = malloc(sizeof(int *) * height);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		arr[i] = malloc(sizeof(int) * width);
		if (arr[i] == NULL)
			return (NULL);
		for (j = 0; j < width; j++)
			*(arr[i] + j) = 0;
	}
	return (arr);
}
