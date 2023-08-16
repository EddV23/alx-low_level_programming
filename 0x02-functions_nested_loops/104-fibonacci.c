#include <stdio.h>
#define MAX_DIFGITS 1000

/**
 * add_arrays - checks and adds the arrays
 * @result : sum of arrays
 * @a : array to be evaluated
 * @b : array to be evaluated
 * Return: void
 */
void add_arrays(int result[], int a[], int b[])
{
	int carry = 0, i;

	for (i = MAX_DIGITS - 1; i >= 0; i--)
	{
		int sum = a[i] + b[i] + carry;

		result[i] = sum % 10;
		carry = sum / 10;
	}
}
/**
 * main - prints the first 50 fibonacci numbers, starting
 *        with 1 and 2, followed by a new line
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int fib1[MAX_DIGITS] = {0};
	int fib2[MAX_DIGITS] = {0};
	int fib_sum[MAX_DIGITS] = {0};

	fib1[MAX_DIGITS - 1] = 1;
	fib2[MAX_DIGITS - 1] = 2;
	printf("1, 2");
	for (int n = 2; n < 98; n++)
	{
		add_arrays(fib_sum, fib1, fib2);
		printf(", ");
		int i = 0;

		while (fib_sum[i] == 0 && i < MAX_DIGITS)
			i++;
		if (i == MAX_DIGITS)
			printf("0");
		else
		{
			for (; i < MAX_DIGITS; i++)
				printf("%d", fib_sum[i]);
		}
		/*Shift arrays for next iteration*/
		for (i = 0; i < MAX_DIGITS; i++)
		{
			fib1[i] = fib2[i];
			fib2[i] = fib_sum[i];
		}
	}
	printf("\n");
	return (0);
}
