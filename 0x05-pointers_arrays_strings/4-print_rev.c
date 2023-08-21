#include "main.h"

/**
 * print_rev  - prints a string, in reverse, followed
 *               by a new line to stdout
 * @str : input string to be printed
 * Return: void
 */
void print_rev(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		;/*trailing statements always on next line*/
	for (i = i - 1; i >= 0; i--)
		_putchar(str[i]);
	/**
	*while (str[i] != '\0')
	*	i++;
	*while (i >= 0)
	*{
	*	_putchar(str[i]);
	*	i--;
	*}
	*/
	_putchar('\n');
}
