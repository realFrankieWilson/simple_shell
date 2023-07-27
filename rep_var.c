#include "main.h"

/**
 * check_env -> checks if the typed variable is an env variable
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 *
 * Return: no return
 */

void check_env(r_var **h, char *in, shell_input *data)
{
	int row, chr, j, lval;
	char **envr;

	envr = data->_environ;
	for (row = 0; envr[row]; row++)
	{
		for (j = 1, chr = 0; envr[row][chr]; chr++)
		{
			if (envr[row][chr] == '=')
			{
				lval = str_len(envr[row] + chr + 1);
				add_rvar_node(h, j, envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}



/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */

int check_vars(r_var **h, char *in, char *st, shell_input *data)
{
	int i, lst = str_len(st);
	int lpd = str_len(data->pid);


	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - replaces string into variables
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 *
 * Return: replaced string
 */

char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}

			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}



/**
 * rep_var -> calls functions to replace string into vars
 * @input: input string
 * @lineptr: data structure
 *
 * Return: replaced string
 */

char *rep_var(char *input, shell_input *lineptr)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = ito_a(lineptr->status);
	head = NULL;

	olen = check_vars(&head, input, status, lineptr);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
