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
char comando[maxln_Com_Amb]; /*Esta var lee el comando que ingrese el usuario*/
char *args[max_args]; /*en este arreglo se almacenan los argumentos del comando ingresado*/
/*Declarando variables de ambiente*/
char SHELL[maxln_Com_Amb];
char PATH[maxln_Com_Amb];
char HOME[maxln_Com_Amb];
char PWD[maxln_Com_Amb];
/*Declarando cabeceras de funciones*/
void separaArgs(void); /*Esta funcion separa la cadena ingresada por el usuario en 
						 palabras individuales, la 1ra palabra sera considerada comando y el resto sus argumentos*/
void listaDir(void); /*Esta func ejecuta el comando dir*/
void eco(void); /*Esta func ejecuta el comando echo*/
void comExterno(void); /*Esta func ejecuta lo que se considere comandos externos*/


#endif
