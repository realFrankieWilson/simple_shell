#include "main.h"

/**
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
