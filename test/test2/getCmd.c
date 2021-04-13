#include <stdio.h>
#include <string.h>
#include <unistd.h>

void getPATH(char path[50]);
int _strcmp(char *s1, char *s2);


int main(int argc, char *argv[], char *envp[])
{
	int i, j, length = 0, length2 = 0;
	char *str = "PATH=";
	int result;

	while (str[length])// get length of our input string
		length++;

	for (i = 0; envp[i] != NULL; i++)
	{
		if ((_strcmp(str, envp[i]) == 0))
		{
			printf("%s\n", envp[i]);
			getPATH(envp[i]);
		}
	}
}

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

void getPATH(char path[50])
{
	char *tokens[10];
	char *tok = NULL;
	int idx = 0;

	tok = strtok(path, "=");	// initial search for PATH token

	while (tok != NULL)
	{
		tokens[idx] = tok;	// populate our array of tokens
		tok = strtok(NULL, ":"); // call function again to move to next element
		idx++;	// increase index to save on array
	}
	tokens[idx] = NULL;// last element of where array ended, set to NULL as end marker

	for (idx = 0; tokens[idx] != NULL; idx++)  // lets iterate the token array and print each element
		printf("%s\n", tokens[idx]);
}
