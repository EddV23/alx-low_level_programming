#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @n : integer to be evaluated
 * Return: -n if integer is negative; n if zero or positive
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
