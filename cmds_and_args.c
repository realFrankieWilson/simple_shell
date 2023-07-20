#include "main.h"

/**
 * cmd_line -> commands and arguments that parses commands.
 * @lineptr: A pointer to the input string.
 * @size: A buffer for a number of size_t. always equals 0.
 * @cmd_ctr: A counter that keeps track of command entry to shell.
 * @av: The argument vectors of the shell.
 */

void cmd_line(char *lineptr, size_t size, int cmd_ctr, char **av)
{
	const char *delim = "\n\t ";
	char **buff_array;
	ssize_t nread;
	int token_count = 0, i;

	write(STDOUT_FILENO, PRMT, str_len(PRMT));
	nread = getline(&lineptr, &size, stdin);
	/*check for error */
	if (nread != -1)
	{
		buff_array = token_access(lineptr, delim, token_count);
		if (buff_array[0] == NULL)
		{
			free_once(2, buff_array, lineptr);
			return;
		}
		i = std_built_ins(buff_array, lineptr);
		if (i == -1)
			create_ppid(buff_array, lineptr, cmd_ctr, av);
		for (i = 0; buff_array[i] != NULL; i++)
			free(buff_array[i]);
		free_once(2, buff_array, lineptr);
	}
	else
		exit_shell(lineptr);
}


/**
 * create_ppid -> Creates a child process id, to execute program.
 * @lineptr: A pointer to the content of the read line
 * @buff_array: An array of pointers to strings containing the possible string
 * @cmd_ctr: Keeps tract of how manyy commands entered
 * @av: Arguments vector of the running shell
 */

void create_ppid(char **buff_array, char *lineptr, int cmd_ctr, char **av)
{
	char *cmd, *tmp_buf;
	struct stat buf;
	int update, i = 0;
	pid_t pi_d;

	pi_d = fork();
	if (pi_d == 0)
	{
		tmp_buf = buff_array[0];
		cmd = find_path_int(buff_array[0]);
		if (cmd == NULL)
		{
			/* look for file in current directory*/
			update = stat(tmp_buf, &buf);
			if (update == -1)
			{
				error_msg(av[0], cmd_ctr, tmp_buf);
				print_s(": not found ", 0);
				free_once(2, lineptr, tmp_buf);
				for (i = 1; buff_array[i]; i++)
					free(buff_array[i]);
				free(buff_array);
				exit(100);
			}
			/*file exist in cwd or has full path*/
			cmd = tmp_buf;
		}
		buff_array[0] = cmd;
		if (buff_array[0] != NULL)
		{
			if (execve(buff_array[0], buff_array, environ) == -1)
				exec_error(av[0], cmd_ctr, tmp_buf);
		}
	}
	else
		wait(&update);
}


/**
 * token_access -> Give access to other parts of the proram
 * and interact with them
 * @lineptr: string raw input
 * @delim: strings delimiters to tokenize line
 * @token_count: counts the idividual or splited tokesn
 *
 * Return: Nothing
 */

char **token_access(char *lineptr, const char *delim, int token_count)
{
	char **buff_array;

	token_count = count_token(lineptr, delim);
	if (token_count == -1)
	{
		free(lineptr);
		return (NULL);
	}
	buff_array = token_separator(token_count, lineptr, delim);
	if (buff_array == NULL)
	{
		free(lineptr);
		return (NULL);
	}
	return (buff_array);
}

/**
 * token_separator -> Separates a string into an array of tokens.
 * @token_count: An integer representing the amount of tokens in the array
 * @lineptr: separated string by delim
 * @delim: The desired delimeter to separate tokens
 *
 * Return: NULL terminited array of ptr to string on success.
 * otherwise returns NULL
 */

char **token_separator(int token_count, char *lineptr, const char *delim)
{
	char **buff_array, *token, *temp_line;
	int i;

	temp_line = str_dup(lineptr);
	buff_array = malloc(sizeof(char *) * (token_count + 1));
	if (buff_array == NULL)
		return (NULL);
	token = strtok(temp_line, delim);
	for (i = 0; token != NULL; i++)
	{
		buff_array[i] = str_dup(token);
		token = strtok(NULL, delim);
	}
	buff_array[i] = NULL;
	free(temp_line);
	return (buff_array);
}


/**
 * count_token -> Counts passed string.
 * @lineptr: String that are separated by special characters
 * @delim: The desired delimeter to separate tokens
 *
 * Return: total count of tokens
 * Otherwise: -1
 */

int count_token(char *lineptr, const char *delim)
{
	char *token, *strings = str_dup(lineptr);
	int i = 0;

	if (strings == NULL)
		return (-1);
	token = strtok(strings, delim);
	for (; token != NULL; i++)
		token = strtok(NULL, delim);
	free(strings);
	return (i);
}
