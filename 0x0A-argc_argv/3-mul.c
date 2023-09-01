#include <stdio.h>
#include "main.h"

/**
 * main - multiplies two numbers provided as command-line
 *        arguments and prints the result, and if it does
 *        not receive two arguments, it prints an error
 *        message and returns 1
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the input string
 *
 * Return: the integer value converted from the string
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int i = 0;
	int digit = 0;

	while (s[i])
	{
		if (s[i] == '-')
			sign *= -1;
		while (s[i] >= '0' && s[i] <= '9')
		{
			digit = 1;
			result = result * 10 + (s[i] - '0');
			i++;
		}
		if (digit == 1)
			break;
		i++;
	}
	result *= sign;
	return (result);
}
