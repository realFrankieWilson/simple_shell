#include "main.h"

/**
 * del_cmnt -> deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */

char *del_cmnt(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = rea_lloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}



/**
 * shell_loop - Loop of shell
 * @lineptr: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(shell_input *lineptr)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, PROMPT, 3);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = del_cmnt(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(lineptr, input) == 1)
			{
				lineptr->status = 2;
				free(input);
				continue;
			}

			input = rep_var(input, lineptr);
			loop = split_cmd(lineptr, input);
			lineptr->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
