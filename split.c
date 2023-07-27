#include "main.h"
#include <string.h>

/**
 * swap_char - swaps | and & for non-printed chars
 * @in: input string
 * @bo: type of swap
 *
 * Return: swapped string
 */

char *swap_ch(char *in, int bo)
{
	int i;

	if (bo == 0)
	{
		for (i = 0; in[i]; i++)
		{
			if (in[i] == '|')
			{
				if (in[i + 1] != '|')
					in[i] = 16;
				else
					i++;
			}

			if (in[i] == '&')
			{
				if (in[i + 1] != '&')
					in[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; in[i]; i++)
		{
			in[i] = (in[i] == 16 ? '|' : in[i]);
			in[i] = (in[i] == 12 ? '&' : in[i]);
		}
	}
	return (in);
}

/**
 * add_nodes - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @in: input string
 * Return: no return
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *in)
{
	int i;
	char *line;

	in = swap_ch(in, 0);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == ';')
			add_sep_node_end(head_s, in[i]);

		if (in[i] == '|' || in[i] == '&')
		{
			add_sep_node_end(head_s, in[i]);
			i++;
		}
	}

	line = strtok(in, ";|&");
	do {
		line = swap_ch(line, 1);
		add_line_node_end(head_l, line);
		line = strtok(NULL, ";|&");
	} while (line != NULL);

}


/**
 * go_nxt - go to the next command line stored
 * @list_s: separator list
 * @list_l: command line list
 * @lineptr: data structure
 *
 * Return: no return
 */

void go_nxt(sep_list **list_s, line_list **list_l, shell_input *lineptr)
{
	int loop_sep = 1;
	sep_list *ls_s = *list_s;
	line_list *ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (lineptr->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_cmd - splits command lines according to
 * the separators ;, | and &, and executes them
 * @datash: data structure
 * @input: input string
 *
 * Return: 0 to exit, 1 to continue
 */

int split_cmd(shell_input *lineptr, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		lineptr->input = list_l->line;
		lineptr->args = split_line(lineptr->input);
		loop = exec_line(lineptr);
		free(lineptr->args);

		if (loop == 0)
			break;

		go_nxt(&list_s, &list_l, lineptr);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}



/**
 * split_line - tokenizes the input string
 *
 * @input: input string.
 * Return: string splitted.
 */

char **split_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
