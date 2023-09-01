#include <stdio.h>

/**
 * main - prints all command-line arguments, including the
 *        first one or program name, one argument per line
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	while (argc--)
		printf("%s\n", *argv++);
	return (0);
	/*
	 *int i;
	 *
	 *for (i = 0; i < argc; i++)
	 *	printf("%s\n", argv[i]);
	 *return (0);
	 */
}
