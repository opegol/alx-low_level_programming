#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int loopcount(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * loopcount - counts number of nodes in loop
 * @head : given listint_t list head node
 * Return: count of loop nodes or 0 if no loop
 */
int loopcount(const listint_t *head)
{
	const listint_t *s;
	const listint_t *f;
	const listint_t *tmp;
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
 * print_listint_safe - prints a listint_t linked list.
 * @head : given listint_t list head node
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
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
		while (head != NULL)
		{
			i++;
			printf("[%p] %i\n", (void *)head, head->n);
			head = head->next;
		}
		return (i);
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
			if (tmp2 != head)
			{
				printf("[%p] %i\n", (void *)tmp2, tmp2->n);
				i++;
				head = tmp2->next;
				continue;
			}
			else if (tmp2 == head)
			{
				printf("[%p] %i\n", (void *)tmp2, tmp2->n);
				i++;
				while (tmp2->next != head)
				{
					tmp2 = tmp2->next;
					printf("[%p] %i\n", (void *)tmp2, tmp2->n);
					i++;
				}
				printf("-> [%p] %i\n", (void *)head, head->n);
				break;
			}
		}
	}

	return (i);

}
