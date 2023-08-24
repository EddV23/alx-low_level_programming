#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b : the buffer to be printed
 * @size : the size in bytes of the buffer
 * Return:  void
 */
void print_buffer(char *b, int size)
{
	int i, j, k;

	for (i = 0; i <= (size - 1) / 10 && size; i++)
	{
		printf("%08x: ", i * 10);
		for (j = 0; j <= 9; j++)
		{
			if (j <= (i < size / 10 ? 9 : size % 10 - 1))
				printf("%02x", (unsigned int)(unsigned char)b[i * 10 + j]);
			else
				printf("  ");
			if (j % 2)
				putchar(' ');
		}
		for (k = 0; k <= (i < size / 10 ? 9 : size % 10 - 1); k++)
		{
			if (b[i * 10 + k] > 31 && b[i * 10 + k] < 127)
				putchar(b[i * 10 + k]);
			else
				putchar('.');
		}
		putchar('\n');
	}
	if (size == 0)
		putchar('\n');
}
