#ifndef _MYSHELL_
#define _MYSHELL_

#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct SLL - structure to manage the shell
 * @cmd: comand
 * @flags: arguments
 * @num_flags: number of arguments
*/
typedef struct SLL
{
	char *cmd;
	char **flags;
	int num_flags;
} sll_t;

void free_all(cmd_t *cmd);
int count_flags_by_space(char *input);
cmd_t *new_cmd(int num_flags);

#endif
