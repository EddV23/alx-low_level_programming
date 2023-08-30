#include "main.h"

int find_sqrt_recursion(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to calculate the square root of
 *
 * Return: the resulting square root, or -1 if
 *         n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	return (find_sqrt_recursion(n, 0));
}

/**
 * find_sqrt_recursion - returns the natural square root of a number
 * @n: the number to calculate the square root of
 * @i: iterator used for recursion
 *
 * Return: the resulting square root, or -1 if
 *         n does not have a natural square root
 */
int find_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	else if (i * i == n)
		return (i);
	else
		return (find_sqrt_recursion(n, i + 1));
}
