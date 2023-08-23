#include <stdio.h>

/**
 * _strcmp - Compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: negative if s1 is less than s2
 *         0 if s1 is equal to s2
 *         positive if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int result = *s1 - *s2;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (result);
}
