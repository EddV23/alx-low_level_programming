#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Checks if a number is a palindrome
 * @n: Number to check
 * Return: 1 if the number is a palindrome, 0 otherwise
 */
int is_palindrome(int n)
{
	int reversed = 0, original = n;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return (original == reversed);
}

/**
 * main - Finds the largest palindrome from the product of two 3-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int max_palindrome = 0;
	int i, j, product;
	FILE *file;

	for (i = 100; i < 1000; i++)
	{
		for (j = i; j < 1000; j++)
		{
			product = i * j;
			if (is_palindrome(product) && product > max_palindrome)
			{
				max_palindrome = product;
			}
		}
	}

	file = fopen("102-result", "w");
	if (file == NULL)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}
	fprintf(file, "%d\n", max_palindrome);
	fclose(file);

	return (EXIT_SUCCESS);
}
