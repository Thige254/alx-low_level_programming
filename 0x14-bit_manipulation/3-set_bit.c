#include "main.h"

/**
 * set_bit - Sets a bit at a given index to 1
 * @n: Pointer to the number to change
 * @index: Index of the bit to set to 1 starting from 0
 *
 * Return: 1 on success, -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
