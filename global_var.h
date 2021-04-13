#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#define max_args 13
#define maxEnvCmd 105

char *args[max_args]; /*reads command from user input*/
char comando[maxEnvCmd]; /*store number of arguments from commands */

char SHELL[maxEnvCmd];
char PATH[maxEnvCmd];
char HOME[maxEnvCmd];
char PWD[maxEnvCmd];

#endif
