#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int favNum = 84;

int _exec(int argc, char *argv[])
{
	printf("   My PID %d.\n", getpid());
	
	printf("helloExec.c: fav num is %d\n", favNum);
	printf("   My arguments: ");
	for (int i = 0; i < argc; i++)
	{
		printf("%s", argv[i]);
	}
	printf("\n");

	return (0);
}
