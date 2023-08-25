#include "main.h"

/**
 * _strncpy - copies a string
 * @dest : copy buffer
 * @src : string to be copied
 * @n: max number of bytes from src to copy
 * Return: Pointer to buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);
	for ( ; i < n; i++)
		*(dest + i) = '\0';

	return (dest);
}
