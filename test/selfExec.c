#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	printf("selfExec: My pid is %d.\n", getpid());

	if (argc != 2)
	{
		printf("Pass 1 argmuent as an interger\n");
		exit(1);
	}
	int n = atoi(argv[1]);
	printf("%d...\n", n-1);

	if (n != 0)
	{
		char nMinus1[10];
		sprintf(nMinus1,"%d", n - 1);
	//printf("Arg to pass %s\n", nMinus1");
		execl(argv[0], argv[0], nMinus1, NULL);
	}

	printf("F*&^\n");
	return (0);
}
