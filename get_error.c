#include "main.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @lineptr: data structure that contains arguments
 * @eval: error value
<<<<<<< HEAD
 *
=======
 * 
>>>>>>> update
 * Return: error
 */
int get_error(shell_input *lineptr, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(lineptr);
		break;
	case 126:
		error = error_path_126(lineptr);
		break;
	case 127:
		error = error_not_found(lineptr);
		break;
	case 2:
		if (str_cmp("exit", lineptr->args[0]) == 0)
			error = error_exit_shell(lineptr);
		else if (str_cmp("cd", lineptr->args[0]) == 0)
			error = error_get_cd(lineptr);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, str_len(error));
		free(error);
	}

	lineptr->status = eval;
	return (eval);
}
