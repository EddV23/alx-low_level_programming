#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip to get from n to m
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;
	/*unsigned int num_bits = sizeof(unsigned long int) * 8;*/

	while (xor_result > 0)
	{
		xor_result &= (xor_result - 1);
		count++;
	}
	/*
	 *while (num_bits > 0)
	 *{
	 *	count += (xor_result & 1);
	 *	xor_result >>= 1;
	 *	num_bits--;
	 *}
	 */
	/*
	 *while (num_bits > 0)
	 *{
	 *	count += ((n ^ m) & 1);
	 *	n >>= 1;
	 *	m >>= 1;
	 *	num_bits--;
	 *}
	 */

	return (count);
}
