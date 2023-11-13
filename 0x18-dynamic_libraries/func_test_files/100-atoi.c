#include "main.h"

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
