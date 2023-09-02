#include <stdio.h>

/**
 * main - program that multiplies two numbers..
 * @argc : number of command line arguments
 * @argv : array of strings passed at the command line
 * Return: 1 if error, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int m = 1, i = 0, j = 0, k = 0, s = 1, len = 0;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	while (argv[1][i] != '\0')
		len++, i++;
	i = 0;
	while (i < len)
	{
		if (argv[1][len - i - 1] == '-')
		{
			s *= -1, i++;
			continue;
		}
		j += m * ((int)argv[1][len - i - 1] - '0'), i++, m *= 10;
	}
	i = 0, m = 1, len = 0;

	while (argv[2][i] != '\0')
	{
		len++, i++;
	}
	i = 0;
	while (i < len)
	{
		if (argv[2][len - i - 1] == '-')
		{
			s *= -1, i++;
			continue;
		}
		k += m * (argv[2][len - i - 1] - '0'), i++, m *= 10;
	}

	printf("%i\n", j * k * s);

	return (0);
}
