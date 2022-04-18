#include "my_shell.h"
/**
 * built_in - builtin functions of shell
 * @sll: shell structure
 * @envs: environements
 * Return: int
 */
int built_in(sll_t *sll, char **envs)
{
	if (strcmp(sll->command, "exit") == 0)
	{
		free_all(cmd);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(sll->command, "env") == 0)
	{
		while (*envs)
		{
			printf("%s\n", *envs);
			envs++;
		}
		free_all(sll);
		return (1);
	}

	if (strcmp(sll->command, "cd") == 0)
	{
		printf("I'm cd command\n");
		free_all(sll);
		return (1);
	}

	if (strcmp(sll->command, "cd") == 0)
	{
		printf("I'm cd command\n");
		free_all(sll);
		return (1);
	}
	return (0);
}
