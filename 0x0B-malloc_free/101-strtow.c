#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * is_space - checks if a character is a space
 * @c: the character to check
 *
 * Return: 1 if it's a space, 0 otherwise
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * word_count - counts the number of words in a string
 * @str: the input string
 *
 * Return: The number of words
 */
int word_count(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (is_space(*str))
		{
			if (in_word)
			{
				in_word = 0;
			}
		}
		else
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		str++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the input string
 *
 * Return: A pointer to an array of strings containing words,
 *         or NULL if str is NULL, str is empty, or if it fails
 */
char **strtow(char *str)
{
	int wc, i, j, word_len;
	char **words, *start;

	if (str == NULL || *str == '\0')
		return (NULL);
	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (*str)
		{
			start = str;
			while (*str && !is_space(*str))
				str++;

			word_len = str - start;
			words[i] = malloc(word_len + 1);
			if (words[i] == NULL)
			{
				for (j = 0; j < i; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			strncpy(words[i], start, word_len);
			words[i][word_len] = '\0';
			i++;
		}
	}
	words[i] = NULL;
	return (words);
}
