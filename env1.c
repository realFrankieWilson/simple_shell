#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */

int cmp_env_name(const char *nenv, const char *name)
{
	int i = 0;

	for (; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env = NULL;
	int i, mov;

	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironment variables
 *
 * @lineptr: data relevant.
 * Return: 1 on success.
 */
int _env(shell_input *lineptr)
{
	int i = 0, j;

	for (; lineptr->_environ[i]; i++)
	{

		for (j = 0; lineptr->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, lineptr->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	lineptr->status = 0;

	return (1);
}




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
