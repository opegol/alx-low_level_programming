#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of a number
 *
 * Return: ALways 0.
 */

int main(void)
{
	int div = 2, max_p = 2;
	long int n = 612852475143;

	while (n > 1)
	{
		if (n % div == 0)
		{
			/* printf("%d ", div); */
			if (div > max_p)
				max_p = div;
			n /= div;
		}
		else
			div++;
	}
	printf("%d", max_p);
	printf("\n");
	return (0);
}
