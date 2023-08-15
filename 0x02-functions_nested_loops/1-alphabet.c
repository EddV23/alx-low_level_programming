#include "main.h"

/**
 * print_alphabet - prints the alphabets in lowercase followed
 *                  by a new line, using only _putchar function
 *                  and only twice in the code
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	/*declaration of alphabet variable*/
	char alpha = 'a';

	while (alpha <= 'z')
	{
		_putchar(alpha);
		alpha++;
	}
	_putchar('\n');
}
