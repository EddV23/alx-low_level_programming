#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: the destination memory area to copy to
 * @src: the source memory area to copy from
 * @n: the size or number of bytesof the
 *           memory area to be copied
 *
 * Return: pointer to the memory area dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
