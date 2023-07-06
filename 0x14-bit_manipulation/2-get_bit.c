#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: the number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
    return (index >= sizeof(unsigned long int) * 8) ? -1 : (n >> index) & 1;
}
