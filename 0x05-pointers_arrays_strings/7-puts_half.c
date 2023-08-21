#include "main.h"

/**
 * puts_half - prints the second half of a string,
 *             followed by a new line
 * @str : input string to be printed
 * Return: void
 */
void puts_half(char *str)
{
	int i = 0;
	int half = 0;

	/**
	*for (i = 0; str[i] != '\0'; i++)
	*	_putchar(str[i]);
	*	i += 2;
	*/
	while (str[i] != '\0')
		i++;
	half = i / 2;
	while (str[half] != '\0')
	{
		_putchar(str[half]);
		half++;
	}
	_putchar('\n');
}
