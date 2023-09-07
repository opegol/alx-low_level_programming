#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr : pointer to memory previously allocated
 * @old_size : is the size, in bytes, of the allocated space for ptr
 * @new_size : is the new size, in bytes of the new memory block
 * Return: pointer to new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *r;
	char *p_copy, *tmp;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		r = malloc(new_size);

		if (r == NULL)
			return (NULL);

		return (r);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p_copy = ptr;
	r = malloc(sizeof(*p_copy) * new_size);

	if (r == NULL)
	{
		free(ptr);
		return (NULL);
	}

	tmp = r;

	for (i = 0; i < old_size && i < new_size; i++)
		tmp[i] = *p_copy++;

	free(ptr);
	return (r);
}


