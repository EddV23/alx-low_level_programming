#include "main.h"

/**
 * print_uns_int - print an integer
 * @args: the va_list that holds the integer to print
 *
 * Return: The number of characters printed
 */
int print_uns_int(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp, length, is_negative = 0;
	int char_count = 0, i;
	char buffer[12];

	/*
	 *if (num < 0)
	 *{
	 *	is_negative = 1;
	 *	num = -num;
	 *}
	 */
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
