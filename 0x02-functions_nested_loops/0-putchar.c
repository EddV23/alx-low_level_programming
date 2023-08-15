#include "main.h"

/**
 * main - prints _putchar, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/*declares variable of the word to be printed*/
	char word[] = "_putchar";
	int i = 0;

	for (i = 0; word[i] != '\0'; i++)
		_putchar(word[i]);
	_putchar('\n');
	return (0);
}
