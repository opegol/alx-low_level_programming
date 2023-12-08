#include <stdlib.h>
#include "lists.h"


/**
 * insert_dnodeint_at_index - adds a new node at a given position
 * @head : dlistint_t  list head
 * @idx : index of the list where the new node should be added
 * @n : dlistint_t list int element
 * Return: the address of the new node at index idx, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head,
	unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *cur;
	dlistint_t *temp;
	unsigned int i = 0;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if ((*head) == NULL && idx == 0)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	else
	{
		cur = *head;
		while (cur != NULL)
		{
			temp = cur;
			cur = cur->next;
			i++;
			if (i == idx)
			{
				new->prev = temp;
				temp->next = new;
				new->next = cur;
				return (new);
			}
		}
		if (i == (idx + 1))
		{
			new->prev = temp;
			temp->next = new;
			return (new);
		}
	}
	return (NULL);
}
