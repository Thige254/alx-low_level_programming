#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key,
const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (!ht || !key || !*key || !value)
		return (0);

	/* Use key_index function to calculate the index for the key */
	index = key_index((const unsigned char *)key, ht->size);

	current = ht->array[index];
	while (current)
	{
		/* Check if key already exists ion has table */
		if (strcmp(current->key, key) == 0)
		{
			/* Update the value + return */
			free(current->value);
			current->value = strdup(value);
			if (!current->value)
				return (0);
			return (1);
		}
		current = current->next;
	}

	/* add a new node at the beginning if key Nt found */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* handle collision */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
