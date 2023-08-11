#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase
 *        using the putchar function followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of numeric and alphabet variables*/
	char num;
	char alpha;

	for (num = 0; num < 10; num++)
		putchar(num + '0');
	for (alpha = 'a'; alpha < 'g'; alpha++)
		putchar(alpha);
	putchar('\n');
	return (0);
}
