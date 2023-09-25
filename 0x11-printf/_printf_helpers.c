#include "main.h"

/**
 * handle_format_specifier - Handles conversion specifiers
 * @specifier: The conversion specifier character
 * @args: The variable argument list
 * Return: Number of characters printed
 */
int handle_format_specifier(const char *specifier, va_list args)
{
	switch (*specifier)
	{
	case 'c':
		return (print_char(args));
	case 's':
		return (print_str(args));
	case '%':
		write(1, "%", 1);
		return (1);
	default:
		write(1, "%", 1);
		write(1, &specifier, 1);
		return (2);
	}
}

/**
 * print_char - Prints a character
 * @c: The character to print
 * Return: 1 (character printed)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return(write(1, &c, 1));
}

/**
 * print_str - Prints a string
 * @s: The string to print
 * Return: Number of characters printed
 */
int print_str(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}

	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}

	return (len);
}
