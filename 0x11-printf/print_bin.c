#include "main.h"

/**
 * print_bin - prints an unsigned integer
 * @args: the va_list that holds the integer to print
 *
 * Return: The number of characters printed
 */
int print_bin(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int arr[32], digit, i, result;
	int char_count;
	char digit_char;

	digit = 2147483648;

	arr[0] = num / digit;
	for (i = 1; i < 32; i++)
	{
		digit /= 2;
		arr[i] = (num / digit) % 2;
	}
	for (i = 0, result = 0, char_count = 0; i < 32; i++)
	{
		result += arr[i];
		if (result || i == 31)
		{
			digit_char = '0' + arr[i];
			_putchar(digit_char);
			char_count++;
		}
	}
	return (char_count);
}
