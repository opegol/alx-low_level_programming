#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that adds positive numbers.
 * @argc : number of command line arguments
 * @argv : array of strings passed at the command line
 * Return: 1 if error, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int n, i, sum = 0;

	for (n = 1; n < argc; n++)
	{
		for (i = 0; argv[n][i]; i++)
		{
			if (argv[n][i] < '0' || argv[n][i] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[n]);
	}

	printf("%d\n", sum);

	return (0);
}

