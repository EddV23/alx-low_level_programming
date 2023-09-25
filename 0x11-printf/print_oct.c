#include "main.h"

/**
 * print_oct - Print an unsigned integer in octal format
 * @args: Arguments list
 * Return: Number of characters printed
 */
int print_oct(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int char_count = 0;
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		char_count++;
	}
	else
	{
		while (n > 0)
		{
			buffer[i] = (n % 8) + '0';
			n /= 8;
			i++;
		}

		while (--i >= 0)
		{
			_putchar(buffer[i]);
			char_count++;
		}
	}

	return (char_count);
}
