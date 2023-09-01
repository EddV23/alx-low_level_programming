#include <stdio.h>

/**
 * main - prints the number of arguments passed into the program,
 *        followed by a new line
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/*acknowledges that the parameter argv is unused*/
	(void)argv;

	if (argc > 0)
		printf("%d\n", argc - 1);
	return (0);
	/*
	*if (argv[0])
	*	printf("%d\n", argc - 1);
	*return (0);
	*/
}
