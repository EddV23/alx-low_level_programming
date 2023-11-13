#include <stdio.h>

/**
 * _strncpy - Copies appends the string pointed by src
 *            to the string pointed by dest,
 *            using at most n bytes from src
 * @dest: the destination string
 * @src: the source string to be copied
 * @n: the maximum number of bytes to be copied from src
 * Return: the pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *result = dest;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (result);
}
