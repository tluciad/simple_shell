#ifndef _MYSHELL_
#define _MYSHELL_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct SLL
{
    char *cmd;
    char **arguments;
    int num_args;
} sll_t;

#endif
