#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers from min to max
 * @min: the minimum value (inclusive)
 * @max: the maximum value (inclusive)
 *
 * Return: A pointer to the newly created array of integers
 *         or NULL if min > max or if malloc fails
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min++;

	return (arr);
}
