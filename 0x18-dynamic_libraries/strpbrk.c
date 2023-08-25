#include "main.h"

/**
 * _strpbrk - Locates the first occurrence in 's' of any of
 * the bytes in 'accept'
 * @s: The string to be scanned
 * @accept: The string containing the characters to match
 *
 * Return: Pointer to the byte in 's' that matches one of the bytes
 * in 'accept', or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int y;

	while (*s)
	{
		for (y = 0; accept[y]; y++)
		{
			if (*s == accept[y])
				return (s);
		}
		s++;
	}

	return ('\0');
}
