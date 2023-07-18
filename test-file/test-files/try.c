#include <stdio.h>
#include <unistd.h>
int main(int *arc, char *argv[])
{
	int r = 0;

	while (arc < argv)
	{
		r = getline(&argv, &arc, stdin);
	}

	printf("text entered: %s, total: %ld\n", argv, arc);
	
}
