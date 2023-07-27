#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @lineptr: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(shell_input *lineptr)
{
	int (*builtin)(shell_input *lineptr);

	if (lineptr->args[0] == NULL)
		return (1);

	builtin = get_builtin(lineptr->args[0]);

	if (builtin != NULL)
		return (builtin(lineptr));

	return (cmd_exec(lineptr));
}
