#include "main.h"

/**
 * exec_fn -> executes commands passed by the user.
 * @av: arguments vectors from the user.
 *
 * Return: a void ptr.
 */

void exec_fn(char **av)
{
	char *cmd = NULL;

	if (av)
	{
		cmd = av[0];
		if (execve(cmd, av, NULL) == -1)
			perror("Error: ");
	}
}
