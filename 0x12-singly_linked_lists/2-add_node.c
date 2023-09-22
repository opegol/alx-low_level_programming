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
 * add_node - adds a new node at the beginning of a list_t list.
 * @head : old list_t head
 * @str : string element of list
 * Return: the number of nodes
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = slen(str);
	new->next = *head;
	*head = new;
	return (new);
}
