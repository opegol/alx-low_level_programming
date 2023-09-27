#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 *		and returns the head node’s data (n).
 * @head : given listint_t head
 * Return: the head node's data (n) and (0) lf linked list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int hn;

	temp = *head;

	if (*head == NULL)
	{
		free(temp);
		return (0);
	}
	else
	{
		hn = (*head)->n;
		*head = (*head)->next;
		free(temp);
		return (hn);
	}
}
