#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 *
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian = (char *)&num;

	if (*endian != 0)
		return 1; /* little endian */
	else
		return 0; /* big endian */
}
