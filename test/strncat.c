#include "holberton.h"
#include <stdio.h>

/**
 * *_strncat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: number of bytes
 * Return: Concatenated strings
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{

	}

	for (j = 0; j < n; j++)
	{
		dest[i] = src[j];
		i++;
	}

	return (dest);
}
