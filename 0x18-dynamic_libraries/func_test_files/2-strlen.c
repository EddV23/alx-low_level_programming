#include "main.h"

/**
 * _strlen  - returns the length of a string
 * @s : input string whose length will be returned
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	/*for (i = 0; s[i] != '\0'; i++);*/
	while (s[i] != '\0')
		i++;
	return (i);
}
