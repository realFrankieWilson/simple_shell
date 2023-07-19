@@ -1,27 +0,0 @@
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int r;

	while (1)
	{
		printf("$ ");
		/* getline authomatically adds a new line when ever it ecounters an enter key */
		r = getline(&lineptr, &n, stdin);
		/* Checking for errors and EOF */
		if (r == -1)
		{
			exit(0);
		}
		/* print out the inpute from the stdin */
		printf("%s", lineptr);

		/* execv is use to execute command */

		execv(lineptr, NULL, NULL);
	}
}