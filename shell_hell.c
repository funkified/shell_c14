#include "shell.h"
#include "global_var.h"

/**
 * main - main program that prompts user
 * Return: Nothing
 */
int main(void)
{
	int endRun = 1;

	getcwd(PWD, maxEnvCmd);
	_strcpy(PATH, getenv("PATH"));
	_strcpy(HOME, PWD);
	_strcpy(SHELL, PWD);

	do {
		_printf("Shell Hell $ ");
		__fpurge(stdin);
		_memset(cmd, '\0', maxEnvCmd);
		scanf("%[^\n]s", cmd);

		if (_strlen(cmd) > 0)
		{
			getArgs();

			if (strcmp(cmd, "cd") == 0)
			{
				if (args[1]) /* verify if additional parameters*/
				{
					if (chdir(args[1]) != 0)
						printf("Error: %s not found\n", args[1]);
					else
						getcwd(PWD, maxEnvCmd);
				}
			}
			else if (strcmp(cmd, "dir") == 0)
			{
				showDir();
			}
			else if (strcmp(cmd, "clr") == 0)
			{
				_strcpy(cmd, "clear");
				externalCmd();
			}
			else if (strcmp(cmd, "environ") == 0)
			{
				_printf(" Environment variables:\n");
				_printf("  HOME=%s\n  PWD=%s\n", HOME, PWD);
				_printf("  SHELL=%s\n  PATH=%s\n", SHELL, PATH);
			}
			else if (strcmp(cmd, "echo") == 0)
			{
				if (args[1])
					echo();
			}
			else if (strcmp(cmd, "pwd") == 0)
				_printf("%s\n", PWD);

			else if (strcmp(cmd, "exit") == 0)
				endRun = 0; /* Value of 0 exits the program*/

			else
				externalCmd();
		}

	} while (endRun); /*Infinite loop*/

	return (0);
}


/**
 * getArgs - separates user submitted buffer into tokens
 * Return: Nothing
 */
void getArgs(void)
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
	{

	}
}


/**
 * showDir - prints list of files and folders of current directory
 * @dirent: list of gfiles and folders found
 * Return: nothing
 */
void showDir(void)
{
	char path[maxEnvCmd]; /*custom path string to build*/
	int filesFound; /*Files found counter*/
	int cnt = -1;
	struct dirent **folderList;


	_strcpy(path, PWD);

	if (args[1])
	{
		_strcat(path, "/");
		_strcat(path, args[1]);
	}
	/* if its subfolder, concatenate them*/
	filesFound = scandir(path, &folderList, 0, alphasort);

	if (filesFound < 0)
		printf("Error: not found [%s]\n", path);

	else if (filesFound == 2) /* only two entries . and .. nothing else */
		_printf(" Folder [%s] is empty", path);

	else
	{ /* if at least one is found*/
		_printf(" Content found: [%s]\n", path);

		while (++cnt < filesFound)
		{
			if (strcmp(folderList[cnt]->d_name, ".") != 0 && strcmp(folderList[cnt]->d_name, "..") != 0)
				_printf(" %s\n", folderList[cnt]->d_name);
		}
	}
}

/**
 * echo - prints a user specified string in a new line
 * Return: Nothing
 */
void echo(void)
{
	unsigned int i;
	int j;
	int k = 0;
	char aux[6];

	while (args[++k])
	{
		for (i = 0; i < strlen(args[k]); i++)
		{
			if (args[k][i] != '$')/* will iterate through each char until $ is found */
				_printf("%c", args[k][i]);

			else
			{ /*if char is $ look if its followed by env var. if yes print it. */
				j = -1;

				while (++j < 5 && (i + j + 1) < strlen(args[k]) && args[k][i + j + 1] != '\0')
					aux[j] = args[k][i + j + 1]; /*Copy to aux chars that follow the $ */

				aux[j] = '\0';
				/* check for individual environment vars*/
				if (_strcmp(aux, "SHELL") == 0)
					_printf("%s", SHELL), i += 5;

				else if (_strcmp(aux, "PATH") == 0)
					_printf("%s", PATH), i += 4;

				else if (_strcmp(aux, "PWD") == 0)
					_printf("%s", PWD), i += 3;

				else if (_strcmp(aux, "HOME") == 0)
					_printf("%s", HOME), i += 4;

				else
					_printf("$");
			}
		}
		_printf(" ");
	}
	_printf("\n");
}


/**
 * externalCmd - executes linux command on user prompt
 * Return: Nothing
 */
void externalCmd(void)
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
