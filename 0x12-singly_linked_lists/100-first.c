#include <stdio.h>

/**
 * first - Function executed before main
 * It prints the required message
 * Return: void
 */
void first(void) __attribute__((constructor));

/**
 * first - Constructor function.
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
