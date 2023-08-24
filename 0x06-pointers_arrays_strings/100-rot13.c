#include "main.h"
/**
 * rot13 - encodes a string using to rot13
 * @str: input string to be encoded
 *
 * Return: a pointer of to the encoded string
 */
char *rot13(char *str)
{
	char *ptr = str;
	char rot_dict[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot_replace[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0;

	for (; *ptr; ptr++)
	{
		for (i = 0; rot_dict[i] <= 51; i++)
		{
			if (*ptr == rot_dict[i])
			{
				*ptr = rot_replace[i];
				break;
			}
		}
	}
	return (str);
}
