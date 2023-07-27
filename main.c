#include "main.h"

/**
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
<<<<<<< HEAD
}
=======
}
>>>>>>> update
