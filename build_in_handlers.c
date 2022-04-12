#include "main.h"

/**
 * cd_handler -
 * 
 * return int 
 */

int cd_handler(va_list args)
{  
    chdir(args);
    return (0);
}

/**
 * exit_handler -
 * 
 * Return: Always 0 (Success) 
 */

int exit_handler(va_list args)
{
    long int status = va_arg(args, long int);

    if (status < 0)
    {
        printf("hsh: 1: exit: Illegal number: -%d", status);
        return (2);
    }

    if (status > 0)
    {
        exit(status);
    }

    return (0);
}

/**
 * env_handler -
 * 
 * return int 
 */

int env_handler(va_list args)
{
    int i = 0, len = 0;
    char **envs = va_arg(args, char**);

    for (; envs[i]; i++)
    {
        write(STDOUT_FILENO, envs[i], strlen(envs[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    
    return (0);
}

/**
 * help_handler - 
 * 
 * return int 
 */

int help_handler(va_list args)
{
    return (0);
}
