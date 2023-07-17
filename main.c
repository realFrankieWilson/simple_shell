#include "main.h"

/**
 * main -> runs the code
 *
 * Return: void
 */
int main(void)
{
	char *lineptr = NULL, *buf = NULL;
	ssize_t char_read = 0; /* number of characters the user type */
	int split_tokens = 0;
	char *split, **av;
	size_t n = 0;
	const char *new_line = " \n";

	/* loop for shell prompt */
	while (1)
	{
		printf("$ ");
		/* get the string from the user */
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
			return (-1);
		/* Allocate memory space to store the characters read by getline*/

		buf = malloc(sizeof(char) * char_read);
		/* treat error */
		if (buf == NULL)
		{
			perror("tsh: Unable to allocate memory");
			return (-1);
		}

		/*buff(buf);*/
		/* make a copy of command stored in buf */
		strcpy(buf, lineptr);

		/*split string inf lineptr into array of words */
		split = strtok(lineptr, new_line);
		/* calculate how many tokens present */
		calc(split);
		/* allocate enough space fot the pointer to the argmt variable */
		av = malloc(sizeof(char *) * split_tokens);
		/* breake string into sequence of sequence of nonempty tokens */
		split = strtok(lineptr, new_line);
		/* allocate space to splited strings */
		spc_allocation(av, split);
		/* execute command */
		exec_fn(av);
	}
	free(buf);
	free(lineptr);
	return (0);
}
