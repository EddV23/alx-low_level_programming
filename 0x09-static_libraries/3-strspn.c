#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to be evaluated
 * @accept: the string containing the characters to search for
 *
 * Return: The number of bytes in the initial segment
 *         of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int length = 0;
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				length++;
				break;
			}
		}
		if (!*a)
			break;
		s++;
	}
	return (length);
}
