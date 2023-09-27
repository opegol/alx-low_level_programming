#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head : given listint_t list head node
 * Return: The address of the node where the loop starts,
 *	or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *temp1;
	/*listint_t *temp2;*/

	if (head == NULL)
		return (NULL);

	temp1 = head;

	while (temp1 != NULL)
	{
		head = temp1->next;
		while (head != NULL)
		{
			if (head == temp1)
			{
				printf("temp1: %d\n", temp1->n);
				printf("head->next: %d\n", head->next->n);
				return (head);
			}
			if (head->next == NULL)
				break;
			head = head->next;

			printf("temp1: %d\n", temp1->n);
			printf("head: %d\n", head->n);
		}
		temp1 = temp1->next;
	}
	return (NULL);
}
