#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme
 *
 * Return: (0) Always Success
 */
#define PASSWORD_LENGTH 59

int main(void)
{
	char password[PASSWORD_LENGTH + 1];

	srand(time(NULL));
	for (int i = 0; i < PASSWORD_LENGTH; i++)
		password[i] = rand() % 94 + 33;
	password[PASSWORD_LENGTH] = '\0';
	printf("%s\n", password);
	return (0);
}
