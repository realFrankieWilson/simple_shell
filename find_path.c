/**
* find_path_int-> Acts as an interface for functions that will be to find
* find the full path of a program.
* @cmd: Represents a command.
*
*Return: Upon success a full path of the executable program
*/

char *find_path_int(char *cmd)
{
	char **path_token, *direct, cnst, *str = "PATH";
	int i;

	i = find_path_ind(str);
	path_token = tokenized_pa(i, str);
	if (path_token == NULL)
		return (NULL);

	direct = direct_search(path_token, cmd);
	if (direct == NULL)
	{
		double_free(path_token);
		return (NULL);
	}

	cnst = build_path(direct, cmd);
	if (cnst == NULL)
	{
		double_free(path_token);
		return (NULL);
	}

	double_free(path_token);
	return (cnst);
}


/**
* find_path_index -> Finds the index of an environmental variable.
* @env: Environmental vairable that needs to be found.
*
* Return: Index of the environmental variable. Otherwise -1.
*/

int find_path_index(char *env)
{
	int j, len, i = 0;

	len = str_len(env);
	for (; environ[i] != NULL; i++)
	{
		for (j = 0, j < len; j++)
		{
			if (environ[i][j] != env[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}


/**
* str_separator-> Separates a string representing paths as an array
* of strings containing the path directories.
* @i: Index of the path in the environment vairables.
* @str: string to separate and tokenize.
*
* Return: Null terminated array pointer to strings on Success.
* Otherwise Null.
*/

char **str_separator(int i, char *str)
{
	int len, counter = 0;
	char **path_token, char *en_var;
	const char *delim = ":\n";

	len = str_len(str);
	/* moving the ptr len of string plus = sign*/
	en_var = environ[i] + (len++);
	path_token = token_access(en_var, delim, counter);
	if (path_token == NULL)
		return (NULL);
	return (path_token);
}


/**
* search_direct -> Looks through directories stored in path_tokens
* for specified cmd.
* @str_ptr: A pointer to an array of strings representing the different path
* contained in the PATH environment variable.
* @cmd: Represents a command.
*
* Return: String with UPPER directly containing the command file.
* otherwise: Return null
*/

char *search_direct(char **str_ptr, char *cmd)
{
	struct stat stat_buf;
	size_t size = 0;
	char *buf = NULL, wdchar;
	int i, j;

	/* Read wide characters from stdin */
	wdchar = getcwd(buf, size);
	if (wdchar == NULL)
		return (NULL);
	if (cmd[0] == '/')
		cmd = cmd + 1;
	for (i = 0; str_ptr[i] != NULL; i++)
	{
		j = chdir(str_ptr[i]);
		if (j == -1)
		{
			perror("Error!");
			return (NULL);
		}
		j = stat(cmd, &stat_buf);
		if (j == 0)
		{
			chdir(wdchar);
			free(wdchar);
			return (str_ptr[i]);
		}
	}
	chdir(wdchar);
	free(wdchar);
	return (NULL);
}


/**
* create_path -> Combines two strings. Representing the path directory
* and command file.
* @d_path: Directory path.
* @f_path: file path.
*
* Return: string represnting the full path of a command. otherwise NULL.
*/

char *create_path(char *d_path, char *f_path)
{
	int cmd_len, len, i, j, dir_len;
	char *create;

	if (d_path == NULL || f_path == NULL)
		return (NULL);
	dir_len = str_len(d_path) + 1;
	cmd_len = str_len(f_path) + 1;
	len = dir_len + cmd_len;

	create malloc(sizeof(char) * len);
	if (create == NULL)
		return (NULL);

	for (i = 0, i < len; i++)
	{
		for (j = 0; d_path[j] != '\0'; j++, i++)
			create[i] = d_path[j];
		create[i] = '/';
		i++;
		for (j = 0; f_path[j] != '\0'; j++, i++)
			create[i] = f_path[j];
	}
	create[--i] = '\0';
	return (create);
}
