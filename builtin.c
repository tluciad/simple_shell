#include "my_shell.h"
/**
 * built_in - builtin functions of shell
 * @sll: shell structure
 * @envs: environements
 * Return: int
 */
int built_in(sll_t *sll, char **envs)
{
	if (strcmp(sll->Command, "exit") == 0)
	{
		ALLfree(sll);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(sll->Command, "env") == 0)
	{
		while (*envs)
		{
			printf("%s\n", *envs);
			envs++;
		}
		ALLfree(sll);
		return (1);
	}

	if (strcmp(sll->Command, "cd") == 0)
	{
		printf("I'm cd Command\n");
		ALLfree(sll);
		return (1);
	}

	return (0);
}
