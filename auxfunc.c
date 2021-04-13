#include "holberton.h"
#include "shell.h"
/**
 *_putchar - this will print one character at a time
 *@c: this is the parameter for character
 *Return: will return the character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_strlen - will get the lenght of the string (argument)
 *@s: is the string to get the lenght
 *Return: will return the lenght
 */

int _strlen(char *s)
{
	int index;

	index = 0;

	while (*s)
	{
		s++;
		index++;
	}
	return (index);
}

/**
 *_putstring - will put the string after getting the length
 *@s: the string to print
 *Return: (argument) to print stdout
 */

int _putstring(char *s)
{
	return (write(1, s, _strlen(s)));
}

/**
 * *_strcat - function that concanates two strings
 *@dest: pointer to first string
 *@src: pointer to second string
 *Return: concanate string
 */

char *_strcat(char *dest, char *src)
{
	int len1;
	int len2;

	for (len1 = 0; dest[len1] != '\0'; len1++)
	{
	}
	for (len2 = 0; src[len2] != '\0'; len2++)
		dest[len1 + len2] = src[len2];

	dest[len1 + len2] = '\0';

	return (dest);
}

/**
 * _strlen - function for testing lenght
 *@s: pointer
 *
 *Return: the lenght of str
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
