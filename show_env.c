#include "shell.h"
#include "holberton.h"

/**
 * showenv - prints the entire enviroment
 * @args: The arguments that came wit env
 * @env: list of envirmonetal variables
 */

void shownenv(char *args, char **env)
{
	int count, len;

	if (strcmp("-i", args) == 0)
		return;

	for (count = 0; env[count] != NULL; count++)
	{
		len = strlen(env[count]);
		write(STDOUT_FILENO, env[count], len);

		if (strcmp("-0", args) == 0)
			write(STDOUT_FILENO, "\0", 1);
		else
			write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * show_only_env - Function that prints the entire environmental
 * variable list onto the console
 * This function handles env with no arguments
 * @environ: List of environmental variables, passed from main
 * Return: Nothing
 */

void show_1_env(char **env)
{
	int count, len;

	for (count = 0; env[count] != NULL; count++)
	{
		len = strlen(env[count]);
		write(STDOUT_FILENO, env[count], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
