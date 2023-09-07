#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		{
			return (0);
		}
	}
	return (1);
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
char *multiply(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int lenResult = len1 + len2;
	int *result = calloc(lenResult, sizeof(int));
	int i, j, product, sum;
	char *resultStr;

	if (result == NULL)
	{
		perror("Error");
		exit(98);
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0');
			sum = product + result[i + j + 1];
			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}
	resultStr = malloc(lenResult + 1);
	if (resultStr == NULL)
	{
		perror("Error");
		free(result);
		exit(98);
	}
	for (i = 0; i < lenResult; i++)
		resultStr[i] = result[i] + '0';
	resultStr[lenResult] = '\0';
	free(result);

	i = 0;
	while (resultStr[i] == '0' && resultStr[i + 1] != '\0')
	i++;
	return (&resultStr[i]);
}

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

	printf("%s\n", result);

	free(result);

	return (0);
}
