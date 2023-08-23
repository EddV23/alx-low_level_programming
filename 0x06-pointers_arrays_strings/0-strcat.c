#include <stdio.h>

/**
 * _strcat - Concatenates or appends the string pointed by src
 *           to the string pointed by dest, and adds
 *           the terminating null byte (\0),
 * @dest: the destination string
 * @src: the source string to be appended
 * Return: the pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}
