#include <stdlib.h>
#include "lists.h"


/**
 * delete_nodeint_at_index - deletes the node at index @index
 *		of a listint_t linked list.
 * @head : listint_t  list head
 * @index : index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *cur;
	listint_t *prev;
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
		prev = cur;
		cur = cur->next;
		i++;
		if (i == index)
		{
			prev->next = cur->next;
			free(cur);
			return (1);
		}
	}
	return (-1);
}
