#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(size_t n, char *lineptr)
{
	char *argv[] = {"/bin/ls", NULL};
	n = 0;
	int r;

	while (1)
	{
		printf("$ ");
		r = getline(&lineptr, &n, stdin);

		/* handle erros and EOF */
		if (r == -1)
		{
			exit(0);
		}

		//execve(lineptr, argv, NULL);
		printf("%s", argv);
	}

	return (0);
}


