#include "main.h"

/**
* str_len -> Calculates the length of a string.
* @str: String that needs length to be found.
*
* Return: length of a string. Otherwise return 0.
*/

int str_len(char *str)
{
	int i = 0;

	if (str != NULL)
	{
		for (; str[i] != TRM; i++)
			;
		return (i);
	}
	else
		return (0);
}


/**
* double_free -> Free double pointer variables.
* @ptr: The address of the element to be freed.
* Return: 0;
*/

void double_free(char **ptr)
{
	int i = 0;

	for (; ptr[i] != NULL; i++)
		free(ptr[i]);
	free(ptr);
}