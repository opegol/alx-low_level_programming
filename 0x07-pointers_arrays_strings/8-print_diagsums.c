#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a
 *		square matrix of integers.
 * @a : square matrix
 * @size : size of matrix
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	int sum_lr = 0, sum_rl = 0;

	for (i = 0; i < size; i++)
	{
		sum_lr += a[i];
		a += size;
	}

	a -= size;

	for (j = 0; j < size; j++)
	{
		sum_rl += a[j];
		a -= size;
	}
	printf("%i, %i\n", sum_lr, sum_rl);
}
