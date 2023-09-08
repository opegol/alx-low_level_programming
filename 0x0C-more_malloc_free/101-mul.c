#include "main.h"
#include <stdlib.h>

int slen(char *s);
char *new_array(int size);
char *parse_zeros(char *s);
int conv_to_digit(char d);
void single_mul(char *prod, char *mult, int digit, int zeros);
void sum(char *final_prod, char *next_prod, int next_len);
/**
 * slen - Gets length of a string.
 * @s: Given string
 * Return: length of string
 */
int slen(char *s)
{
	int  i = 0, len = 0;

	while (s[i] != '\0')
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * new_array - Creates array of chars
 * @size: size of the new array
 * Return: pointer to the array.
 */
char *new_array(int size)
{
	char *arr;
	int i;

	arr = malloc(sizeof(char) * size);

	if (arr == NULL)
		exit(98);

	for (i = 0; i < (size - 1); i++)
		arr[i] = 'a';

	arr[i] = '\0';

	return (arr);
}

/**
 * parse_zeros - parses string of zeros until it gets to a non-zero number.
 * @s : string to be parsed
 * Return: pointer to next non-zero element.
 */
char *parse_zeros(char *s)
{
	while (*s != '\0' && *s == '0')
		s++;

	return (s);
}

/**
 * conv_to_digit - Converts a char between 0 and 9 to an int
 * @d: char to be converted
 * Return: integer from char.
 */
int conv_to_digit(char d)
{
	int dgt = d - '0';

	if (dgt < 0 || dgt > 9)
	{
		_putchar('E');	
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	return (dgt);
}

/**
 * single_mul - Multiplies string of numbers by a single digit.
 * @prod: buffer to store result of multiplication
 * @mult: string of nums to multiply
 * @digit: single digit multiplier
 * @zeros: num of leading zeros.
 */
void single_mul(char *prod, char *mult, int digit, int zeros)
{
	int mult_len, num, tens = 0;

	mult_len = slen(mult) - 1;
	mult += mult_len;

	while (*prod != '\0')
	{
		*prod = 'a';
		prod++;
	}

	prod--;

	while (zeros--)
	{
		*prod = '0';
		prod--;
	}

	for (; mult_len >= 0; mult_len--, mult--, prod--)
	{
		if (*mult < '0' || *mult > '9')
		{
			_putchar('E');	
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			exit(98);
		}

		num = (*mult - '0') * digit;
		num += tens;
		*prod = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*prod = (tens % 10) + '0';
}

/**
 * sum - sums up numbers stored in two strings.
 * @final_prod: The buffer storing the running final product.
 * @next_prod: The next product to be added.
 * @next_len: The length of next_prod.
 */
void sum(char *final_prod, char *next_prod, int next_len)
{
	int num, tens = 0;

	while (*(final_prod + 1) != '\0')
		final_prod++;

	while (*(next_prod + 1))
		next_prod++;

	for (; *final_prod != 'a'; final_prod--)
	{
		num = (*final_prod - '0') + (*next_prod - '0');
		num += tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		next_prod--;
		next_len--;
	}

	for (; next_len >= 0 && *next_prod != 'a'; next_len--)
	{
		num = (*next_prod - '0');
		num += tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		final_prod--;
		next_prod--;
	}

	if (tens)
		*final_prod = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argc : number of arguments passed to program.
 * @argv : array of strings passed to program
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *final_prod, *next_prod;
	int size, i, digit, zeros = 0;

	if (argc != 3)
	{
		_putchar('E');	
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = parse_zeros(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = parse_zeros(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	size = slen(argv[1]) + slen(argv[2]);
	final_prod = new_array(size + 1);
	next_prod = new_array(size + 1);

	for (i = (slen(argv[2]) - 1); i >= 0; i--)
	{
		digit = conv_to_digit(*(argv[2] + i));
		single_mul(next_prod, argv[1], digit, zeros++);
		sum(final_prod, next_prod, size - 1);
	}
	for (i = 0; final_prod[i]; i++)
	{
		if (final_prod[i] != 'a')
			_putchar(final_prod[i]);
	}
	_putchar('\n');

	free(next_prod);
	free(final_prod);

	return (0);
}

