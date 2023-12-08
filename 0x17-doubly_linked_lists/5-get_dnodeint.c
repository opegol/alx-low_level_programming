#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a listint_t linked list.
 * @head : dlistint_t list head
 * @index : the index of the node, starting at 0
 * Return: returns the nth node of list or NULL if node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while ((head != NULL) && (i <= index))
	{
		cur = head;
		head = head->next;
		i++;
	}

	if (i > (index + 1)) /* plus 1 because of  i++ */
		return (NULL);
	return (cur);
}
