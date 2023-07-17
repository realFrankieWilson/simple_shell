#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
	char *arg[] = {"ls", NULL};
	char c = 'c', n = '\n';

	write(1, &c, 1);
	write(1, &n, 1);

	pid_t child = fork();

	if (child == 0)
	{
		execve("/bin/ls", arg, NULL);
	}
	else
		wait(NULL);

	write(1, &n, 1);
	write(1, &c, 1);
	printf("\n");

	return (0);
}
