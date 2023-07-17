#include "main.h"

/**
 * executes commands we pass to main
 *
 */

void exec_cmd(char *args, char *filename)
{
	/*create a child process */
	pid_t child = fork(); /*fork always return a new process*/
	char *ar[] = {"b", NULL};

	

	/** us the return value of fork to handle error */
	if (child == -1)
