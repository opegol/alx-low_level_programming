#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of
 *		a dlistint_t linked list
 * @head : given dlistint_t list head
 * Return: sum of all the data (n) of doubly linked list or 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum += (head->n);
		head = head->next;
	}
	return (sum);
}
