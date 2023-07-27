#include "main.h"

/**
 * help - Help information for the builtin help
 *
 * Return: no return
 */

void help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, str_len(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, str_len(help));
}


/**
 * help_alias - Help information for the builtin alias
 *
 * Return: no return
 */

void help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, str_len(help));
}


/**
 * help_cd - Help information for the builtin alias
 *
 * Return: no return
 */

void help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, str_len(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, str_len(help));
}
