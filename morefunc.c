#include "shell.h"
#include "global_var.h"
/**
 *_memset - function that fill first byte of memory are pointed to a const byte
 * Return: pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
