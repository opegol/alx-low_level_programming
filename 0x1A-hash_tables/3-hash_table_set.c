#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - a function that adds an element to the hash table.
 * @ht : the hash table you want to add or update the key/value to
 * @key : key is the key. key can not be an empty string
 * @value : value associated with the key. value must be duplicated.
 *		value can be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{

	unsigned long int index;
	hash_node_t *new_node, *tmp;
	char *val;

	if (ht == NULL || value == NULL)
		return (0);
	if (key == NULL || key[0] == '\0')
		return (0);

	new_node = malloc(sizeof(hash_node_t));

	index = key_index((const unsigned char *)key, ht->size);
	new_node->key = (char *)key;
	val = strdup(value);
	if (val == NULL)
		return (0);
	new_node->value = val;
	new_node->next = NULL;

	if (ht->array[index] == NULL)
	{
		ht->array[index] = new_node;
	}
	else
	{
		tmp = ht->array[index];
		ht->array[index] = new_node;
		new_node->next = tmp;
	}
	return (1);
}
