#include "main.h"

/**
 * str_cat -> concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 *
 * Return: the dest
 */

char *str_cat(char *dest, const char *src)
{
	int i = 0, j;

	for (; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}



/**
 * *str_cpy -> Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 *
 * Return: the dest.
 */

char *str_cpy(char *dest, char *src)
{

	size_t a = 0;

	for (; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}


/**
 * str_cmp -> Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 *
 * Return: Always 0.
 */

int str_cmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
