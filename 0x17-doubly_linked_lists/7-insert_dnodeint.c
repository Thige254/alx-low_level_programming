#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @idx: index of the list where the new node should be added.
 * @n: integer to insert into the new node
 * @h: pointer to the head of the list
 *
 * Return: the address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *latest_node, *current_element;
	unsigned int nodes = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	current_element = *h;
	while (current_element && nodes < idx)
	{
		if (nodes == idx - 1 && current_element->next == NULL)
			return (add_dnodeint_end(h, n));

		current_element = current_element->next;
		nodes++;
	}

	if (!current_element || nodes != idx)
		return (NULL);

	latest_node = malloc(sizeof(dlistint_t));
	if (!latest_node)
		return (NULL);

	latest_node->n = n;
	latest_node->prev = current_element->prev;
	latest_node->next = current_element;
	current_element->prev->next = latest_node;
	current_element->prev = latest_node;

	return (latest_node);
}
