#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int getLength(char *str);
void handleError(void);

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
	int length1, length2, totalLen, *res, tempSum;
	int i, nz, d1, d2;

	if (argc != 3)
		handleError();

	num1 = argv[1];
	num2 = argv[2];
	length1 = getLength(num1);
	length2 = getLength(num2);
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
			tempSum /= 10;
		}

		if (tempSum > 0)
			res[length1 + length2 + 1] += tempSum;
	}

	nz = 0;
	for (i = 0; i < totalLen - 1; i++)
	{
		if (res[i] != 0)
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

/**
 * getLength - Returns the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int getLength(char *str)
{
	int length = 0;

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
