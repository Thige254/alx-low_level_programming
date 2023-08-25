#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: string to evaluate
 * @accept: containslist of characters to match in s
 *
 * Return: the number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int x, y;

	for (x = 0; s[x]; x++)
	{
		for (y = 0; accept[y]; y++)
		{
			if (s[x] == accept[y])
				break;
		}

		if (!accept[y])
			break;
	}

	return (x);
}
