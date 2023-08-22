#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout.
 *
 * @str : pointer to string to be printed to stdout
 */
void _puts(char *str)
{
	char c = str[0];
	int i = 0;

	while (c != '\0')
	{
		_putchar(c);
		++i;
		c = str[i];
	}
	_putchar('\n');
}

