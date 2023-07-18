#include <stdio.h>
#include <stdlib.h>
/**
 * main -> runs the program.
 *
 * Return: 0
 */

int main(void)
{
	size_t n;

	char *lptr = NULL;
	printf("Enter name ");
	getline(&lptr, &n, stdin);
	printf("name is %s Buffer size is %ld\n", lptr, n);

	free(lptr);
	return (0);
}


