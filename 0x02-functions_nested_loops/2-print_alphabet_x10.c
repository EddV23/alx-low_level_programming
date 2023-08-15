#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabets, in lowercase,
 *                      followed by new line, using only _putchar
 *                      function and only twice in the code
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	/*declaration of alphabet variable*/
	char alpha = 'a';
	int i = 0;

	while (i < 10)
	{
		for (alpha = 'a'; alpha <= 'z'; alpha++)
			_putchar(alpha);
		_putchar('\n');
		i++;
	}
}
