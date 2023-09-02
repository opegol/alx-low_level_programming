#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s : string whose length is to be returned
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;
	int i = 0;
	char c = s[0];

	while (c != '\0')
	{
		++i;
		c = s[i];
		++len;
	}
	return (len);
}
