#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table.
 * @key: The key.
 *
 * Return: The value associated with the element,
 * NULL if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (!ht || !key || !*key)
		return (NULL);

	/* Calculate index fokey using key_index function */
	index = key_index((const unsigned char *)key, ht->size);

	/* Checks linked list at the computed index */
	for (current = ht->array[index]; current; current =
	current->next)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
	}

	return (NULL);
}
