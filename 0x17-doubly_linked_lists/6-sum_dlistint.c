#include "lists.h"

/**
 * sum_dlistint - calculates sum of all the data of a dlistint_t linked
 * @head:  head of the list pointer
 *
 * Return: sum of all the data / 0 if the list empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
