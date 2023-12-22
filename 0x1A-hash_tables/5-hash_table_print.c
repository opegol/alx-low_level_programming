#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - a function that prints a hash table
 * @ht : the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	int j = 0;
	unsigned long int i;
	hash_node_t *item;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		item = ht->array[i];
		if (!item)
			continue;
		while (item)
		{
			if (j == 0)
			{
				printf("'%s': '%s'", item->key, item->value);
				j = 1;
			}

			else
				printf(", '%s': '%s'", item->key, item->value);
			item = item->next;
		}
	}
	printf("}\n");
}

