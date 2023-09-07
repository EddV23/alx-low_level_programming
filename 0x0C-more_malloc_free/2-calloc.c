#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array and initializes it with zeros
 * @nmemb: number of elements in the array
 * @size: size in bytes of each element
 *
 * Return: A pointer to the allocated memory
 *         or NULL if nmemb or size is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *filler;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	filler = ptr;
	for (i = 0; i < nmemb * size; i++)
		filler[i] = 0;

	return (ptr);
}
