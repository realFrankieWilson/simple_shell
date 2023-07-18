#include <stdio.h>
/**
 * main - prints all the arguments, without using ac.
 * argv: the array of arguments to be printed
 *
 * Return: Number of arguments.
 */

int main(int, char **argv)
{
	int i = 0;

	while (*(argv + i) != 0)
	{
		printf("%s ", *(argv + i));
		i++;
	}
	printf("\n");

	return (0);


}
