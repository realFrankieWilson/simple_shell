#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @lineptr: data relevant (counter, arguments)
 *
 * Return: error message.
 */

char *error_env(shell_input *lineptr)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = ito_a(lineptr->counter);
	msg = ": Unable to add/remove from environment\n";
	length = str_len(lineptr->av[0]) + str_len(ver_str);
	length += str_len(lineptr->args[0]) + str_len(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	str_cpy(error, lineptr->av[0]);
	str_cat(error, ": ");
	str_cat(error, ver_str);
	str_cat(error, ": ");
	str_cat(error, lineptr->args[0]);
	str_cat(error, msg);
	str_cat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @lineptr: data relevant (counter, arguments).
 *
 * Return: The error string.
 */

char *error_path_126(shell_input *lineptr)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = ito_a(lineptr->counter);
	length = str_len(lineptr->av[0]) + str_len(ver_str);
	length += str_len(lineptr->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	str_cpy(error, lineptr->av[0]);
	str_cat(error, ": ");
	str_cat(error, ver_str);
	str_cat(error, ": ");
	str_cat(error, lineptr->args[0]);
	str_cat(error, ": Permission denied\n");
	str_cat(error, "\0");
	free(ver_str);
	return (error);
}



/**
* free_data -> frees data struct.
* @lineptr: line struct.
*
* Return: Nothing.
*/

void free_data(shell_input *lineptr)
{
	unsigned int i = 0;

	for (; lineptr->_environ[i]; i++)
		free(lineptr->_environ[i]);

	free(lineptr->_environ);
	free(lineptr->pid);
}


/**
* set_data -> Initialize data struct.
* @lineptr: line data struct.
* @av: argument vector.
*
* Return: Nothing.
*/

void set_data(shell_input *lineptr, char **av)
{
	unsigned int i;

	lineptr->av = av;
	lineptr->input = NULL;
	lineptr->args = NULL;
	lineptr->status = 0;
	lineptr->counter = 1;

	i = 0;

	for (; environ[i]; i++)
		;
	lineptr->_environ = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
		lineptr->_environ[i] = str_dup(environ[i]);
	lineptr->_environ[i] = NULL;
	lineptr->pid = ito_a(getpid());
<<<<<<< HEAD
}
=======
}
>>>>>>> update
