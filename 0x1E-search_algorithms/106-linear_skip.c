#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a sorted list of integers
 *		using the Jump search algorithm.
 * @list: pointer to the  head of the list to search in.
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to the first node where value is located
 *		or NULL If not present
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t b = lit->index, sqr = sqrt(size), a = 0, i;
	listint_t *temp;

	if (list == NULL || size == 0)
		return (NULL);

	while (list && (list->n < value))
	{
		a = b;
		b += sqr;
		if (a >= size - 1)
		{
			printf("Value checked at index[%li] = [%d]\n", list->index, list->n);
			break;
		}
		if (b >= size - 1)
		{
			temp = list;
			for (i = a; i < (size - 1); i++)
				list = list->next;
			continue;
		}
		temp = list;
		for (i = 0; i < sqr; i++)
			list = list->next;
		printf("Value checked at index[%li] = [%d]\n", list->index, list->n);
	}
	printf("Value found between indexes [%li] and [%li]\n",
		temp->index, list->index);

	while (temp->n <= list->n)
	{
		printf("Value checked at index[%li] = [%d]\n", temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
		if (!temp)
			break;
	}
	return (NULL);
}
