#include <stdio.h>
#include <stdlib.h>

char* _getline(FILE *f, char *s,  size_t maxchar)
{
	size_t i = 0;

	if(maxchar)
	{
		int c;

		while(i < maxchar - 1 && (c = fgetc(f)) != EOF && 	 c != '\n')
		{
			s[i++] = c;
		}
	}
	s[i] = '\0';

	return(s);
}

#define MAX_CHAR 80

int main(void)
{
	FILE *f;
	char s[MAX_CHAR];
	
	printf("%s\n", _getline(f, s, 3));
	printf("%s\n", _getline(f, s, 5));
	return(0);
}


