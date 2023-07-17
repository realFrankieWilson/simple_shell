#include <stdio.h>
#include <stdlib.h>
/**
 * getline -> reads an entire line from stream.
 * storing the address of the buffer containning the text into
 * *lineptr
 *
 * Return: the number of characters read include special characters such as ,, . / etc.
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (--argc != 1)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("Retrieved line of length %zd:\n", nread);
		fwrite(line, nread, 1, stdout);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
