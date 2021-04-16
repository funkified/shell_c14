#include "shell1.h"
#include "holberton.h"

/**
 * env_value - takes an evniroment string and gets the value in variable
 * @str: string to be value
 * @delim: chars where strtok split string
 * Return: valie of th eenviromnet
 */

char *env_value(char *str, char *delim)

{
	str = strtok(str, delim);
	str = strtok(NULL, delim);

	return (str);
}

char *_getenv(char *name, char **env)
{
	int index, elements, len = 0;
	char *env_string = NULL;

	while (name[len])
		len++;

	env_string = malloc(sizeof(char) * len + 1);

	if (env_string == NULL)
	{
		free(env_string);
		return (NULL);
	}
	for (index = 0; env[index] != NULL; index++)
	{
		elements = 0;
		while (elements < len)
		{
			env_string[elements] = env[index][elements];
			elements++;
		}
		if (strcmp(name, env_string) == 0)
		{
			free(env_string);
			return (env[index]);
		}
	}
	free(env_string);
	return (NULL);
}

/**
 * _free = free malloc'd variable
 * @d: struct to be free
 * @Return: Nothing
 */

void _free(struct data *d)
{
	free(d->tokens);
	free(d->buffer);
}
