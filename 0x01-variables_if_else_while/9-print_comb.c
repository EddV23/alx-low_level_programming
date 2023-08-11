#include <stdio.h>

/**
 * main - prints all possible single digit numbers
 *        combinations, separated by a , and a space
 *        and in ascending order, using putchare
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
		if (num != 9)
		{
			putchar(',');
			putchar(' ');
		}
		num++;
	}
	putchar('\n');
	return (0);
}
