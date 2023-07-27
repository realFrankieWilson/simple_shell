#include "main.h"

/**
 * str_dup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 *
 * Return: duplicated str
 */

char *str_dup(const char *s)
{
	char *new;
	size_t len;


	len = str_len(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	mem_cpy(new, s, len + 1);
	return (new);
}


/**
 * str_len - Returns the lenght of a string.
 * @s: Type char pointer
 *
 * Return: Always 0.
 */

int str_len(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
		;

	return (len);
}



/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}


/**
 * is_digit - defines if string passed is a number
 * @s: input string
 *
 * Return: 1 if string is a number. 0 in other case
 */

int is_digit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}




/**
 * rev_string - reverses a string.
 * @s: input string
 *
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;


	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
