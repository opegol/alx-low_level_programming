#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - function that retrieves a value associated with a key.
 * @ht : hash table to look into
 * @key : key being looked for
 * Return: value associated with the key, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *item;

	if (key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	item = ht->array[index];

	while (item)
	{
		if (strcmp(item->key, key) == 0)
		{
			return (item->value);
		}
		item = item->next;
	}
	return (NULL);
}


