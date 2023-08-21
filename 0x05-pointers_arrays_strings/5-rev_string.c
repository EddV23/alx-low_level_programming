#include "main.h"

/**
 * rev_string  - reverses a string
 * @s : input string to be reversed
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0;
	int start = 0; /*char *start = s;*/
	int end; /*char end;*/
	char temp;

	while (s[i] != '\0')
		i++;
	end = i - 1; /*end = s + i - 1;*/
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}
