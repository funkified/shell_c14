#include "shell.h"
#include <dirent.h>

/*unsigned int path (int argc, char *argv[])
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
}*/

unsigned dir_look (char *path)
{
	unsigned int dir = 0, idx = 0, flag = 0;

	while (path[idx])
	{
		if (path[idx] != ':')
			flag = 1;
		if ((flag && path[idx + 1] == ':')|| (flag && path[idx + 1] == '\0'))
		{
			++dir;
			flag = 0;
	}
	++idx;
	}
	return (dir);
}
