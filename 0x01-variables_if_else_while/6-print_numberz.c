#include <stdio.h>

/**
 * main - prints all single digit numbers of base 10
 *        starting from 0, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of single digits variable*/
	int num = 0;

	while (num < 10)
	{
		putchar(num + '0');
		num++;
	}
	putchar('\n');
	return (0);
}
