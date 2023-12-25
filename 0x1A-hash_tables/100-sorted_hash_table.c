#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void free_list(shash_node_t *head);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - function to create a hash table
 * @size : size of the hash table array
 * Return: a pointer to the newly created hash table or NULL if
 *		something went wrong
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *new_h;
	shash_node_t **item;

	new_h = malloc(sizeof(shash_table_t));
	if (!new_h)
	{
		return (NULL);
	}

	item = malloc(sizeof(shash_node_t *) * size);
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
	new_h->shead = NULL;
	new_h->stail = NULL;

	return (new_h);
}


/**
 * shash_table_set - a function that adds an element to the hash table.
 * @ht : the hash table you want to add or update the key/value to
 * @key : key is the key. key can not be an empty string
 * @value : value associated with the key. value must be duplicated.
 *		value can be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *tmp = NULL, *tab_head, *tab_tail;
	char *val;

	if (ht == NULL || value == NULL)
		return (0);
	if (key == NULL || key[0] == '\0')
		return (0);

	new_node = malloc(sizeof(shash_node_t));

	index = key_index((const unsigned char *)key, ht->size);
	new_node->key = (char *)key;
	val = strdup(value);
	if (val == NULL)
		return (0);
	new_node->value = val;
	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	if (ht->shead == NULL && ht->stail == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		if (strcmp(new_node->key, ht->shead->key) < 0)
			ht->shead = new_node;
		tab_head = ht->shead;

		while (tab_head && (strcmp(new_node->key, tab_head->key) > 0))
		{
			tmp = tab_head;
			tab_head = tab_head->snext;
		}
		if (tmp)
			tmp->snext = new_node;
		new_node->sprev = tmp;

		if (strcmp(new_node->key, ht->stail->key) > 0)
			ht->stail = new_node;
		tab_tail = ht->stail;

		tmp = NULL;
		while (tab_tail && (strcmp(new_node->key, tab_tail->key) < 0))
		{
			tmp = tab_tail;
			tab_tail = tab_tail->sprev;
		}
		if (tmp)
			tmp->sprev = new_node;
		new_node->snext = tmp;


		tmp = NULL;
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
	}

	return (1);
}

/**
 * shash_table_get - function that retrieves a value associated with a key.
 * @ht : hash table to look into
 * @key : key being looked for
 * Return: value associated with the key, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *item;

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


/**
 * shash_table_print - a function that prints a hash table
 * @ht : the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	int f = 0;
	shash_node_t *item;

	printf("{");
	item = ht->shead;
	while (item)
	{
		if (f == 0)
		{
			printf("'%s': '%s'", item->key, item->value);
			f = 1;
		}
		else
			printf(", '%s': '%s'", item->key, item->value);
		item = item->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 * @ht : sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int j = 0;
	shash_node_t *item;

	printf("{");
	item = ht->stail;
	while (item)
	{
		if (j == 0)
		{
			printf("'%s': '%s'", item->key, item->value);
			j = 1;
		}
		else
			printf(", '%s': '%s'", item->key, item->value);
		item = item->sprev;
	}
	printf("}\n");
}

/**
 * free_list - frees a list_t list
 * @head : linked list to be freed
 */
void free_list(shash_node_t *head)
{
	shash_node_t *temp;

	while (head != NULL)
	{
		temp = head;
		free(temp->value);
		head = head->next;
		free(temp);
	}
}

/**
 * shash_table_delete - deletes a hash table
 * @ht : the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *item;
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
