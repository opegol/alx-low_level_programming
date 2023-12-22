#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head : linked list to be freed
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		free(temp->str);
		head = head->next;
		free(temp);
	}
}

