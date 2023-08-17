#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer to insert into the latest node
 *
 * Return: the address of the new element, or NULL if it fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_element;

	new_element = malloc(sizeof(dlistint_t));
	if (!new_element)
		return (NULL);

	new_element->n = n;
	new_element->prev = NULL;
	new_element->next = *head;

	if (*head != NULL)
		(*head)->prev = new_element;

	*head = new_element;

	return (new_element);
}
