#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * slen - returns length of string
 * @s : given string
 * Return: length of string
 */
int slen(const char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head : old list_t head
 * @str : list_t list string element
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *cur;
	list_t *prev;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = slen(str);
	new->next = NULL;
	if ((*head) == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		cur = *head;
		while (cur != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
	}
	prev->next = new;
	return (new);
}
