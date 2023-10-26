#include <stdlib.h>
#include <stdio.h>
#include "main.h"

unsigned int slen(const char *s);
unsigned int binary_to_uint(const char *b);

/**
 * slen - returns length of string
 * @s : given string
 * Return: length of string
 */
unsigned int slen(const char *s)
{
	unsigned int len = 0;

	while (*s++)
		len++;
	return (len);
}
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b : points to a string of 0 and 1 chars
 * Return: the converted number, or 0 if
 *	there is one or more chars in the string b that is not 0 or 1
 *	b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int len;
	unsigned int sum = 0;
	unsigned int m2 = 1;

	if (b == NULL)
		return (0);

	len = slen(b);

	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] < 48 || b[i] > 49)
			return (0);
		if (b[i] == 49)
			sum += m2;
		m2 = m2 << 1;
	}
	return (sum);
}
