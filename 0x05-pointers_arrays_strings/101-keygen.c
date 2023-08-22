#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme
 *
 * Return: (0) Always Success
 */

int main(void)
{
	int i = 0;
	int key = 0;
	time_t t;

	srand((unsigned int)time(&t));
	while (key < 2772)
	{
		i = rand() % 128;
		if ((key + i) > 2772)
			break;
		key = key + i;
		printf("%c", i);
	}
	printf("%c\n", (2772 - key));
	return (0);
}
