#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @head : head of given listint_t list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **head)
{
	listint_t *temp;
	int i = 0;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp < *head)
			break;
		free(temp);
		i++;
	}
	*head = NULL;
	return (sizeof(listint_t) * i);
}
