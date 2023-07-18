#include <stdio.h>

int main(void)
{
	char buf[5];
	
	while (1)
	{
		printf("$ ");
		fgets(buf, 5, stdin);
		printf("%s", buf);
	}
	return (0);
}
