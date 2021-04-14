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
/**
 *_strcmp - compares two string
 *@s1: string 1
 *@s2: string 2
 *Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int len = 0;

	for (len = 0; s1[len] == s2[len]; len++)
		if (s1[len] == '\0')
			return (0);

	return (s1[len] - s2[len]);

}
/**
 * _strncpy - copy a string
 * @dest: var to be copied into
 * @src: source var
 * @n: number of bytes
 * Return: Copied string
 */

char * _strcpy(char *dest, char *src)
{
	int i;
	char str;

	for (i = 0; src[i] != '\0'; i++)
	{
		str = src[i];
		dest[i] = str;
	}
	dest[i] = ('\0');
	return (dest);
}
