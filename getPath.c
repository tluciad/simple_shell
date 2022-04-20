#include "my_shell.h"
/**
 * getpath_sll - Get the path from Command object
 * @sll: Command
 * @envPath: environment path
 * Return: char*
 */
char *getpath_sll(sll_t *sll, char *envPath)
{
	char *path = NULL,
		 *token = NULL,
		 *tempEnvP = NULL;
	struct stat stats;
	int flag = 0;

	tempEnvP = _strdup(envPath);
	flag = look_char(sll);

	token = strtok(tempEnvP, ":");
	while (token != NULL)
	{
		if (flag == 1)
			path = _strdup(sll->Command);
		
		else
			path = _strconcat(token, "/", sll->Command);

		if (stat(path, &stats) == 0)
			break;

		free(path);
		path = NULL;
		token = strtok(NULL, ":");
	}

	free(tempEnvP);

	if (!path)
		return (NULL);
	return (path);
}
