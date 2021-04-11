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
