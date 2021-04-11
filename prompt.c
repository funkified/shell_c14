#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
int prompt(void)
{
	char *lineptr;
	size_t buffersize = 32;
	size_t input;

	lineptr = malloc(sizeof(char) * buffersize);
	if (lineptr == NULL)
	{
		free(lineptr);
		EOF;
		return (-1);
	}

	input = getline(&lineptr, &buffersize, stdin);
	printf("%lu\n",input);
	EOF;

	return (0);
}

