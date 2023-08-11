#include <stdio.h>

/**
 * main - prints all possible different combinatioins of
 *        two digits, separated by a , and a space
 *        and in ascending order, using putchar
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of two digits variables*/
	int i;
	int j;

	for (i = 0; i <= 8; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
			putchar(i + '0');
			putchar(j + '0');
			if (i != 8 || j != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
