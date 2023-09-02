#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * @s : memory location pointed to
 * @b : constant byte to fill the first n bytes of memory with
 * @n : number of bytes
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);

}
