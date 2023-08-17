#include "main.h"

/**
 * main - finds and prints the largest prinme factor of the
 *        number 612852475143, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long num = 612852475143;
	long prime = 2;

	while (num > 1)
	{
		if (num % prime == 0)
			num /= prime;
		else
			prime++;
	}
	printf("%ld\n", prime);
	return (0);
}
