#include <stdio.h>
#include "main.h"

/**
 * main - adds positive numbers provided as command-line
 *        arguments and prints the result, followed by a
 *        new line and if it does not receive two arguments,
 *        it prints an error message and returns 1
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, num, result = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		num = _atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0')
		{
			printf("Error\n");
			return (1);
		}
		else if (num < 0)
		{
			printf("Error\n");
			return (1);
		}
		result += num;
	}
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

	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = 1;
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (digit == 0)
		return (0);
	result *= sign;
	return (result);
}
