/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Pointer to the number to modify
 * @index: Index of the bit to set to 0
 *
 * Return: 1 on success, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
