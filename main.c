#include "main.h"

/**
<<<<<<< HEAD
* main -> Entry point for the program.
* @argc: argument count.
* @argv: argument vector.
*
* Return: 0 on success.
*/

int main(int argc, char *argv[])
{
	shell_input lineptr;
	(void) argc;

	signal(SIGINT, get_sigint);
	set_data(&lineptr, argv);
	shell_loop(&lineptr);

	free_data(&lineptr);
	if (lineptr.status < 0)
		return (255);
	return (lineptr.status);
}
=======
* main -> Runs the program.
* @argc: Number of arguments passed to the executable file.
* NOTE: the argc variable passed is not used in this function.
* @argv: Arguments lists, AKA name and argument of the program.
*
* Return: Always 0.
*/

int main(__attribute__((unused)) int argc, char *argv[])
{
	char *linptr;
	int cmd_counter = 0;
	size_t size;

	signal(SIGINT, SIG_IGN);

	do {
		cmd_counter++;
		linptr = NULL;
		size = 0;
		cmd_line(linptr, size, cmd_counter, argv);
	} while (1);

	return (0);
}
>>>>>>> refs/remotes/origin/update
