#include "main.h"


int (*get_build_in_func(char *command))(va_list)
{   
    int i = 0;
    build_in funcs[] = {
        {"cd", cd_handler},
        {"exit", exit_handler},
        {"env", env_handler},
        {"help", help_handler},
    };

    while(funcs[i].command)
    {
        if (strcmp(funcs[i].command, command) == 0)
            return (funcs[i].exec);
        i++;
    }

    return (NULL);
};
