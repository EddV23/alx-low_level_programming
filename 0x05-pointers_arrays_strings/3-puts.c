#include "main.h"

/**
 * _puts  - prints a string, followed by a new line to stdout
 * @str : input string to be printed
 * Return: void
 */
void _puts(char *str)
{
	int i;

	/**
	*for (i = 0; str[i] != '\0'; i++)
	*	_putchar(str[i]);
	*/
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
