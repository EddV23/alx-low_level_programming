#include "main.h"

/**
 * print_perc - Print a percentage sign
 * @args: Arguments list
 * Return: Number of characters printed (1)
 */
int print_perc(va_list args)
{
	(void)args;

	_putchar('%');
	return (1);
}
