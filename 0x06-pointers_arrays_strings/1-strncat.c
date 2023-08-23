#include <stdio.h>

/**
 * _strncat - Concatenates or appends the string pointed by src
 *            to the string pointed by dest,
 *            using at most n bytes from src
 * @dest: the destination string
 * @src: the source string to be appended
 * @n: the maximum number of bytes to concatenate from src
 * Return: the pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (result);
}
