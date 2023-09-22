#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h : given list_t struct
 * Return: the number of elements in linked list
 */
size_t list_len(const list_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		/*printf("h: %p\n", (void *)h);*/
		/*printf("h->next: %p\n", (void *)h->next);*/
		/*printf("&h: %p\n", (void *)&(h->next));*/
		i++;
		h = h->next;

	}
	return (i);
}
