#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9)
 * @str : character to be checked
 * Return: 1 if is a digit, 0 otherwise
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * getLength - Returns the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int getLength(char *str)
{
	int length;

	for (length = 0; str[length] != '\0'; length++)
		;
	return (length);
}

/**
 * handleError - Handles errors and prints an error message
 * Return : void
 */
void handleError(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - Multiplies two positive numbers
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on successful execution, or 98 in case of an error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int length1, length2, totalLen, *res, tempSum, i, nz = 0, d1, d2;

	num1 = argv[1], num2 = argv[2];
	if (!_isdigit(num1) || !_isdigit(num2) || argc != 3)
		handleError();

	length1 = getLength(num1), length2 = getLength(num2);
	totalLen = length1 + length2 + 1;
	res = malloc(sizeof(int) * totalLen);
	if (!res)
		return (1);
	for (i = 0; i <= length1 + length2; i++)
		res[i] = 0;
	for (length1 = length1 - 1; length1 >= 0; length1--)
	{
		d1 = num1[length1] - '0';
		tempSum = 0;
		for (length2 = getLength(num2) - 1; length2 >= 0; length2--)
		{
			d2 = num2[length2] - '0';
			tempSum += res[length1 + length2 + 1] + (d1 * d2);
			res[length1 + length2 + 1] = tempSum % 10;
			tempSum = tempSum / 10;
		}
		if (tempSum > 0)
			res[length1 + length2 + 1] += tempSum;
	}
	for (i = 0; i < totalLen - 1; i++)
	{
		if (res[i])
			nz = 1;
		if (nz)
			_putchar(res[i] + '0');
	}
	if (!nz)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
