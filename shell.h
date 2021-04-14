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

/**
 * struct data - struct for bypass the restrictioctons ommitting global variables
 * @tokens: 1st
 * @buffer: 2nd
 * Description: allows to free variables in memory to avoid memorys leaks issues
 */

struct data
{
	char *tokens;
	char *buffer;
};

/*prototypes*/

int _printf(const char *format, ...);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _printStr(va_list args);
int _printChar(va_list args);
int _printDec(va_list args);
void prompt(void);
char *read_cmd(void);
int _fork(void);
void split_args(void);
void dir_list(void);
void external_commands(void);
int _putchar(char c);
/** enviroment prototypes */
char *env_value(char *str, char *delim);
char *_getenv(char *name, char **env);
void _free(struct data *d);
void shownenv(char *args, char **env);
void show_1_env(char **env);
int _exec(int argc, char *argv[]);
int _putstring(char *s);
void getArgs(char *cmd, char **args);
void showDir(char *pwd, char **args);
void echo(char *pwd, char *home, char *shell, char *path, char **args);
void externalCmd(char *cmd, char **args);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);

#endif
