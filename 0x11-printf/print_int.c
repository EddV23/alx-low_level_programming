#include "main.h"

/**
 * print_int - print an integer
 * @args: the va_list that holds the integer to print
 *
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int temp, length, i, char_count = 0;
	int is_negative = 0;
	char buffer[12];

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	temp = num;
	length = 0;
	while (temp > 0)
	{
		temp /= 10;
		length++;
	}

	i = length - 1;
	while (i >= 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	if (is_negative)
	{
		_putchar('-');
		char_count++;
	}
	char_count += write(1, buffer, length);

	return (char_count);
}
