#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 * @lineptr: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @str: counter lines
 *
 * Return: error message
 */

char *strcat_cd(shell_input *lineptr, char *msg, char *error, char *str)
{
	char *red_flag;

	str_cpy(error, lineptr->av[0]);
	str_cat(error, ": ");
	str_cat(error, str);
	str_cat(error, ": ");
	str_cat(error, lineptr->args[0]);
	str_cat(error, msg);
	if (lineptr->args[1][0] == '-')
	{
		red_flag = malloc(3);
		red_flag[0] = '-';
		red_flag[1] = lineptr->args[1][1];
		red_flag[2] = '\0';
		str_cat(error, red_flag);
		free(red_flag);
	}
	else
	{
		str_cat(error, lineptr->args[1]);
	}

	str_cat(error, "\n");
	str_cat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @lineptr: data relevant (directory)
 *
 * Return: Error message
 */

char *error_get_cd(shell_input *lineptr)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = ito_a(lineptr->counter);
	if (lineptr->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = str_len(lineptr->args[1]);
	}

	length = str_len(lineptr->av[0]) + str_len(lineptr->args[0]);
	length += str_len(ver_str) + str_len(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(lineptr, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - generic error message for command not found
 * @lineptr: data relevant (counter, arguments)
 *
 * Return: Error message
 */

char *error_not_found(shell_input *lineptr)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = ito_a(lineptr->counter);
	length = str_len(lineptr->av[0]) + str_len(ver_str);
	length += str_len(lineptr->args[0]) + 16;
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
	str_cat(error, ": not found\n");
	str_cat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @lineptr: data relevant (counter, arguments)
 *
 * Return: Error message
 */

char *error_exit_shell(shell_input *lineptr)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = ito_a(lineptr->counter);
	length = str_len(lineptr->av[0]) + str_len(ver_str);
	length += str_len(lineptr->args[0]) + str_len(lineptr->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	str_cpy(error, lineptr->av[0]);
	str_cat(error, ": ");
	str_cat(error, ver_str);
	str_cat(error, ": ");
	str_cat(error, lineptr->args[0]);
	str_cat(error, ": Illegal number: ");
	str_cat(error, lineptr->args[1]);
	str_cat(error, "\n\0");
	free(ver_str);

	return (error);
}

