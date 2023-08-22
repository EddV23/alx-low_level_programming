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
	int password = 0;
	time_t t;

	srand((unsigned int) time(&t));
	while (password < 2772)
	{
		i = rand() % 128;
		if ((i + password) > 2772)
			break;
		password = password + i;
		printf("%c", i);
	}
	printf("%c\n", (2772 - password));
	return (0);
}
