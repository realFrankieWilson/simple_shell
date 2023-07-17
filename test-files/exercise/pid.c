#include <unistd.h>
#include <stdio.h>

/**
 * main -> A program that prints the PID of the parent and child_process.
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = getpid();
	ppid = getppid();
	printf("parent PID is \"%u\"\n", ppid);
	printf("child PID is \"%u\"\n", pid);
	return (0);
}
