#include "main.h"

/**
 * print_add_p - Print a pointer address
 * @args: Arguments list
 * Return: Number of characters printed
 */
int print_add_p(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int address = (unsigned long int)ptr;
	int char_count = 0, remainder;
	char buffer[20];
	int i = 0;

	_putchar('0');
	_putchar('x');
	char_count += 2;

	if (address == 0)
	{
		_putchar('0');
		char_count++;
	}
	else
	{
		while (address > 0)
		{
			remainder = address % 16;
			buffer[i] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
			address /= 16;
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
