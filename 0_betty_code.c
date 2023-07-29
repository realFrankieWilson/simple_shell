#include "main.h"

/**
 * main-> Entry point.
 *
 * Return: Nothing.
 */

int main(void)
{
	int i, j = 0;

	for (i = 0; i < 10; i++)
	{
		while (j != 10)
		{
			printf("%d\n", j);
			j++;
		}
		printf("%d\n", i);
	}
	return (0);
}
