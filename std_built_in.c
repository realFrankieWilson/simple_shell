#include "main.h"

/**
 * std_built_ins -> interact with builtin functions.
 * @av: Array of arguments passed to the shell.
 * @usr_in: String representing the user input
 *
 * Return: 0 on success. Otherwise -1.
 */

int std_built_ins(char **av, char *usr_in)
{
	void (*create)(char *);

	create = check_create(av[0]);
	if (create == NULL)
		return (-1);
	if (str_cmp("exit", av[0]) == 0)
		free_twice(av);
	create(usr_in);
	return (0);
}


/**
 * exit_shell -> Exits the shell. After allocated resouces.
 * @usr_in: A string from user input.
 *
 * Return: Nothin.
 */

void exit_shell(char *usr_in)
{
	free(usr_in);
	print_s("\n", 1);
	exit(1);
}


/**
* check_builtin -> Finds the right function needed for execution.
* @name_fun: Name of the function that is needed.
*
* Return: pointer on success. Otherwise NULL.
*/

void (*check_builtin(char *name_fun))(char *name_fun)
{
	int i = 0;

	built_t choice_exec[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{"cd", cd_shell},
		{NULL, NULL}
	};

	for (; choice_exec[i].execute != NULL; i++)
	{
		if (str_cmp(name_fun, choice_exec[i].execute) == 0)
			return (choice_exec[i].f);
	}
	return (NULL);
}


/**
 * env_shell -> Prints all the environmental variables in the current shell.
 * @lineptr: pointer to a string representing the user input.
 *
 * Return: Nothing
 */

void env_shell(__attribute__((__unused__))char *lineptr)
{
	int i, j = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != TRM; j++)
			write(STDOUT_FILENO, TRM, 1);
	}
}


/**
 * cd_shell -> Changes the current working directory to the parameter passed
 * to cd.
 * @lineptr: A string representing the user input
 *
 * Return: HOME directory if no parameter is passed.
 */

void cd_shell(char *lineptr)
{
	int tk_cnt = 0, i;
	char **arv;
	const char *delim = "\n\t ";

	arv = token_access(lineptr, delim, tk_cnt);
	if (arv[0] == NULL)
	{
		single_free(2, arv, lineptr);
		return;
	}
	else if (arv[1] == NULL)
	{
		i = find_path("HOME");
		chdir((environ[i]) + 5);
	}
	else if (str_cmp(arv[1], "-") == 0)
		print_s(arv[1], 0);
	else
		chdir(arv[1]);
	free_twice(arv);
}
