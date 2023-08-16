#include <stdio.h>

/**
 * main - prints the sum of the even-valued terms in the
 *        Fibonacci sequence that do not exceed 4,000,000,
 *        followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of variables*/
	long a = 1, b = 2, temp;
	long sum = 0;

	while (a <= 4000000)
	{
		if (a % 2 == 0)
			sum += a;
		temp = a + b;
		a = b;
		b = temp;
	}
	printf("%ld\n", sum);
	return (0);
}
