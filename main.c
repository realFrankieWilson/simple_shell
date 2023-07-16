#include "main.h"

/**
 * main -> runs the code
 *
 * Return: void
 */

int main(void)
{
	char *lineptr = NULL, *buf = NULL;
	size_t n = 0;
	ssize_t char_read; /* number of characters the user type */
	int i = 0, split_tokens = 0;
	char *split, **av;
	const char *new_line = " \n";

	/* loop for shell prompt */
	while (1)
	{
		printf("$ ");

		/* get the string from the user */
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
			return (-1);

		/* Allocate memory space to store the characters read by getline */

		buf = malloc(sizeof(char) * char_read);
		/* treat error */
		if (buf == NULL)
		{
			perror("tsh: Unable to allocate memory");
			return (-1);
		}
		/* make a copy of command stored in buf */
		strcpy(buf, lineptr);

		/*split string inf lineptr into array of words */
		split = strtok(lineptr, new_line);

		/* calculate how many tokens present */
		while (split != NULL)
		{
			split_tokens++;
			split = strtok(NULL, new_line);
		}
		split_tokens++;



		/* allocate enough space fot the pointer to the argmt variable */
		av = malloc(sizeof(char *) *split_tokens);
		split = strtok(lineptr, new_line);

		for (i = 0; split != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(split));
			strcpy(av[i], split);

			split = strtok(NULL, new_line);
		}
		av[i] = NULL;
		/* execute the commands with execv */
		exec_fn(av);
	}
	free(buf);
	free(lineptr);

	return (0);
}
