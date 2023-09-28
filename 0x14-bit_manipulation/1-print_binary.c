#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: the number to print in binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int i, flag = 0;
	unsigned long int bit;

	if (n == 0)
		_putchar('0');

	for (i = 63; i >= 0; i--)
	{
		bit = n >> i;

		if (bit & 1)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
	}
	/**
	 *if (n == 0)
	 *	_putchar('0');
	 *if (n > 1)
	 *	print_binary(n >> 1);
	 *_putchar((n & 1) + '0');
	 */
}
