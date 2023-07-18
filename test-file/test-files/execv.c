#include <stdio.h>
#include <unistd.h>

/**
 * main -> execv
 *
 * Return: 0
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execv\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execv\n");
	return (0);
}
