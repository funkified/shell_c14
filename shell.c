#include "shell.h"
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	char *cmd;

	do
	{
		print_prompt();
	
		cmd = read_cmd();
		
		if (!cmd)
		{
			exit(EXIT_SUCCESS);
		}

		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}

		if (strcmp(cmd, "exit\n") == 0)
		{
			fprintf(stderr, "Error found\n");
			free(cmd);
			break;
		}

		printf("%s\n", cmd);
		free(cmd);
	}
	while (1);
	exit(EXIT_SUCCESS);
}

void print_prompt()
{
	/*fprintf(stderr, "#cisfun$ ");*/
	write(STDERR_FILENO, "$ ", 2);
}
void print_prompt2()
{
	fprintf(stderr, "> ");
}

char *read_cmd(void)
{
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	while (fgets(buf, 1024, stdin))
	{
		int buflen = strlen(buf);

		if (!ptr)
		{
			ptr = malloc(buflen + 1);
		}
		else
		{
			char *ptr2 = realloc(ptr, ptrlen + buflen + 1);

			if (ptr2)
			{
				ptr = ptr2;
			}
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}
		if (!ptr)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
			return (NULL);
		}
		strcpy(ptr+ptrlen, buf);

		if (buf[buflen + 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
			{
				return (ptr);
			}
			ptr[ptrlen +buflen - 2] = '\0';
			buflen -= 2;
			print_prompt();
		}

		ptrlen += buflen;
		}
		return (ptr);
}

#include "holberton.h"
#include "shell.h"

#define BUFSIZE 64
#define DELIMETER "\t\r\n\a"

/**
 * **split = get the usr input and split in tokens. 
 * @input: pointer to char
 *
 * Return: On success, pointer to pointer with tokens
 */

char **split(char *input)
{
	int bufsize = BUFSIZE;
	int idx;
	char **tokens;
	char *token;

	tokens = malloc(sizeof(char *) * bufsize);

	if (tokens == NULL)
	{
		free(tokens);
		return (0);
	}
	
	token = strtok(input, DELIMETER);

	for (idx = 0; token != NULL; idx++)
	{
		tokens[idx] = token;

		if (idx >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (tokens == NULL)
			{
				free(tokens);
				return (0);
			}
		}
		token = strtok(NULL, DELIMETER);
	}
	tokens[idx] = '\0';

	return (tokens);
}

