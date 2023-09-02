#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that prints the minimum number of coins
 *	to make change for an amount of money.
 * @argc : number of command line arguments
 * @argv : array of strings passed at the command line
 * Return: 1 if error, 0 otherwise
 */
int main(int argc, char *argv[])
{
	int n_coins = 0;
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	while (cents > 0)
	{
		n_coins++;
		if ((cents - 25) >= 0)
		{
			cents -= 25;
			continue;
		}
		if ((cents - 10) >= 0)
		{
			cents -= 10;
			continue;
		}
		if ((cents - 5) >= 0)
		{
			cents -= 5;
			continue;
		}
		if ((cents - 2) >= 0)
		{
			cents -= 2;
			continue;
		}
		cents--;
	}

	printf("%d\n", n_coins);

	return (0);
}

