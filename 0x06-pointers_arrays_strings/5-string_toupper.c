#include <stdio.h>

/**
 * string_toupper - changes all lowercase letters of a string
 *                  to uppercase
 * @str: input string whose letters are converted to uppercase
 * Return: the pointer the string
 */
char *string_toupper(char *str)
{
	char *result = str;
	
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - ('a' - 'A');
		str++;
	}
	return (result);
}
