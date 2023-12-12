#include "main.h"

/**
 * _strcat - This function appends the src string to the dest string,
 *		overwriting the terminating null byte (\0) at the en
 *		d of dest, and then adds a terminating null byte
 * @dest : base string
 * @src : string to append
 * Return: Pointer to concatenated string @dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int len = 0;
	int j;

	while (*(dest + i))
	{
		i++;
		++len;
	}

	for (j = 0; *(src + j); j++)
		*(dest + len + j) = *(src + j);

	return (dest);
}
