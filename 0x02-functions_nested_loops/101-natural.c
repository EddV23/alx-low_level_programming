#include <stdio.h>

/**
 * main - prints the sum of all multiples of 3 0r 5
 *        that are below 1024
 *
 * Return: Always 0 (Success)e
 */
int main(void)
{
	int n, sum = 0;

	for (n = 0; n < 1024; n++)
	{
		if (n % 3 == 0 || n % 5 == 0)
			sum += n;
	}
	printf("%d\n", sum);
	return (0);
}
