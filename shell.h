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
int *_strcat(char *dest, char *src);
int _strlen(char *s);
int _printStr(va_list args);
int _printChar(va_list args);
int printDec(va_list args);

void prompt(void);
void print_prompt(void);
void print_prompt2(void);
char *read_cmd(void);
unsigned int dir_look (char *path);
char* _getline(FILE *f, char *s, size_t maxchar);
int _fork(void);
void split_args(void);
void dir_list(void);
void echo(void);
void external_commands(void);
int _putchar(char c);
/** enviroment prototypes */
void shownenv(char *args, char **env);
char *env_value(char *str, char *delim);
char *_getenv(char *name, char **env);
void _free(struct data *d);
void shownenv(char *args, char **env);
void show_1_env(char **env);
int _exec(int argc, char *argv[]);
int _putstring(char *s);
void getsArgs(void); /*Esta funcion separa la cadena ingresada por el usuario en 
						 palabras individuales, la 1ra palabra sera considerada comando y el resto sus argumentos*/
void showDir(void); /*Esta func ejecuta el comando dir*/
void echo(void); /*Esta func ejecuta el comando echo*/
void Externalcmd(void); /*Esta func ejecuta lo que se considere comandos externos*/


#endif
