#include "holberton.h"

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
