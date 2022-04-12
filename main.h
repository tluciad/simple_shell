#ifndef SHELL
#define SHELL

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>

typedef struct BuildIn
{
    char* command;
    int (*exec)(va_list);
} build_in;


int (*get_build_in_func(char*))(va_list);

/* Build-in handlers */
int cd_handler(va_list);
int exit_handler(va_list);
int env_handler(va_list);
int help_handler(va_list);

#endif
