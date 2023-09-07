#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiply(char *num1, char *num2);
int isNumeric(const char *str);

/**
 * main - Entry point of the program. Multiplies two positive numbers.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on successful execution, or 98 in case of an error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3 || !isNumeric(argv[1]) || !isNumeric(argv[2]))
	{
		printf("Error\n");
		return (98);
	}
	num1 = argv[1];
	num2 = argv[2];
	result = multiply(num1, num2);
	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}
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

	if (len1 == 0 || len2 == 0)
		return (NULL);

	result = calloc(len3, sizeof(int));

	if (result == NULL)
	{
		perror("Error");
		exit(98);
	}
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
	resultStr = malloc(len3 + 1);
	if (resultStr == NULL)
	{
		perror("Error");
		free(result);
		exit(98);
	}
	for (i = 0; i < len3; i++)
		resultStr[i] = result[i] + '0';

	resultStr[len3] = '\0';
	free(result);

	i = 0;
	while (resultStr[i] == '0' && resultStr[i + 1] != '\0')
		i++;
	return (&resultStr[i]);
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

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
