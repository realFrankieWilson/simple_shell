#include "main.h"

/**
* cpy_info -> copies info to create a new env or alias.
* @name: name of env or alias
* @value: value of the env, or alias.
*
* Return: new env or alias.
*/

char *cpy_info(char *name, char *value)
{
	int len_n = str_len(name), len_v = str_len(value), len = len_n + len_v + 2;
	char *tmp = malloc(sizeof(char) * (len));

	str_cpy(tmp, name);
	str_cat(tmp, "=");
	str_cat(tmp, value);
	str_cat(tmp, "\0");
	return (tmp);
}


/**
* set_env -> sets an environment variable.
* @name: name of the environment variable.
* @value: value of the environment variable.
* @lineptr: input from the user.
*
* Return: Nothing.
*/

void set_env(char *name, char *value, shell_input *lineptr)
{
	char *v_env, *n_env;
	int i = 0;

	for (; lineptr->_environ[i]; i++)
	{
		v_env = str_dup(lineptr->_environ[i]);
		n_env = strtok(v_env, "=");
		if (str_cmp(n_env, name) == 0)
		{
			free(lineptr->_environ[i]);
			lineptr->_environ[i] = cpy_info(n_env, value);
			free(v_env);
			return;
		}
		free(v_env);
	}
	lineptr->_environ = rea_llocdp(lineptr->_environ, i, sizeof(char *) *
			(i + 2));
	lineptr->_environ[i] = cpy_info(name, value);
	lineptr->_environ[i + 1] = NULL;
}



/**
 * _setenv - compares env variables names
 * with the name passed.
 * @lineptr: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */

int _setenv(shell_input *lineptr)
{

	if (lineptr->args[1] == NULL || lineptr->args[2] == NULL)
	{
		get_error(lineptr, -1);
		return (1);
	}

	set_env(lineptr->args[1], lineptr->args[2], lineptr);

	return (1);
}


/**
 * _unsetenv - deletes a environment variable
 * @lineptr: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(shell_input *lineptr)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (lineptr->args[1] == NULL)
	{
		get_error(lineptr, -1);
		return (1);
	}
	k = -1;
	for (i = 0; lineptr->_environ[i]; i++)
	{
		var_env = str_dup(lineptr->_environ[i]);
		name_env = strtok(var_env, "=");
		if (str_cmp(name_env, lineptr->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(lineptr, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; lineptr->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = lineptr->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(lineptr->_environ[k]);
	free(lineptr->_environ);
	lineptr->_environ = realloc_environ;
	return (1);
}
