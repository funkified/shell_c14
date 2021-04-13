#include "holberton.h"
#include "shell.h"
/**
 *_printStr - this will print a string of character
 *@args: is the next argument in line
 *Return: will return the arguments
 */

int _printStr(va_list args)
{
	char *str;

	str = (char *)va_arg(args, char *);

	return (_putstring(str));
}

/**
 *_printChar - this will print a single character
 *@args: is the next argument in line
 *Return: will return the arguments
 */

int _printChar(va_list args)
{
	char ch;

	ch = (char)va_arg(args, int);

	return (_putchar(ch));
}

/**
 *_printDec - will print an integer to decimal
 *@args: is the list of arguments
 *Return: this will return the count of caracters
 */

int _printDec(va_list args)
{
	long int arguments;
	long int contador = 0;
	long int divisor;

	arguments = va_arg(args, int);

	if (arguments == 0)
	{
		_putchar('0');
		contador++;
	}
	else if (arguments < 0)
	{
		_putchar('-');
		arguments = -arguments;
		contador++;
	}

	if (arguments > 0)
	{
		divisor = 1;
		while (divisor <= arguments)
		{
			divisor *= 10;
		}
		while (divisor > 1)
		{
			divisor /= 10;
			_putchar((arguments / divisor) + '0');
			arguments %= divisor;
			contador++;
		}
	}
	return (contador);
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

/*char *_strncpy(char *dest, char *src, int n)*/
char * _strcpy(char *dest, char *src)
{
	int i, n;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

/*	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
*/
	return (dest);
}
