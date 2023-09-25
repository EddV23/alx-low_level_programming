#include "main.h"

/**
 * print_str - Print a string
 * @args: Arguments list
 * Return: Number of characters printed
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int char_count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		char_count++;
	}

	return (char_count);
}
