#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	if (fork())
	{
		printf("nonezero\n");
	}
	else
	{
		printf("zero\n");
	}
}
