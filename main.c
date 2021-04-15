#include "shell.h"

char *_getEnv(char *str, char *envp[]);

/**
 * main - main program that prompts user
 * Return: Nothing
 */
int main(void)
{
	int endRun = 1;
	char *args[max_args], cmd[maxEnvCmd], SHELL[maxEnvCmd];
	char PATH[maxEnvCmd], HOME[maxEnvCmd], PWD[maxEnvCmd];

	getcwd(PWD, maxEnvCmd), _strcpy(PATH, getenv("PATH"));
	_strcpy(HOME, PWD), _strcpy(SHELL, PWD);

	do {
		_printf("$ ");
		__fpurge(stdin);
		_memset(cmd, '\0', maxEnvCmd);
		scanf("%[^\n]s", cmd);

		if (_strlen(cmd) > 0)
		{
			getArgs(cmd, args);

			if (_strcmp(cmd, "environ") == 0)
			{
				_printf(" Environment variables:\n");
				_printf("  HOME=%s\n  PWD=%s\n", HOME, PWD);
				_printf("  SHELL=%s\n  PATH=%s\n", SHELL, PATH);
			}
			else if (_strcmp(cmd, "exit") == 0)
				endRun = 0; /* Value of 0 exits the program*/

			else
				externalCmd(cmd, args);
		}

	} while (endRun); /*Infinite loop*/

	return (0);
}


/**
 * getArgs - get arguments from buffer
 * @cmd: string to be checked as command
 * @args: string from buffer as arguments
 */
void getArgs(char *cmd, char **args)
{
	int i;

	for (i = 0; i < (max_args - 1); i++)
	{
		args[i] = NULL; /*clear list of arguments*/
	}
	strtok(cmd, " ");

	i = 0; /*separate argument string in tokens*/
	args[i] = cmd; /*1st argument is the command*/

	while ((args[++i] = strtok(NULL, " ")) != NULL && i < (max_args - 2))
		;
}


/**
 * externalCmd - executes linux command on user prompt
 * @cmd: string to be read as command
 * @args: list of arguments summited
 * Return: Nothing
 */
void externalCmd(char *cmd, char **args)
{
	int pid = 0;
	int status;

	pid = fork(); /*Create subprocess*/

	if (pid < 0)
		_printf("Error: Could not create process for this command.");

	if (pid == 0)
	{
		status = execvp(cmd, args); /*Call command with args*/

		if (status)
		{
			_printf("Error: %s not recognized\n", cmd);
			exit(1);
		}
	}
	else
		wait(NULL); /* parent process hold runtime until child finishes */
}

/**
 * _getEnv - get path from environment variable received
 * @str: pointer to string representing environment variable
 * @envp: environment variables to search in
 * Return: environment path
 */
char *_getEnv(char *str, char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if ((_strcmp(str, envp[i]) == 0))
		{
			return (envp[i]);
		}
	}
	return (NULL);
}

