#include <stdio.h>

/**
 * main - prints the alphabets in lowercase followed by a
 *        new line, excerpt q and e, using only the putchar
 *        function and only twice in the code
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declaration of lowercase alphabet variable*/
	char lower = 'a';

	while (lower <= 'z')
	{
		/*prints all lowercase letters except q and e*/
		if (lower != 'q' && lower != 'e')
			putchar(lower);
		lower++;
	}
	putchar('\n');
	return (0);
}
