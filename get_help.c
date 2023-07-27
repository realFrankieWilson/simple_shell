#include "main.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @lineptr: data structure (args and input)
 * Return: Return 0
*/
int get_help(shell_input *lineptr)
{

	if (lineptr->args[1] == 0)
		help_general();
	else if (str_cmp(lineptr->args[1], "setenv") == 0)
		help_setenv();
	else if (str_cmp(lineptr->args[1], "env") == 0)
		help_env();
	else if (str_cmp(lineptr->args[1], "unsetenv") == 0)
		help_unsetenv();
	else if (str_cmp(lineptr->args[1], "help") == 0)
		help();
	else if (str_cmp(lineptr->args[1], "exit") == 0)
		help_exit();
	else if (str_cmp(lineptr->args[1], "cd") == 0)
		help_cd();
	else if (str_cmp(lineptr->args[1], "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, lineptr->args[0],
		      str_len(lineptr->args[0]));

	lineptr->status = 0;
	return (1);
}
