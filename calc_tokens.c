#include "main.h"
/**
 * calc -> calculate string tokens
 * @s: string to be calculated.
 *
 * Return: void
 */

void calc(char *s)
{
	int split_tokens;

	while (s != NULL)
	{
		split_tokens++;
		s = strtok(NULL, "\n");
	}
	split_tokens++;
}
