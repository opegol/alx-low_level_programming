#include "main.h"

/**
 * puts2 - prints every other character of a string,
 *         starting with the first character, followed by a new line.
 * @str : pointer to string to be printed
 */
void puts2(char *str)
{
	int i = 0;
	int len = 0;
	char c = str[0];

	while (c != '\0')
	{
		++i;
		c = str[i];
		++len;
	}
	for (i = 0; i < len; i += 2)
		_putchar(str[i]);

	_putchar('\n');
}

