#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: head of list pointer
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeds/ -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int nodes = 0;

	if (!head || !*head)
		return (-1);

	current_node = *head;

	if (index == 0)
	{
		*head = current_node->next;
		if (*head)
			(*head)->prev = NULL;
		free(current_node);
		return (1);
	}

	while (current_node && nodes < index)
	{
		current_node = current_node->next;
		nodes++;
	}

	if (!current_node)
		return (-1);

	if (current_node->next)
		current_node->next->prev = current_node->prev;

	if (current_node->prev)
		current_node->prev->next = current_node->next;

	free(current_node);

	return (1);
}
