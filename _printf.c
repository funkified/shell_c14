#include "holberton.h"

/**
 *_printf - will print a string of characters or call functions using %
 *@format: is the string of characters inside the printf
 *Return: will return 0 if sucess
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(format + 1))
			{
			case '\0':
				return (-1);
			case '%':
				count += _putchar('%');
				format++;
				break;
			case 'c':
				count += _printChar(args);
				format++;
				break;
			case 's':
				count += _printStr(args);
				format++;
				break;
			case 'd':
			case 'i':
				count += _printDec(args);
				format++;
				break;
			default:
				count += _putchar('%');
			}
		}
		else
			count += _putchar(*format);
		format++;
	}
	return (count);
}
