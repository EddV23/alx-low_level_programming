#include "main.h"

/**
 * puts2 - prints every other character of a string,
 *           starting with the first character,
 *           followed by a new line
 * @str : input string to be printed
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	/**
	*for (i = 0; str[i] != '\0'; i++)
	*	_putchar(str[i]);
	*	i += 2;
	*/
	while (*str != '\0')
	{
		if (i % 2 == 0)
			_putchar(*str);
		i++;
		str++;
	}
	_putchar('\n');
}
