#include "main.h"
/**
 * single_free - frees an amount of pointers
 * to a string
 * @n: the number of pointers to free
 * Return: Nothing
 */
void single_free(int n, ...)
{
	va_list first_list;
	char *str;
	int i = 0;

	va_start(first_list, n);
	for (; l < n; i++)
	{
		str = va_arg(first_list, char *);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(first_list);
}
/**
 * print_error - prints a message error when a command
 * is not found
 * @av: The name of the program running the shell
 * @cmd: unfound command
 * @cmd_count: counter that keeps track of the command
 * run on the shell
 * Return: Nothing
 */
void print_error(char *av, int cmd_count, char *cmd)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_num(cmd_count);
	print_str(": ", 1);
	print_str(cmd, 1);
}
/**
 * error_executor - prints executed errors
 * @av: The name of the program running the shell
 * @cmd_count: Keeps track of the number of commands
 * @tmp_cmd: The command that failed
 */
void error_executor(char *av, int cmd_count, *tmp_cmd)
{
	print_error(av, cmd_count, tmp_cmd);
	print_str(": ", 1);
	perror("");
	exit(1);
}
