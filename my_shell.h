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
 * @sll: Command
 * @flags: arguments
 * @num_flags: number of arguments
 */
typedef struct SLL
{
	char *Command;
	char **flags;
	int num_flags;
} sll_t;

void ALLfree(sll_t *sll);
int flagsCOUNT(char *input);
sll_t *new_sll(int num_flags);
sll_t *parse_sll(char *input);
void new_signal_handler(int pid __attribute__((unused)));
char *getpath_sll(sll_t *sll, char *envPath);
int nobuilt_in(sll_t *sll, char *CommandPath);
int built_in(sll_t *sll, char **envs);
int look_char(sll_t *sll);
int look_char(sll_t *sll);
void GETline(char **line);

int _strlen(const char *str);
char *_strconcat(char *s1, char *s2, char *s3);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

#endif
