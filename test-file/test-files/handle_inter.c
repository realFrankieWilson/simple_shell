#include "main.h"

/**
 * a function that handles the interactive shell
 *
 */

void handle_int(char *filename)
{
	char *args = NULL, temp = 0;
	int read; size_t n = 0;


	while (1)
	{
		printf("$ ");
	}

	read = getline(&args, &n, stdin);

	temp = args;

	while (*temp != NULL)
	{
		if (temp == '\n')
		{
			*temp = '\n';
		}
		temp++;
	}

	 /** free the getline on success or or not */
	if (read == -1)
	{
		free(args);
		exit(EXIT_SUCCESS);
	}
	
	/* exec command is a function that execusts command */
	exec_cmd(args, filename);
}
