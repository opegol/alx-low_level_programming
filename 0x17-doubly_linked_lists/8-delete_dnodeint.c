#include <stdlib.h>
#include "lists.h"


/**
 * delete_dnodeint_at_index - deletes the node at index @index
 *		of a dlistint_t linked list.
 * @head : dlistint_t  list head
 * @index : index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur;
	dlistint_t *temp;
	unsigned int i = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	cur = *head;
	if (cur != NULL && index == 0)
	{
		*head = (*head)->next;
		free(cur);
		return (1);
	}
	while (cur != NULL && (i <= index))
	{
		temp = cur;
		cur = cur->next;
		i++;
		if (i == index)
		{
			temp->next = cur->next;
			free(cur);
			return (1);
		}
	}
	return (-1);
}
