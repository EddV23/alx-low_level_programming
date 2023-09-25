#include "main.h"

/**
 * print_hex_low - Print an unsigned integer in lowercase hexadecimal format
 * @args: Arguments list
 * Return: Number of characters printed
 */
int print_hex_low(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int char_count = 0, remainder;
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
			remainder = n % 16;
			buffer[i] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
			n /= 16;
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
