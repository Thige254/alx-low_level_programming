#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: head pointer of the list
 * @index: of node to retrieve
 *
 * Return: pointer to the nth node/NULL if node doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int nodes = 0;

	while (head)
	{
		if (nodes == index)
			return (head);
		head = head->next;
		nodes++;
	}

	return (NULL);
}
