#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - function to create a hash table
 * @size : size of the hash table array
 * Return: a pointer to the newly created hash table or NULL if
 *		something went wrong
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *new_h;
	hash_node_t **item;

	new_h = malloc(sizeof(hash_table_t));
	if (!new_h)
	{
		return (NULL);
	}

	item = malloc(sizeof(hash_node_t *) * size);
	if (!item)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		item[i] = NULL;
	}
	new_h->size = size;
	new_h->array = item;

	return (new_h);
}
