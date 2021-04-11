#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#define MAX_CHAR 80

int main(void)
{
	FILE *f;
	char s[MAX_CHAR];
	
	
	f = fopen("flie.xt", "r");

	if (s[MAX_CHAR] != '\0')
	{
		fprintf(f, "%s", s);
	}
	return (0);
}
