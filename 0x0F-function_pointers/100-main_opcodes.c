#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 if arguments are incorrect,
 *         2 if num_bytes is negative
 */
int main(int argc, char *argv[])
{
	int i, num_bytes;
	char *main_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	main_ptr = (char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx", main_ptr[i]);
		if (i < num_bytes - 1)
			printf(" ");
	}

	printf("\n");

	return (0);
}
