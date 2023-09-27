#include <stdlib.h>
#include "lists.h"


/**
 * insert_nodeint_at_index - adds a new node at a given position
 * @head : listint_t  list head
 * @idx : index of the list where the new node should be added
 * @n : listint_t list int element
 * Return: the address of the new node at index idx, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new;
	listint_t *cur;
	listint_t *prev;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if ((*head) == NULL && idx == 0)
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
			i++;
			if (i == idx)
			{
				prev->next = new;
				new->next = cur;
				return (new);
			}
		}
		if (i == (idx + 1))
		{
			prev->next = new;
			return (new);
		}
	}
	return (NULL);
}
