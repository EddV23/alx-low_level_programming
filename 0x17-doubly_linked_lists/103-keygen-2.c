#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * encode - Encodes a given name into a password
 * @user: The username
 *
 * Return: The encoded password
 */
char *encode(char *user)
{
	long str[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f,	0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850
	};
	char *key = malloc(sizeof(char) * 7);
	int len = strlen(user);
	int i, first, second = 0, third = 1, fourth, fifth = 0, sixth = 0;

	first = (len ^ 0x3b) & 0x3f;
	for (i = 0; i < len; i++)
		second += user[i];
	second = (second ^ 0x4f) & 0x3f;
	for (i = 0; i < len; i++)
		third *= user[i];
	third = (third ^ 0x55) & 0x3f;
	fourth = user[0];
	for (i = 0; i < len; i++)
	{
		if (user[i] > fourth)
			fourth = user[i];
	}
	srand(fourth ^ 0xe);
	fourth = (rand() & 0x3f);
	for (i = 0; i < len; i++)
		fifth += user[i] * user[i];
	fifth = (fifth ^ 0xef) & 0x3f;
	for (i = 0; user[0] > i; i++)
		sixth = rand();
	sixth = (sixth ^ 0xe5) & 0x3f;

	key[0] = ((char *)str)[first];
	key[1] = ((char *)str)[second];
	key[2] = ((char *)str)[third];
	key[3] = ((char *)str)[fourth];
	key[4] = ((char *)str)[fifth];
	key[5] = ((char *)str)[sixth];
	key[6] = 0;

	return (key);
}

/**
 * main - Entry point of the crackme program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *key;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	key = encode(argv[1]);
	printf("%s", key);
	free(key);

	return (0);
}
