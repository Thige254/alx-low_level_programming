#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table,
 * NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	/* Allocate memory for the hash table struct */
	new_table = malloc(sizeof(hash_table_t));
	if (!new_table)
		return (NULL);

	/* Allocate memory for the array within the hash table */
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}

	/* Initialize the array pointers to NULL */
	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	new_table->size = size;

	return (new_table);
}
