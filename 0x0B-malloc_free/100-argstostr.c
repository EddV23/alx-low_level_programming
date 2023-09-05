#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the argument count
 * @av: the argument vector (an array of strings)
 *
 * Return: A pointer to a new string containing concatenated arguments
 *         separated by newline characters, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, len = 0, total_len = 0;
	char *concatenated;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			len++;
			total_len++;
		}
		total_len++;
	}

	concatenated = malloc(sizeof(char) * (total_len + 1));

	if (concatenated == NULL)
		return (NULL);

	total_len = 0;

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			concatenated[total_len] = av[i][len];
			len++;
			total_len++;
		}
		concatenated[total_len] = '\n';
		total_len++;
	}
	concatenated[total_len] = '\0';
	return (concatenated);
}
