#include "hash_tables.h"
/**
 * shash_table_set - Adds or updates a key/value
 * pair in the sorted hash table.
 *
 * Given a key and its corresponding value,
 * the function computes an index
 * in the hash table using the djb2 algorithm.
 * If a collision occurs, it's handled
 * by chaining. Along with adding the key/value pair to the hash table,
 * this
 * function also ensures that the pair is placed in
 * the right order in the
 * sorted doubly linked list.
 */

int shash_table_set(shash_table_t *ht,
const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *new_node = NULL, *current = NULL, *prev = NULL;

	if (!ht || !key || strlen(key) == 0 || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	current = ht->array[idx];

	/* Check for an existing key */
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	/* Create a new node */
	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	/* Insertion in the sorted linked list */
	if (!ht->shead) /* If it's the first node */
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
	}
	else
	{
		current = ht->shead;
		while (current && strcmp(current->key, key) < 0)
		{
			prev = current;
			current = current->snext;
		}

		if (!current) /* Insert at the end */
		{
			prev->snext = new_node;
			new_node->sprev = prev;
			new_node->snext = NULL;
			ht->stail = new_node;
		}
		else /* Insert in between */
		{
			new_node->snext = current;
			new_node->sprev = current->sprev;

			if (current->sprev)
				current->sprev->snext = new_node;
			else /* New head of the list */
				ht->shead = new_node;

			current->sprev = new_node;
		}
	}

	return (1);
}




/**
 * shash_table_get - Retrieves a value associated with
 * a provided key.
 *
 * Given a key, the function computes its index in
 * the hash table and then
 * searches the linked list at that index to find the
 * corresponding value.
 * The function returns the found value or NULL if the key is absent.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *current;

	if (!ht || !key)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	for (current = ht->array[idx]; current;
	current = current->next)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
	}

	return (NULL);
}


/**
 * shash_table_print - Prints the entire sorted hash table.
 *
 * The function traverses the doubly linked list,
 * which maintains the order
 * of insertion, and prints each key/value pair.
 * The pairs are displayed
 * in the order they were added to the hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	char *delimiter = "";

	if (!ht)
		return;

	printf("{");

	for (current = ht->shead; current; current = current->snext)
	{
		printf("%s'%s': '%s'", delimiter, current->key,
		current->value);
		delimiter = ", ";
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash
 * table in reverse order.
 *
 * The function traverses the sorted doubly linked
 * list from tail to head,
 * effectively printing the key/value pairs in the
 * reverse order of their
 * insertion into the hash table.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	char *delimiter = "";

	if (!ht)
		return;

	printf("{");

	for (current = ht->stail; current; current = current->sprev)
	{
		printf("%s'%s': '%s'", delimiter, current->key,
		current->value);
		delimiter = ", ";
	}

	printf("}\n");
}


/**
 * shash_table_delete - Deletes the entire sorted hash table.
 *
 * The function ensures that all memory allocated
 * for the hash table's array
 * and for each key/value pair is properly freed.
 * Both the linked lists in the
 * hash table's array and the sorted doubly linked
 * list are traversed to
 * release all allocated memory.
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *next_node;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			next_node = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next_node;
		}
	}

	free(ht->array);
	free(ht);
}
