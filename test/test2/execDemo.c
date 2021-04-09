#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int favNum = 84;

int main (int argc, char *argv[])
{
	printf("execDemo PID is %d\n", getpid());
	/*
	 * exec
	 * with L: comma separated arguments
	 * with V: Vector (an array of strings)
	 * With P: Include normal search path for executable
	 */
	char *args[] = {"helloExec", "Hello", "World", NULL};
	execvp("./helloExec", args);
	return (0);
}
