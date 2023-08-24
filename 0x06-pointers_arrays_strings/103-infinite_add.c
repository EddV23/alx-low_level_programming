#include <stdio.h>
#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings.
 * @n1: First number as string.
 * @n2: Second number as string.
 * @r: Buffer to store the result.
 * @size_r: Size of the buffer.
 *
 * Return: Pointer to the result string, or 0 if the result cannot be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int index_r = size_r - 1;
	int index_n1 = 0;
	int index_n2 = 0;
	int i = 0, digit = 0;

	r[index_r] = '\0';
	while (index_r > 0 || carry)
	{
		int num1 = (index_n1 < size_r - 1 && n1[index_n1] != '\0') ? n1[index_n1] - '0' : 0;
		int num2 = (index_n2 < size_r - 1 && n2[index_n2] != '\0') ? n2[index_n2] - '0' : 0;
		int sum = num1 + num2;

		
		carry = sum / 10;
		digit = sum % 10;
		if (index_r >= 0)
			r[index_r] = digit + '0';
		index_r--;
		index_n1++;
		index_n2++;
	}
	if (index_r < 0)
		return (0);
	for (i = 0; i < size_r - index_r - 1; i++)
	{
		r[i] = r[index_r + i];
	}
	return (r);
}
