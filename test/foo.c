#include "shell.h"
#include <dirent.h>

int path (int argc, char *argv[])
{
	DIR *dir;
	struct dirent *ad;

	dir = opendir(".");

	if (dir == NULL)
	{
		printf("Error! Unable to open directory.\n");
		exit(1);
	}

	while ((ad == readdir(dir)) != '\0')
	{
		printf(">> %s\n", ad->d_name);
	}

	closedir(dir);

	return (0);
}
