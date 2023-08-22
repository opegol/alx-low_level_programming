#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line.
 * @str : pointer to string to be printed
 */
void puts_half(char *str)
{
	int i = 0, n;
	int len = 0;
	char c = str[0];

	while (c != '\0')
	{
		++i;
		c = str[i];
		++len;
	}
	if ((len % 2) == 0)
		n = len / 2;
	else
		n = (len - 1) / 2;

	for (i = n; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

