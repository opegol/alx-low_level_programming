#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head : listint_t list head
 * @index : the index of the node, starting at 0
 * Return: returns the nth node of list or NULL if node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *cur;
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
