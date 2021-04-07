#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	printf("test_exec: My pid is %d.\n", getpid());

	char *args[] = {"./test_exec", "Hello", "World", NULL};
	execvp(args[0], args);
	exit(1);

	printf("Farewell cruel world\n");
	return (0);
}
