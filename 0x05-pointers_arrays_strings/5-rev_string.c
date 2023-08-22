#include "main.h"

/**
 * rev_string - reverses a string
 * @s : pointer to string to be reversed
 */
void rev_string(char *s)
{
	int i = 0;
	int len = 0;
	char c = s[0];
	char tmp;

	while (c != '\0')
	{
		++i;
		c = s[i];
		++len;
	}
	for (i = len - 1; i >= len / 2; i--)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}
