#include <stdio.h>
#include <string.h>

int main(void)
{
	char path[40] = "PATH=Hola:yo:soy:de:PuertoRico";
	char *tokens[10];
	char *tok = NULL;
	int idx = 0;

	printf("Our input string: %s\n", path);

	tok = strtok(path, "=");	// initial search for first token
	while (tok != NULL)
	{
		tokens[idx] = tok;	// populate our array of tokens
		tok = strtok(NULL, ":"); // call function again to move to next element
		idx++;	// increase index to save on array
	}
	tokens[idx] = NULL;// last element of where array ended, set to NULL as end marker

	for (idx = 0; tokens[idx] != NULL; idx++)  // lets iterate the token array and print each element
		printf("%s\n", tokens[idx]);

	return(0);
}
