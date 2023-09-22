#include <stdio.h>
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

	if (h != NULL)
	{
		if (h->str)
			i++;
		if (h->len)
			i++;
		/*printf("h: %p\n", (void *)h);*/
		/*printf("h->next: %p\n", (void *)h->next);*/
		/*printf("&h: %p\n", (void *)&(h->next));*/

	/*	h = h->next;*/

	}
	return (i);
}
