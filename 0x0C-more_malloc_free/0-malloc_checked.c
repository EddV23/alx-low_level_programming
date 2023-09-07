#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocate memory using malloc and check for success
 * @b: the number of bytes to allocate
 *
 * Return: A pointer to the allocated memory if successful,
 *         If malloc fails, the function terminates with a status of 98
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		exit(98);
	}

	return (ptr);
}
