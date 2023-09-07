#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiply(char *num1, char *num2);
int isNumeric(const char *str);
int _isdigit(int c);

/**
 * main - multiplies two positive numbers
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on successful execution, or 98 in case of an error
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	if (!isNumeric(argv[1]) || !isNumeric(argv[2]))
	{
		printf("Error\n");
		return (98);
	}
	result = multiply(argv[1], argv[2]);
	printf("%s\n", result);
	free(result);
	return (0);
}

/**
 * multiply - Multiplies two positive numbers represented as strings.
 * @num1: The first positive number as a string.
 * @num2: The second positive number as a string.
 *
 * Return: A newly allocated string containing the
 *         result of the multiplication.
 *         This result should be freed after use.
 */
char *multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len3 = len1 + len2;
	int *result, i, j, mul, sum;
	char *resultStr;

	result = calloc(len3, sizeof(int));

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];

			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}
	while (len3 > 0 && result[len3 - 1] == 0)
		len3--;

	resultStr = malloc(len3 + 1);
	for (i = 0; i < len3; i++)
		resultStr[i] = result[i] + '0';

	resultStr[len3] = '\0';
	free(result);
	return (resultStr);
}

/**
 * isNumeric - Checks if a string contains only digits.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int isNumeric(const char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (!_isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c : character to be checked
 * Return: 1 if is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
