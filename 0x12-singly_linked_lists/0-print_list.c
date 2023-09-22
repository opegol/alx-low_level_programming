#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list.
 * @h : given list_t struct
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	int i = 0;
	/*const list_t *tmp = h;*/

	while (h != NULL)
	{
		i++;
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%i] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}
