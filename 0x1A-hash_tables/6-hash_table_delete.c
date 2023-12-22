#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"


/**
 * free_list - frees a list_t list
 * @head : linked list to be freed
 */
void free_list(hash_node_t *head)
{
	hash_node_t *temp;

	while (head != NULL)
	{
		temp = head;
		free(temp->value);
		head = head->next;
		free(temp);
	}
}

/**
 * hash_table_delete - deletes a hash table
 * @ht : the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *item;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		item = ht->array[i];
		if (item)
			free_list(item);
	}
	free(ht->array);
	free(ht);
}
