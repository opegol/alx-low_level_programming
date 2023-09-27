#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head : listint_t linked list head node
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp1;
	listint_t *temp2;

	if (*head == NULL)
		return (NULL);

	temp2 = (*head)->next;
	(*head)->next = NULL;

	while (temp2 != NULL)
	{
		temp1 = *head;
		*head = temp2;
		temp2 = (*head)->next;
		(*head)->next = temp1;
	}
	return (*head);
}
