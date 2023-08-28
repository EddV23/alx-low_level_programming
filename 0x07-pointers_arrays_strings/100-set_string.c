#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: pointer to a pointer that will be updated
 * @to: string to set the pointer to
 */
void set_string(char **s, char *to)
{
	*s = to;
}
