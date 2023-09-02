#include <stdio.h>

/**
 * main - program that prints it the number of arguments passed to it
 * @argc : number of command line arguments
 * @argv : array of strings passed at the command line
 * Return: Always 0
 */
int main(int argc, char *argv[]  __attribute__ ((unused)))
{
	printf("%i\n", argc - 1);

	return (0);
}
