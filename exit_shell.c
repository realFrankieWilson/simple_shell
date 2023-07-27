#include "main.h"

/**
 * exit_shell - exits the shell
 * @lineptr: data relevant (status and args)
 *
 * Return: 0 on success.
 */

int exit_shell(shell_input *lineptr)
{
	unsigned int ustatus;
	int digit;
	int str_l;
	int big_number;

	if (lineptr->args[1] != NULL)
	{
		ustatus = ato_i(lineptr->args[1]);
		digit = is_digit(lineptr->args[1]);
		str_l = str_len(lineptr->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!digit || str_l > 10 || big_number)
		{
			get_error(lineptr, 2);
			lineptr->status = 2;
			return (1);
		}
		lineptr->status = (ustatus % 256);
	}
	return (0);
}
