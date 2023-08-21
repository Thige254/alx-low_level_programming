#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: string to be searched.
 * @c: character to search
 *
 * Return: pointer to the first occurence of c if c is found.
 * NULL If c is not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
