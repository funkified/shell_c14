#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("before the fork\n");
	pid = fork();

	if (pid == -1)
	{
		perror("Where is the fork?\n");
		return(1);
	}

	if (pid == 0)
	{
		printf("I am the child\n");
	}
	else
	{
		printf("I am the father\n");
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	return(0);
}

