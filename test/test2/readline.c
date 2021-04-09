#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char text[100];

	printf("Type a line of text: ");
	scanf("%[^\n]s", text);

	printf("You typed \'%s\'\n", text);
	return (0);
}
