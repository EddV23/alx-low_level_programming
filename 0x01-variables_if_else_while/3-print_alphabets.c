#include <stdio.h>

/**
 * main - prints the alphabets in lowercase, and then in
 *        uppercase, followed by a new line, using only
 *        the putchar function and only thrice in the code
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of lowercase and uppercase alphabet variables*/
	char lower = 'a';
	char upper = 'A';

	while (lower <= 'z')
	{
		putchar(lower);
		lower++;
	}
	while (upper <= 'Z')
	{
		putchar(upper);
		upper++;
	}
	putchar('\n');
	return (0);
}
