#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int loopcount(const listint_t *head);
listint_t *find_listint_loop(listint_t *head);

/**
 * loopcount - counts number of nodes in loop
 * @head : given listint_t list head node
 * Return: count of loop nodes or 0 if no loop
 */
int loopcount(listint_t *head)
{
	listint_t *s;
	listint_t *f;
	listint_t *tmp;
	int count = 1;

	s = head;
	f = head;

	while (s && f && f->next)
	{
		s = s->next;
		f = (f->next)->next;
		if (s == f)
		{
			tmp = s;
			while (tmp->next != s)
			{
				count++;
				tmp = tmp->next;
			}
			return (count);
		}
	}
	return (0);
}

/**
 * find_listint_loop - finds the loop listint_t linked list.
 * @head : given listint_t list head node
 * Return: address of the node where the loop starts,
 *	or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head);
{
	size_t i = 0;
	const listint_t *tmp1, *tmp2;
	int count, j;

	if (head == NULL)
		exit(98);

	tmp1 = head;
	count = loopcount(tmp1);

	if (count == 0)
	{
		return (NULL);
	}
	else
	{
		while (head != NULL)
		{
			tmp2 = head;

			for (j = 0; j < count; j++)
			{
				head = head->next;
			}
			if (tmp2 == head)
			{
				while (tmp2->next != head)
					tmp2 = tmp2->next;
				return (tmp2);

			}
			head = tmp->next;
		}
	}

	return (NULL);

}
