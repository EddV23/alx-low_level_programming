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
	int i = 0, j = 0, d = 0;
	int v1 = 0, v2 = 0, t = 0;
	int left = 0, right = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (NULL);
	while (j >= 0 || i >= 0 || carry == 1)
	{
		v1 = (i >= 0) ? n1[i] - '0' : 0;
		v2 = (j >= 0) ? n2[j] - '0' : 0;
		t = v1 + v2 + carry;
		carry = t / 10;
		r[d] = (t % 10) + '0';
		if (d >= size_r - 1)
			return (NULL);
		d++;
		j--;
		i--;
	}
	r[d] = '\0';
	left = 0;
	right = d - 1;

	while (left < right)
	{
		char temp = r[left];

		r[left] = r[right];
		r[right] = temp;
		left++;
		right--;
	}
	return (r);
}
