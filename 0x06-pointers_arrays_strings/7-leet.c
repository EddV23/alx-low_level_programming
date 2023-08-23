#include <stdio.h>

/**
 * leet - encodes a string into 1337.
 * @str: the input string to be encoded
 *
 * Return: a pointer to the encoded string
 */
char *leet(char *str)
{
	char *ptr = str;
	char leet_dict[] = "aAeEoOtTlL";
	char leet_replace[] = "4433007711";
	int i = 0;

	for (; *ptr; ptr++)
	{
		for (i = 0; leet_dict[i]; i++)
		{
			if (*ptr == leet_dict[i])
			{
				*ptr = leet_replace[i];
				break;
			}
		}
	}
	return (str);
}
