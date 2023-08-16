/* 7-print_last_digit.c */

#include "main.h"

/**
 * print_last_digit - computes the absolute value of an integer
 * @n : number whose last digit is to be printed
 *
 * Return: last digit of @n
 */

int print_last_digit(int n)
{
	int ld = n % 10;

	if (n < 0)
		ld = ld * (-1);

	_putchar(ld + '0');

	return (ld);

}
