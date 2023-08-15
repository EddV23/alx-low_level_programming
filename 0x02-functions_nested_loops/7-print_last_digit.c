#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n : number to be evaluated
 * Return: -last_digit if is negative; last_digit if zero or positive
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (last_digit < 0)
		last_digit = -last_digit;
	_putchar (last_digit + '0');
	return (last_digit);
}
