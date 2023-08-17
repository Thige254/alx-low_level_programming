#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer to insert into the new node
 *
 * Return: address of the new element / NULL if it fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_element, *current_element;

	new_element = malloc(sizeof(dlistint_t));
	if (!new_element)
		return (NULL);

	new_element->n = n;
	new_element->next = NULL;

	if (!*head)
	{
		new_element->prev = NULL;
		*head = new_element;
		return (new_element);
	}

	current_element = *head;
	while (current_element->next)
		current_element = current_element->next;

	current_element->next = new_element;
	new_element->prev = current_element;

	return (new_element);
}
