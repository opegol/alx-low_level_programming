/*
 * File: 2-print_alphabet_x10.c
 */
#include "main.h"

/**
 * print_alphabet_x10 -  to print out 10 times the alphabet,
 *                      in lowercase, followed by a new line.
 *
 * Return: Always (0)
 */
void print_alphabet_x10(void)
{
	int i;
	char c;

	for (i = 0; i < 10; i++)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);

		_putchar('\n');
	}
}


