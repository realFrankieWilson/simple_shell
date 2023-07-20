#include "main.h"
/**
 * free_once - frees an amount of pointers
 * to a string
 * @n: the number of pointers to free
 * Return: Nothing
 */
void free_once(int n, ...)
{
	va_list first_list;
	char *str;
	int i = 0;

	va_start(first_list, n);
	for (; i < n; i++)
	{
		str = va_arg(first_list, char *);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(first_list);
}
/**
 * error_msg - prints a message error when a command
 * is not found
 * @av: The name of the program running the shell
 * @cmd: unfound command
 * @cmd_count: counter that keeps track of the command
 * run on the shell
 * Return: Nothing
 */
void error_msg(char *av, int cmd_count, char *cmd)
{
	print_s(av, 1);
	print_s(": ", 1);
	print_num(cmd_count);
	print_s(": ", 1);
	print_s(cmd, 1);
}
/**
 * exec_error - prints executed errors
 * @av: The name of the program running the shell
 * @cmd_count: Keeps track of the number of commands
 * @tmp_cmd: The command that failed
 */
void exec_error(char *av, int cmd_count, char *tmp_cmd)
{
	error_msg(av, cmd_count, tmp_cmd);
	print_s(": ", 1);
	perror("");
	exit(1);
}
