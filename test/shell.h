#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

/*prototypes*/

void print_prompt(void);
void print_prompt2(void);
char *read_cmd(void);
unsigned int dir_look (char *path);

/*child procces */
int fork(void);
#endif
