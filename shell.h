#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio_ext.h>
#include <dirent.h>
#include <stdarg.h>
#define max_args 13
#define maxEnvCmd 105


/* Printf prototypes */
int _printStr(va_list args);
int _printChar(va_list args);
int _printDec(va_list args);
int _putchar(char c);
int _putstring(char *s);


/** Shell prototypes */
void getArgs(char *cmd, char **args);
void externalCmd(char *cmd, char **args);
char *_getEnv(char *str, char *envp[]);


/* Aux prototypes */
int _printf(const char *format, ...);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif
