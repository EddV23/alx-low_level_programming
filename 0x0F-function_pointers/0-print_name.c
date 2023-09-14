#include "function_pointers.h"

/**
 * print_name - prints a name using a given printing function
 * @name: name of the person
 * @f: pointer to the printing function
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
