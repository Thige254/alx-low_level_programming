#include "main.h"

/**
 * _memset - fills memory with a specific value.
 * @s: A pointer to the memory area to be changed
 * @b: constant value
 * @n: The number of bytes to be changed
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
