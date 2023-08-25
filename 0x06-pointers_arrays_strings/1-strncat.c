#include "main.h"

/**
 * _strncat - concatenates two strings.
 * @dest : base string
 * @src : string to append
 * @n: max number of bytes from src to append
 * Return: Pointer to concatenated string @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int len = 0;
	int j;

	while (*(dest + i))
	{
		i++;
		++len;
	}

	for (j = 0; j < n ; j++)
	{
		if (*(src + j) == '\0')
			break;
		*(dest + len + j) = *(src + j);
	}
	return (dest);
}
