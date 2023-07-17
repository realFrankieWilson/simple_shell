#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * main -> exec
 *
 */
#include <sys/wait.h>
int main(void)
{
	char *argv[] = {"ls", NULL};
	char *bin_file = argv[0];

	if (fork() == 0)
	{
		//child process

		int redirect = open("redirect.txt", O_CREAT | O_TRUNC | O_WRONLY);

		dup2(redirect, STDOUT_FILENO);
		close(redirect);
		if (execvp(bin_file, argv) == -1)
			perror("Error: ");
		printf("done\n");
	}
	else
	{
		wait(NULL);
		printf("don!\n");
	}
}
