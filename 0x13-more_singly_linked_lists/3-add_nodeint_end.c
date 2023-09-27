#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head : old listint_t head
 * @n : listint_t list int element
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *cur;
	listint_t *prev;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if ((*head) == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		cur = *head;
		while (cur != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
	}
	prev->next = new;
	return (new);
}
