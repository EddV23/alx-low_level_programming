#include <stdio.h>

/**
 * _strcpy - Copies the string pointed to by src,
 *           including the terminating null byte (\0)
 *           to the buffer pointed to by dest
 * @dest: the destination buffer
 * @src: the source string to be copied
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	char *start_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start_dest);
}
