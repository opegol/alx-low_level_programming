#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h : given dlistint_t struct
 * Return: the number of elements in doubly_linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h != NULL)
	{

		i++;
		h = h->next;

	}
	return (i);
}
