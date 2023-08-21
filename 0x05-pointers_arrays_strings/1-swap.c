#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a : first integer to be swapped with second integer
 * @b : second integer to be swapped with first integer
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
