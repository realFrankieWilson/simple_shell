#include "main.h"


int get_line(ssize_t read)
{
	char **lineptr = 0;
	size_t n = 0;
	read = getline(&*lineptr, &n, stdin);
	if (read == -1)
		return (-1);
	return (0);
}
