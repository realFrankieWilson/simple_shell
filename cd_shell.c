#include "main.h"

/**
 * cd_shell - changes current directory
 * @lineptr: data relevant
 *
 * Return: 1 on success
 */

int cd_shell(shell_input *lineptr)
{
	int ishome, ishome2, isddash;
	char *dir = lineptr->args[1];

	if (dir != NULL)
	{
		ishome = str_cmp("$HOME", dir);
		ishome2 = str_cmp("~", dir);
		isddash = str_cmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(lineptr);
		return (1);
	}

	if (str_cmp("-", dir) == 0)
	{
		cd_previous(lineptr);
		return (1);
	}

	if (str_cmp(".", dir) == 0 || str_cmp("..", dir) == 0)
	{
		cd_dot(lineptr);
		return (1);
	}

	cd_to(lineptr);

	return (1);
}
