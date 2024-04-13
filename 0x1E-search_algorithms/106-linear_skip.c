#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
#include <math.h>


/**
 * linear_skip - searches for a value in a sorted list of integers
 *		using the Jump search algorithm.
 * @list: pointer to the  head of the skip list to search in.
 * @value: value to search for
 * Return: pointer to the first node where value is located
 *		or NULL If not present
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp, *last;

	if (list == NULL)
		return (NULL);
	while (list->n < value)
	{
		temp = list;
		list = list->express;
		if (!list)
		{
			last = temp;
			while (last)
			{
				list = last;
				last = last->next;
			}
			break;
		}
		printf("Value checked at index [%li] = [%d]\n", list->index, list->n);
	}
	printf("Value found between indexes [%li] and [%li]\n",
		temp->index, list->index);

	while (temp->n <= list->n)
	{
		printf("Value checked at index [%li] = [%d]\n", temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
		if (!temp)
			break;
	}
	return (NULL);
}
