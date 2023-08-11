#include <stdio.h>

/**
 * main - prints the lowercase alphabets in reverse
 *        followed by a new line, using only the
 *        putchar function and only twice in the code
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of alphabet variable*/
	char alpha = 'z';

	while (alpha >= 'a')
	{
		putchar(alpha);
		alpha--;
	}
	putchar('\n');
	return (0);
}
