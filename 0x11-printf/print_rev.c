#include "main.h"

/**
 * print_rev - Print a reversed string
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_rev(va_list args)
{
	char *str = va_arg(args, char *);
	int char_count = 0, length, i;

	if (str == NULL)
		str = "(null)";

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		char_count++;
	}

	return (char_count);
}
