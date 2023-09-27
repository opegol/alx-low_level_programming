#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h : given list_t struct
 * Return: the number of elements in linked list
 */
size_t listint_len(const listint_t *h)
{
	int i = 0;

	while (h != NULL)
	{

		i++;
		h = h->next;

	}
	return (i);
}
