#include <stdio.h>

/**
 * cap_string - capitalizes all words of a string
 * @str: input string whose words are to be capitalized
 * Return: the pointer the string
 */
char *cap_string(char *str)
{
	char *result = str;
	int i = 0, conv = 32;
	int sep[] = {32, 9, 10, 44, 59, 46, 33, 63, 34, 40, 41, 123, 125};

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - conv;
		conv = 0;
		i = 0;
		while (sep[i] != 0)
		{
			if (sep[i] == *str)
			{
				conv = 32;
				break;
			}
			i++;
		}
		str++;
	}
	return (result);
}
