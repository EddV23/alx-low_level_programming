#include "dog.h"
#include <stdio.h>

/**
 * print_dog - prints the name, age, and owner of the struct dog,
 *             if any element of the struct is NULL, it prints
 *             "(nil)" for that element.
 * @d: Pointer to the struct dog to print
 *
 * Return: void
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		printf("Age: %.6f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
