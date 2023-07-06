#include "main.h"

/**
 * get_endianness - checks if machine used is either little or a big endian
 * Return: 0 if big and 1 if little
 */
int get_endianness()
{
	unsigned int number = 1;
	char *endian = (char *) &number;

	return (*endian);
}
