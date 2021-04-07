#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
/*prototypes*/

void print_prompt(void);
void print_prompt2(void);
char *read_cmd(void);

#endif
