#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings, using at most n bytes of s2
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes from s2 to concatenate
 *
 * Return: A pointer to the newly allocated concatenated string,
 *         or NULL if memory allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i;
	char *concat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	if (n >= len2)
		n = len2;

	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	for (i = 0; i < n; i++)
		concat[len1 + i] = s2[i];

	concat[len1 + n] = '\0';

	return (concat);
}
