#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head : given listint_t list head node
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i = 0;
	const listint_t *prev;

	if (head == NULL)
		exit(98);

	prev = head;

	while (head != NULL)
	{
		if (prev < head)
		{
			printf("-> [%p] %i\n", (void *)head, head->n);
			return (i);
		}
		prev = head;
		i++;
		printf("[%p] %i\n", (void *)head, head->n);
		head = head->next;
	}
	return (i);
}
