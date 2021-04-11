#include "shell.h"


int main (int argc, char **argv)
{
	char *str = NULL, **args, *prompt = "$ ";
	size_t len = 0;
	ssize_t chr;
	int count = 0;
	(void)argc;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 2);
		
	signal(SIGINT, handler);
	
	while ((chr = getline(&str, &len, stdin)))
	{
		if (chr == EOF)
		EOF(str);
		++count;
		args = strtok(str);
		_fork();
		len = 0;
		str = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
	}
	if (chr == -1)
		return(EXIT_SUCCESS);
		
	return (EXIT_SUCCESS);
}
