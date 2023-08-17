#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: integer to be printed
 * Return: void
 */
void print_number(int n)
{
	/*declaration of absolute value variable*/
	unsigned int abs;

	if (n < 0)
	{
		abs = -n;
		_putchar('-');
	}
	else
		abs = n;
	if (abs / 10)
		print_number(abs / 10);
	_putchar('0' + (abs % 10));
}
