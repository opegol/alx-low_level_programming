#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb : number of memory blocks of size bytes each
 * @size : byte size of each element
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *r;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	r = malloc(nmemb * size);
	if (r == NULL)
		return (NULL);
	for (i = 0; i < nmemb; i += size)
		*((char *)r + (i * size)) = 0;
	return (r);
}
