#include "main.h"

/**
 * _printf - A printf function that produces output
 *           according to a format
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int char_count;
	format_specifier fmt[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_perc},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{"u", print_uns_int},
		{"o", print_oct},
		{"x", print_hex_low},
		{"X", print_hex_up},
		{"p", print_add_p},
		{"r", print_rev},
		{NULL, NULL}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	char_count = handler(format, fmt, arg_list);

	va_end(arg_list);

	return (char_count);
}
