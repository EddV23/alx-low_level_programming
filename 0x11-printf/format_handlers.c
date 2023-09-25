#include "main.h"

/**
 * handler - Handles the format specifiers and prints accordingly
 * @format: The format string
 * @fmt: An array of format specifiers
 * @arg_list: The variable argument list
 *
 * Return: The number of characters printed.
 */
int handler(const char *format, format_specifier fmt[], va_list arg_list)
{
	int char_count = 0;
	int i = 0, j, found, printed;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			found = 0;

			for (j = 0; fmt[j].specifier != NULL; j++)
			{
				if (format[i] == fmt[j].specifier[0])
				{
					found = 1;
					printed = fmt[j].handler(arg_list);
					if (printed == -1)
						return (-1);
					char_count += printed;
					break;
				}
			}

			if (!found)
			{
				_putchar('%');
				char_count++;
			}
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}

		i++;
	}

	return (char_count);
}
