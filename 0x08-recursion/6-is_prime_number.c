#include "main.h"

int is_prime_recursive(int n, int divisor);

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	return (is_prime_recursive(n, 2));
}

/**
 * is_prime_recursive - checks if a number is prime recursively
 * @n: the number to check
 * @divisor: the current divisor being tested
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_recursive(int n, int divisor)
{
	if (n <= 1)
		return (0);
	if (n <= 3)
		return (1);
	if (divisor * divisor > n)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_prime_recursive(n, divisor + 1));
}
