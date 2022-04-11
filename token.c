#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * _strtok - function that split a PATH string 
 * @env: the string to split
 * @delim: the delimiter 
 * @Return: char** 
 */
char **_strtok(char *env, char *delim)
{
    
}

int main()
{
    char env[]; 
    char* token = strtok(env, ":");
 
    while (token != NULL) 
    {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
 
    return 0;
}