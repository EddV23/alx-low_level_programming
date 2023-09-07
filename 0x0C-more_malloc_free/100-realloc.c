#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the previously allocated memory
 * @old_size: size in bytes of the old memory block
 * @new_size: new size in bytes of the memory block
 *
 * Return: A pointer to the newly reallocated memory block
 *         or NULL if new_size is zero and ptr is not NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int copy_size, i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	copy_size = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < copy_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_ptr);
}
