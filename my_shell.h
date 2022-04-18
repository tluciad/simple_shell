#ifndef MY_SHELL
#define MY_SHELL
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

#define EMPTY_STR ""

/**
 * struct SLL - structure to manage the shell
 * @cmd: Command
 * @flags: arguments
 * @num_flags: number of arguments
*/
typedef struct SLL
{
	char *Command;
	char **flags;
	int num_flags;
} sll_t;

void free_all(sll_t *cmd);
int count_flags_by_space(char *input);
sll_t *new_cmd(int num_flags);
sll_t *parse_cmd(char *input);
void new_signal_handler(int pid __attribute__((unused)));
char *_strconcat(char *s1, char *s2, char *s3);
int _strlen(const char *str);
char *_strdup(char *str);
char *getpath_cmd(sll_t *cmd, char *envPath);

#endif
