#include <stdio.h>

/**
 * main - prints the first 50 fibonacci numbers, starting
 *        with 1 and 2, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of variables*/
	int a = 1, b = 2, temp, n;

	printf("%d, %d", a, b);
	for (n = 2; n < 50; n++)
	{
		temp = a + b;
		printf(", %d", temp);
		a = b;
		b = temp;
	}
	printf("\n");
	return (0);
}
