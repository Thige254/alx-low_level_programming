#include "lists.h"

/**
 * free_dlistint - frees the given dlistint_t list
 * @head: pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_element;

	while (head)
	{
		current_element = head;
		head = head->next;
		free(current_element);
	}
}
