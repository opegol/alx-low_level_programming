#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s : pointer to string to be reversed
 */
void print_rev(char *s)
{
	int i = 0;
	int len = 0;
	char c = s[0];

	while (c != '\0')
	{
		++i;
		c = s[i];
		++len;
	}
	while (len >= 0)
	{
		_putchar(c);
		--len;
		c = s[len];
	}
	_putchar('\n');
}

