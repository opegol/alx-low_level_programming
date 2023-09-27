#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of
 *		a listint_t linked list
 * @head : given listint_t list head
 * Return: sum of all the data (n) of linked list or 0 if empty
 */
int sum_listint(listint_t *head)
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
