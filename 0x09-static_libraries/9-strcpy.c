#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including the
 *		terminating null byte (\0), to the buffer pointed to by dest.
 * @dest : buffer to copy string to
 * @src : pointer to string to copy
 *
 * Return: A pointer to @dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
