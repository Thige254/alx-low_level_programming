#include "main.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by s
 * with the constant byte b.
 * @s: a pointer to the memory area to fill.
 * @b: the character to fill the memory area with.
 * @n: the number of bytes to fill.
 *
 * Return: a pointer to the filled memory area @s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
