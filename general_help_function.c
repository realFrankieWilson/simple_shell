#include "main.h"

/**
* str_len -> Calculates the length of a string.
* @str: String that needs length to be found.
*
* Return: length of a string. Otherwise return 0.
*/

int str_len(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != TRM; i++)
		;
	return (i);
}


/**
* twice_free -> Free double pointer variables.
* @ptr: The address of the element to be freed.
* Return: 0;
*/

void twice_free(char **ptr)
{
	int i = 0;

	for (; ptr[i] != NULL; i++)
		free(ptr[i]);
	free(ptr);
}
