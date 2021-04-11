#include "holberton.h"
#include <stdarg.h>

/**
 *itoa - converts interger to string
 *@s: pointer to string
 *@base: converts to base 10
 *@num: interger to be converted
 *Return: pointer of string converted to interger
 */

char *itoa(int num, char *s, int base)
{
	int i = 0;

	if (num == 0)
	{
		s[i++] = '\0';
		s[i] = '\0';
		return (s);
	}
	while (num != 0)
	{
		int rem = num % base;

		s[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	return (s);
}

