#include "main.h"

/**
 * putchar_ -> writes a single character to stdout.
 * @c: characters to b writen out
 *
 * Return: Number of characters writen.
 */

int putchar_(char c)
{
	return (write(1, &c, 1));
}

/**
 * str_cmp -> compares two strings
 * @str1: First string
 * @str2: second string
 *
 * Return: -1 on falure, otherwise 0
 */

int str_cmp(char *str1, char *str2)
{
	int i = 0;

	if (str_len(str1) != str_len(str2))
		return (-1);
	for (; str1[i] != TRM; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}

/**
 * str_dup -> make a duplicate of a string
 * @org: The original string
 *
 * Return: copied stiring.
 */

char *str_dup(char *org)
{
	char *dest;
	int len, i = 0;

	len = str_len(org);
	dest = malloc(sizeof(char) * (len + 1));

	for (; org[i] != TRM; i++)
		dest[i] = org[i];
	dest[i] = TRM;
	return (dest);
}

/**
 * print_str -> prints a string character by character.
 * @str: string to be printed.
 * @new_l: prints a new line
 *
 * Return: prints null if no string is printed.
 */

void print_str(char *str, int new_l)
{
	int i = 0;

	if (str != NULL)
	{
		for (; str[i] != TRM; i++)
			write(STDOUT_FILENO, &str[i], 1);
		if (new_l == 0)
			write(STDOUT_FILENO, "\n", 1);
	}
	else
		str = "(null)";
}


/**
* print_num -> Prints an unsigned number
* @n: unsigned int to be printed
*
* Return: number of numpers printed
*/

int print_num(int n)
{
	unsigned int num = n;
	int len = 0, slash = 1;

	for (; num / slash; )
	{
		len += putchar_('0' + num / slash);
		num %= slash;
		slash /= 10;
	}
	return (len);
}
