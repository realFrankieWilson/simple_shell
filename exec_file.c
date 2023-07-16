#include "main.h"

/**
 * exec_fn -> executes commands passed by the user
 * @av: arguments vectors from the user.
 * 
 * Return: a void pointer
 */
void exec_fn(char **av)
{
	char *cmd = NULL;

    if (av)
    {
        /* get the command */
        cmd = av[0];

        /* execution with the execv functin */
        if (execve(cmd, av, NULL) == -1)
            perror("Error: ");
    }
}
