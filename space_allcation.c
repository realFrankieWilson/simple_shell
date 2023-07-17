#include "main.h"
/**
 * spc_allocation -> allocates space for arguments
 * @v: arguments vector.
 * @s: the splited string
 *
 * Return: Nothing
 */

void spc_allocation(char **v, char *s)
{
	int i;

	for (i = 0; s != NULL; i++)
	{
		v[i] = malloc(sizeof(char) * strlen(s));
		strcpy(v[i], s);
		s = strtok(NULL, "\n");
	}
	v[i] = NULL;
}
